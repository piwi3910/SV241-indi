#!/usr/bin/env python3
"""
Comprehensive test of the custom SV241 firmware.
Tests all commands and verifies responses.

IMPORTANT: Uses special serial port settings to prevent ESP32 reset on close.
"""
import serial
import sys
import time
import struct
import termios


def calc_checksum(data):
    """Calculate checksum (sum of bytes mod 255)"""
    s = sum(data)
    if s > 255:
        s = s % 255
    return s


def open_serial_no_reset(port, baudrate=115200):
    """
    Open serial port with settings to prevent ESP32 reset on open/close.
    - Disables HUPCL to prevent DTR drop on close
    - Disables DTR/RTS to prevent reset signals
    - Uses dsrdtr=True and rtscts=False per ESP32 forum recommendations
    """
    ser = serial.Serial()
    ser.port = port
    ser.baudrate = baudrate
    ser.timeout = 2
    ser.rtscts = False  # Disable RTS/CTS hardware flow control
    ser.dsrdtr = True   # This combo prevents reset on close per ESP32 forum

    # Set DTR/RTS before opening
    ser.setDTR(False)
    ser.setRTS(False)

    # Open the port
    ser.open()

    # Explicitly set DTR/RTS low after opening
    ser.setDTR(False)
    ser.setRTS(False)

    # Get current termios settings and disable HUPCL
    # This prevents DTR drop on close which would reset the ESP32
    fd = ser.fileno()
    attrs = termios.tcgetattr(fd)
    attrs[2] = attrs[2] & ~termios.HUPCL  # c_cflag &= ~HUPCL
    termios.tcsetattr(fd, termios.TCSANOW, attrs)

    return ser


def send_command(ser, cmd_id, param1=0, param2=0):
    """Send a command and return the response"""
    cmd = bytes([0x24, 0x06, cmd_id, param1, param2])
    checksum = calc_checksum(cmd)
    cmd = cmd + bytes([checksum])

    # Clear any pending data
    if ser.in_waiting > 0:
        ser.read(ser.in_waiting)

    ser.write(cmd)
    time.sleep(0.3)

    if ser.in_waiting > 0:
        return ser.read(ser.in_waiting)
    return None


def parse_sensor_value(data, offset=0):
    """Parse a 4-byte big-endian value from response data"""
    if len(data) < 4 + offset:
        return None
    value = struct.unpack('>i', data[offset:offset+4])[0]
    return value


def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/cu.usbserial-1133440"

    print(f"Testing custom SV241 firmware on {port}")
    print("(Using HUPCL-disabled serial to prevent ESP32 reset)")
    print("=" * 60)

    try:
        ser = open_serial_no_reset(port)
        time.sleep(0.5)

        # Clear any boot messages
        if ser.in_waiting > 0:
            ser.read(ser.in_waiting)

        # Test 1: Sync States (0x08)
        print("\n[Test 1] Sync States Command (0x08)")
        resp = send_command(ser, 0x08)
        if resp:
            print(f"  Response: {resp.hex()}")
            if resp[0] == 0x24 and resp[1] == 14:
                print("  ✓ Valid response format")
                states = resp[3:13]
                print(f"  DC: DC1={states[0]} DC2={states[1]} DC3={states[2]} "
                      f"DC4={states[3]} DC5={states[4]}")
                print(f"  USB: USB12={states[5]} USB345={states[6]}")
                print(f"  PWM: PWM13={states[7]} PWM14={states[8]} PWM15={states[9]}")
            else:
                print("  ✗ Invalid response format")
        else:
            print("  ✗ No response")

        time.sleep(0.3)

        # Test 2: Read Voltage (0x03)
        print("\n[Test 2] Read Voltage Command (0x03)")
        resp = send_command(ser, 0x03)
        if resp:
            print(f"  Response: {resp.hex()}")
            if resp[0] == 0x24 and len(resp) >= 8:
                raw_value = parse_sensor_value(resp, 3)
                voltage = raw_value / 100.0 if raw_value else 0
                print(f"  ✓ Input Voltage: {voltage:.2f}V (raw: {raw_value})")
            else:
                print("  ✗ Invalid response format")
        else:
            print("  ✗ No response")

        time.sleep(0.3)

        # Test 3: Read Ambient Temperature (0x05)
        print("\n[Test 3] Read Ambient Temperature Command (0x05)")
        resp = send_command(ser, 0x05)
        if resp:
            print(f"  Response: {resp.hex()}")
            if resp[0] == 0x24 and len(resp) >= 8:
                raw_value = parse_sensor_value(resp, 3)
                temp = (raw_value / 100.0) - 255.5 if raw_value else 0
                print(f"  ✓ Ambient Temp: {temp:.1f}°C (raw: {raw_value})")
            else:
                print("  ✗ Invalid response format")
        else:
            print("  ✗ No response")

        time.sleep(0.3)

        # Test 4: Read Humidity (0x06)
        print("\n[Test 4] Read Humidity Command (0x06)")
        resp = send_command(ser, 0x06)
        if resp:
            print(f"  Response: {resp.hex()}")
            if resp[0] == 0x24 and len(resp) >= 8:
                raw_value = parse_sensor_value(resp, 3)
                humidity = (raw_value / 100.0) - 254.0 if raw_value else 0
                print(f"  ✓ Humidity: {humidity:.1f}% (raw: {raw_value})")
            else:
                print("  ✗ Invalid response format")
        else:
            print("  ✗ No response")

        time.sleep(0.3)

        # Test 5: Read Power (0x07)
        print("\n[Test 5] Read Power Command (0x07)")
        resp = send_command(ser, 0x07)
        if resp:
            print(f"  Response: {resp.hex()}")
            if resp[0] == 0x24 and len(resp) >= 8:
                raw_value = parse_sensor_value(resp, 3)
                power = raw_value / 100.0 if raw_value else 0
                print(f"  ✓ Power: {power:.2f}W (raw: {raw_value})")
            else:
                print("  ✗ Invalid response format")
        else:
            print("  ✗ No response")

        time.sleep(0.3)

        # Test 6: Write Output (0x01) - Toggle DC1 on then off
        print("\n[Test 6] Write Output Command (0x01) - Toggle DC1")

        # Turn DC1 ON
        send_command(ser, 0x01, 0, 1)  # index=0 (DC1), value=1 (ON)
        print("  Turn DC1 ON command sent")

        time.sleep(0.3)

        # Check state
        resp = send_command(ser, 0x08)
        if resp and len(resp) >= 4:
            print(f"  State after ON: DC1={resp[3]} (expected: 1)")
        else:
            print("  Could not read state")

        time.sleep(0.3)

        # Turn DC1 OFF
        send_command(ser, 0x01, 0, 0)  # index=0 (DC1), value=0 (OFF)
        print("  Turn DC1 OFF command sent")

        time.sleep(0.3)

        # Check state again
        resp = send_command(ser, 0x08)
        if resp and len(resp) >= 4:
            print(f"  State after OFF: DC1={resp[3]} (expected: 0)")
        else:
            print("  Could not read state")

        print("\n" + "=" * 60)
        print("Custom firmware test complete!")
        print("=" * 60)

        ser.close()

    except serial.SerialException as e:
        print(f"Serial error: {e}")
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())
