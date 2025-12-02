#!/usr/bin/env python3
"""
Serial Port Proxy/Sniffer for SVBONY SV241
This creates a virtual serial port that logs all traffic between the app and device
"""

import serial
import serial.tools.list_ports
import threading
import time
import sys
from datetime import datetime

class SerialProxy:
    def __init__(self, real_port, virtual_port, baudrate=115200):
        self.real_port_name = real_port
        self.virtual_port_name = virtual_port
        self.baudrate = baudrate
        self.running = False
        self.log_file = f"serial_capture_{datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"

    def log_data(self, direction, data):
        """Log data with timestamp and formatting"""
        timestamp = datetime.now().strftime("%H:%M:%S.%f")[:-3]

        # Format as hex
        hex_str = ' '.join([f'{b:02X}' for b in data])

        # Format as ASCII (printable chars only)
        ascii_str = ''.join([chr(b) if 32 <= b < 127 else f'<{b:02X}>' for b in data])

        log_line = f"[{timestamp}] {direction}: {hex_str}\n           ASCII: {ascii_str}\n"

        print(log_line)

        with open(self.log_file, 'a') as f:
            f.write(log_line)
            f.flush()

    def forward_data(self, source, dest, direction):
        """Forward data from source to destination and log it"""
        while self.running:
            try:
                if source.in_waiting > 0:
                    data = source.read(source.in_waiting)
                    if data:
                        self.log_data(direction, data)
                        dest.write(data)
                        dest.flush()
                time.sleep(0.001)  # Small delay to prevent CPU spinning
            except Exception as e:
                print(f"Error in {direction}: {e}")
                break

    def run(self):
        """Run the proxy"""
        print(f"\n=== Serial Port Proxy ===")
        print(f"Real Device: {self.real_port_name}")
        print(f"Virtual Port: {self.virtual_port_name}")
        print(f"Baudrate: {self.baudrate}")
        print(f"Log file: {self.log_file}")
        print("\nStarting proxy... Press Ctrl+C to stop\n")
        print("="*70)

        try:
            # Open both ports
            real_port = serial.Serial(self.real_port_name, self.baudrate, timeout=0.1)
            virtual_port = serial.Serial(self.virtual_port_name, self.baudrate, timeout=0.1)

            self.running = True

            # Create threads for bidirectional forwarding
            thread_app_to_device = threading.Thread(
                target=self.forward_data,
                args=(virtual_port, real_port, "APP->DEV")
            )
            thread_device_to_app = threading.Thread(
                target=self.forward_data,
                args=(real_port, virtual_port, "DEV->APP")
            )

            thread_app_to_device.start()
            thread_device_to_app.start()

            # Wait for threads
            thread_app_to_device.join()
            thread_device_to_app.join()

        except KeyboardInterrupt:
            print("\n\nProxy stopped by user")
        except Exception as e:
            print(f"\nError: {e}")
        finally:
            self.running = False
            print(f"\nLog saved to: {self.log_file}")
            try:
                real_port.close()
                virtual_port.close()
            except:
                pass


def list_ports():
    """List all available serial ports"""
    ports = serial.tools.list_ports.comports()
    print("\n=== Available Serial Ports ===")
    for i, port in enumerate(ports, 1):
        print(f"  {i}. {port.device}: {port.description}")
    return ports


def simple_sniffer(port_name, baudrate=115200):
    """Simple sniffer that just reads from one port (read-only monitoring)"""
    print(f"\n=== Simple Serial Sniffer ===")
    print(f"Port: {port_name}")
    print(f"Baudrate: {baudrate}")
    print("\nThis will only READ from the port (passive monitoring)")
    print("Press Ctrl+C to stop\n")
    print("="*70)

    log_file = f"serial_sniff_{datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"

    try:
        with serial.Serial(port_name, baudrate, timeout=0.1) as ser:
            with open(log_file, 'w') as f:
                f.write(f"Serial Sniffer Log - {datetime.now()}\n")
                f.write(f"Port: {port_name}, Baudrate: {baudrate}\n")
                f.write("="*70 + "\n\n")

                while True:
                    if ser.in_waiting > 0:
                        data = ser.read(ser.in_waiting)
                        timestamp = datetime.now().strftime("%H:%M:%S.%f")[:-3]

                        hex_str = ' '.join([f'{b:02X}' for b in data])
                        ascii_str = ''.join([chr(b) if 32 <= b < 127 else f'<{b:02X}>' for b in data])

                        log_line = f"[{timestamp}] ({len(data)} bytes): {hex_str}\n           ASCII: {ascii_str}\n"
                        print(log_line)
                        f.write(log_line)
                        f.flush()

                    time.sleep(0.01)

    except KeyboardInterrupt:
        print(f"\n\nSniffer stopped. Log saved to: {log_file}")
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    print("=== SVBONY SV241 Serial Protocol Analyzer ===\n")

    if len(sys.argv) < 2:
        print("Usage:")
        print("  Simple sniffer (read-only):")
        print("    python serial_proxy.py sniff <PORT> [BAUDRATE]")
        print("    Example: python serial_proxy.py sniff COM3 115200")
        print("")
        print("  Full proxy (requires virtual COM port pair):")
        print("    python serial_proxy.py proxy <REAL_PORT> <VIRTUAL_PORT> [BAUDRATE]")
        print("    Example: python serial_proxy.py proxy COM3 COM4 115200")
        print("")

        list_ports()
        print("\nRecommendation: Use 'sniff' mode first to capture traffic")
        print("You'll need to connect directly to the device and run the app")
        sys.exit(0)

    mode = sys.argv[1].lower()

    if mode == "sniff":
        if len(sys.argv) < 3:
            print("Error: Port required")
            print("Usage: python serial_proxy.py sniff <PORT> [BAUDRATE]")
            sys.exit(1)

        port = sys.argv[2]
        baudrate = int(sys.argv[3]) if len(sys.argv) > 3 else 115200
        simple_sniffer(port, baudrate)

    elif mode == "proxy":
        if len(sys.argv) < 4:
            print("Error: Both real and virtual ports required")
            print("Usage: python serial_proxy.py proxy <REAL_PORT> <VIRTUAL_PORT> [BAUDRATE]")
            sys.exit(1)

        real_port = sys.argv[2]
        virtual_port = sys.argv[3]
        baudrate = int(sys.argv[4]) if len(sys.argv) > 4 else 115200

        proxy = SerialProxy(real_port, virtual_port, baudrate)
        proxy.run()
    else:
        print(f"Unknown mode: {mode}")
        print("Use 'sniff' or 'proxy'")
        sys.exit(1)
