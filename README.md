# SVBONY SV241 INDI Driver

INDI driver for the SVBONY SV241 Powerbox, enabling control from Linux-based astronomy software like KStars/Ekos.

## Status

| Component | Status |
|-----------|--------|
| Protocol Research | ✅ Complete |
| Hardware Testing | ✅ Verified |
| INDI Driver | ✅ Complete |
| Custom Firmware | ✅ Available |

## What is the SV241?

The SVBONY SV241 is an astronomy power distribution box featuring:

- **5x DC outputs** (12V switchable) - For cameras, mount, focuser, etc.
- **2x USB groups** (switchable power) - USB 1-2 and USB 3-4-5
- **3x PWM outputs**:
  - PWM13: Adjustable voltage 0-15.3V
  - PWM14: Dew heater 1 (0-100%)
  - PWM15: Dew heater 2 (0-100%)
- **Sensors**: Input voltage, power consumption, ambient temperature, humidity

## Important: Firmware Considerations

### Using with Original SVBONY Firmware

The INDI driver works with the **original factory firmware**, but there are known bugs:

⚠️ **Known Issues with Original Firmware:**

1. **I2C Bus Lockup** - Sensors randomly stop responding (return zeros)
   - Caused by electrical noise from dew heaters, mount motors, etc.
   - **Workaround:** Unplug and replug the USB cable
   - Can happen at any time during an imaging session

2. **No Recovery Mechanism** - Once sensors lock up, they stay locked
   - Device outputs (DC/PWM) continue to work
   - Only sensor readings fail

3. **Serial Reconnection Issues** - First read after reconnecting may fail

### Recommended: Custom Firmware

We've created a **custom firmware** that fixes these issues:

✅ **Automatic I2C bus recovery** - Detects and fixes sensor lockups
✅ **On-demand recovery** - Each sensor read includes retry logic
✅ **Startup bus reset** - Clears issues from previous sessions
✅ **100% protocol compatible** - Works with INDI driver and Windows app

**See [`firmware/README.md`](firmware/README.md) for:**
- Detailed explanation of bugs found
- What the custom firmware fixes
- Pre-built binary for easy flashing
- Build instructions if you want to compile yourself

### Quick Flash (Pre-Built Binary)

```bash
pip install esptool

esptool --chip esp32 --port /dev/ttyUSB0 --baud 115200 --no-stub \
  write-flash 0x0 firmware/SV241_Custom/SV241_Custom.merged.bin
```

## Features

### INDI Driver Features

- **DC Output Control** - Toggle DC1-DC5, USB12, USB345
- **PWM/Dew Heater Control** - Set PWM values 0-253
- **Adjustable Voltage Display** - Shows PWM13 output voltage (0-15.3V)
- **Sensor Readings** - Voltage, power, temperature, humidity
- **State Synchronization** - Reads current device state on connect
- **Configuration Saving** - Persists port and PWM settings

### Tested & Working

- ✅ Serial communication (115200 baud)
- ✅ All DC output control
- ✅ All PWM/dew heater control
- ✅ All sensor readings
- ✅ State synchronization
- ✅ INDI property definitions

## Repository Structure

```
sv241-indi/
├── driver/                    # INDI driver (C++)
│   ├── indi_sv241.cpp         # Driver implementation
│   ├── indi_sv241.h           # Driver header
│   ├── indi_sv241.xml         # INDI device descriptor
│   └── CMakeLists.txt         # Build configuration
│
├── firmware/                  # Custom firmware
│   ├── README.md              # Firmware documentation & bugs
│   └── SV241_Custom/          # Arduino sketch + pre-built binary
│       ├── SV241_Custom.ino   # Firmware source
│       └── SV241_Custom.merged.bin  # Pre-built (flash at 0x0)
│
├── scripts/                   # Testing & utility scripts
│   ├── test_custom_firmware.py    # Firmware validation
│   ├── stress_test_sensors.py     # Long-duration stability test
│   ├── reconnect_stress_test.py   # Connection cycling test
│   └── continuous_test.py         # Continuous polling test
│
├── docs/                      # Documentation
│   ├── SV241_PROTOCOL.md      # Complete protocol reference
│   └── ...
│
└── README.md                  # This file
```

