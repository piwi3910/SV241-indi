# SVBONY SV241 INDI Driver Project - Complete Summary

## Project Goal
Create an INDI driver for the SVBONY SV241 powerbox to enable control from Linux-based astronomy software (KStars, Ekos, NINA, etc.).

## What We've Accomplished

### ✅ 1. Protocol Reverse Engineering
**Status**: COMPLETE

We successfully reverse-engineered the SV241 serial protocol by:
- Decompiling the Windows desktop application (.NET 6 app)
- Extracting all command structures and response formats
- Testing and verifying the protocol works

**Key Files**:
- [SV241_PROTOCOL.md](SV241_PROTOCOL.md) - Complete protocol documentation
- [test_sv241_protocol.py](test_sv241_protocol.py) - Working Python test implementation
- [decompiled/SerialControlApp/MainForm.cs](decompiled/SerialControlApp/MainForm.cs) - Original decompiled source

### ✅ 2. Protocol Verification
**Status**: TESTED AND WORKING

Verified communication with real hardware:
- Baudrate: 115200 confirmed
- DC outputs: Working
- PWM control: Working
- Sensor readings: Working (voltage, temperature, humidity, power)
- State synchronization: Working

Test results show:
```
Voltage: 12.97 V ✓
Power: 0.92 W ✓
DC outputs toggle: ✓
PWM control: ✓
State sync: ✓
```

## Hardware Specifications

### Device: SVBONY SV241 Powerbox
- **Connection**: USB (CH340 serial adapter)
- **Baudrate**: 115200
- **Protocol**: Binary, 6-byte commands
- **Channels**:
  - 5x DC outputs (12V switchable)
  - 2x USB groups (switchable)
  - 3x PWM outputs (2 dew heaters + 1 adjustable voltage)
- **Sensors**:
  - Input voltage
  - Power consumption
  - Ambient temperature
  - Humidity
  - Lens temperature

## Protocol Summary

### Command Structure
All commands are 6 bytes:
```
[0x24] [0x06] [CMD_ID] [PARAM1] [PARAM2] [CHECKSUM]
```

### Key Commands
| Command | ID | Function |
|---------|-----|----------|
| Write DC/PWM | 0x01 | Control outputs |
| Sync States | 0x08 | Read all states |
| Read Voltage | 0x03 | Get voltage |
| Read Temp | 0x04/0x05 | Temperature |
| Read Humidity | 0x06 | Humidity |
| Read Power | 0x07 | Power consumption |

### Checksum Algorithm
```
sum = byte[0] + byte[1] + byte[2] + byte[3] + byte[4]
checksum = (sum > 255) ? (sum % 255) : sum
```

## Development Tools Created

### Analysis Tools
1. **serial_proxy.py** - Serial port sniffer/proxy
2. **analyze_protocol.py** - Protocol analyzer
3. **find_device.py** - Device discovery
4. **test_baudrates.py** - Baudrate tester
5. **extract_strings.py** - DLL string extraction

### Testing Tools
1. **test_sv241_protocol.py** - Complete protocol test suite (WORKING)

### Documentation
1. **SV241_PROTOCOL.md** - Complete protocol specification
2. **REVERSE_ENGINEERING_GUIDE.md** - How we reverse-engineered it
3. **README.md** - Project overview

## Repository Structure

```
sv241-indi/
├── docs/
│   ├── SV241_PROTOCOL.md           # Protocol documentation
│   ├── REVERSE_ENGINEERING_GUIDE.md
│   └── PROJECT_SUMMARY.md          # This file
│
├── tools/
│   ├── serial_proxy.py             # Serial sniffer
│   ├── test_sv241_protocol.py      # Protocol test (working!)
│   ├── analyze_protocol.py
│   ├── find_device.py
│   └── test_baudrates.py
│
├── reference/
│   ├── decompiled/                 # Decompiled C# source
│   ├── interesting_strings.txt
│   └── all_strings.txt
│
├── driver/                         # INDI driver (to be created)
│   ├── CMakeLists.txt
│   ├── indi_sv241.cpp
│   ├── indi_sv241.h
│   └── README.md
│
├── .gitignore
└── README.md
```

## Next Steps

### Phase 1: Mac Development Setup
- [ ] Install INDI library on Mac
- [ ] Install C++ development tools (Xcode/CMake)
- [ ] Clone repository on Mac

