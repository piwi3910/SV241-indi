# SVBONY SV241 GPIO Pin Mapping

## Extracted from Ghidra Disassembly

This document contains the GPIO pin mapping extracted from the ESP32 firmware using Ghidra reverse engineering.

## DC Output GPIO Pins

The DC outputs are controlled via `FUN_400d5714(gpio_pin, state)` which is a wrapper for `gpio_set_level()`.

Based on the decompiled code from `FUN_400d1b2c` and `FUN_400d1bac`:

| Channel | Function | GPIO Pin (Hex) | GPIO Pin (Decimal) |
|---------|----------|---------------|-------------------|
| DC1 | DC Output 1 | 0x0D | **GPIO 13** |
| DC2 | DC Output 2 | 0x0C | **GPIO 12** |
| DC3 | DC Output 3 | 0x0E | **GPIO 14** |
| DC4 | DC Output 4 | 0x1B | **GPIO 27** |
| DC5 | DC Output 5 | 0x1A | **GPIO 26** |
| USB12 | USB Ports 1-2 | 0x13 | **GPIO 19** |
| USB345 | USB Ports 3-5 | 0x12 | **GPIO 18** |

## PWM Output GPIO Pins

The PWM outputs are controlled via `FUN_400d5e10(gpio_pin, ledc_channel)` which configures LEDC PWM.

Based on the decompiled code from `FUN_400d17fc`:

| Channel | Function | GPIO Pin (Hex) | GPIO Pin (Decimal) | LEDC Channel |
|---------|----------|---------------|-------------------|--------------|
| PWM13 | Adjustable Voltage | 0x19 | **GPIO 25** | Channel 1 |
| PWM14 | Dew Heater 1 | 0x21 | **GPIO 33** | Channel 2 |
| PWM15 | Dew Heater 2 | 0x20 | **GPIO 32** | Channel 3 |

## I2C Pins

From string analysis and ESP32 defaults:

| Function | GPIO Pin |
|----------|---------|
| SDA | **GPIO 21** (default) |
| SCL | **GPIO 22** (default) |

I2C Devices:
- **INA219** - Power monitor (address 0x40 typical)
- **SHT4x** - Temperature/humidity sensor (address 0x44 typical)

## UART Pins

| Function | GPIO Pin |
|----------|---------|
| TX | **GPIO 1** (default USB) |
| RX | **GPIO 3** (default USB) |

## Additional GPIO (from FUN_400d1724)

| Function | GPIO Pin (Hex) | GPIO Pin (Decimal) |
|----------|---------------|-------------------|
| Unknown (LED?) | 0x17 | **GPIO 23** |
| Unknown | 0x0F | **GPIO 15** |

## State Memory Structure

The firmware stores output states in a structure at `DAT_400d0024` with the following offsets:

| Offset | Function |
|--------|----------|
| 0x44 | DC1 state |
| 0x48 | DC2 state |
| 0x4C | DC3 state |
| 0x50 | DC4 state |
| 0x54 | DC5 state |
| 0x58 | USB12 state |
| 0x5C | USB345 state |
| 0x0C | PWM13 value |
| 0x10 | PWM14 value |
| 0x14 | PWM15 value |
| 0x18 | (additional PWM?) |
| 0x1C | (additional PWM?) |
| 0x20 | (additional PWM?) |

## Complete Pin Summary

```
ESP32 Pin Assignments for SV241:
================================

Digital Outputs (DC/USB):
  GPIO 12 - DC2
  GPIO 13 - DC1
  GPIO 14 - DC3
  GPIO 18 - USB345
  GPIO 19 - USB12
  GPIO 26 - DC5
  GPIO 27 - DC4

PWM Outputs (Dew Heaters):
  GPIO 25 - PWM13 (Variable Voltage)
  GPIO 32 - PWM15 (Dew Heater 2)
  GPIO 33 - PWM14 (Dew Heater 1)

I2C Bus:
  GPIO 21 - SDA
  GPIO 22 - SCL

Serial (USB):
  GPIO 1 - TX
  GPIO 3 - RX

Misc:
  GPIO 15 - Unknown
  GPIO 23 - Unknown (possibly status LED)
```

## Verification Notes

These pin mappings were extracted from:
1. Ghidra disassembly of `main.ino.bin`
2. Function `FUN_400d1b2c` - DC output control
3. Function `FUN_400d1bac` - GPIO initialization
4. Function `FUN_400d17fc` - PWM initialization
5. String analysis for I2C sensor references

The mappings should be verified against hardware before creating custom firmware.