## Installation

### Prerequisites

- **OS**: Linux or macOS
- **INDI Library**: 1.9.0 or later
- **CMake**: 3.10 or later
- **C++ Compiler**: g++ or clang with C++11 support

### Install INDI Library

**Ubuntu/Debian:**
```bash
sudo apt-get install libindi-dev
```

**macOS (Homebrew):**
```bash
brew install indi
```

**From Source:**
```bash
git clone https://github.com/indilib/indi.git
cd indi && mkdir build && cd build
cmake .. && make && sudo make install
```

### Build the Driver

```bash
cd driver
mkdir build && cd build
cmake ..
make
sudo make install
```

### Run the Driver

```bash
# Start INDI server with SV241 driver
indiserver indi_sv241

# Or add to your existing INDI server configuration
```

## Usage

### With KStars/Ekos

1. Open KStars → Ekos
2. Add a new device: "SV241 Powerbox"
3. Configure the serial port (e.g., `/dev/ttyUSB0`)
4. Connect

### With INDI Control Panel

```bash
# Start server
indiserver indi_sv241

# In another terminal, use indi_getprop/indi_setprop
indi_getprop "SV241 Powerbox.*"
indi_setprop "SV241 Powerbox.DC1.DC1_ON=On"
```

## Hardware Setup

1. Connect SV241 to computer via USB
2. Device appears as:
   - Linux: `/dev/ttyUSB0`
   - macOS: `/dev/cu.usbserial-*`
3. No drivers needed (uses CH340/CP2102 chip)

## Protocol Summary

### Connection
- **Baudrate**: 115200
- **Data**: 8N1
- **Flow Control**: None

### Command Structure
```
[0x24] [0x06] [CMD_ID] [PARAM1] [PARAM2] [CHECKSUM]
```

### Key Commands
| ID | Command |
|----|---------|
| 0x01 | Write DC/PWM state |
| 0x03 | Read input voltage |
| 0x04 | Read lens temperature |
| 0x05 | Read ambient temperature |
| 0x06 | Read humidity |
| 0x07 | Read power consumption |
| 0x08 | Sync all output states |

See [docs/SV241_PROTOCOL.md](docs/SV241_PROTOCOL.md) for complete protocol documentation.

## Troubleshooting

### Sensor readings are zero

**With original firmware:** This is the I2C lockup bug. Unplug and replug USB cable.

**Permanent fix:** Flash the [custom firmware](firmware/README.md).

### Connection fails

1. Check device is connected: `ls /dev/ttyUSB* /dev/cu.usbserial*`
2. Check permissions: `sudo chmod 666 /dev/ttyUSB0`
3. Add user to dialout group: `sudo usermod -a -G dialout $USER`

### Driver doesn't appear in INDI

1. Verify installation: `which indi_sv241`
2. Check XML file: `ls /usr/share/indi/indi_sv241.xml`
3. Restart INDI server

## Testing Scripts

Several Python scripts are included for testing:

```bash
# Test all firmware commands
python scripts/test_custom_firmware.py /dev/ttyUSB0

# Long-duration stability test (10 minutes)
python scripts/stress_test_sensors.py /dev/ttyUSB0 10

# Connection cycling stress test
python scripts/reconnect_stress_test.py /dev/ttyUSB0
```

## Contributing

Contributions welcome! Areas of interest:

- Testing on different Linux distributions
- Raspberry Pi compatibility testing
- Integration with other INDI clients
- Documentation improvements

## License

LGPL-2.1 - Compatible with INDI library license.

## Acknowledgments

- **INDI Library Team** - For the excellent INDI framework
- **SVBONY** - For creating affordable astronomy equipment
- **Astronomy community** - For feedback and testing

## Support

1. Check the [firmware README](firmware/README.md) for known issues
2. Run the test scripts to diagnose problems
3. Open an issue on GitHub with:
   - Your OS and version
   - Firmware version (original or custom)
   - Error messages or logs
   - Steps to reproduce
