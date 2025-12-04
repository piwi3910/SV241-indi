# SV241 I2C Bus Lockup Issue Analysis

## Problem Description

The SV241 randomly starts returning zero values from sensors (voltage, temperature, humidity, power). Once this occurs, the device becomes unresponsive until physically unplugged and reconnected.

## Root Cause Analysis

### What's Happening

The SV241 has two I2C sensors on the same bus:
1. **INA219** - Power monitor (voltage/current)
2. **SHT4x** - Temperature/humidity sensor

When an I2C transaction is interrupted or a sensor becomes unresponsive, the I2C bus can enter a **locked state** where:
- The SDA (data) line is held LOW by a slave device
- The master cannot initiate new transactions
- All subsequent reads return 0x00 or 0xFF

### Why It Happens

Common triggers for I2C bus lockup:
1. **Electrical noise** on the I2C lines (common in astronomy setups with motors, dew heaters)
2. **Clock stretching timeout** - sensor holds SCL low too long
3. **Interrupted transaction** - power glitch during read/write
4. **Sensor internal error** - SHT4x or INA219 firmware bug
5. **EMI from PWM signals** - dew heater PWM bleeding into I2C lines

### Firmware Deficiency

Based on the string analysis, the SV241 firmware:
- ✅ Has `i2c_driver_install` and `i2c_driver_delete`
- ✅ Has `i2c_reset_rx_fifo` and `i2c_reset_tx_fifo`
- ✅ Has `i2c_set_timeout`
- ❌ **No evidence of I2C bus recovery routine**
- ❌ **No automatic sensor re-initialization on failure**
- ❌ **No watchdog to detect stuck I2C state**

## The Missing Recovery Code

A proper I2C bus recovery should include:

```cpp
// This is what SHOULD be in the firmware but likely isn't
void i2c_bus_recovery() {
    // 1. Release I2C driver
    i2c_driver_delete(I2C_NUM_0);

    // 2. Toggle SCL line 9+ times to clear stuck slave
    gpio_set_direction(SCL_PIN, GPIO_MODE_OUTPUT);
    for (int i = 0; i < 9; i++) {
        gpio_set_level(SCL_PIN, 0);
        delayMicroseconds(5);
        gpio_set_level(SCL_PIN, 1);
        delayMicroseconds(5);
    }

    // 3. Generate STOP condition
    gpio_set_direction(SDA_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(SDA_PIN, 0);
    delayMicroseconds(5);
    gpio_set_level(SCL_PIN, 1);
    delayMicroseconds(5);
    gpio_set_level(SDA_PIN, 1);

    // 4. Re-initialize I2C driver
    i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);

    // 5. Re-initialize sensors
    ina219_init();
    sht4x_init();
}
```

## Workarounds

### Software Workaround (In Your INDI Driver)

You can detect and handle this in your INDI driver:

```cpp
// In your sensor polling routine
double voltage = readVoltage();
double temp = readTemperature();
double humidity = readHumidity();

// Detect stuck state
static int zeroReadCount = 0;
if (voltage == 0 && temp == 0 && humidity == 0) {
    zeroReadCount++;
    if (zeroReadCount >= 3) {
        LOG_WARN("Sensor readings stuck at zero - I2C bus may be locked");
        LOG_WARN("Device may need power cycle to recover");
        // Could implement automatic reconnect here
        zeroReadCount = 0;
    }
} else {
    zeroReadCount = 0;
}
```

### Hardware Workarounds

1. **Add I2C bus isolator/buffer**
   - Use a PCA9517 or similar I2C buffer IC
   - Provides electrical isolation and helps with bus recovery

2. **Add ferrite beads**
   - Place ferrite beads on I2C lines near the ESP32
   - Reduces EMI from PWM/motor noise

3. **Improve I2C pull-ups**
   - Factory pull-ups may be too weak
   - Try adding external 2.2kΩ pull-ups to 3.3V on SDA and SCL

4. **USB power isolator**
   - Some USB hubs can inject noise
   - Use a USB isolator between computer and SV241

### Firmware Fix (If You Want to Create Custom Firmware)

I can help you create replacement Arduino firmware that includes:
1. Proper I2C bus recovery
2. Automatic sensor re-initialization on failure
3. Watchdog timer to detect and recover from hangs
4. Better error reporting via serial protocol

## Recommended Solution Priority

1. **Immediate**: Add detection logic in INDI driver to alert user
2. **Short-term**: Try hardware workarounds (ferrite beads, pull-ups)
3. **Long-term**: Create custom firmware with proper recovery

## Custom Firmware Approach

If you want to go the custom firmware route, I can help create a drop-in replacement that:

1. Uses the exact same serial protocol (compatible with existing apps)
2. Adds I2C bus recovery routine
3. Adds automatic sensor retry on failure
4. Adds periodic watchdog ping to detect lockups
5. Implements proper error responses instead of zeros

### Required Information for Custom Firmware

To create custom firmware, we need to determine:
1. **GPIO pin mapping** - Which ESP32 pins control which outputs
2. **I2C addresses** - INA219 (usually 0x40) and SHT4x (usually 0x44)
3. **PWM configuration** - Frequency, resolution, channels

Options to get this info:
- Hardware probing with multimeter/oscilloscope
- Full Ghidra disassembly of firmware
- Contact SVBONY for technical documentation

## Testing the Issue

To confirm this is I2C lockup:

```python
#!/usr/bin/env python3
# Test script to detect I2C lockup pattern
import serial
import time

def read_sensors(port):
    ser = serial.Serial(port, 115200, timeout=1)

    # Read voltage (CMD 0x03)
    cmd = bytes([0x24, 0x06, 0x03, 0x00, 0x00, 0x2D])
    ser.write(cmd)
    time.sleep(0.1)
    resp = ser.read(8)

    if len(resp) == 8:
        # Check for all-zero payload (bytes 3-6)
        if resp[3:7] == bytes([0,0,0,0]):
            return "ZERO_READING"
        return "OK"
    return "NO_RESPONSE"

if __name__ == "__main__":
    import sys
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/ttyUSB0"

    zero_count = 0
    for i in range(100):
        result = read_sensors(port)
        print(f"Read {i}: {result}")
        if result == "ZERO_READING":
            zero_count += 1
            if zero_count >= 3:
                print("I2C BUS LOCKUP DETECTED!")
                break
        else:
            zero_count = 0
        time.sleep(1)
```

## Conclusion

The random zero readings are almost certainly caused by I2C bus lockup, which is a **known issue with ESP32 I2C implementation** especially in electrically noisy environments. The firmware lacks proper bus recovery, so the only solution currently is power cycling.

The best long-term fix is custom firmware with proper I2C error handling.
