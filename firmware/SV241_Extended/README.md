# SV241 Extended Firmware v2.0

Advanced firmware for the SVBONY SV241 Power Box with auto dew control, session statistics, voltage alerts, sensor calibration, and custom port naming.

## Overview

The extended firmware builds on the basic firmware (v1.x) with a hybrid protocol design:

- **Binary Protocol (0x01-0x08)**: Original commands for backward compatibility with Windows ASCOM driver
- **Extended JSON Protocol (0x10)**: New JSON-based commands for advanced INDI driver features

This means you can use the extended firmware with both:
- The INDI driver (full feature access)
- The original SVBONY Windows application (basic features only)

## Features

### 1. Auto Dew Heater Control

Automatically manages dew heater power based on ambient conditions.

**How it works:**
1. Firmware calculates dew point from temperature and humidity
2. Target temperature = dew point + margin (configurable, default 5°C)
3. PID controller adjusts heater power to maintain target

**Configuration via INDI:**
- Enable/disable auto mode per channel (PWM14, PWM15)
- Set temperature margin (how many degrees above dew point)
- View calculated dew point and current heater output

**PID Controller:**
- Kp = 2.0 (proportional gain)
- Ki = 0.5 (integral gain)
- Kd = 0.1 (derivative gain)
- i_max = 50 (integral windup limit)

### 2. Session Statistics

Tracks key metrics throughout your imaging session.

**Voltage Statistics:**
- Minimum voltage recorded
- Maximum voltage recorded
- Average voltage (running average)

**Power Statistics:**
- Peak power consumption (W)
- Total energy used (Wh) - great for battery planning

**Temperature Statistics:**
- Minimum ambient temperature
- Maximum ambient temperature

**Other:**
- Uptime (seconds since power-on)
- I2C recovery count

**Reset:** Statistics can be reset via INDI driver to start fresh.

### 3. Voltage Alerts

Protect your equipment with configurable voltage monitoring.

**Low Voltage Warning:**
- Default threshold: 11.5V
- Enable/disable independently
- Visual indicator in INDI driver

**Critical Voltage Alert:**
- Default threshold: 11.0V
- Enable/disable independently
- **Auto-shutdown option**: Automatically disable non-essential ports when triggered

**Alert States (visible in INDI):**
- Low voltage warning active
- Critical voltage alert active
- Thermal alert (reserved for future use)
- I2C communication failure

### 4. Sensor Calibration

Fine-tune sensor readings to match your reference instruments.

**Adjustable Offsets:**
- **Voltage offset**: ±2V range, stored in EEPROM
- **Temperature offset**: ±10°C range, stored in EEPROM
- **Humidity offset**: ±20% range, stored in EEPROM

**Typical Usage:**
```
Your multimeter shows 12.85V
SV241 reports 12.70V
Set voltage offset to +0.15V
```

### 5. Port Naming

Give meaningful names to your equipment connections.

**Nameable Ports:**
- DC1 through DC5 (e.g., "Mount", "Camera", "Focuser")
- USB12, USB345 (e.g., "Guide Cam", "Filter Wheel")
- PWM13, PWM14, PWM15 (e.g., "Adj Voltage", "Primary Dew", "Guide Dew")

**Features:**
- Up to 15 characters per name
- Stored in EEPROM (survives power cycles)
- Visible in INDI driver interface

### 6. Diagnostics

Monitor system health and troubleshoot issues.

**I2C Health:**
- INA219 (voltage/current sensor) status
- SHT4x (temperature/humidity sensor) status
- Manual I2C bus recovery trigger

**System:**
- Free heap memory (ESP32)
- I2C error count

## Quick Start

### Flash the Firmware

```bash
pip install esptool

esptool --chip esp32 --port /dev/ttyUSB0 --baud 115200 --no-stub \
  write-flash 0x0 SV241_Extended.ino.merged.bin
```

**Port names:**
- macOS: `/dev/cu.usbserial-*`
- Linux: `/dev/ttyUSB0`
- Windows: `COM3` (check Device Manager)

### Test the Firmware

```bash
python scripts/test_extended_firmware.py /dev/ttyUSB0
```

