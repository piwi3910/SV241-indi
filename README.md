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

## Development and Installation

### Requirements
- **OS**: Linux or macOS
- **C++ Compiler**: g++ or clang with C++11 support
- **CMake**: 3.10 or later
- **INDI Library**: 1.9.0 or later

### 1. Install Dependencies

**Ubuntu/Debian:**
```bash
sudo apt-get install build-essential cmake git libindi-dev
```

**macOS (Homebrew):**
```bash
brew install cmake indi
```

### 2. Build the Driver

```bash
cd driver/build
cmake ..
make
```
The compiled driver will be located at `driver/build/indi_sv241`.

### 3. Install the Driver

```bash
cd driver/build
sudo make install
```

This installs:
- The `indi_sv241` binary to `/usr/local/bin/`
- The `indi_sv241.xml` driver definition file to the INDI system directory.

## Usage

### Starting with INDI Server

You can start the driver manually with `indiserver`:
```bash
indiserver -v indi_sv241
```

### Using with KStars/Ekos

1.  Open KStars and go to the Ekos profile editor.
2.  Create a new profile or edit an existing one.
3.  Under the "Auxiliary" category, select **SVBONY SV241** from the dropdown menu.
4.  Start the profile.
5.  In the INDI Control Panel, go to the **Connection** tab for the SV241 driver.
6.  Set the correct serial port (e.g., `/dev/tty.usbserial-12340` on macOS or `/dev/ttyUSB0` on Linux).
7.  Click **Connect**.

## Driver Properties

### Main Control Tab

| Property | Type | Description |
|----------|------|-------------|
| DC1-DC5 | Switch | Toggle 12V DC outputs |
| USB12 | Switch | Toggle USB ports 1-2 |
| USB345 | Switch | Toggle USB ports 3-4-5 |
| PWM13 | Number | Adjustable voltage (0-253 = 0-15.3V) |
| PWM14 | Number | Dew heater 1 duty cycle (0-253) |
| PWM15 | Number | Dew heater 2 duty cycle (0-253) |
| PWM13 Voltage | Number | Calculated output voltage (read-only) |

### Sensors Tab

| Property | Type | Description |
|----------|------|-------------|
| Voltage | Number | Input voltage (V) |
| Power | Number | Power consumption (W) |
| Ambient Temp | Number | Ambient temperature (°C) |
| Lens Temp | Number | Lens temperature (°C) |
| Humidity | Number | Relative humidity (%) |

## Troubleshooting

### Driver not found in KStars/Ekos

This usually means the XML file was not installed in a location where the INDI server looks for it.
1.  Check where INDI looks for XML files: `pkg-config --variable=datadir libindi`
2.  Ensure `indi_sv241.xml` is in that directory's `indi` subfolder (e.g., `/usr/local/share/indi`).
3.  If not, run `sudo make install` from the `driver/build` directory again.

### Permission denied on serial port (Linux)

You may need to add your user to the `dialout` group to access serial devices.
```bash
sudo usermod -a -G dialout $USER
```
You will need to **log out and log back in** for this change to take effect.

## Technical Deep Dive: The Serial Port Reset Issue

A major hurdle in this project was a hardware-specific issue where the SV241 device would reset upon closing the serial port on POSIX-compliant systems (Linux and macOS).

- **The Cause**: On these systems, the default serial port configuration includes the `HUPCL` (Hang-Up on Close) flag. When the port is closed, the OS kernel drops the DTR (Data Terminal Ready) line, which the SV241's ESP32 microcontroller interprets as a reset signal.

- **The Solution**: We bypassed higher-level serial libraries and used low-level `termios` system calls to manually configure the port, specifically disabling the `HUPCL` flag. This prevents the OS from toggling the DTR line and makes the driver connection stable. For more details, see the well-commented `openSerialPort` function in `driver/indi_sv241.cpp`.
