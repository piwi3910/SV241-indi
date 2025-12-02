# SVBONY SV241 Reverse Engineering Guide

## Overview
This guide will help you capture and analyze the serial protocol used by the SVBONY SV241 powerbox to create INDI drivers.

## What We Know So Far

### From Desktop App Analysis
- **Application**: .NET 6 Windows Desktop App
- **Serial Library**: System.IO.Ports
- **Key Methods Found**:
  - `ReadPowerSensor`
  - `ReadVoltageSensor`
  - `ReadTemperatureSensor`
  - `ReadHumiditySensor`
  - `ReadLensTSensor`
  - `WritePWM` (channels 13, 14, 15)
  - `WriteDCState`
  - `SendAndReceive`
  - `SyncAllSwitchStates`

### Expected Protocol (based on similar devices)
- **Baudrate**: Likely 115200 or 9600
- **Format**: Could be text-based (JSON/ASCII) or binary
- **Features**:
  - DC output control (multiple channels)
  - PWM control for dew heaters
  - Sensor readings (voltage, current, temperature, humidity)
  - USB hub control

## Step-by-Step Capture Process

### Method 1: Direct Sniffing (Recommended)

1. **Connect your SV241 to your computer**
   - Note which COM port it uses (e.g., COM3)

2. **Run the sniffer BEFORE starting the SVBONY app**
   ```bash
   python serial_proxy.py sniff COM3 115200
   ```

3. **Start the SVBONY desktop app**
   - The app should connect to the device
   - The sniffer will capture all communication

4. **Perform various operations**:
   - Read sensor values (click "Read Sensors")
   - Toggle DC outputs on/off
   - Adjust PWM sliders
   - Switch between different tabs/views

5. **Stop the sniffer (Ctrl+C)**
   - It will save everything to `serial_sniff_YYYYMMDD_HHMMSS.txt`

### Method 2: Using COM0COM (Advanced)

If direct sniffing doesn't work (app locks the port):

1. **Install com0com**
   - Download from: https://sourceforge.net/projects/com0com/
   - Create a virtual COM port pair (e.g., COM10 <-> COM11)

2. **Set up the proxy**
   ```bash
   python serial_proxy.py proxy COM3 COM10 115200
   ```

3. **Configure the SVBONY app to use COM11**
   - The proxy will forward traffic and log everything

## Analyzing the Captured Data

### Automatic Analysis
```bash
python analyze_protocol.py serial_sniff_YYYYMMDD_HHMMSS.txt
```

This will:
- Parse all messages
- Identify patterns
- Detect protocol type (text/binary/JSON)
- Show command/response pairs

### Manual Analysis

Look for:

1. **Message Structure**
   - Start/end markers
   - Fixed vs variable length
   - Delimiters (newline, null bytes, etc.)

2. **Command Patterns**
   - How are different operations encoded?
   - What's the difference between "turn on DC1" vs "turn on DC2"?
   - How are PWM values encoded?

3. **Response Format**
   - Fixed or variable length?
   - Status codes or full data?
   - Binary vs text encoding

4. **Protocol Type Detection**
   ```
   Text/JSON:     {"command": "read_sensors"}
   Binary:        0xAA 0x55 0x01 0x03 ...
   AT-style:      AT+READ=SENSORS\r\n
   ```

## Expected Scenarios

### Scenario A: JSON Protocol (like SV241-Unbound)
- Commands: `{"set": {"d1": 1}}` (turn on DC1)
- Response: `{"d1": 1, "voltage": 12.5, ...}`
- Easy to implement!

### Scenario B: Binary Protocol
- Commands: Byte sequences with opcodes
- Example: `[0xAA, 0x01, 0x01, 0xAC]` = turn on DC1
- Need to map each byte's meaning

### Scenario C: AT-Command Style
- Commands: `AT+DC1=1\r\n`
- Response: `OK\r\n` or `+VOLTAGE:12.5\r\n`

## Testing Different Baudrates

If 115200 doesn't work, try:
```bash
for baud in 9600 19200 38400 57600 115200; do
    echo "Testing $baud"
    python serial_proxy.py sniff COM3 $baud
    # Press Ctrl+C after a few seconds
done
```

## Creating the INDI Driver

Once you understand the protocol:

1. **Document all commands** (I'll help with this)
2. **Create INDI driver skeleton**
3. **Implement serial communication**
4. **Map INDI properties to SV241 commands**
5. **Test with INDI clients**

## Troubleshooting

### App won't connect when sniffer is running
- The port is locked by the sniffer
- Use Method 2 (COM0COM proxy) instead

### No data captured
- Wrong COM port
- Wrong baudrate
- Check if device is powered on
- Try running sniffer as Administrator

### Data looks corrupted
- Wrong baudrate (most common)
- Incorrect parity/stop bits settings
- Try different baudrate values

## Next Steps

1. **Run the capture** using Method 1
2. **Share the log file** with me
3. **I'll analyze the protocol** and document it
4. **We'll create the INDI driver** together

## Tools Created

- `serial_proxy.py` - Capture serial traffic
- `analyze_protocol.py` - Parse and analyze captured data
- `extract_strings.py` - Extract strings from DLL (already done)

## Reference Information

- Desktop app location: `new-svbonyhubControl 1.5-eng/`
- Expected features: DC outputs, PWM heaters, sensors (V/I/T/H)
- Similar devices use: 115200 baud, JSON or binary protocols
