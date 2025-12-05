# SVBONY SV241 INDI Driver User Guide

This guide provides comprehensive documentation for the SVBONY SV241 Powerbox INDI driver interface. The driver supports both the standard SVBONY firmware and the extended custom firmware with advanced features.

## Table of Contents

1. [Main Control Tab](#1-main-control-tab)
2. [General Info Tab](#2-general-info-tab)
3. [Options Tab](#3-options-tab)
4. [Connection Tab](#4-connection-tab)
5. [Sensors Tab](#5-sensors-tab)
6. [Dew Control Tab](#6-dew-control-tab)
7. [Statistics Tab](#7-statistics-tab)
8. [Diagnostics Tab](#8-diagnostics-tab)
9. [Calibration Tab](#9-calibration-tab)
10. [Alerts Tab](#10-alerts-tab)
11. [Port Labels Tab](#11-port-labels-tab)
12. [Profiles Tab](#12-profiles-tab)
13. [Timers Tab](#13-timers-tab)
14. [Safety Tab](#14-safety-tab)

---

## 1. Main Control Tab

![Main Control Tab](../pics/Screenshot%202025-12-05%20at%2011.37.06.png)

The Main Control tab provides direct control over all power outputs on the SV241 powerbox.

### Connection
- **Connect/Disconnect**: Establishes or terminates the connection to the SV241 device. The status indicator (green = connected, gray = disconnected) shows the current state.

### DC Outputs (DC1-DC5)
Five independent 12V DC power outputs for powering astronomy equipment.

| Output | Typical Use |
|--------|-------------|
| DC1 | Mount |
| DC2 | Camera |
| DC3 | Focuser |
| DC4 | Filter Wheel |
| DC5 | Guide Camera |

- **On**: Enables the DC output (provides 12V power)
- **Off**: Disables the DC output (cuts power)

**Usage**: Click "On" to power a device, "Off" to cut power. Use these to remotely control power to your equipment without physical access.

### USB Outputs
- **USB 1-2**: Controls power to USB ports 1 and 2 as a group
- **USB 3-4-5**: Controls power to USB ports 3, 4, and 5 as a group

**Usage**: Toggle On/Off to enable or disable USB power. Useful for power-cycling USB devices that become unresponsive.

### PWM Outputs
Variable power outputs using Pulse Width Modulation (0-253 range).

| Output | Function | Description |
|--------|----------|-------------|
| PWM13 | Adjustable Voltage | Variable voltage output (see PWM13 Voltage below) |
| PWM14 | Dew Heater 1 | First dew heater channel |
| PWM15 | Dew Heater 2 | Second dew heater channel |

- **Value (0-253)**: Enter a value from 0 (off) to 253 (maximum power)
- **Set**: Click to apply the entered value

**PWM13 Voltage**: Read-only display showing the actual output voltage of PWM13, calculated from the PWM value. The voltage ranges from 0V (PWM=0) to approximately 12V (PWM=253).

**Usage**:
- For dew heaters, start with a low value (50-100) and increase if needed
- Higher values = more heat = more power consumption
- Monitor your equipment temperature to find the optimal setting

---

## 2. General Info Tab

![General Info Tab](../pics/Screenshot%202025-12-05%20at%2011.37.27.png)

The General Info tab displays driver identification information.

### Driver Info
| Field | Description |
|-------|-------------|
| **Name** | Device name as registered in INDI (SVBONY SV241) |
| **Exec** | Executable name of the driver (indi_sv241) |
| **Version** | Driver version number (1.0) |
| **Interface** | INDI interface bitmask (32768 = AUX_INTERFACE) |

**Usage**: This tab is informational only. Use it to verify you're running the correct driver version when troubleshooting.

---

## 3. Options Tab

![Options Tab](../pics/Screenshot%202025-12-05%20at%2011.37.41.png)

The Options tab provides driver configuration settings and firmware information.

### Debug
- **Enable/Disable**: Toggles verbose debug logging
- When enabled, detailed communication logs are written to the INDI log

**Usage**: Enable only when troubleshooting issues. Debug mode generates significant log output.

### Simulation
- **Enable/Disable**: Toggles simulation mode
- When enabled, the driver simulates device responses without actual hardware

**Usage**: Use for testing your setup without physical hardware connected.

### Configuration
- **Load**: Loads previously saved driver configuration
- **Save**: Saves current driver settings to configuration file
- **Default**: Resets all settings to factory defaults
- **Purge**: Deletes saved configuration file

**Usage**: Save your configuration after setting up the driver to restore settings on next connection.

### Polling
- **Period (ms)**: How often the driver queries the device for sensor updates
- Default: 1000ms (1 second)
- Range: 100-10000ms

**Usage**: Lower values = more responsive updates but higher CPU/communication load. 1000ms is recommended for most users.

### Firmware (Extended Firmware Only)
- **Version**: Firmware identifier (e.g., "SV241-EXT" for extended firmware)
- **Capabilities**: List of supported extended features

**Capabilities explained**:
| Capability | Description |
|------------|-------------|
| dew | Automatic dew control |
| stats | Session statistics tracking |
| alerts | Voltage and thermal alerts |
| cal | Sensor calibration |
| profiles | Equipment profiles |
| timers | Scheduled actions |
| temp_rate | Temperature change rate monitoring |
| watchdog | Connection watchdog safety |
| current_alert | Over-current protection |
| boot_profile | Auto-load profile on power-up |
| persistent_stats | Statistics survive reboot |

---

## 4. Connection Tab

![Connection Tab](../pics/Screenshot%202025-12-05%20at%2011.37.53.png)

The Connection tab configures the serial port connection to the SV241.

### Connection
- **Port**: The serial port device path where the SV241 is connected

**Common port paths**:
| Platform | Example Path |
|----------|--------------|
| Linux | /dev/ttyUSB0, /dev/ttyUSB1 |
| macOS | /dev/cu.usbserial-XXXXX |
| Windows (via WSL) | /dev/ttyS0 |

**Usage**:
1. Connect the SV241 via USB
2. Enter the correct port path (check `ls /dev/ttyUSB*` on Linux)
3. Click "Set" to save
4. Go to Main Control tab and click "Connect"

**Tip**: If connection fails, verify:
- The correct port is selected
- You have permission to access the port (`sudo usermod -a -G dialout $USER`)
- No other application is using the port

---

## 5. Sensors Tab

![Sensors Tab](../pics/Screenshot%202025-12-05%20at%2011.38.05.png)

The Sensors tab displays real-time environmental and power readings from the SV241's onboard sensors.

### Voltage
- **Input (V)**: Current input voltage from your power supply
- Normal range: 11.5V - 14.5V for 12V systems

**Usage**: Monitor to ensure your power supply is providing adequate voltage. Low voltage can cause equipment malfunction.

### Power
- **Power (W)**: Total power consumption of all connected devices
- Calculated from voltage and current measurements

**Usage**: Track power usage to ensure you don't exceed your power supply capacity.

### Ambient Temp
- **Ambient (C)**: Air temperature measured by the onboard SHT4x sensor
- Used for dew point calculations

### Lens Temp
- **Lens (C)**: Temperature from external sensor (if connected)
- Typically placed on telescope optics to monitor for dewing

**Note**: If no external sensor is connected, this may show the same value as ambient temperature.

### Humidity
- **Humidity (%)**: Relative humidity measured by the SHT4x sensor
- Used for dew point calculations

### Dew Point (Extended Firmware)
- **Dew Point (C)**: Calculated temperature at which moisture will condense
- Formula: Based on ambient temperature and humidity

**Usage**: Compare dew point to lens temperature. If lens temp approaches dew point, increase dew heater power.

### Temp Change Rate (Extended Firmware)
- **Rate (C/hour)**: Rate at which temperature is changing
- Positive values = warming, Negative values = cooling

**Usage**: Helps predict when dewing might occur. Rapid cooling (negative rate) may require preemptive dew heater adjustment.

---

## 6. Dew Control Tab

![Dew Control Tab](../pics/Screenshot%202025-12-05%20at%2011.38.15.png)

The Dew Control tab provides automatic dew prevention settings (Extended Firmware only).

### Auto Dew CH14 / CH15
- **On**: Enables automatic dew control for this channel
- **Off**: Manual control only (use PWM values from Main Control)

**When Auto Dew is enabled**, the firmware automatically adjusts heater power to maintain lens temperature above the dew point.

### CH14/CH15 Margin
- **Margin (C)**: Temperature buffer above dew point
- Default: 3.0°C
- Range: 0-20°C

**How it works**: If dew point is 10°C and margin is 3°C, the system targets keeping the lens at 13°C or above.

**Usage**:
- Higher margin = more aggressive heating, more power consumption
- Lower margin = energy efficient but higher dewing risk
- 3-5°C is recommended for most conditions

### PID CH14 / PID CH15
PID (Proportional-Integral-Derivative) controller tuning for automatic dew control.

| Parameter | Description | Default | Range |
|-----------|-------------|---------|-------|
| **Kp** | Proportional gain - how aggressively to respond to temperature error | 2.0 | 0-10 |
| **Ki** | Integral gain - how quickly to correct persistent error | 0.1 | 0-5 |
| **Kd** | Derivative gain - dampens oscillation | 0.5 | 0-2 |

**Usage**: Default values work well for most setups. Only adjust if:
- Heater oscillates (temperature swings up and down) - reduce Kp
- Temperature doesn't reach target - increase Ki
- System overshoots target significantly - increase Kd

**Tip**: Most users should leave PID settings at defaults unless experienced with control systems.

---

## 7. Statistics Tab

![Statistics Tab](../pics/Screenshot%202025-12-05%20at%2011.38.27.png)

The Statistics tab tracks session metrics (Extended Firmware only).

### Voltage Stats
- **Min (V)**: Lowest voltage recorded this session
- **Max (V)**: Highest voltage recorded this session
- **Avg (V)**: Average voltage over the session

**Usage**: Check Min voltage to detect power supply sag under load.

### Power Stats
- **Peak (W)**: Maximum instantaneous power draw
- **Total (Wh)**: Cumulative energy consumed (Watt-hours)

**Usage**: Total Wh helps estimate battery life remaining when running on battery power.

### Temp Stats
- **Min (C)**: Coldest temperature recorded
- **Max (C)**: Warmest temperature recorded

**Usage**: Review after a session to understand temperature range your equipment experienced.

### Uptime
- **Uptime (s)**: Seconds since the device was powered on or statistics were reset

### Reset Statistics
- **Reset**: Clears all statistics and starts fresh

**Usage**: Click Reset at the start of each imaging session to track per-session metrics.

---

## 8. Diagnostics Tab

![Diagnostics Tab](../pics/Screenshot%202025-12-05%20at%2011.38.39.png)

The Diagnostics tab provides system health monitoring (Extended Firmware only).

### Alerts
Status indicators for system warnings:

| Alert | Green | Red |
|-------|-------|-----|
| **Low Voltage** | Voltage OK | Voltage below warning threshold |
| **Critical Voltage** | Voltage OK | Voltage below critical threshold |
| **Thermal** | Temperature OK | Overtemperature detected |
| **I2C Fail** | Sensors OK | Sensor communication failure |

### Diagnostics
- **Free Heap (bytes)**: Available memory on the ESP32 microcontroller
- Normal: >100,000 bytes
- If very low, the device may need a power cycle

### Sensor Status
Individual sensor health indicators:

| Sensor | Function |
|--------|----------|
| **I2C Bus** | Communication bus for sensors |
| **INA219** | Voltage/current sensor |
| **SHT4x** | Temperature/humidity sensor |

Green = OK, Red = Fault

### I2C Recovery
- **Recover**: Attempts to reset the I2C bus if sensors become unresponsive

**Usage**: Click if sensors show fault status. This performs a bus reset sequence to recover stuck sensors.

---

## 9. Calibration Tab

![Calibration Tab](../pics/Screenshot%202025-12-05%20at%2011.38.50.png)

The Calibration tab allows sensor offset adjustments (Extended Firmware only).

### Calibration
Apply correction offsets to sensor readings:

| Parameter | Description | Range |
|-----------|-------------|-------|
| **Voltage (V)** | Offset added to voltage reading | -2.0 to +2.0 |
| **Temperature (C)** | Offset added to temperature reading | -10.0 to +10.0 |
| **Humidity (%)** | Offset added to humidity reading | -20.0 to +20.0 |

**How to calibrate**:
1. Measure the actual value with a known-accurate reference instrument
2. Compare to the SV241 reading
3. Enter the difference as the offset
4. Click "Set" to apply

**Example**: If SV241 shows 12.5V but your multimeter shows 12.7V, enter +0.2 as voltage offset.

**Usage**: Calibration values are stored in the device and persist across power cycles.

---

## 10. Alerts Tab

![Alerts Tab](../pics/Screenshot%202025-12-05%20at%2011.39.00.png)

The Alerts tab configures warning and protection thresholds (Extended Firmware only).

### Alert Thresholds
| Parameter | Description | Default |
|-----------|-------------|---------|
| **Low V Threshold** | Voltage level for low voltage warning | 11.5V |
| **Critical V Threshold** | Voltage level for critical warning/action | 11.0V |
| **Reserved** | Reserved for future use | - |

### Low Voltage Alert
- **Enabled**: System will alert when voltage drops below Low V Threshold
- **Disabled**: No low voltage warnings

### Critical Voltage Alert
- **Enabled**: System will alert/act when voltage drops below Critical V Threshold
- **Disabled**: No critical voltage protection

### Auto-Off on Critical
- **Enabled**: Automatically turn off all outputs when critical voltage is reached
- **Disabled**: Alert only, no automatic action

**Usage**:
- Enable Auto-Off for battery operation to prevent deep discharge
- Set Critical V Threshold above your battery's minimum safe voltage
- Low V Threshold should be set higher as an early warning

**Recommended settings for 12V systems**:
- Low V Threshold: 11.5V (early warning)
- Critical V Threshold: 11.0V (protective shutdown)
- Auto-Off on Critical: Enabled for battery, Disabled for AC power supply

---

## 11. Port Labels Tab

![Port Labels Tab](../pics/Screenshot%202025-12-05%20at%2011.39.12.png)

The Port Labels tab allows customizing port names (Extended Firmware only).

### Port Names
Assign meaningful names to each output:

| Port | Default | Example Custom Name |
|------|---------|---------------------|
| DC1 | DC1 | Mount |
| DC2 | DC2 | Camera |
| DC3 | DC3 | Focuser |
| DC4 | DC4 | Filter Wheel |
| DC5 | DC5 | Guide Cam |
| USB12 | USB12 | USB Hub |
| USB345 | USB345 | Accessories |
| PWM13 | PWM13 | Adj Voltage |
| PWM14 | PWM14 | Primary Dew |
| PWM15 | PWM15 | Secondary Dew |

**Usage**:
1. Enter your custom name in the text field
2. Click "Set" to apply
3. Names are stored in the device and persist across sessions

**Tip**: Use descriptive names that match your equipment for easier identification during imaging sessions.

---

## 12. Profiles Tab

![Profiles Tab](../pics/Screenshot%202025-12-05%20at%2011.39.23.png)

The Profiles tab manages equipment configuration profiles (Extended Firmware only).

### Saved Profiles
Displays the 4 available profile slots:
- **Slot 0-3**: Shows profile name or "(empty)" if unused

### Load Profile
- **Load 0/1/2/3**: Instantly applies the saved profile's power states

**What gets loaded**: DC output states, PWM values, USB states

### Save Profile
- **Save to 0/1/2/3**: Saves current power configuration to selected slot

### Delete Profile
- **Delete 0/1/2/3**: Removes the profile from selected slot

### Save As
- **Profile Name**: Enter a descriptive name for the profile
- **Set**: Creates the profile with the specified name

### Active Profile
- **Active**: Shows which profile is currently loaded (-1 = none)

**Usage workflow**:
1. Configure all outputs for your imaging setup
2. Enter a name in "Profile Name" (e.g., "Deep Sky Setup")
3. Click "Save to 0" (or another empty slot)
4. Next session, click "Load 0" to restore all settings instantly

**Tip**: Create profiles for different equipment configurations:
- "Visual Only" - Mount + eyepiece heater
- "Imaging" - Full setup with camera, guide scope, dew heaters
- "Solar" - Daytime setup without dew heaters

---

## 13. Timers Tab

![Timers Tab](../pics/Screenshot%202025-12-05%20at%2011.39.32.png)

The Timers tab allows scheduling delayed power actions (Extended Firmware only).

### Active Timers
Displays up to 4 active timer slots showing:
- Port name and scheduled action
- Time remaining until execution

### Timer Configuration

#### Port
- **Port**: Target port for the action
- Valid values: dc1-dc5, usb12, usb345, pwm13, pwm14, pwm15

#### Action
- **On**: Turn the port on when timer expires
- **Off**: Turn the port off when timer expires
- **Set PWM**: Set a specific PWM value when timer expires

#### Delay
- **Minutes**: Time delay before action executes (1-1440 minutes / 24 hours max)

#### PWM Value
- **PWM Value**: Target value for "Set PWM" action (0-253)

### Create
- **Create Timer**: Creates the timer with current settings

### Cancel Timer
- **Cancel 1/2/3/4**: Cancels the corresponding active timer

**Usage examples**:

**Auto-shutdown after imaging**:
1. Port: dc1 (mount)
2. Action: Off
3. Delay: 180 (3 hours)
4. Click "Create Timer"

**Delayed warm-up**:
1. Port: pwm14 (dew heater)
2. Action: Set PWM
3. PWM Value: 150
4. Delay: 30 (30 minutes before session)
5. Click "Create Timer"

**Tip**: Timers survive the INDI driver disconnecting but are lost if the device loses power.

---

## 14. Safety Tab

![Safety Tab](../pics/Screenshot%202025-12-05%20at%2011.39.43.png)

The Safety tab provides watchdog and over-current protection (Extended Firmware only).

### Watchdog
A safety feature that takes action if the INDI driver loses connection.

#### Watchdog Enable
- **Enable**: Activates watchdog monitoring
- **Disable**: No automatic action on connection loss

#### Watchdog Timeout
- **Timeout (s)**: Seconds of no communication before action triggers
- Default: 60 seconds
- Set higher than your polling period

#### Watchdog Action
- **Alert Only**: Just set alert flag, no automatic action
- **All Off**: Turn off all outputs when triggered
- **Load Profile**: Load a safety profile when triggered

#### Safety Profile
- **Profile Slot**: Which profile to load for "Load Profile" action (0-3)

#### Watchdog Status
- **Triggered**: Indicator shows if watchdog has been triggered
- Green = OK, Red = Triggered

#### Time Remaining
- **Remaining (s)**: Countdown until watchdog triggers (-1 = disabled)

**Usage**: Enable watchdog for unattended operation to ensure equipment is safely powered down if your control computer crashes or loses network connection.

**Recommended setup**:
1. Create a "Safe" profile with all outputs off
2. Enable Watchdog
3. Set Timeout to 300 (5 minutes)
4. Set Action to "Load Profile"
5. Set Safety Profile to your "Safe" profile slot

### Current Alert
Protection against excessive current draw that could indicate a short circuit.

#### Current Alert Enable
- **Enable**: Activates over-current monitoring
- **Disable**: No current monitoring

#### Current Threshold
- **Threshold (A)**: Current level that triggers the alert
- Default: 5.0A
- Set below your power supply's maximum rating

#### Current Status
- **Over Current**: Indicator shows if current exceeds threshold
- Green = OK, Red = Over current

#### Current Draw
- **Current (A)**: Real-time current measurement

**Usage**: Enable current alert as protection against equipment faults. If a device shorts, the alert will warn you before potentially damaging your power supply.

**Recommended settings**:
- Calculate total expected current from all connected devices
- Set threshold 20-30% above expected maximum
- Example: If expecting 4A max, set threshold to 5A

---

## Appendix: Status Indicator Colors

Throughout the interface, colored indicators show status:

| Color | Meaning |
|-------|---------|
| Green | OK / On / Active |
| Gray | Idle / Off / Inactive |
| Yellow | Warning / Busy |
| Red | Alert / Error / Fault |

---

## Troubleshooting

### Cannot connect to device
1. Verify correct port in Connection tab
2. Check USB cable connection
3. Ensure no other application is using the port
4. Try unplugging and reconnecting USB

### Sensors show 0 or incorrect values
1. Check Diagnostics tab for sensor faults
2. Try I2C Recovery button
3. Power cycle the device

### Dew heaters not working
1. Verify PWM value is set (0 = off)
2. Check if Auto Dew is overriding manual values
3. Confirm heater is properly connected

### Extended features not showing
1. Verify "SV241-EXT" appears in Options > Firmware > Version
2. Standard firmware only supports basic features
3. Extended firmware required for Statistics, Profiles, Timers, Safety tabs

---

## Version History

- **v1.0** - Initial release with full extended firmware support

---

*Documentation generated for SVBONY SV241 INDI Driver v1.0*
*Compatible with Extended Firmware v2.3*
