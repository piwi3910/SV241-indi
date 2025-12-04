# SV241 Extended Firmware v2.3

Advanced firmware for the SVBONY SV241 Power Box with auto dew control, session statistics, voltage alerts, sensor calibration, custom port naming, configuration profiles, timer scheduling, temperature rate tracking, PID tuning, watchdog safety mode, current threshold alerts, boot profile auto-load, and persistent statistics.

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

### 7. Configuration Profiles (NEW in v2.1)

Save and restore complete device configurations instantly.

**Features:**
- Up to 4 profile slots
- Stores all DC/USB states and PWM values
- Named profiles (e.g., "Widefield", "Planetary", "Visual")
- EEPROM persistence across power cycles

**Saved State:**
- DC1-DC5, USB12, USB345 on/off states
- PWM13, PWM14, PWM15 values
- Auto-dew enable/disable state
- Dew margins

**Usage via INDI:**
- Save current state to any slot with a custom name
- Load a profile to restore all settings instantly
- Delete profiles you no longer need
- View active profile indicator

### 8. Timer Scheduling (NEW in v2.1)

Schedule port actions to occur automatically in the future.

**Features:**
- Up to 8 concurrent timers
- Actions: On, Off, or Set (to specific PWM value)
- Per-port scheduling (DC1-DC5, USB12, USB345, PWM13-PWM15)
- Countdown display in INDI driver

**Typical Usage:**
```
"Turn off DC3 in 30 minutes" (auto-shutdown camera cooler)
"Set PWM14 to 200 in 60 minutes" (pre-heat dew heater before sunset)
"Turn on DC1 in 5 minutes" (delayed mount power-up)
```

**Timer Management:**
- Create timers with port, action, and minutes
- View all active timers with remaining time
- Cancel individual timers as needed

### 9. Temperature Rate Tracking (NEW in v2.1)

Monitor how fast temperature is changing.

**Features:**
- Rolling 30-minute temperature history
- Rate of change in °C/hour
- Helps predict dew formation timing

**How it works:**
1. Firmware samples temperature every minute
2. Maintains 30-sample circular buffer
3. Calculates rate from oldest to newest sample
4. Positive = warming, Negative = cooling

**Typical Usage:**
- Rate of -3°C/hour indicates rapid cooling
- Combined with dew point proximity, helps anticipate dew issues
- Plan dew heater activation before problems occur

### 10. PID Tuning

Fine-tune the auto dew heater PID controller for your equipment.

**Default Values:**
- Kp = 2.0 (proportional gain)
- Ki = 0.5 (integral gain)
- Kd = 0.1 (derivative gain)

**Per-Channel Tuning:**
- PWM14 and PWM15 have independent PID coefficients
- Adjust for different heater characteristics
- Stored in EEPROM

**Tuning Tips:**
- Increase Kp for faster response, but may overshoot
- Increase Ki to eliminate steady-state error
- Increase Kd to reduce oscillation
- Start with defaults; adjust only if needed

### 11. Watchdog / Safety Mode (NEW in v2.2)

Protect your equipment if the control computer crashes or loses connection.

**How it works:**
1. Firmware monitors USB communication
2. If no commands received within timeout period, watchdog triggers
3. Configurable action executes automatically

**Configuration:**
- **Timeout**: 0-65535 seconds (default: 300 = 5 minutes)
- **Action**: Choose what happens when watchdog triggers:
  - `none` - Just set alert flag, don't change outputs
  - `all_off` - Turn off all DC/USB ports, set all PWM to 0
  - `profile` - Load a specific profile (e.g., "safe shutdown" configuration)

**Typical Usage:**
```
Set timeout to 300 seconds (5 minutes)
Set action to "all_off"
If computer crashes during imaging, all outputs turn off after 5 minutes
Prevents dew heaters from running indefinitely unattended
```

**INDI Controls:**
- Enable/disable watchdog
- Set timeout in seconds
- Select action type
- Choose profile slot (for profile action)
- View triggered status and remaining time

**Important Notes:**
- Any command received resets the watchdog timer
- The triggered flag must be cleared manually after a watchdog fires
- Configuration is stored in EEPROM

### 12. Current Threshold Alert (NEW in v2.2)

Monitor total current draw and get alerts when it exceeds a safe threshold.

**How it works:**
1. INA219 monitors total current continuously
2. When current exceeds threshold, alert flag is set
3. Alert auto-clears when current drops below threshold

**Configuration:**
- **Threshold**: 0.0-10.0 amps (default: 5.0A)
- **Enable/disable**: Turn alerting on or off

**Typical Usage:**
```
Set threshold to 5.0A (max safe draw for your battery/supply)
If a short circuit or equipment malfunction causes excess current
Alert triggers immediately, visible in INDI driver
```

**INDI Controls:**
- Enable/disable current alerting
- Set threshold in amps
- View current draw in real-time
- View alert status light

**Important Notes:**
- INA219 monitors total system current, not per-port
- Alert is informational only (no automatic shutdown)
- Useful for detecting equipment issues early
- Configuration is stored in EEPROM

