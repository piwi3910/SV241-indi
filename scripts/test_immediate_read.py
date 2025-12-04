#!/usr/bin/env python3
"""
Test immediate sensor reading via command - doesn't rely on background polling.
This tests whether the sensor commands properly trigger I2C reads.
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
    """Open serial port with settings to prevent ESP32 reset."""
    ser = serial.Serial()
    ser.port = port
    ser.baudrate = baudrate
    ser.timeout = 2
    ser.rtscts = False
    ser.dsrdtr = True

    ser.setDTR(False)
    ser.setRTS(False)
    ser.open()
    ser.setDTR(False)
    ser.setRTS(False)

    fd = ser.fileno()
    attrs = termios.tcgetattr(fd)
    attrs[2] = attrs[2] & ~termios.HUPCL
    termios.tcsetattr(fd, termios.TCSANOW, attrs)

    return ser


def send_command(ser, cmd_id, param1=0, param2=0, wait_ms=200):
    """Send a command and return the response"""
    cmd = bytes([0x24, 0x06, cmd_id, param1, param2])
    checksum = calc_checksum(cmd)
    cmd = cmd + bytes([checksum])

    if ser.in_waiting > 0:
        ser.read(ser.in_waiting)

    ser.write(cmd)
    time.sleep(wait_ms / 1000.0)

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

    print(f"Testing immediate sensor reads on {port}")
    print("=" * 60)

    try:
        ser = open_serial_no_reset(port)
        time.sleep(0.5)

        # Clear buffer
        if ser.in_waiting > 0:
            ser.read(ser.in_waiting)

        # Read voltage multiple times to see if values stabilize
        for i in range(10):
            print(f"\n[Read {i+1}] Voltage (0x03)")
            # First read after idle needs longer wait for recovery
            wait_time = 2000 if i == 0 else 200
            resp = send_command(ser, 0x03, wait_ms=wait_time)
            if resp:
                print(f"  Raw response: {resp.hex()}")
                if resp[0] == 0x24 and len(resp) >= 8:
                    raw = parse_sensor_value(resp, 3)
                    voltage = raw / 100.0 if raw else 0
                    print(f"  Voltage: {voltage:.2f}V (raw: {raw})")
                else:
                    print("  Invalid response format")
            else:
                print("  No response")

            time.sleep(0.5)

        ser.close()

    except serial.SerialException as e:
        print(f"Serial error: {e}")
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())
