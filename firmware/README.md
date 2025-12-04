# SV241 Custom Firmware

Drop-in replacement firmware for the SVBONY SV241 Power Box that fixes critical bugs in the original firmware.

## Why This Firmware Was Created

### Bugs Found in Original SVBONY Firmware

During development of the INDI driver, we discovered several serious issues with the original SV241 firmware:

#### 1. I2C Bus Lockup (Critical)

The original firmware has no I2C bus recovery mechanism. The I2C bus can become locked due to:

- **Electrical noise** from dew heaters, motors, or mount slewing
- **Hot-plugging** sensors or cables
- **EMI interference** from nearby equipment
- **Power fluctuations** during high-current operations

**Symptoms:**
- All sensor readings suddenly return zero (voltage, temperature, humidity, power)
- The device becomes completely unresponsive to sensor queries
- Output controls (DC/PWM) continue to work, but sensors are dead
- **Only fix:** Physically unplug and replug the USB cable

This is a critical issue for astrophotography where the device may be mounted on a telescope and difficult to access during an imaging session.

#### 2. No Watchdog Timer

The original firmware lacks a hardware watchdog timer, meaning:
- If the firmware hangs for any reason, the device becomes a brick
- No automatic recovery from lockups
- Requires manual intervention (power cycle)

#### 3. ESP32 Reset on Serial Reconnection

When host software (INDI driver, Windows app) disconnects and reconnects:
- The USB-serial chip toggles DTR/RTS lines
- This triggers an ESP32 reset on most serial adapters
- **First sensor read after reconnection often fails** because the I2C bus needs reinitialization

#### 4. No On-Demand Recovery

The original firmware only reads sensors periodically in the background. If a sensor read fails:
- It simply returns stale/zero data
- No attempt to recover before responding
- Host software receives incorrect readings

## What This Firmware Fixes

### I2C Bus Recovery

Implements proper I2C bus recovery per the I2C specification:

1. **Detection:** Monitors for consecutive sensor read failures
2. **Clock cycling:** Sends 9 SCL pulses to release stuck slaves
3. **STOP condition:** Generates proper STOP to reset bus state
4. **Peripheral reset:** Uses ESP32's `periph_module_reset()` for hardware-level recovery
5. **Sensor reinitialization:** Reinitializes INA219 and SHT4x after recovery

### On-Demand Recovery

Each sensor read command now includes intelligent recovery:

```
Host requests voltage →
  If cached value is 0 or stale →
    Try fresh I2C read →
      If fails → Trigger bus recovery →
        Retry up to 3 times →
          Return best available data
```

This ensures the host always gets the most accurate reading possible.

### Startup I2C Reset

On boot, the firmware performs a full I2C peripheral reset:
- Clears any lingering `bus_busy` state from previous sessions
- Handles the DTR/RTS reset issue gracefully
- Ensures clean I2C state before first sensor read

### Watchdog Timer

Configurable hardware watchdog (default: 5 seconds):
- Automatically resets ESP32 if main loop hangs
- Prevents permanent lockups
- Note: Currently disabled due to ESP32 Arduino Core 3.x compatibility issues

## Pre-Built Firmware

A pre-compiled binary is included for easy flashing:

```
SV241_Custom/SV241_Custom.merged.bin
```

This is a "merged" binary containing bootloader + partition table + application, ready to flash at address 0x0.

## Flashing Instructions

### Option 1: Quick Flash (Pre-Built Binary)

Using `esptool` (recommended for reliability):

```bash
# Install esptool
pip install esptool

# Flash the pre-built binary (use --no-stub for reliability)
esptool --chip esp32 --port /dev/cu.usbserial-XXXX --baud 115200 --no-stub \
  write-flash 0x0 SV241_Custom/SV241_Custom.merged.bin
```

**Port names:**
- macOS: `/dev/cu.usbserial-*` or `/dev/cu.wchusbserial*`
- Linux: `/dev/ttyUSB0`
- Windows: `COM3` (check Device Manager)

**Note:** The `--no-stub` flag is important! Without it, esptool tries to upload a faster stub flasher which can fail on some USB-serial adapters.

### Option 2: Arduino IDE

1. **Install Arduino IDE** (2.0+ recommended)

2. **Install ESP32 Board Support:**
   - Go to File → Preferences
   - Add to "Additional Board Manager URLs":
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Go to Tools → Board → Boards Manager
   - Search "esp32" and install "ESP32 by Espressif Systems"

3. **Select Board:**
   - Tools → Board → ESP32 Arduino → "ESP32 Dev Module"