### 13. Boot Profile (NEW in v2.3)

Automatically load a configuration profile when the device powers on.

**How it works:**
1. Configure which profile to load on boot (-1 = disabled, 0-3 = profile slot)
2. On power-on, firmware applies the selected profile before any USB connection
3. Device immediately starts with your preferred configuration

**Typical Usage:**
```
Save your imaging setup as profile 0 "Imaging"
Set boot profile to slot 0
Now every time you power on, your imaging setup is ready
```

**Benefits:**
- Start with dew heaters pre-warmed
- Mount power ready immediately
- No need to wait for computer connection
- Perfect for remote/unattended setups

**INDI Controls:**
- Select boot profile slot (-1 to disable)
- View current boot profile setting
- Profile name displayed when set

### 14. Persistent Statistics (NEW in v2.3)

Track total energy consumption and uptime across multiple sessions.

**How it works:**
1. Statistics are automatically saved to EEPROM every 30 minutes
2. On reboot, previous session totals are loaded
3. Manual save available for immediate persistence

**Tracked Data:**
- `p_total_all` - Total energy consumed across ALL sessions (Wh)
- `total_uptime` - Total device uptime across ALL sessions (seconds)

**Typical Usage:**
```
View stats command now shows:
- p_total: 2.5 Wh (current session)
- p_total_all: 156.8 Wh (all time)
- uptime: 3600 (current session)
- total_uptime: 360000 (all time)
```

**EEPROM Wear Considerations:**
- Auto-save every 30 minutes = ~17,500 writes/year
- ESP32 flash rated for ~100,000 write cycles
- ~5+ years of operation before wear concerns
- Manual save on disconnect for complete accuracy

**INDI Controls:**
- View all-time energy consumption
- View all-time uptime
- Manual stats save command
- Reset persistent stats to zero

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
  Ext Profile List: PASS
  Ext Profile Save: PASS
  Ext Profile Load: PASS
  Ext Profile Delete: PASS
  Ext Timer Set: PASS
  Ext Timer List: PASS
  Ext Timer Cancel: PASS
  Ext Temp Rate: PASS
  Ext Watchdog: PASS
  Ext Current Alert: PASS
  Ext Boot Config: PASS
  Ext Stats Save: PASS

Total: 28/28 passed
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
Response: {"fw":"SV241-EXT","ver":"2.3.0","caps":["dew","stats","alerts","cal","profiles","timers","temp_rate","watchdog","current_alert","boot_profile","persistent_stats"]}
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
  "i2c_recoveries": 2,
  "p_total_all": 156.8,
  "total_uptime": 36000
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
Response: {"low_v":false,"crit_v":false,"thermal":false,"i2c_fail":false,"over_current":false,"watchdog":false}
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

#### Profiles (NEW in v2.1)

**profile_list** - Get all saved profiles
```json
Request:  {"cmd":"profile_list"}
Response: {
  "profiles": [
    {"slot": 0, "name": "Widefield", "active": true},
    {"slot": 1, "name": "Planetary", "active": false},
    {"slot": 2, "name": "", "active": false},
    {"slot": 3, "name": "", "active": false}
  ]
}
```

**profile_save** - Save current state to a profile slot
```json
Request:  {"cmd":"profile_save","slot":0,"name":"Widefield"}
Response: {"ok":true}
```

**profile_load** - Load a saved profile
```json
Request:  {"cmd":"profile_load","slot":0}
Response: {"ok":true}
```

**profile_delete** - Delete a profile
```json
Request:  {"cmd":"profile_delete","slot":0}
Response: {"ok":true}
```

#### Timers (NEW in v2.1)

**timer_list** - Get all active timers
```json
Request:  {"cmd":"timer_list"}
Response: {
  "timers": [
    {"id": 1, "port": "DC3", "action": "off", "remaining": 1500},
    {"id": 2, "port": "PWM14", "action": "set", "value": 200, "remaining": 3200}
  ]
}
```

**timer_set** - Create a new timer
```json
Request:  {"cmd":"timer_set","port":"DC3","action":"off","minutes":30}
Response: {"ok":true,"id":1}
```

```json
Request:  {"cmd":"timer_set","port":"PWM14","action":"set","minutes":60,"value":200}
Response: {"ok":true,"id":2}
```

**timer_cancel** - Cancel a timer by ID
```json
Request:  {"cmd":"timer_cancel","id":1}
Response: {"ok":true}
```

#### Temperature Rate (NEW in v2.1)

**temp_rate** - Get temperature rate of change
```json
Request:  {"cmd":"temp_rate"}
Response: {"rate": -2.5, "samples": 30}
```

Note: Rate is in °C/hour. Negative values indicate cooling.

#### PID Tuning (NEW in v2.1)

**dew_pid** - Get or set PID coefficients for dew heaters
```json
Request:  {"cmd":"dew_pid","ch":14}
Response: {"ch":14,"kp":2.0,"ki":0.5,"kd":0.1}
```

