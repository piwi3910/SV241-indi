#!/usr/bin/env python3
"""
Long-duration stress test for SV241 custom firmware I2C recovery.
Continuously polls sensors and reports any failures or recoveries.
"""
import serial
import sys
import time
import struct
import termios
from datetime import datetime


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
    """
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


def send_command(ser, cmd_id, param1=0, param2=0):
    """Send a command and return the response"""
    cmd = bytes([0x24, 0x06, cmd_id, param1, param2])
    checksum = calc_checksum(cmd)
    cmd = cmd + bytes([checksum])

    if ser.in_waiting > 0:
        ser.read(ser.in_waiting)

    ser.write(cmd)
    time.sleep(0.1)

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
    duration_minutes = int(sys.argv[2]) if len(sys.argv) > 2 else 10

    print(f"SV241 I2C Recovery Stress Test")
    print(f"Port: {port}")
    print(f"Duration: {duration_minutes} minutes")
    print("=" * 60)

    try:
        ser = open_serial_no_reset(port)
        time.sleep(0.5)

        if ser.in_waiting > 0:
            ser.read(ser.in_waiting)

        start_time = time.time()
        end_time = start_time + (duration_minutes * 60)

        poll_count = 0
        success_count = 0
        fail_count = 0
        recovery_count = 0
        last_was_failure = False

        print(f"\nStarted at {datetime.now().strftime('%H:%M:%S')}")
        print("Polling sensors every 500ms...")
        print("-" * 60)

        while time.time() < end_time:
            poll_count += 1
            all_ok = True
            readings = {}

            # Read voltage
            resp = send_command(ser, 0x03)
            if resp and len(resp) >= 8 and resp[0] == 0x24:
                raw = parse_sensor_value(resp, 3)
                readings['voltage'] = raw / 100.0 if raw else 0
            else:
                readings['voltage'] = None
                all_ok = False

            # Read temperature
            resp = send_command(ser, 0x05)
            if resp and len(resp) >= 8 and resp[0] == 0x24:
                raw = parse_sensor_value(resp, 3)
                readings['temp'] = (raw / 100.0) - 255.5 if raw else 0
            else:
                readings['temp'] = None
                all_ok = False

            # Read humidity
            resp = send_command(ser, 0x06)
            if resp and len(resp) >= 8 and resp[0] == 0x24:
                raw = parse_sensor_value(resp, 3)
                readings['humidity'] = (raw / 100.0) - 254.0 if raw else 0
            else:
                readings['humidity'] = None
                all_ok = False

            # Read power
            resp = send_command(ser, 0x07)
            if resp and len(resp) >= 8 and resp[0] == 0x24:
                raw = parse_sensor_value(resp, 3)
                readings['power'] = raw / 100.0 if raw else 0
            else:
                readings['power'] = None
                all_ok = False

            timestamp = datetime.now().strftime('%H:%M:%S')
            elapsed = int(time.time() - start_time)

            if all_ok:
                success_count += 1
                if last_was_failure:
                    recovery_count += 1
                    print(f"[{timestamp}] RECOVERED! V={readings['voltage']:.1f}V "
                          f"T={readings['temp']:.1f}C H={readings['humidity']:.0f}% "
                          f"P={readings['power']:.2f}W")
                elif poll_count % 20 == 0:  # Print status every 10 seconds
                    print(f"[{timestamp}] OK ({elapsed}s) V={readings['voltage']:.1f}V "
                          f"T={readings['temp']:.1f}C H={readings['humidity']:.0f}% "
                          f"P={readings['power']:.2f}W "
                          f"[{success_count}/{poll_count} polls]")
                last_was_failure = False
            else:
                fail_count += 1
                failed = [k for k, v in readings.items() if v is None]
                print(f"[{timestamp}] FAIL ({elapsed}s) - No response: {', '.join(failed)}")
                last_was_failure = True

            time.sleep(0.5)

        print("-" * 60)
        print(f"\nTest Complete at {datetime.now().strftime('%H:%M:%S')}")
        print(f"Duration: {duration_minutes} minutes")
        print(f"Total polls: {poll_count}")
        print(f"Successful: {success_count} ({100*success_count/poll_count:.1f}%)")
        print(f"Failed: {fail_count} ({100*fail_count/poll_count:.1f}%)")
        print(f"Recoveries: {recovery_count}")
        print("=" * 60)

        ser.close()

    except serial.SerialException as e:
        print(f"Serial error: {e}")
        return 1
    except KeyboardInterrupt:
        print("\n\nTest interrupted by user")
        print(f"Polls: {poll_count}, Success: {success_count}, Fail: {fail_count}, Recoveries: {recovery_count}")
        return 0

    return 0


if __name__ == "__main__":
    sys.exit(main())
