# SV241 Extended Protocol Specification v2.3

This document defines the extended JSON-based protocol for the SV241 custom firmware. The extended protocol provides advanced features while maintaining full backward compatibility with the original binary protocol.

## Protocol Design

### Backward Compatibility

The firmware supports two protocols simultaneously:

1. **Original Binary Protocol (0x01-0x08)** - For Windows ASCOM driver compatibility
2. **Extended JSON Protocol (0x10)** - For advanced INDI driver features

### Framing

All extended commands use command ID `0x10`:

**Request:**
```
[0x24] [LEN] [0x10] [JSON payload...] [CHECKSUM]
```

**Response:**
```
[0x24] [LEN] [0x10] [JSON payload...] [CHECKSUM]
```

Where:
- `0x24` - Header byte (same as original protocol)
- `LEN` - Total packet length including header
- `0x10` - Extended command ID
- `JSON payload` - UTF-8 encoded JSON string
- `CHECKSUM` - Sum of all bytes mod 255 (same algorithm as original)

### Firmware Detection

On connect, the INDI driver sends a version query:
- **No response/timeout** → Original firmware, use basic binary commands only
- **JSON response** → Extended firmware, enable advanced features

---

## Command Reference

### 1. System Commands

#### version
Identify firmware version and capabilities.

```json
Request:  {"cmd":"version"}
Response: {"fw":"SV241-EXT","ver":"2.3.0","caps":["dew","stats","alerts","cal","profiles","timers","temp_rate","watchdog","current_alert","boot_profile","persistent_stats"]}
```

Capability flags:
- `dew` - Auto dew heater control with PID
- `stats` - Session statistics tracking
- `alerts` - Voltage and thermal alerts
- `cal` - Sensor calibration offsets
- `profiles` - Configuration profiles
- `timers` - Timer/scheduling features
- `temp_rate` - Temperature rate of change tracking
- `watchdog` - Communication watchdog safety mode
- `current_alert` - Total current threshold alerts
- `boot_profile` - Auto-load profile on boot (NEW in v2.3)
- `persistent_stats` - Statistics that survive reboot (NEW in v2.3)

#### status
Get complete system status in one call (reduces polling overhead).

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

Fields:
- `v` - Input voltage (V)
- `p` - Power consumption (W)
- `t` - Ambient temperature (°C)
- `h` - Humidity (%)
- `dew` - Calculated dew point (°C)
- `dc` - DC output states [DC1, DC2, DC3, DC4, DC5, USB12, USB345]
- `pwm` - PWM values [PWM13, PWM14, PWM15]
- `auto_dew` - Auto-dew enabled [PWM14, PWM15]
- `uptime` - Seconds since boot
- `i2c_err` - I2C error/recovery count

---

### 2. Dew Control

#### dew_status
Get dew heater state and calculations.

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

#### dew_config
Configure auto-dew for a channel.

```json
Request:  {"cmd":"dew_config","ch":14,"auto":true,"margin":5.0}
Response: {"ok":true}
```

With optional PID parameters:
```json
Request:  {"cmd":"dew_config","ch":14,"auto":true,"margin":5.0,"kp":2.0,"ki":0.5,"kd":0.1}
Response: {"ok":true}
```

Parameters:
- `ch` - Channel (14 or 15)
- `auto` - Enable/disable auto mode
- `margin` - Degrees above dew point to target (default: 5.0)
- `kp`, `ki`, `kd` - PID tuning parameters (optional)

#### dew_pid
Get or set PID tuning parameters.

```json
Request:  {"cmd":"dew_pid","ch":14}
Response: {"kp":2.0,"ki":0.5,"kd":0.1,"i_max":50}
```

```json
Request:  {"cmd":"dew_pid","ch":14,"kp":1.5,"ki":0.3,"kd":0.05}
Response: {"ok":true}
```

---

### 3. Power & Alerts

#### stats
Get session statistics.

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

Fields:
- `uptime` - Seconds since boot (current session)
- `v_min`, `v_max`, `v_avg` - Voltage statistics (V)
- `p_max` - Peak power (W)
- `p_total` - Total energy consumed this session (Wh)
- `t_min`, `t_max` - Temperature range (°C)
- `i2c_recoveries` - Number of I2C bus recoveries
- `p_total_all` - Total energy consumed across all sessions (Wh) (NEW in v2.3)
- `total_uptime` - Total uptime across all sessions (seconds) (NEW in v2.3)

#### stats_reset
Reset session statistics.

```json
Request:  {"cmd":"stats_reset"}
Response: {"ok":true}
```

#### alert_config
Get or set voltage alert configuration.

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

Parameters:
- `low_v.en` - Enable low voltage warning
- `low_v.thresh` - Warning threshold (V)
- `crit_v.en` - Enable critical voltage alert
- `crit_v.thresh` - Critical threshold (V)
- `crit_v.auto_off` - Auto-shutdown non-essential ports on critical

