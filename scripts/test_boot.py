#!/usr/bin/env python3
"""
Test script to check if the custom firmware boots and outputs debug messages.
"""
import serial
import sys
import time

def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/cu.usbserial-1133440"

    print(f"Opening serial port {port}...")
    print("Waiting for boot messages (replug the device if needed)...")
    print("-" * 60)

    try:
        ser = serial.Serial(port, 115200, timeout=0.1)

        start_time = time.time()
        while time.time() - start_time < 10:  # Read for 10 seconds
            if ser.in_waiting > 0:
                data = ser.read(ser.in_waiting)
                try:
                    text = data.decode('utf-8', errors='replace')
                    print(text, end='', flush=True)
                except:
                    print(f"[RAW: {data.hex()}]", end='', flush=True)
            else:
                time.sleep(0.01)

        print("\n" + "-" * 60)
        print("Now testing protocol commands...")

        # Clear any remaining data
        ser.reset_input_buffer()
        time.sleep(0.1)

        # Send sync command (0x08)
        cmd = bytes([0x24, 0x06, 0x08, 0x00, 0x00, 0x32])
        print(f"Sending: {cmd.hex()}")
        ser.write(cmd)

        time.sleep(0.5)

        if ser.in_waiting > 0:
            resp = ser.read(ser.in_waiting)
            print(f"Response ({len(resp)} bytes): {resp.hex()}")
            try:
                text = resp.decode('utf-8', errors='replace')
                if text.isprintable() or '\n' in text or '\r' in text:
                    print(f"As text: {text}")
            except:
                pass
        else:
            print("No response received")

        ser.close()

    except serial.SerialException as e:
        print(f"Serial error: {e}")
        return 1

    return 0

if __name__ == "__main__":
    sys.exit(main())
