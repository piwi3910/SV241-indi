# SVBONY SV241 INDI Driver

INDI driver for the SVBONY SV241 Powerbox, enabling control from Linux and macOS-based astronomy software.

## Status

- **Protocol Research**: ✅ COMPLETE
- **Driver Development**: ✅ COMPLETE
- **Hardware Testing**: ✅ VERIFIED (macOS)
- **Release**: PENDING

## Quick Links

- **[Complete Protocol Documentation](docs/SV241_PROTOCOL.md)** - Full command reference.
- **[Project Summary](docs/PROJECT_SUMMARY.md)** - Development history and technical details.

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
├── docs/                   # Protocol and project documentation
├── driver/                 # INDI driver source code (C++)
│   ├── build/              # Build directory
│   ├── indi_sv241.cpp      # Driver implementation
│   ├── indi_sv241.h
│   └── indi_sv241.xml      # INDI driver definition
│
├── test_driver.sh          # Test script for the driver
└── README.md               # This file
```

## Serial Port Behavior and Workaround

A significant challenge during development was that the SV241 device, which is based on an ESP32, would reset every time the serial port was closed on macOS and Linux. This is not standard behavior for serial devices and is not handled by default INDI connection libraries.

- **The Cause**: On POSIX-compliant systems (like Linux and macOS), the default behavior is to set the `HUPCL` (Hang-Up on Close) flag for serial devices. When the last process closes the port, the kernel sends a "hang-up" signal by lowering the DTR (Data Terminal Ready) line. The ESP32's USB-to-serial chip is wired to use the DTR line to trigger a reset, putting the chip into bootloader mode.

- **The Solution**: We worked around this by bypassing higher-level serial libraries and using low-level `termios` system calls to manually configure the port. Specifically, we disable the `HUPCL` flag right after the port is opened.

This is the key code snippet from `driver/indi_sv241.cpp`:
```cpp
// In openSerialPort()
#include <termios.h>

// ... open file descriptor ...

struct termios options;
tcgetattr(PortFD, &options);

// ... set baud, etc ...

// IMPORTANT: Disable HUPCL to prevent DTR drop on close
options.c_cflag &= ~HUPCL;

tcsetattr(PortFD, TCSANOW, &options);
```
This fix ensures that closing the serial port does not cause the device to reset, allowing for stable, repeated connections.

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

## Roadmap

- [x] **Phase 1: Protocol Research**: Reverse engineer and document protocol.
- [x] **Phase 2: Driver Development**: Implement a stable C++ driver.
- [ ] **Phase 3: Testing**: Perform wider testing on different platforms (Linux, Raspberry Pi) and with different clients (KStars, Ekos).
- [ ] **Phase 4: Release**: Submit to the INDI 3rd party drivers repository and create installation packages.
