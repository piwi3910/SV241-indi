# SVBONY SV241 Serial Protocol Documentation

## Connection Parameters
- **Baudrate**: 115200
- **Data Bits**: 8
- **Parity**: None
- **Stop Bits**: 1

## Protocol Format

All commands follow a 6-byte structure:
```
[0x24] [0x06] [CMD_ID] [PARAM1] [PARAM2] [CHECKSUM]
```

### Byte Breakdown:
- **Byte 0**: `0x24` (36 decimal, '$' character) - Start marker
- **Byte 1**: `0x06` (6 decimal) - Fixed value
- **Byte 2**: Command ID
- **Byte 3**: Parameter 1 (channel/index)
- **Byte 4**: Parameter 2 (value/state)
- **Byte 5**: Checksum

### Checksum Calculation:
```
sum = byte[0] + byte[1] + byte[2] + byte[3] + byte[4]
if sum > 255:
    sum = sum % 255
checksum = sum
```

## Command Reference

### 1. Write DC Output State
**Function**: Turn DC outputs ON/OFF

**Command Format**:
```
[0x24] [0x06] [0x01] [INDEX] [STATE] [CHECKSUM]
```

- **CMD_ID**: `0x01`
- **INDEX**: Channel index (0-6)
  - 0 = DC1 (physical channel 6)
  - 1 = DC2 (physical channel 7)
  - 2 = DC3 (physical channel 8)
  - 3 = DC4 (physical channel 9)
  - 4 = DC5 (physical channel 10)
  - 5 = USB C12 (physical channel 11)
  - 6 = USB 345 (physical channel 12)
- **STATE**:
  - `0x00` = OFF
  - `0xFF` (255) = ON

**Example** (Turn on DC1):
```
[0x24, 0x06, 0x01, 0x00, 0xFF, 0x2A]
```

**C# Code**:
```csharp
byte index = (byte)(channel - 6);  // channel is 6-12
byte[] cmd = new byte[] {
    0x24,
    0x06,
    0x01,
    index,
    state ? (byte)0xFF : (byte)0x00,
    0x2B + index  // Simplified checksum
};
serialPort.Write(cmd, 0, 6);
```

### 2. Write PWM Value
**Function**: Set PWM output (dew heaters)

**Command Format**:
```
[0x24] [0x06] [0x01] [INDEX] [VALUE] [CHECKSUM]
```

- **CMD_ID**: `0x01` (same as DC control)
- **INDEX**: PWM channel index
  - 7 = PWM13 (physical channel 13)
  - 8 = PWM14 (physical channel 14)
  - 9 = PWM15 (physical channel 15)
- **VALUE**: PWM value (0-253)
  - For PWM13: Voltage = (value * 15.3) / 253.0

**Example** (Set PWM13 to 127):
```
[0x24, 0x06, 0x01, 0x07, 0x7F, CHECKSUM]
```

**C# Code**:
```csharp
byte[] cmd = new byte[] { 0x24, 0x06, 0x01, 0x00, 0x00, 0x00 };
cmd[3] = (byte)(channel - 6);  // channel is 13-15
cmd[4] = (byte)raw;
cmd[5] = CalcChecksum(cmd);
serialPort.Write(cmd, 0, 6);
```

### 3. Read All Switch States
**Function**: Synchronize all DC and PWM states from device

**Command Format**:
```
[0x24] [0x06] [0x08] [0x00] [0x00] [CHECKSUM]
```

- **CMD_ID**: `0x08`
- **PARAM1**: `0x00`
- **PARAM2**: `0x00`

**Response**: 14 bytes
```
[0x24] [0x06] [0x08] [DC1] [DC2] [DC3] [DC4] [DC5] [USB12] [USB345] [PWM13] [PWM14] [PWM15] [CHECKSUM]
```

**Response Breakdown**:
- Byte 0-2: Header
- Byte 3-9: DC/USB states (0=OFF, 1=ON)
- Byte 10-12: PWM values (0-253)
- Byte 13: Checksum

**C# Code**:
```csharp
byte[] cmd = new byte[] { 0x24, 0x06, 0x08, 0x00, 0x00, 0x00 };
cmd[5] = CalcChecksum(cmd);
serialPort.DiscardInBuffer();
serialPort.Write(cmd, 0, 6);
Thread.Sleep(50);
byte[] buffer = new byte[14];
serialPort.Read(buffer, 0, 14);

// Parse response
for (int i = 0; i < 7; i++) {
    bool state = buffer[3 + i] > 0;
    // Update DC states
}

// PWM values at buffer[10], buffer[11], buffer[12]
```

### 4. Read Voltage Sensor
**Function**: Read input voltage

**Command Format**:
```
[0x24] [0x06] [0x03] [0x00] [0x00] [CHECKSUM]
```

- **CMD_ID**: `0x03`

