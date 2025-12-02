#!/usr/bin/env python3
"""
Test different baudrates on COM3 to find the right one
"""

import serial
import time

def test_baudrates(port_name):
    """Test different baudrates to find which one works"""
    baudrates = [9600, 19200, 38400, 57600, 115200]

    print(f"\n=== Testing Baudrates on {port_name} ===\n")

    for baud in baudrates:
        try:
            print(f"Testing {baud} baud...", end=" ", flush=True)
            with serial.Serial(port_name, baud, timeout=0.5) as ser:
                # Clear any existing data
                ser.reset_input_buffer()
                time.sleep(0.1)

                # Send test commands (try multiple protocols)
                test_commands = [
                    b'{"get":"sensors"}\n',  # JSON (like SV241-Unbound)
                    b'{"get":"version"}\n',  # JSON version query
                    b'AT\r\n',                # AT commands
                    b'?\n',                   # Simple query
                    b'STATUS\n',              # Text command
                    b'\xAA\x55\x01\x00\xAC', # Binary test
                ]

                for cmd in test_commands:
                    ser.write(cmd)
                    time.sleep(0.2)  # Wait a bit longer for response

                    if ser.in_waiting > 0:
                        response = ser.read(ser.in_waiting)
                        print(f"[OK] GOT RESPONSE!")
                        print(f"   Command sent: {cmd}")
                        print(f"   Response (hex): {response.hex()}")
                        print(f"   Response (len): {len(response)} bytes")
                        try:
                            ascii_str = response.decode('ascii', errors='ignore')
                            if ascii_str.strip():
                                print(f"   Response (ascii): {ascii_str}")
                        except:
                            pass
                        print()
                        return baud

                print("No response")

        except serial.SerialException as e:
            print(f"[X] Error: {e}")
        except Exception as e:
            print(f"[X] Unexpected error: {e}")

    print("\n" + "="*60)
    print("No working baudrate found with test commands")
    print("\nThis is normal if the device only responds to specific commands")
    print("or requires the desktop app to initialize it first.")
    print("\nNext step: Try running the sniffer while using the desktop app:")
    print("  python serial_proxy.py sniff COM3 115200")
    print("="*60)
    return None

if __name__ == "__main__":
    port = "COM3"
    print("=== SVBONY SV241 Baudrate Test ===")
    print(f"Testing port: {port}")
    print("Make sure the SV241 is connected and powered on!")
    print()

    working_baud = test_baudrates(port)

    if working_baud:
        print(f"\n{'='*60}")
        print(f"[SUCCESS] Working baudrate found: {working_baud}")
        print(f"{'='*60}")
        print(f"\nYou can now run:")
        print(f"  python serial_proxy.py sniff {port} {working_baud}")