Expected output:
```
======================================================================
TEST SUMMARY
======================================================================
  Binary Sensors: PASS
  Binary Sync States: PASS
  Binary DC Outputs: PASS
  Binary PWM Outputs: PASS
  Ext Version: PASS
  Ext Status: PASS
  Ext Dew Status: PASS
  Ext Dew Config: PASS
  Ext Stats: PASS
  Ext Alerts: PASS
  Ext Calibration: PASS
  Ext Diagnostics: PASS
  Ext I2C Recovery: PASS
  Ext Stats Reset: PASS
  Ext Names Get: PASS
  Ext Names Set: PASS

Total: 16/16 passed
```

## Protocol Reference

### Extended Command Framing

All extended commands use command ID `0x10`:

**Request:**
```
[0x24] [LEN] [0x10] [JSON payload...] [CHECKSUM]
```

**Response:**
```
[0x24] [LEN] [0x10] [JSON payload...] [CHECKSUM]
```

### Command Reference

#### System Commands

**version** - Get firmware version and capabilities
```json
Request:  {"cmd":"version"}
Response: {"fw":"SV241-EXT","ver":"2.0.0","caps":["dew","stats","alerts","cal"]}
```

**status** - Get complete system status
```json
Request:  {"cmd":"status"}
Response: {
  "v": 12.85,
  "p": 2.34,
  "t": 18.5,
  "h": 65.2,
  "dew": 11.8,
  "dc": [1, 1, 0, 0, 1, 1, 1],
  "pwm": [0, 127, 200],
  "auto_dew": [false, true],
  "uptime": 3600,
  "i2c_err": 0
}
```

#### Dew Control

**dew_status** - Get dew heater state
```json
Request:  {"cmd":"dew_status"}
Response: {
  "dew_point": 11.8,
  "ambient": 18.5,
  "humidity": 65.2,
  "ch14": {"auto": true, "margin": 5.0, "output": 127, "target": 16.8},
  "ch15": {"auto": false, "output": 200}
}
```

**dew_config** - Configure auto-dew for a channel
```json
Request:  {"cmd":"dew_config","ch":14,"auto":true,"margin":5.0}
Response: {"ok":true}
```

#### Statistics

**stats** - Get session statistics
```json
Request:  {"cmd":"stats"}
Response: {
  "uptime": 7200,
  "v_min": 11.8,
  "v_max": 13.1,
  "v_avg": 12.6,
  "p_max": 45.2,
  "p_total": 12.5,
  "t_min": 15.2,
  "t_max": 22.1,
  "i2c_recoveries": 2
}
```

**stats_reset** - Reset statistics
```json
Request:  {"cmd":"stats_reset"}
Response: {"ok":true}
```

#### Alerts

**alerts** - Get current alert state
```json
Request:  {"cmd":"alerts"}
Response: {"low_v":false,"crit_v":false,"thermal":false,"i2c_fail":false}
```

**alert_config** - Get or set alert configuration
```json
Request:  {"cmd":"alert_config"}
Response: {
  "low_v": {"en": true, "thresh": 11.5},
  "crit_v": {"en": true, "thresh": 11.0, "auto_off": true}
}
```

```json
Request:  {"cmd":"alert_config","low_v":{"en":true,"thresh":11.5},"crit_v":{"en":true,"thresh":11.0,"auto_off":true}}
Response: {"ok":true}
```

#### Calibration

**cal_get** - Get calibration offsets
```json
Request:  {"cmd":"cal_get"}
Response: {"v_offset":0.0,"t_offset":0.0,"h_offset":0.0}
```

**cal_set** - Set calibration offsets
```json
Request:  {"cmd":"cal_set","v_offset":-0.15,"t_offset":0.5}
Response: {"ok":true}
```

#### Port Names

**names_get** - Get custom port names
```json
Request:  {"cmd":"names_get"}
Response: {
  "dc": ["Mount", "Camera", "Focuser", "DC4", "DC5", "USB12", "USB345"],
  "pwm": ["PWM13", "Primary", "Guide"]
}
```

