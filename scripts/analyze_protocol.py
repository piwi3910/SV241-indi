#!/usr/bin/env python3
"""
Analyze the original firmware protocol more carefully.
"""
import serial
import sys
import time

def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/cu.usbserial-1133440"

    print(f"Opening serial port {port}...")

    try:
        # Try different baud rates
        for baud in [115200, 9600, 57600, 38400, 19200]:
            print(f"\n=== Trying baud rate {baud} ===")
            try:
                ser = serial.Serial(port, baud, timeout=1)
                time.sleep(0.2)
                ser.reset_input_buffer()

                # Send sync command
                cmd = bytes([0x24, 0x06, 0x08, 0x00, 0x00, 0x32])
                print(f"Sending sync: {cmd.hex()}")
                ser.write(cmd)

                time.sleep(0.3)

                if ser.in_waiting > 0:
                    resp = ser.read(ser.in_waiting)
                    print(f"Response ({len(resp)} bytes): {resp.hex()}")

                    # Analyze structure
                    if len(resp) >= 2:
                        print(f"  Byte 0: 0x{resp[0]:02x} (start marker)")
                        print(f"  Byte 1: 0x{resp[1]:02x} (length or fixed)")
                        if len(resp) >= 3:
                            print(f"  Byte 2: 0x{resp[2]:02x} (command ID)")
                        if len(resp) > 3:
                            print(f"  Data bytes: {resp[3:-1].hex()}")
                        if len(resp) > 0:
                            print(f"  Last byte: 0x{resp[-1]:02x} (checksum)")
                else:
                    print("No response")

                ser.close()

                if ser.in_waiting > 0 or (resp and len(resp) > 0):
                    break

            except Exception as e:
                print(f"Error at {baud}: {e}")

    except Exception as e:
        print(f"Error: {e}")
        return 1

    return 0

if __name__ == "__main__":
    sys.exit(main())
