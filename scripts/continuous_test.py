#!/usr/bin/env python3
"""
Single-connection continuous test - keeps serial port open throughout.
Tests whether the issue is serial port close/reopen vs firmware stability.
"""
import serial
import sys
import time
import struct
import termios
from datetime import datetime


def calc_checksum(data):
    s = sum(data)
    if s > 255:
        s = s % 255
    return s


def open_serial_no_reset(port, baudrate=115200):
    """Open serial port with settings to prevent ESP32 issues."""
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


def send_command(ser, cmd_id, param1=0, param2=0, wait_ms=300):
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
    if len(data) < 4 + offset:
        return None
    value = struct.unpack('>i', data[offset:offset+4])[0]
    return value


def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/cu.usbserial-1133440"
    duration_seconds = int(sys.argv[2]) if len(sys.argv) > 2 else 60

    print(f"Continuous Test - Single Serial Connection")
    print(f"Port: {port}")
    print(f"Duration: {duration_seconds} seconds")
    print("=" * 60)

    try:
        ser = open_serial_no_reset(port)
        print(f"Serial port opened at {datetime.now().strftime('%H:%M:%S')}")
        time.sleep(0.5)

        if ser.in_waiting > 0:
            ser.read(ser.in_waiting)

        start_time = time.time()
        end_time = start_time + duration_seconds

        poll_count = 0
        success_count = 0
        fail_count = 0

        print(f"Starting continuous polling at {datetime.now().strftime('%H:%M:%S')}")
        print("-" * 60)

        # First command may trigger recovery - wait longer
        first_command = True

        while time.time() < end_time:
            poll_count += 1

            # Read voltage as simple test
            wait_time = 2000 if first_command else 300
            resp = send_command(ser, 0x03, wait_ms=wait_time)
            first_command = False

            timestamp = datetime.now().strftime('%H:%M:%S')
            elapsed = int(time.time() - start_time)

            if resp and len(resp) >= 8 and resp[0] == 0x24:
                raw = parse_sensor_value(resp, 3)
                voltage = raw / 100.0 if raw else 0
                success_count += 1

                if poll_count % 10 == 0:
                    print(f"[{timestamp}] OK ({elapsed}s) V={voltage:.2f}V [{success_count}/{poll_count}]")
            else:
                fail_count += 1
                print(f"[{timestamp}] FAIL ({elapsed}s) - No response")

            time.sleep(0.5)

        print("-" * 60)
        print(f"\nTest Complete at {datetime.now().strftime('%H:%M:%S')}")
        print(f"Serial connection kept open throughout")
        print(f"Total polls: {poll_count}")
        print(f"Successful: {success_count} ({100*success_count/poll_count:.1f}%)")
        print(f"Failed: {fail_count} ({100*fail_count/poll_count:.1f}%)")
        print("=" * 60)

        ser.close()
        print("Serial port closed")

    except serial.SerialException as e:
        print(f"Serial error: {e}")
        return 1
    except KeyboardInterrupt:
        print("\n\nTest interrupted")
        return 0

    return 0


if __name__ == "__main__":
    sys.exit(main())