#### alerts
Get current alert state.

```json
Request:  {"cmd":"alerts"}
Response: {"low_v":false,"crit_v":false,"thermal":false,"i2c_fail":false,"over_current":false,"watchdog":false}
```

Additional fields (v2.2.0+):
- `over_current` - Current draw exceeds threshold
- `watchdog` - Watchdog timeout triggered

---

### 4. Calibration

#### cal_get
Get calibration offsets.

```json
Request:  {"cmd":"cal_get"}
Response: {"v_offset":0.0,"t_offset":0.0,"h_offset":0.0}
```

#### cal_set
Set calibration offsets (stored in EEPROM).

```json
Request:  {"cmd":"cal_set","v_offset":-0.15,"t_offset":0.5}
Response: {"ok":true}
```

---

### 5. Port Naming

#### names_get
Get custom port names.

```json
Request:  {"cmd":"names_get"}
Response: {
  "dc1": "Mount",
  "dc2": "Camera",
  "dc3": "Focuser",
  "dc4": "",
  "dc5": "",
  "pwm14": "Primary",
  "pwm15": "Guide"
}
```

#### names_set
Set port names (stored in EEPROM, max 16 chars each).

```json
Request:  {"cmd":"names_set","dc1":"Mount","dc2":"Camera"}
Response: {"ok":true}
```

---

### 6. Profiles

#### profile_list
List saved profiles.

```json
Request:  {"cmd":"profile_list"}
Response: {"profiles":["Imaging","Visual","Idle"],"active":0}
```

#### profile_save
Save current state as profile.

```json
Request:  {"cmd":"profile_save","slot":0,"name":"Imaging"}
Response: {"ok":true}
```

#### profile_load
Load a saved profile.

```json
Request:  {"cmd":"profile_load","slot":0}
Response: {"ok":true}
```

---

### 7. Scheduling

#### timer_set
Set a timer for a port action.

```json
Request:  {"cmd":"timer_set","port":"dc3","action":"off","minutes":180}
Response: {"ok":true,"id":1}
```

```json
Request:  {"cmd":"timer_set","port":"pwm14","action":"set","value":0,"minutes":240}
Response: {"ok":true,"id":2}
```

Parameters:
- `port` - Port name (dc1-dc5, usb12, usb345, pwm13-pwm15)
- `action` - "on", "off", or "set"
- `value` - PWM value (only for "set" action)
- `minutes` - Time until action

#### timer_list
List active timers.

```json
Request:  {"cmd":"timer_list"}
Response: {"timers":[{"id":1,"port":"dc3","action":"off","remaining":165}]}
```

#### timer_cancel
Cancel a timer.

```json
Request:  {"cmd":"timer_cancel","id":1}
Response: {"ok":true}
```

---

### 8. Diagnostics

#### diag
Get diagnostic information.

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

#### i2c_recovery
Force I2C bus recovery.

```json
Request:  {"cmd":"i2c_recovery"}
Response: {"ok":true,"sda_released":true}
```

---

### 9. Temperature Rate

#### temp_rate
Get temperature change rate (useful for focuser compensation).

```json
Request:  {"cmd":"temp_rate"}
Response: {"rate":-0.3,"period":600,"samples":10}
```

Fields:
- `rate` - Temperature change rate (°C/hour)
- `period` - Measurement period (seconds)
- `samples` - Number of samples used

---

### 10. Watchdog / Safety Mode

The watchdog feature monitors USB communication and takes action if no commands are received within the timeout period. This protects equipment if the control computer crashes or loses connection.

#### watchdog
Get or set watchdog configuration.

**Get configuration:**
```json
Request:  {"cmd":"watchdog"}
Response: {
  "enabled": true,
  "timeout": 300,
  "action": "all_off",
  "profile": 0,
  "triggered": false,
  "remaining": 285
}
```

Fields:
- `enabled` - Watchdog enabled/disabled
- `timeout` - Timeout in seconds (0-65535)
- `action` - Action on timeout: "none", "all_off", or "profile"
- `profile` - Profile slot to load if action is "profile" (0-3)
- `triggered` - Whether watchdog has fired (read-only)
- `remaining` - Seconds until timeout, -1 if disabled or triggered (read-only)

**Set configuration:**
```json
Request:  {"cmd":"watchdog","enabled":true,"timeout":300,"action":"all_off"}
Response: {"ok":true}
```

```json
Request:  {"cmd":"watchdog","enabled":true,"timeout":600,"action":"profile","profile":2}
Response: {"ok":true}
```

**Reset watchdog timer:**
Any command received by the firmware resets the watchdog timer. Additionally, you can explicitly feed the watchdog:

```json
Request:  {"cmd":"watchdog","feed":true}
Response: {"ok":true}
```

**Clear triggered state:**
After a watchdog fires, the triggered flag must be cleared to re-arm:

```json
Request:  {"cmd":"watchdog","clear":true}
Response: {"ok":true}
```

