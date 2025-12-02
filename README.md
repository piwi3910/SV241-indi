# SVBONY SV241 INDI Driver

INDI driver for the SVBONY SV241 Powerbox, enabling control from Linux-based astronomy software.

## Status

🎯 **Protocol Research**: ✅ COMPLETE
🔬 **Hardware Testing**: ✅ VERIFIED
🚧 **Driver Development**: IN PROGRESS
📦 **Release**: PENDING

## Quick Links

- **[Complete Protocol Documentation](docs/SV241_PROTOCOL.md)** - Full command reference
- **[Project Summary](docs/PROJECT_SUMMARY.md)** - Development roadmap
- **[Reverse Engineering Guide](docs/REVERSE_ENGINEERING_GUIDE.md)** - How we did it

## What is the SV241?

The SVBONY SV241 is an astronomy power distribution box with:
- **5x DC outputs** (12V switchable)
- **2x USB groups** (switchable power)
- **3x PWM outputs** (2 dew heaters + 1 adjustable voltage 0-15.3V)
- **Sensors**: Voltage, Current, Temperature, Humidity, Lens Temperature

## Features

### Current (Tested & Working)
- ✅ Serial communication (115200 baud)
- ✅ DC output control
- ✅ PWM/Dew heater control
- ✅ Sensor readings (V, A, T, H)
- ✅ State synchronization

### Planned (INDI Driver)
- 🔲 INDI server integration
- 🔲 KStars/Ekos compatibility
- 🔲 Weather station interface
- 🔲 Persistent settings
- 🔲 Auto-reconnect

## Repository Structure

```
sv241-indi/
├── docs/                   # Complete documentation
│   ├── SV241_PROTOCOL.md
│   ├── PROJECT_SUMMARY.md
│   └── REVERSE_ENGINEERING_GUIDE.md
│
├── tools/                  # Testing & analysis tools
│   ├── test_sv241_protocol.py    # Protocol test suite ✅
│   ├── serial_proxy.py
│   └── ...
│
├── reference/              # Reverse engineering artifacts
│   ├── decompiled/         # Original C# source
│   └── *.txt
│
├── driver/                 # INDI driver (C++)
│   └── (coming soon on Mac)
│
└── README.md              # This file
```

## Quick Start (Testing)

### Test the Protocol (Python)

```bash
# Connect your SV241 to USB
python tools/test_sv241_protocol.py /dev/ttyUSB0

# On macOS
python tools/test_sv241_protocol.py /dev/tty.usbserial-*

# On Windows (for testing only, INDI needs Linux)
python tools/test_sv241_protocol.py COM3
```

This will:
1. Connect to the device
2. Read all sensor values
3. Toggle DC1 on/off
4. Set PWM to 50%

## Development

### Requirements
- **OS**: Linux or macOS (INDI is not available on Windows)
- **C++ Compiler**: g++ or clang with C++11 support
- **CMake**: 3.10 or later
- **INDI Library**: 1.9.0 or later

### Install INDI Library

**Ubuntu/Debian:**
```bash
sudo apt-get install libindi-dev
```

**macOS:**
```bash
# Build from source (recommended)
git clone https://github.com/indilib/indi.git
cd indi
mkdir build && cd build
cmake ..
make
sudo make install
```

### Build the Driver

```bash
cd driver
mkdir build && cd build
cmake ..
make
sudo make install
```

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
- `0x01` - Write DC/PWM state
- `0x03-0x07` - Read sensors
- `0x08` - Sync all states

See [complete protocol documentation](docs/SV241_PROTOCOL.md) for details.

## Testing Results

Successfully tested on real hardware:

```
=== Device Communication ===
✓ Connection established (115200 baud)
✓ Voltage reading: 12.97V
✓ Power reading: 0.92W
✓ DC outputs: WORKING
✓ PWM control: WORKING
✓ State sync: WORKING
```

## Hardware Setup

1. Connect SV241 to computer via USB
2. Device appears as `/dev/ttyUSB0` (Linux) or `/dev/tty.usbserial-*` (macOS)
3. No drivers needed on Linux (uses CH340 chip)

On Windows (for initial testing only):
- Device appears as `COMx`
- CH340 drivers may be needed

## Contributing

Contributions welcome! Areas of focus:
- Driver development (C++)
- Testing on different platforms
- Documentation improvements
- Bug reports

## Roadmap

### Phase 1: Protocol Research ✅
- [x] Reverse engineer protocol
- [x] Test with hardware
- [x] Document commands

### Phase 2: Driver Development 🚧
- [ ] Create C++ driver skeleton
- [ ] Implement serial communication
- [ ] Add INDI property definitions
- [ ] Implement all features

### Phase 3: Testing 📋
- [ ] Test with INDI server
- [ ] Test with KStars/Ekos
- [ ] Test on Raspberry Pi
- [ ] Stress testing

### Phase 4: Release 📦
- [ ] Submit to INDI 3rd party drivers
- [ ] Create installation packages
- [ ] Write user manual
- [ ] Community feedback

## Similar Projects

- **Pegasus Astro Powerbox** - Commercial alternative with INDI support
- **DIY Flatbox** - Community DIY projects
- **SV241-Unbound** - Custom firmware (not required for this driver)

## License

TBD - Will be compatible with INDI library license (LGPL)

## Authors

- Protocol reverse engineering & documentation
- Driver development (in progress)

## Acknowledgments

- INDI Library Team - For the excellent INDI framework
- SVBONY - For creating affordable astronomy equipment
- DIYAstro/SV241-Unbound - Reference for understanding the device

## Support

For issues or questions:
1. Check the [protocol documentation](docs/SV241_PROTOCOL.md)
2. Run the test script: `python tools/test_sv241_protocol.py`
3. Open an issue on GitHub

---

**Current Status**: Protocol fully documented and tested. Driver development starting on macOS. 🚀
