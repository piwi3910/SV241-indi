# SVBONY SV241 INDI Driver Project - Summary

## Project Goal
Create a robust, stable INDI driver for the SVBONY SV241 powerbox to enable control from Linux and macOS-based astronomy software (e.g., KStars, Ekos).

## Key Accomplishments

### ✅ 1. Protocol Reverse Engineering
**Status**: COMPLETE

We successfully reverse-engineered the SV241 serial protocol by decompiling the official Windows application. This allowed us to understand all commands for controlling outputs and reading sensors.

- **[SV241_PROTOCOL.md](SV241_PROTOCOL.md)**: Complete protocol documentation.
- **[REVERSE_ENGINEERING_GUIDE.md](REVERSE_ENGINEERING_GUIDE.md)**: A guide to the process we followed.

### ✅ 2. Driver Development & Testing
**Status**: COMPLETE

A C++ INDI driver was developed that implements all known functions of the powerbox. The driver has been successfully tested on macOS, demonstrating stable operation across multiple connect/disconnect cycles.

---

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

## Final Repository Structure

```
sv241-indi/
├── docs/
│   ├── SV241_PROTOCOL.md
│   ├── REVERSE_ENGINEERING_GUIDE.md
│   └── PROJECT_SUMMARY.md          # This file
│
├── driver/
│   ├── build/
│   ├── indi_sv241.cpp              # Driver implementation
│   ├── indi_sv241.h
│   └── indi_sv241.xml
│
├── test_driver.sh
└── README.md
```

## Next Steps

With a stable C++ driver, the next phases focus on testing and distribution:

- **Phase 1: Wider Testing**:
    - Test on a dedicated Linux machine (e.g., Ubuntu).
    - Test on a Raspberry Pi-based astronomy setup (e.g., Stellarmate, Astroberry).
    - Test with different INDI clients (KStars/Ekos, N.I.N.A., etc.).

- **Phase 2: Distribution**:
    - Write a user manual for installation and use.
    - Submit the driver to the official INDI 3rd-party repository.
    - Create installation packages if feasible.