```json
Request:  {"cmd":"dew_pid","ch":14,"kp":2.5,"ki":0.6,"kd":0.15}
Response: {"ok":true}
```

#### Watchdog (NEW in v2.2)

**watchdog** - Get or set watchdog configuration
```json
Request:  {"cmd":"watchdog"}
Response: {"enabled":true,"timeout":300,"action":"all_off","profile":0,"triggered":false,"remaining":285}
```

```json
Request:  {"cmd":"watchdog","enabled":true,"timeout":300,"action":"all_off"}
Response: {"ok":true}
```

```json
Request:  {"cmd":"watchdog","enabled":true,"timeout":600,"action":"profile","profile":2}
Response: {"ok":true}
```

**feed** - Reset watchdog timer (also reset by any command)
```json
Request:  {"cmd":"watchdog","feed":true}
Response: {"ok":true}
```

**clear** - Clear triggered state after watchdog fires
```json
Request:  {"cmd":"watchdog","clear":true}
Response: {"ok":true}
```

#### Current Alert (NEW in v2.2)

**current_alert** - Get or set current alert configuration
```json
Request:  {"cmd":"current_alert"}
Response: {"enabled":true,"threshold":5.0,"current":2.34,"alert":false}
```

```json
Request:  {"cmd":"current_alert","enabled":true,"threshold":5.0}
Response: {"ok":true}
```

**clear** - Clear alert state
```json
Request:  {"cmd":"current_alert","clear":true}
Response: {"ok":true}
```

#### Boot Profile (NEW in v2.3)

**boot_config** - Get or set boot profile configuration
```json
Request:  {"cmd":"boot_config"}
Response: {"profile":-1}
```

```json
Request:  {"cmd":"boot_config"}
Response: {"profile":0,"name":"Imaging"}
```

```json
Request:  {"cmd":"boot_config","profile":0}
Response: {"ok":true}
```

#### Persistent Stats (NEW in v2.3)

**stats_save** - Save stats to EEPROM and get totals
```json
Request:  {"cmd":"stats_save"}
Response: {"ok":true,"p_total_all":156.8,"total_uptime":36000}
```

**reset** - Reset all persistent stats to zero
```json
Request:  {"cmd":"stats_save","reset":true}
Response: {"ok":true,"reset":true}
```

## EEPROM Storage

Configuration is stored in EEPROM and persists across power cycles:

| Address | Data |
|---------|------|
| 0x00 | Magic number (0x5641) |
| 0x04 | Calibration offsets (12 bytes) |
| 0x14 | Dew configuration (64 bytes) |
| 0x5A | Alert configuration (16 bytes) |
| 0x6E | Port names (160 bytes) |
| 0x118 | Profiles (4 x 64 = 256 bytes) |
| 0x1D8 | Watchdog configuration (8 bytes) |
| 0x1E0 | Current alert configuration (8 bytes) |
| 0x1E8 | Boot configuration (4 bytes) |
| 0x1EC | Persistent stats (16 bytes) |

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

### Profiles not loading correctly

1. Verify the profile was saved with a name
2. Check that EEPROM write succeeded (no errors in response)
3. Power cycle and try loading again
4. If issues persist, delete and re-save the profile

### Timers not executing

1. Check timer shows in timer_list with correct remaining time
2. Verify the port name matches exactly (case-sensitive)
3. Confirm action type is valid (on, off, set)
4. Note: Timers are not persistent - lost on power cycle

### Temperature rate shows 0

1. Rate calculation needs at least 2 samples (wait 2 minutes)
2. Full accuracy requires 30 samples (30 minutes of operation)
3. Verify temperature sensor is working in diagnostics

### Watchdog keeps triggering

1. Increase timeout to allow for network/computer delays
2. Ensure INDI driver is polling (default every 5 seconds)
3. After watchdog fires, must clear triggered state to re-arm
4. Check watchdog action is appropriate for your use case

### Current alert not working

1. Verify INA219 sensor is functioning (check diagnostics)
2. Ensure threshold is set to a reasonable value
3. Current monitoring is total system current only
4. Alert auto-clears when current drops below threshold

## Version History

### v2.3.0 (Current)
- Boot profile - auto-load a configuration profile when device powers on
- Persistent statistics - track total energy consumption and uptime across sessions
- Stats auto-save every 30 minutes with manual save option
- All v2.2.0 features included

### v2.2.0
- Watchdog / safety mode - protect equipment if control computer crashes
- Current threshold alert - monitor total current draw for overloads
- All v2.1.0 features included

### v2.1.0
- Configuration profiles (4 slots) - save/load complete device setups
- Timer scheduling (8 concurrent) - schedule future port actions
- Temperature rate tracking - monitor cooling/heating trends
- PID tuning - adjustable coefficients per dew heater channel
- All v2.0.0 features included

### v2.0.0
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
- Profile save/load cycles
- Timer scheduling accuracy
- Temperature rate calculation over extended sessions
- PID tuning effectiveness with different heater types
- Watchdog behavior during long sessions
- Current alert threshold accuracy