4. **Configure Settings:**
   - Flash Mode: DIO
   - Flash Size: 4MB (32Mb)
   - Partition Scheme: Default 4MB with spiffs
   - Upload Speed: 115200 (lower is more reliable)

5. **Open and Flash:**
   - Open `SV241_Custom/SV241_Custom.ino`
   - Select the correct COM port
   - Click Upload

### Option 3: Arduino CLI

```bash
# Install arduino-cli
brew install arduino-cli  # macOS
# or see https://arduino.github.io/arduino-cli/installation/

# Install ESP32 core
arduino-cli core install esp32:esp32

# Compile
arduino-cli compile --fqbn esp32:esp32:esp32 firmware/SV241_Custom

# Upload
arduino-cli upload -p /dev/cu.usbserial-XXXX --fqbn esp32:esp32:esp32 firmware/SV241_Custom
```

## Flashing Troubleshooting

### "Connecting..." hangs or times out

1. **Try lower baud rate:** Use `--baud 115200` instead of higher speeds
2. **Hold BOOT button:** On some ESP32 boards, hold BOOT while clicking upload
3. **Use `--no-stub`:** Add `--no-stub` flag to esptool command
4. **Check cable:** Some USB cables are charge-only without data lines
5. **Check driver:** Install CH340 or CP2102 driver if needed

### Upload starts but fails partway

1. **Use `--no-stub` flag:** Prevents baud rate changes during upload
2. **Try different USB port:** Some ports have power issues
3. **Shorter USB cable:** Long cables can cause signal integrity issues

### Device not detected

```bash
# macOS/Linux - list serial ports
ls /dev/cu.* /dev/tty.* 2>/dev/null

# Windows - check Device Manager → Ports (COM & LPT)
```

## Hardware Information

### ESP32-PICO-D4

The SV241 uses an ESP32-PICO-D4 module:
- Dual-core 240MHz processor
- 4MB embedded flash
- Built-in USB-serial converter

### Pin Mapping

| Function | GPIO | Notes |
|----------|------|-------|
| DC1 | 13 | 12V switchable output |
| DC2 | 12 | 12V switchable output |
| DC3 | 14 | 12V switchable output |
| DC4 | 27 | 12V switchable output |
| DC5 | 26 | 12V switchable output |
| USB12 | 19 | USB ports 1-2 power |
| USB345 | 18 | USB ports 3-4-5 power |
| PWM13 | 25 | Variable voltage 0-15.3V |
| PWM14 | 33 | Dew heater 1 (0-100%) |
| PWM15 | 32 | Dew heater 2 (0-100%) |
| I2C SDA | 21 | Sensor data |
| I2C SCL | 22 | Sensor clock |

### Sensors

- **INA219** (0x40): Voltage and current monitor
- **SHT4x** (0x44): Temperature and humidity sensor

## Serial Protocol

The firmware uses the exact same protocol as the original, ensuring compatibility with:
- SVBONY Windows application
- This INDI driver
- Any other software written for the original firmware

### Command Format (6 bytes)
```
[0x24] [0x06] [CMD_ID] [PARAM1] [PARAM2] [CHECKSUM]
```

### Response Format (variable length)
```
[0x24] [LENGTH] [CMD_ID] [DATA...] [CHECKSUM]
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

### Checksum Calculation

```python
def calc_checksum(data):
    s = sum(data)
    if s > 255:
        s = s % 255  # Note: mod 255, not 256!
    return s
```

**Important:** The protocol uses `sum % 255` (not `% 256`) when the sum exceeds 255. This is intentional device behavior.

## Debugging

Enable debug mode by setting `debugMode = true` in the source code:

```cpp
bool debugMode = true;  // Line ~103
```

Then open Serial Monitor at 115200 baud to see:

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
Initialization complete!
Ready for commands...
```

When I2C recovery occurs:
```
Performing I2C bus recovery...
  SDA released after 3 clocks
  After recovery - INA219: OK, SHT4x: OK
```

## Version History

### v1.1 (Current)
- On-demand I2C recovery in sensor read handlers
- Full I2C peripheral reset on startup
- Handles DTR/RTS serial reconnection issues
- Pre-built merged binary included

### v1.0
- Initial release
- I2C bus recovery implementation
- Watchdog timer (disabled in 1.1 due to ESP32 Core 3.x issues)
- Full protocol compatibility

## License

This firmware is provided for personal use with SVBONY SV241 hardware. Based on reverse engineering of the original firmware protocol.

## Contributing

Issues and improvements welcome! Please test thoroughly before submitting changes, especially:
- I2C recovery scenarios
- Serial reconnection behavior
- Long-duration stability (hours of operation)
