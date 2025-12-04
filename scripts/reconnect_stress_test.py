#!/usr/bin/env python3
"""
Aggressive reconnection stress test for SV241 firmware.
Simulates real INDI driver behavior: connect, poll heavily, disconnect, repeat.
Tries to trigger I2C lockups and verify the on-demand recovery handles them.
"""
import serial
import sys
import time
import struct
import termios
import random
from datetime import datetime


def calc_checksum(data):
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


def send_command(ser, cmd_id, param1=0, param2=0, wait_ms=100):
    """Send command and return response."""
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


def run_session(ser, session_num, polls_per_session):
    """Run a single polling session, return (success_count, fail_count, zero_count)."""
    success = 0
    fail = 0
    zero_readings = 0

    for poll in range(polls_per_session):
        # Randomly choose which sensor to read (simulates real driver behavior)
        cmd_choices = [
            (0x03, "Voltage", lambda r: r / 100.0, 0.1),      # Voltage
            (0x05, "Temp", lambda r: (r / 100.0) - 255.5, -50),  # Temperature
            (0x06, "Humidity", lambda r: (r / 100.0) - 254.0, 0),  # Humidity
            (0x07, "Power", lambda r: r / 100.0, 0),          # Power
        ]

        cmd_id, name, convert, min_valid = random.choice(cmd_choices)

        # First poll of session gets longer wait for recovery (firmware does I2C recovery)
        # Recovery can take 500ms + 100ms delays + retries, so give it 2 seconds
        wait_time = 2000 if poll == 0 else random.randint(50, 150)
        resp = send_command(ser, cmd_id, wait_ms=wait_time)

        if resp and len(resp) >= 8 and resp[0] == 0x24:
            raw = parse_sensor_value(resp, 3)
            value = convert(raw) if raw else 0

            # Check for suspicious zero/near-zero readings
            if cmd_id == 0x03 and value < 0.1:  # Voltage should never be 0
                zero_readings += 1
                print(f"    [!] ZERO VOLTAGE detected: {value:.2f}V (poll {poll+1})")

            success += 1
        else:
            fail += 1
            print(f"    [X] No response for {name} (poll {poll+1})")

        # Random delay between polls (10-100ms)
        time.sleep(random.uniform(0.01, 0.1))

    return success, fail, zero_readings


def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/cu.usbserial-1133440"
    num_sessions = int(sys.argv[2]) if len(sys.argv) > 2 else 50
    polls_per_session = int(sys.argv[3]) if len(sys.argv) > 3 else 30
    disconnect_delay_min = float(sys.argv[4]) if len(sys.argv) > 4 else 0.5
    disconnect_delay_max = float(sys.argv[5]) if len(sys.argv) > 5 else 3.0

    print("=" * 70)
    print("SV241 Aggressive Reconnection Stress Test")
    print("=" * 70)
    print(f"Port: {port}")
    print(f"Sessions: {num_sessions}")
    print(f"Polls per session: {polls_per_session}")
    print(f"Disconnect delay: {disconnect_delay_min}-{disconnect_delay_max}s")
    print(f"Total expected polls: {num_sessions * polls_per_session}")
    print("=" * 70)

    total_success = 0
    total_fail = 0
    total_zero = 0
    session_failures = 0
    start_time = time.time()

    for session in range(num_sessions):
        timestamp = datetime.now().strftime('%H:%M:%S')
        print(f"\n[{timestamp}] Session {session+1}/{num_sessions}")

        try:
            # Open connection
            ser = open_serial_no_reset(port)
            print(f"  Connected, polling {polls_per_session} times...")

            # Run polling session
            success, fail, zeros = run_session(ser, session, polls_per_session)
            total_success += success
            total_fail += fail
            total_zero += zeros

            print(f"  Session result: {success}/{polls_per_session} OK", end="")
            if zeros > 0:
                print(f" ({zeros} ZERO readings!)", end="")
            if fail > 0:
                print(f" ({fail} failures)", end="")
            print()

            # Close connection
            ser.close()

        except serial.SerialException as e:
            print(f"  [ERROR] Serial exception: {e}")
            session_failures += 1
            total_fail += polls_per_session

        except Exception as e:
            print(f"  [ERROR] Unexpected: {e}")
            session_failures += 1

        # Random delay before next session (simulates user disconnect/reconnect)
        delay = random.uniform(disconnect_delay_min, disconnect_delay_max)
        if session < num_sessions - 1:
            print(f"  Disconnected, waiting {delay:.1f}s before reconnect...")
            time.sleep(delay)

    # Final report
    elapsed = time.time() - start_time
    total_polls = total_success + total_fail
    success_rate = (total_success / total_polls * 100) if total_polls > 0 else 0

    print("\n" + "=" * 70)
    print("STRESS TEST COMPLETE")
    print("=" * 70)
    print(f"Duration: {elapsed:.1f} seconds ({elapsed/60:.1f} minutes)")
    print(f"Sessions: {num_sessions} ({session_failures} connection failures)")
    print(f"Total polls: {total_polls}")
    print(f"Successful: {total_success} ({success_rate:.1f}%)")
    print(f"Failed: {total_fail} ({100-success_rate:.1f}%)")
    print(f"Zero voltage readings: {total_zero}")
    print("=" * 70)

    if total_zero > 0:
        print("\n[WARNING] Zero voltage readings detected!")
        print("This indicates the on-demand recovery may not be working correctly.")
    elif total_fail > 0:
        print("\n[WARNING] Some polls failed - check for I2C issues.")
    else:
        print("\n[SUCCESS] All readings valid - firmware recovery is working!")

    return 0 if (total_fail == 0 and total_zero == 0) else 1


if __name__ == "__main__":
    try:
        sys.exit(main())
    except KeyboardInterrupt:
        print("\n\nTest interrupted by user")
        sys.exit(0)
