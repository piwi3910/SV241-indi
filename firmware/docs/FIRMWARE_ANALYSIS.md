# SVBONY SV241 Firmware Analysis

## Overview

This document contains the analysis of the SV241 ESP32-based firmware extracted from the manufacturer's update tool.

## Firmware Files

| File | Size | Description |
|------|------|-------------|
| `main.ino.bin` | 307,056 bytes | Main application firmware |
| `main.ino.bootloader.bin` | 18,992 bytes | ESP32 bootloader |
| `main.ino.partitions.bin` | 3,072 bytes | Partition table |
| `main.exe` | 10,009,876 bytes | Windows flash/update utility |
| `config.json` | 331 bytes | Flash tool configuration |

## Firmware Details

### Build Information
- **Framework**: ESP-IDF v4.4.5
- **Arduino Core**: ESP32 Arduino Core 2.0.11
- **Build Tool**: arduino-lib-builder
- **Build Date**: June 12, 2023 at 16:41:45
- **Developer Path**: `C:\Users\26709\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.11`

### ESP32 Image Information
```
Image version: 1
Entry point: 0x40083278
Segments: 5
Flash size: 4MB
Flash freq: 80MHz
Flash mode: DIO
Chip: ESP32 (not ESP32-S2/S3/C3)
```

### Memory Segments
| Segment | Length | Load Address | Type |
|---------|--------|--------------|------|
| 0 | 0x0ed64 | 0x3f400020 | DROM (data ROM) |
| 1 | 0x0128c | 0x3ffbdb60 | DRAM |
| 2 | 0x292ec | 0x400d0020 | IROM (instruction ROM) |
| 3 | 0x02e78 | 0x3ffbedec | DRAM |
| 4 | 0x0edac | 0x40080000 | IRAM |

### Partition Table
| Name | Type | Offset | Size |
|------|------|--------|------|
| nvs | data | 0x9000 | 0x5000 (20KB) |
| otadata | data | 0xe000 | 0x2000 (8KB) |
| app0 | app | 0x10000 | 0x140000 (1.25MB) |
| app1 | app | 0x150000 | 0x140000 (1.25MB) |
| spiffs | data | 0x290000 | 0x160000 (1.375MB) |
| coredump | data | 0x3f0000 | 0x10000 (64KB) |

## Hardware Components Identified

### 1. INA219 Power Monitor
- **Function**: Input voltage and current measurement
- **Interface**: I2C
- **Firmware Messages**:
  - "Failed to find INA219 chip"
  - "Check INA219 timeout, break;"
- **Usage**: Monitors input power supply (12V input)

### 2. SHT4x Temperature/Humidity Sensor
- **Function**: Ambient temperature and humidity measurement
- **Interface**: I2C
- **Firmware References**:
  - `SHT4x_H` - Humidity reading
  - `SHT4x_T` - Temperature reading
- **Model**: Likely SHT40 or SHT41 (Sensirion)

### 3. UART Communication
- **Baud Rate**: 115200 (confirmed from protocol testing)
- **Interface**: USB via CH340 serial adapter
- **Firmware Functions**:
  - `uart_event_task` - Main UART handler
  - `uart_set_pin` - GPIO configuration
  - `uart_param_config` - UART parameters

### 4. PWM/LEDC Controller
- **Function**: PWM output for dew heaters and adjustable voltage
- **Framework**: ESP-IDF LEDC (LED Controller) peripheral
- **Channels**: 3 PWM outputs (PWM13, PWM14, PWM15)
- **Functions**:
  - `ledc_channel_config`
  - `ledc_set_duty`
  - `ledc_update_duty`
  - `ledc_timer_config`

### 5. GPIO Control
- **Function**: Digital output control for DC ports and USB
- **Channels**: 7 switchable outputs (DC1-DC5, USB12, USB345)
- **Functions**:
  - `gpio_set_level`
  - `gpio_set_direction`
  - `gpio_config`

## Application Logic

### Main Tasks Identified
1. **loopTask** - Main Arduino loop task
2. **uart_event_task** - Serial command handler
3. **TASK_SET_ALL_FORCE_ON** - Force all outputs ON
4. **TASK_SET_ALL_FORCE_OFF** - Force all outputs OFF

### Command Processing Flow
Based on string analysis:
1. UART receives 6-byte command packets
2. Commands parsed by command ID (byte 2)
3. Actions performed on GPIO/PWM/I2C peripherals
4. Responses sent back via UART

## Protocol Correlation

The firmware strings confirm the protocol documented in `SV241_PROTOCOL.md`:

