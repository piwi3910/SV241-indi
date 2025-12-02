#!/usr/bin/env python3
"""
Find the SVBONY SV241 device and optimal baudrate
"""

import serial
import serial.tools.list_ports
import time
import sys

def list_all_ports():
    """List all available serial ports with details"""
    print("\n=== Available Serial Ports ===\n")

    ports = serial.tools.list_ports.comports()

    if not ports:
        print("No serial ports found!")
        return []

    for i, port in enumerate(ports, 1):
        print(f"{i}. {port.device}")
        print(f"   Description: {port.description}")
        print(f"   Hardware ID: {port.hwid}")
        print(f"   Manufacturer: {port.manufacturer or 'Unknown'}")
        print(f"   Product: {port.product or 'Unknown'}")
        print(f"   Serial Number: {port.serial_number or 'Unknown'}")
        print()

    return [p.device for p in ports]

def test_baudrates(port_name):
    """Test different baudrates to find which one works"""
    baudrates = [9600, 19200, 38400, 57600, 115200]

    print(f"\n=== Testing Baudrates on {port_name} ===\n")

    for baud in baudrates:
        try:
            print(f"Testing {baud} baud...", end=" ")
            with serial.Serial(port_name, baud, timeout=0.5) as ser:
                # Try to read any data
                time.sleep(0.1)

                # Send a common query (try multiple protocols)
                test_commands = [
                    b'{"get":"sensors"}\n',  # JSON (like SV241-Unbound)
                    b'AT\r\n',                # AT commands
                    b'\xAA\x55\x01\x00\xAC', # Binary test
                    b'?\n',                   # Simple query
                    b'STATUS\n',              # Text command
                ]

                for cmd in test_commands:
                    ser.write(cmd)
                    time.sleep(0.1)

                    if ser.in_waiting > 0:
                        response = ser.read(ser.in_waiting)
                        print(f"[OK] GOT RESPONSE!")
                        print(f"   Command: {cmd}")
                        print(f"   Response (hex): {response.hex()}")
                        try:
                            print(f"   Response (ascii): {response.decode('ascii', errors='ignore')}")
                        except:
                            pass
                        return baud

                print("No response")

        except serial.SerialException as e:
            print(f"[X] Error: {e}")
        except Exception as e:
            print(f"[X] Unexpected error: {e}")

    print("\nNo working baudrate found with test commands")
    print("Try running the desktop app and using the sniffer instead")
    return None

def passive_monitor(port_name, baudrate, duration=5):
    """Passively monitor a port for any traffic"""
    print(f"\n=== Passive Monitor: {port_name} @ {baudrate} baud ===")
    print(f"Monitoring for {duration} seconds...")
    print("(This will detect if the device is sending data on its own)")
    print()

    try:
        with serial.Serial(port_name, baudrate, timeout=0.1) as ser:
            start_time = time.time()
            data_received = False

            while time.time() - start_time < duration:
                if ser.in_waiting > 0:
                    data = ser.read(ser.in_waiting)
                    data_received = True

                    timestamp = time.strftime("%H:%M:%S")
                    print(f"[{timestamp}] Received {len(data)} bytes:")
                    print(f"  Hex: {data.hex()}")
                    try:
                        print(f"  ASCII: {data.decode('ascii', errors='ignore')}")
                    except:
                        pass
                    print()

                time.sleep(0.1)

            if not data_received:
                print("No data received during monitoring period")
                print("Device might only respond to commands")

    except Exception as e:
        print(f"Error: {e}")

def main():
    print("=== SVBONY SV241 Device Finder ===")

    # List all ports
    ports = list_all_ports()

    if not ports:
        sys.exit(1)

    # Look for likely candidates
    print("\n=== Likely Candidates ===")
    candidates = []
    for port_info in serial.tools.list_ports.comports():
        desc_lower = (port_info.description or "").lower()
        mfg_lower = (port_info.manufacturer or "").lower()

        # Look for USB serial adapters, CH340, FTDI, etc.
        if any(keyword in desc_lower + mfg_lower for keyword in
               ['usb', 'serial', 'ch340', 'ch341', 'ftdi', 'cp210', 'pl2303']):
            print(f"  -> {port_info.device}: {port_info.description}")
            candidates.append(port_info.device)

    if not candidates:
        print("  No obvious USB-serial devices found")
        print("  Your device might be using a built-in COM port")
        candidates = ports

    # Interactive mode
    print("\n=== Options ===")
    print("1. Test a specific port")
    print("2. Test all ports")
    print("3. Exit")

    choice = input("\nChoice: ").strip()

    if choice == "1":
        print("\nAvailable ports:")
        for i, port in enumerate(ports, 1):
            print(f"  {i}. {port}")

        port_choice = input("\nSelect port number: ").strip()
        try:
            port_idx = int(port_choice) - 1
            port = ports[port_idx]

            # Test baudrates
            working_baud = test_baudrates(port)

            if working_baud:
                print(f"\n[SUCCESS] Working configuration found!")
                print(f"  Port: {port}")
                print(f"  Baudrate: {working_baud}")
                print(f"\nNow you can run:")
                print(f"  python serial_proxy.py sniff {port} {working_baud}")
            else:
                # Try passive monitoring at 115200
                print("\nTrying passive monitoring at 115200 baud...")
                passive_monitor(port, 115200, duration=5)

        except (ValueError, IndexError):
            print("Invalid selection")

    elif choice == "2":
        print("\nTesting all ports...")
        for port in candidates or ports:
            print(f"\n{'='*60}")
            print(f"Testing {port}")
            print('='*60)
            working_baud = test_baudrates(port)
            if working_baud:
                print(f"\n[SUCCESS] FOUND! Use: python serial_proxy.py sniff {port} {working_baud}")
                break

    print("\n" + "="*60)
    print("RECOMMENDATION:")
    print("="*60)
    print("1. Connect your SV241 to USB")
    print("2. Run this script to find the COM port")
    print("3. Run the desktop app to see which port it connects to")
    print("4. Use: python serial_proxy.py sniff <PORT> 115200")
    print("5. Interact with the app while the sniffer is running")
    print("="*60)

if __name__ == "__main__":
    main()