### Phase 2: INDI Driver Development
- [ ] Create C++ driver skeleton using INDI::DefaultDevice
- [ ] Implement serial communication
- [ ] Implement power control interface
- [ ] Implement weather station interface (sensors)
- [ ] Add property definitions for all outputs
- [ ] Implement state synchronization

### Phase 3: Testing
- [ ] Test with INDI server
- [ ] Test with KStars/Ekos
- [ ] Test all features (DC, PWM, sensors)
- [ ] Debug and refine

### Phase 4: Distribution
- [ ] Create driver XML file
- [ ] Write user documentation
- [ ] Submit to INDI 3rd party drivers
- [ ] Publish on GitHub

## Technical Requirements for Development

### On Mac/Linux:
```bash
# Install INDI library
sudo apt-get install libindi-dev  # Ubuntu/Debian
brew install indi                  # macOS (if available)

# Or build from source
git clone https://github.com/indilib/indi.git
cd indi
mkdir build && cd build
cmake ..
make
sudo make install

# Development tools
sudo apt-get install build-essential cmake git
```

### For Driver:
- C++11 or later
- INDI library (>=1.9.0)
- CMake (>=3.10)

## Key Protocol Details for Implementation

### Checksum Function (C++)
```cpp
uint8_t calcChecksum(const uint8_t* cmd) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += cmd[i];
    }
    if (sum > 255) {
        sum %= 255;
    }
    return (uint8_t)sum;
}
```

### Send Command Template
```cpp
void sendCommand(uint8_t cmdId, uint8_t param1, uint8_t param2) {
    uint8_t cmd[6] = {0x24, 0x06, cmdId, param1, param2, 0x00};
    cmd[5] = calcChecksum(cmd);
    write(fd, cmd, 6);
    usleep(50000);  // Wait 50ms
}
```

### Read Response Template
```cpp
bool readResponse(uint8_t* buffer, size_t len) {
    tcflush(fd, TCIFLUSH);  // Clear input buffer
    size_t bytesRead = read(fd, buffer, len);
    return (bytesRead == len && buffer[2] == expectedId);
}
```

## Testing Checklist

When testing the driver:
- [ ] Connection/disconnection
- [ ] DC1-DC5 toggle
- [ ] USB group control
- [ ] PWM13 adjustable voltage (0-15.3V)
- [ ] PWM14/15 dew heater control
- [ ] Voltage sensor reading
- [ ] Temperature sensor reading
- [ ] Humidity sensor reading
- [ ] Power sensor reading
- [ ] State synchronization on connect
- [ ] Periodic sensor updates
- [ ] Error handling (disconnect/reconnect)

## Known Issues / Notes

1. **Temperature/Humidity sensors**: May show invalid readings if sensors not connected or need calibration
2. **Power calculation**: Requires voltage reading first
3. **Timing**: Always wait 50ms after sending command before reading response
4. **Byte order**: Sensor data is big-endian, must reverse bytes
5. **Windows COM ports**: Use /dev/ttyUSBx on Linux instead of COMx

## Reference Materials

### Similar INDI Drivers to Study:
- `indi-pegasus-powerbox` - Similar power control device
- `indi-aagcloudwatcher` - Weather station example
- `indi-gpsd` - GPS device with sensors

### INDI Documentation:
- https://github.com/indilib/indi
- https://www.indilib.org/develop/developer-manual.html
- https://www.indilib.org/develop/tutorials.html

## Contact & Support

For issues or questions about the protocol:
- Protocol documentation: SV241_PROTOCOL.md
- Test the protocol: python test_sv241_protocol.py /dev/ttyUSB0
- Original decompiled source: decompiled/SerialControlApp/MainForm.cs

## Success Criteria

The driver will be considered complete when:
1. ✅ It connects to the SV241 via serial port
2. ✅ All DC outputs can be controlled
3. ✅ All PWM outputs can be controlled
4. ✅ All sensors can be read
5. ✅ It integrates with KStars/Ekos
6. ✅ State persists across disconnections
7. ✅ Error handling is robust
8. ✅ Code follows INDI driver standards

---

**Ready for Mac development!** 🚀

All protocol research is complete. The next phase is implementing the C++ INDI driver.