**Response**: 8 bytes
```
[0x24] [0x06] [0x03] [DATA3] [DATA2] [DATA1] [DATA0] [CHECKSUM]
```

**Value Calculation**:
```
// Data is 4 bytes, big-endian (reverse byte order)
rawValue = Int32.FromBytes([DATA0, DATA1, DATA2, DATA3])
voltage = (rawValue / 100.0) + 0.0  // offset is 0.0
```

**C# Code**:
```csharp
byte[] cmd = new byte[] { 0x24, 0x06, 0x03, 0x00, 0x00, CHECKSUM };
serialPort.Write(cmd, 0, 6);
Thread.Sleep(50);
byte[] buffer = new byte[8];
serialPort.Read(buffer, 0, 8);
Array.Reverse(buffer, 3, 4);  // Reverse bytes 3-6
double voltage = BitConverter.ToInt32(buffer, 3) / 100.0;
```

### 5. Read Lens Temperature Sensor
**Function**: Read lens temperature

**Command Format**:
```
[0x24] [0x06] [0x04] [0x00] [0x00] [CHECKSUM]
```

- **CMD_ID**: `0x04`

**Response**: 8 bytes (same format as voltage)

**Value Calculation**:
```
rawValue = Int32.FromBytes([reversed])
temperature = (rawValue / 100.0) - 255.5  // offset is -255.5
```

### 6. Read Ambient Temperature Sensor
**Function**: Read ambient temperature

**Command Format**:
```
[0x24] [0x06] [0x05] [0x00] [0x00] [CHECKSUM]
```

- **CMD_ID**: `0x05`

**Response**: 8 bytes (same format)

**Value Calculation**:
```
rawValue = Int32.FromBytes([reversed])
temperature = (rawValue / 100.0) - 255.5
```

### 7. Read Humidity Sensor
**Function**: Read relative humidity

**Command Format**:
```
[0x24] [0x06] [0x06] [0x00] [0x00] [CHECKSUM]
```

- **CMD_ID**: `0x06`

**Response**: 8 bytes (same format)

**Value Calculation**:
```
rawValue = Int32.FromBytes([reversed])
humidity = (rawValue / 100.0) - 254.0  // offset is -254.0
```

### 8. Read Power Sensor
**Function**: Read power consumption

**Command Format**:
```
[0x24] [0x06] [0x07] [0x00] [0x00] [CHECKSUM]
```

- **CMD_ID**: `0x07`

**Response**: 8 bytes (same format)

**Value Calculation**:
```
rawValue = Int32.FromBytes([reversed])
power = (15.57 * (voltage * rawValue / 100.0) + 269.39) / 1000.0
```
Note: Requires voltage reading first!

## Command Summary Table

| Command | ID | Description | Response Size |
|---------|----|-----------|--------------:|
| Write DC/PWM | 0x01 | Set DC output or PWM value | None |
| Sync States | 0x08 | Read all states | 14 bytes |
| Read Voltage | 0x03 | Get input voltage | 8 bytes |
| Read Lens Temp | 0x04 | Get lens temperature | 8 bytes |
| Read Ambient Temp | 0x05 | Get ambient temperature | 8 bytes |
| Read Humidity | 0x06 | Get relative humidity | 8 bytes |
| Read Power | 0x07 | Get power consumption | 8 bytes |

## Channel Mapping

### DC Outputs (Channels 6-12)
- **Channel 6** (Index 0): DC1
- **Channel 7** (Index 1): DC2
- **Channel 8** (Index 2): DC3
- **Channel 9** (Index 3): DC4
- **Channel 10** (Index 4): DC5
- **Channel 11** (Index 5): USB C12 (USB ports 1-2)
- **Channel 12** (Index 6): USB 345 (USB ports 3-4-5)

### PWM Outputs (Channels 13-15)
- **Channel 13** (Index 7): PWM13 - Adjustable voltage output (0-15.3V)
- **Channel 14** (Index 8): PWM14 - Dew heater 1
- **Channel 15** (Index 9): PWM15 - Dew heater 2

## Implementation Notes

1. **Always wait 50-100ms** after sending a command before reading response
2. **Clear input buffer** before sending read commands: `serialPort.DiscardInBuffer()`
3. **Checksum is required** for all commands
4. **Sensor values are big-endian** (most significant byte first) - must reverse bytes
5. **Power calculation requires voltage** - read voltage first
6. Dew point is calculated locally, not read from device

## Dew Point Calculation (Local)
```
a = 17.62
b = 243.12
gamma = ln(humidity/100) + (a * temperature) / (b + temperature)
dewPoint = (b * gamma) / (a - gamma)
```

## Error Handling

- If `SerialPort.Read()` times out or returns incorrect data, sensor reading fails
- Response validation: Check if `buffer[2] == sensorId`
- All sensor read failures return `NaN` or show error message to user