Actions:
- `none` - Set alert flag only, do not change outputs
- `all_off` - Turn off all DC and USB ports, set all PWM to 0
- `profile` - Load a specific profile slot (useful for safe shutdown configuration)

---

### 11. Current Threshold Alert

Monitor total current draw and alert when it exceeds a threshold. Useful for detecting shorts or overloads.

#### current_alert
Get or set current alert configuration.

**Get configuration:**
```json
Request:  {"cmd":"current_alert"}
Response: {
  "enabled": true,
  "threshold": 5.0,
  "current": 2.34,
  "alert": false
}
```

Fields:
- `enabled` - Alert enabled/disabled
- `threshold` - Alert threshold in amps
- `current` - Current draw reading (read-only)
- `alert` - Whether alert is active (read-only)

**Set configuration:**
```json
Request:  {"cmd":"current_alert","enabled":true,"threshold":5.0}
Response: {"ok":true}
```

**Clear alert:**
```json
Request:  {"cmd":"current_alert","clear":true}
Response: {"ok":true}
```

Note: The alert is automatically cleared when current drops below the threshold. The clear command can be used to manually reset the alert state.

---

### 12. Boot Profile (NEW in v2.3)

Configure a profile to automatically load when the device powers on. This allows the device to restore your preferred configuration without needing to connect to the INDI driver.

#### boot_config
Get or set boot profile configuration.

**Get configuration:**
```json
Request:  {"cmd":"boot_config"}
Response: {"profile":-1}
```

```json
Request:  {"cmd":"boot_config"}
Response: {"profile":0,"name":"Imaging"}
```

Fields:
- `profile` - Profile slot to load on boot (-1 = disabled, 0-3 = profile slot)
- `name` - Name of the configured profile (only present if a profile is set)

**Set configuration:**
```json
Request:  {"cmd":"boot_config","profile":0}
Response: {"ok":true}
```

**Disable boot profile:**
```json
Request:  {"cmd":"boot_config","profile":-1}
Response: {"ok":true}
```

Notes:
- The profile must exist before it can be set as the boot profile
- If the boot profile is later deleted, the device will skip loading it on boot
- Configuration is stored in EEPROM and persists across power cycles

---

### 13. Persistent Stats (NEW in v2.3)

Save session statistics to EEPROM so they survive device reboots. Useful for tracking total energy consumption over multiple sessions.

#### stats_save
Manually save current statistics to EEPROM.

**Save stats:**
```json
Request:  {"cmd":"stats_save"}
Response: {"ok":true,"p_total_all":156.8,"total_uptime":36000}
```

Fields:
- `p_total_all` - Total energy consumed across all sessions (Wh)
- `total_uptime` - Total uptime across all sessions (seconds)

**Reset persistent stats:**
```json
Request:  {"cmd":"stats_save","reset":true}
Response: {"ok":true,"reset":true}
```

Notes:
- Stats are automatically saved to EEPROM every 30 minutes (hybrid approach to minimize EEPROM wear)
- Use `stats_save` when disconnecting or before powering off to ensure latest stats are saved
- The `stats` command now includes `p_total_all` and `total_uptime` fields for cumulative statistics
- Use `reset:true` to clear all persistent stats and start fresh

---

## Error Responses

All commands can return error responses:

```json
{"err":"unknown_cmd"}
{"err":"invalid_param","param":"margin"}
{"err":"eeprom_fail"}
{"err":"i2c_fail"}
{"err":"out_of_range","param":"ch","min":14,"max":15}
```

---

## Implementation Phases

### Phase 1 (Core)
- `version`, `status`
- `dew_status`, `dew_config`
- `stats`, `alerts`

### Phase 2 (Quality of Life)
- `cal_get`, `cal_set`
- `names_get`, `names_set`
- `diag`, `i2c_recovery`

### Phase 3 (Advanced)
- `profiles`
- `timers`
- `temp_rate`
- `dew_pid` tuning

### Phase 4 (Safety)
- `watchdog` - Communication watchdog with configurable actions
- `current_alert` - Total current threshold monitoring

### Phase 5 (Persistence)
- `boot_config` - Auto-load profile on boot
- `stats_save` - Persistent statistics across reboots

---

## Dew Point Calculation

The firmware calculates dew point using the Magnus-Tetens approximation:

```
a = 17.27
b = 237.7

gamma = (a * T) / (b + T) + ln(RH / 100)
dew_point = (b * gamma) / (a - gamma)
```

Where:
- T = ambient temperature (°C)
- RH = relative humidity (%)

---

## PID Controller

The auto-dew feature uses a PID controller:

```
error = target_temp - current_temp
P = Kp * error
I = Ki * integral(error)  [clamped to i_max]
D = Kd * derivative(error)
output = clamp(P + I + D, 0, 253)
```

Default PID values:
- Kp = 2.0
- Ki = 0.5
- Kd = 0.1
- i_max = 50

Target temperature = dew_point + margin
