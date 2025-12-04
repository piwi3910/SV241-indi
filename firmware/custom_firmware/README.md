# SV241 Custom Firmware

Drop-in replacement firmware for the SVBONY SV241 Power Box that fixes the I2C bus lockup issue.

## Features

- **I2C Bus Recovery**: Automatically detects and recovers from I2C bus lockups
- **Sensor Retry Logic**: Retries failed sensor reads before triggering recovery
- **Watchdog Timer**: 30-second watchdog prevents complete system hangs
- **100% Protocol Compatible**: Works with existing Windows app and INDI drivers
- **Debug Output**: Serial monitor shows diagnostic information

## The Problem This Solves

The original SV241 firmware has a bug where the I2C bus can become locked (typically due to electrical noise from dew heaters or motors). When this happens:
- All sensor readings return zero
- The device becomes unresponsive
- Only unplugging/replugging fixes it

This firmware implements proper I2C bus recovery:
1. Detects consecutive sensor read failures
2. Releases the I2C driver
3. Toggles SCL line 9 times to clear stuck slaves
4. Generates a proper STOP condition
5. Reinitializes the I2C bus and sensors

## Hardware Requirements

- SVBONY SV241 Power Box
- USB cable for connection/flashing
- Computer with Arduino IDE or esptool

## Flashing Instructions

### Option 1: Arduino IDE

1. **Install Arduino IDE** (2.0+ recommended)

2. **Install ESP32 Board Support**:
   - Go to File → Preferences
   - Add to "Additional Board Manager URLs":
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Go to Tools → Board → Boards Manager
   - Search "esp32" and install "ESP32 by Espressif Systems"

3. **Select Board**:
   - Tools → Board → ESP32 Arduino → "ESP32 Dev Module"

4. **Configure Settings**:
   - Flash Mode: DIO
   - Flash Size: 4MB (32Mb)
   - Partition Scheme: Default 4MB with spiffs
   - Upload Speed: 460800

5. **Connect SV241**:
   - Plug in via USB
   - Select the correct COM port (Tools → Port)
   - On macOS: `/dev/cu.usbserial-*` or `/dev/cu.wchusbserial*`
   - On Linux: `/dev/ttyUSB0`
   - On Windows: `COM3` (or similar)

6. **Flash**:
   - Click Upload button
   - If upload fails, hold the BOOT button on the ESP32 while uploading

### Option 2: esptool (Command Line)

1. **Install esptool**:
   ```bash
   pip install esptool
   # or on macOS
   brew install esptool
   ```

2. **Compile the firmware** (using Arduino IDE):
   - Sketch → Export Compiled Binary
   - Find the `.bin` file in the sketch folder

3. **Flash using esptool**:
   ```bash
   esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 460800 \
     write_flash 0x10000 SV241_Custom.ino.bin
   ```

### Option 3: Restore Original Firmware

If you want to go back to the original firmware:
```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 460800 \
  write_flash \
  0x1000 ../main.ino.bootloader.bin \
  0x8000 ../main.ino.partitions.bin \
  0x10000 ../main.ino.bin
```

## Pin Mapping

| Function | GPIO Pin |
|----------|----------|
| DC1 | 13 |
| DC2 | 12 |
| DC3 | 14 |
| DC4 | 27 |
| DC5 | 26 |
| USB12 | 19 |
| USB345 | 18 |
| PWM13 (Var Voltage) | 25 |
| PWM14 (Dew Heater 1) | 33 |
| PWM15 (Dew Heater 2) | 32 |
| I2C SDA | 21 |
| I2C SCL | 22 |

## Serial Protocol

The firmware uses the exact same protocol as the original:

### Command Format (6 bytes)
```
[0x24] [0x06] [CMD_ID] [PARAM1] [PARAM2] [CHECKSUM]
```

### Commands
| Command | ID | Description |
|---------|-----|-------------|
| Write Output | 0x01 | Control DC/PWM outputs |
| Read Voltage | 0x03 | Get input voltage |
| Read Lens Temp | 0x04 | Get lens temperature |
| Read Ambient Temp | 0x05 | Get ambient temperature |
| Read Humidity | 0x06 | Get humidity |
| Read Power | 0x07 | Get power consumption |
| Sync States | 0x08 | Get all output states |

## Debugging

Open Serial Monitor at 115200 baud to see diagnostic output:

```
=================================
SV241 Custom Firmware v1.0
With I2C Bus Recovery
=================================

Configuring GPIO pins...
  DC outputs configured (GPIO 12,13,14,18,19,26,27)
Configuring PWM channels...
  PWM channels configured (GPIO 25,32,33)
Configuring I2C bus...
  Probing INA219 (0x40): FOUND
  INA219 initialized
  Probing SHT4x (0x44): FOUND
Configuring watchdog timer...
  Watchdog timeout: 30 seconds
Initialization complete!
Ready for commands...
```

When I2C recovery occurs:
```
WARNING: Multiple I2C failures, attempting recovery...
Performing I2C bus recovery...
  SDA released after 3 clocks
  After recovery - INA219: OK, SHT4x: OK
I2C bus recovery successful!
```

## Troubleshooting

### Upload fails
- Hold the BOOT button on the ESP32 while clicking Upload
- Try a lower baud rate (115200)
- Check USB cable (some are charge-only)

### Device not detected
- Check Device Manager (Windows) or `ls /dev/tty*` (Linux/Mac)
- Install CH340 driver if needed

### Sensors still showing zero
- Check I2C connections
- Verify sensors are powered
- Look at Serial Monitor for error messages

### Recovery not working
- Hardware issue may require physical repair
- I2C pull-up resistors may be damaged

## License

This firmware is provided for personal use with SVBONY SV241 hardware.

## Changelog

### v1.0
- Initial release
- I2C bus recovery implementation
- Watchdog timer
- Full protocol compatibility
