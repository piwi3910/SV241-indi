# SVBONY SV241 INDI Driver

INDI driver for the SVBONY SV241 Powerbox, enabling control from Linux and macOS-based astronomy software.

## Status

- **Protocol Research**: ✅ COMPLETE
- **Driver Development**: ✅ COMPLETE
- **Hardware Testing**: ✅ VERIFIED (macOS)
- **Release**: PENDING

## What is the SV241?

The SVBONY SV241 is an astronomy power distribution box with:
- **5x DC outputs** (12V switchable)
- **2x USB groups** (switchable power)
- **3x PWM outputs** (2 for dew heaters, 1 for adjustable voltage)
- **Sensors**: Voltage, Power, Ambient Temperature, Humidity, and Lens Temperature.

## Features

The C++ INDI driver now implements all core functionalities of the device:
- ✅ Serial communication (115200 baud 8N1)
- ✅ Stable connect/disconnect cycling without device resets.
- ✅ Full control of all DC and USB power outputs.
- ✅ Full control of all PWM/Dew heater outputs.
- ✅ Reading of all sensors (Voltage, Power, Temperature, Humidity).
- ✅ State synchronization on connect.
- ✅ Periodic polling of sensors.

## Repository Structure

The repository has been cleaned up to focus solely on the C++ driver.

```
sv241-indi/
├── docs/                   # Protocol documentation
│   └── SV241_PROTOCOL.md
├── driver/                 # INDI driver source code (C++)
│   ├── build/              # Build directory
│   ├── indi_sv241.cpp      # Driver implementation
│   ├── indi_sv241.h
│   └── indi_sv241.xml      # INDI driver definition
│
├── test_driver.sh          # Test script for the driver
└── README.md               # This file
```

## Technical Deep Dive: The Serial Port Reset Issue

A major hurdle in this project was a hardware-specific issue where the SV241 device would reset upon closing the serial port on POSIX-compliant systems (Linux and macOS). This behavior prevented reliable operation, as any client disconnection would reboot the powerbox, turning off all equipment.

### The Root Cause: `HUPCL` and ESP32 Reset Circuit

- **Device Behavior**: The SV241 is based on an ESP32 microcontroller, which uses a common USB-to-Serial chip (CH340). On these development boards, the DTR (Data Terminal Ready) and RTS (Request To Send) serial lines are often cross-wired to the ESP32's `EN` (Enable) and `GPIO0` pins. This design allows for automatic flashing by using the serial lines to put the chip into bootloader mode.

- **Operating System Behavior**: On Linux and macOS, the default serial port configuration includes the `HUPCL` (Hang-Up on Close) flag. When the last process with an open file handle to the serial port closes it, the OS kernel sends a "hang-up" signal by de-asserting (lowering) the DTR line.

- **The Conflict**: The toggling of the DTR line by the OS on port close was triggering the ESP32's reset-to-bootloader mechanism, causing the entire powerbox to reboot. This is why the device worked on Windows (which does not enforce `HUPCL` in the same way) but failed on POSIX systems.

### The Solution: Manual `termios` Configuration

Standard serial libraries, including the INDI `Connection::Serial` class, do not expose the low-level controls needed to disable the `HUPCL` flag. To solve this, we had to bypass these abstractions and directly configure the serial port using `termios` system calls.

The final C++ driver implements the following logic in its `openSerialPort` method:

1.  **Open the Port**: The serial device file is opened using a standard `open()` system call to get a raw file descriptor.
2.  **Get Attributes**: The existing terminal attributes are fetched using `tcgetattr()`.
3.  **Disable `HUPCL`**: The `c_cflag` member of the `termios` struct is modified to remove the `HUPCL` flag. This is the critical step.
    ```cpp
    options.c_cflag &= ~HUPCL;
    ```
4.  **Set Other Flags**: Baud rate, character size (8N1), and raw input mode are configured.
5.  **Set Attributes**: The modified attributes are applied back to the port using `tcsetattr()`.

This low-level control prevents the kernel from dropping the DTR line on close, which completely resolves the reset issue and makes the driver stable for INDI use.

## Development

### Requirements
- **OS**: Linux or macOS
- **C++ Compiler**: g++ or clang with C++11 support
- **CMake**: 3.10 or later
- **INDI Library**: 1.9.0 or later

### Install INDI Library

**Ubuntu/Debian:**
```bash
sudo apt-get install libindi-dev
```

**macOS (Homebrew):**
```bash
brew install indi
```

### Build the Driver

```bash
cd driver/build
cmake ..
make
```
The compiled driver will be located at `driver/build/indi_sv241`.

## Testing the Driver

A test script `test_driver.sh` is provided to perform repeated connect/disconnect cycles and verify the driver's stability.

```bash
# Make sure the script is executable
chmod +x test_driver.sh

# Run the test
./test_driver.sh driver/build/indi_sv241 "C++ Driver"
```

This will:
1. Start the INDI server with the C++ driver.
2. Connect to the device and read all sensor/switch states.
3. Disconnect from the device.
4. Repeat this cycle 3 times to ensure stability.