| Feature | Firmware Evidence | Protocol Command |
|---------|------------------|------------------|
| DC Output Control | GPIO functions | CMD 0x01 |
| PWM Control | LEDC functions | CMD 0x01 (index 7-9) |
| Voltage Reading | INA219 chip | CMD 0x03 |
| Lens Temp | Not visible in strings | CMD 0x04 |
| Ambient Temp | SHT4x_T | CMD 0x05 |
| Humidity | SHT4x_H | CMD 0x06 |
| Power Reading | INA219 chip | CMD 0x07 |
| State Sync | UART task | CMD 0x08 |

## Potential Firmware Issues

### 1. INA219 Detection
The message "Failed to find INA219 chip" suggests the I2C scan may timeout if:
- I2C bus is not properly initialized
- INA219 chip address conflict
- I2C pull-up resistor issues

### 2. SHT4x Communication
Temperature/humidity readings may fail if:
- Sensor not connected or damaged
- I2C address conflict with INA219
- Calibration data corrupted

### 3. UART Communication
Potential issues:
- Buffer overflow in ring buffer handling
- Checksum validation errors
- Timing issues with 50ms response delay

## Recommendations for Fixing Firmware Issues

### Option 1: Re-flash Original Firmware
```bash
# Using esptool.py
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 460800 \
  write_flash \
  0x1000 main.ino.bootloader.bin \
  0x8000 main.ino.partitions.bin \
  0x10000 main.ino.bin
```

### Option 2: Create Custom Arduino Firmware
Since this is Arduino-based, you could create replacement firmware:

```cpp
// Required libraries
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <SensirionI2CSht4x.h>

// Pin definitions (need to reverse-engineer from hardware)
// Based on typical ESP32 dev board:
#define SDA_PIN 21
#define SCL_PIN 22
#define DC1_PIN 4   // Example, needs verification
#define DC2_PIN 5
// ... etc

// Protocol constants
#define CMD_WRITE_OUTPUT 0x01
#define CMD_READ_VOLTAGE 0x03
#define CMD_READ_LENS_TEMP 0x04
#define CMD_READ_AMBIENT_TEMP 0x05
#define CMD_READ_HUMIDITY 0x06
#define CMD_READ_POWER 0x07
#define CMD_SYNC_STATES 0x08
```

### Option 3: Debug Existing Firmware
Connect a serial monitor during boot to capture debug output:
```bash
screen /dev/ttyUSB0 115200
# or
minicom -D /dev/ttyUSB0 -b 115200
```

## True Decompilation

For full disassembly/decompilation of the ESP32 firmware, you would need:

1. **Ghidra** with Xtensa processor module:
   - Install Ghidra from https://ghidra-sre.org/
   - Add Xtensa language pack: https://github.com/Ebiroll/ghidra-xtensa
   - Load `main.ino.bin` with base address 0x40080000 (IRAM) or 0x400d0020 (IROM)

2. **IDA Pro** with ESP32 plugin:
   - Commercial tool with Xtensa support
   - Better ESP32/ESP-IDF recognition

3. **Radare2** with Xtensa support:
   ```bash
   r2 -a xtensa -b 32 -m 0x40080000 main.ino.bin
   ```

## GPIO Pin Mapping (To Be Determined)

The exact GPIO pin mapping needs to be determined either by:
1. Hardware tracing on the PCB
2. Full firmware disassembly
3. Probing with oscilloscope while sending commands

Typical ESP32 GPIO usage for similar devices:
| Function | Possible GPIO | Notes |
|----------|--------------|-------|
| UART TX | GPIO1 | USB serial TX |
| UART RX | GPIO3 | USB serial RX |
| I2C SDA | GPIO21 | INA219, SHT4x |
| I2C SCL | GPIO22 | INA219, SHT4x |
| DC1-DC5 | GPIO4,5,12,13,14 | Digital outputs |
| USB12 | GPIO15 | USB power group 1 |
| USB345 | GPIO16 | USB power group 2 |
| PWM13 | GPIO25 | Variable voltage |
| PWM14 | GPIO26 | Dew heater 1 |
| PWM15 | GPIO27 | Dew heater 2 |

## Conclusion

The SV241 uses a standard ESP32 running Arduino framework with ESP-IDF v4.4.5. The firmware implements a simple serial protocol with command/response structure. The main components are:

1. **INA219** for power monitoring
2. **SHT4x** for environmental sensing
3. **GPIO** for DC output switching
4. **LEDC/PWM** for dew heater control

The protocol is well-documented and working. If you're experiencing firmware issues, try:
1. Re-flashing the original firmware
2. Checking hardware connections (I2C bus, power supply)
3. Monitoring serial debug output during boot