**names_set** - Set a port name (idx: 0-6 for DC, 7-9 for PWM)
```json
Request:  {"cmd":"names_set","idx":0,"name":"Mount"}
Response: {"ok":true}
```

#### Diagnostics

**diag** - Get diagnostic information
```json
Request:  {"cmd":"diag"}
Response: {
  "free_heap": 280000,
  "i2c_ok": true,
  "ina219_ok": true,
  "sht4x_ok": true,
  "last_i2c_err": 0,
  "wifi": false
}
```

**i2c_recovery** - Force I2C bus recovery
```json
Request:  {"cmd":"i2c_recovery"}
Response: {"ok":true,"sda_released":true}
```

## EEPROM Storage

Configuration is stored in EEPROM and persists across power cycles:

| Address | Data |
|---------|------|
| 0x00 | Magic number (0x5641) |
| 0x02 | Calibration offsets (v, t, h) |
| 0x20 | Dew configuration (2 channels) |
| 0x60 | Alert configuration |
| 0x80 | Port names (10 x 16 bytes) |

## Building from Source

### Prerequisites

- Arduino IDE 2.0+ or arduino-cli
- ESP32 board support package
- ArduinoJson library (v7+)

### Arduino IDE

1. Install ESP32 board support:
   - File → Preferences → Additional Board URLs:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```

2. Install ArduinoJson library:
   - Tools → Manage Libraries → Search "ArduinoJson"

3. Select board:
   - Tools → Board → ESP32 Arduino → "ESP32 Dev Module"

4. Configure:
   - Flash Size: 4MB (32Mb)
   - Partition Scheme: Default 4MB with spiffs
   - Upload Speed: 115200

5. Open and upload `SV241_Extended.ino`

### Arduino CLI

```bash
# Install ESP32 core
arduino-cli core install esp32:esp32

# Install ArduinoJson
arduino-cli lib install ArduinoJson

# Compile
arduino-cli compile --fqbn esp32:esp32:esp32 SV241_Extended

# Upload
arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 SV241_Extended
```

### Creating Merged Binary

To create a single flashable binary:

```bash
esptool --chip esp32 merge_bin -o SV241_Extended.ino.merged.bin \
  --flash_mode dio --flash_size 4MB \
  0x1000 build/SV241_Extended.ino.bootloader.bin \
  0x8000 build/SV241_Extended.ino.partitions.bin \
  0x10000 build/SV241_Extended.ino.bin
```

## Dew Point Calculation

The firmware uses the Magnus-Tetens approximation:

```
a = 17.27
b = 237.7

gamma = (a * T) / (b + T) + ln(RH / 100)
dew_point = (b * gamma) / (a - gamma)
```

Where:
- T = ambient temperature (°C)
- RH = relative humidity (%)

## Troubleshooting

### Extended features not visible in INDI

- Verify firmware is flashed: Check for `SV241-EXT` in version response
- Reconnect the driver: Extended features are detected on connect
- Check INDI logs for "Extended firmware detected"

### Statistics not updating

- Statistics update every second in the firmware
- INDI polls every 5 seconds by default
- Reset statistics to start fresh measurement

### Calibration not saving

- Verify the EEPROM magic number is correct
- Try power cycling after setting calibration
- Check for EEPROM errors in diagnostics

### Auto-dew not working

1. Verify temperature and humidity sensors are working
2. Check dew point calculation is reasonable
3. Ensure auto mode is enabled for the channel
4. Verify margin is set appropriately (default 5°C)

## Version History

### v2.0.0 (Current)
- Auto dew heater control with PID
- Session statistics tracking
- Voltage alerts with auto-shutdown
- Sensor calibration offsets
- Custom port naming
- I2C diagnostics and recovery
- Full backward compatibility with binary protocol

### v1.x
- Basic I2C recovery
- Binary protocol only
- See `../SV241_Custom/` for basic firmware

## License

This firmware is provided for personal use with SVBONY SV241 hardware.

## Contributing

Issues and improvements welcome! Please test thoroughly, especially:
- Extended protocol commands
- EEPROM persistence
- Long-duration auto-dew operation
- Edge cases in alert handling
