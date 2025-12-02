#!/usr/bin/env python3
"""
Test script for SVBONY SV241 Protocol
Based on reverse-engineered protocol from desktop app
"""

import serial
import time
import struct

class SV241:
    def __init__(self, port, baudrate=115200):
        self.port = port
        self.baudrate = baudrate
        self.ser = None

    def connect(self):
        """Connect to the device"""
        try:
            self.ser = serial.Serial(self.port, self.baudrate, timeout=1)
            time.sleep(0.1)
            print(f"Connected to {self.port} at {self.baudrate} baud")
            return True
        except Exception as e:
            print(f"Connection failed: {e}")
            return False

    def disconnect(self):
        """Disconnect from the device"""
        if self.ser and self.ser.is_open:
            self.ser.close()
            print("Disconnected")

    def calc_checksum(self, cmd):
        """Calculate checksum for command"""
        sum_bytes = sum(cmd[0:5])
        if sum_bytes > 255:
            sum_bytes = sum_bytes % 255
        return sum_bytes

    def send_command(self, cmd_id, param1=0x00, param2=0x00):
        """Send a 6-byte command"""
        cmd = bytearray([0x24, 0x06, cmd_id, param1, param2, 0x00])
        cmd[5] = self.calc_checksum(cmd)

        print(f"TX: {' '.join([f'{b:02X}' for b in cmd])}")
        self.ser.reset_input_buffer()
        self.ser.write(cmd)
        time.sleep(0.05)

    def read_response(self, expected_len):
        """Read response from device"""
        response = self.ser.read(expected_len)
        if response:
            print(f"RX: {' '.join([f'{b:02X}' for b in response])} ({len(response)} bytes)")
        return response

    def write_dc_state(self, channel, state):
        """
        Turn DC output ON/OFF
        channel: 6-12 (DC1-DC5, USB12, USB345)
        state: True=ON, False=OFF
        """
        index = channel - 6
        state_byte = 0xFF if state else 0x00
        self.send_command(0x01, index, state_byte)
        print(f"Set DC{channel} (index {index}) to {'ON' if state else 'OFF'}")

    def write_pwm(self, channel, value):
        """
        Set PWM value
        channel: 13-15 (PWM13, PWM14, PWM15)
        value: 0-253
        """
        index = channel - 6
        self.send_command(0x01, index, value)
        print(f"Set PWM{channel} (index {index}) to {value}")

    def read_voltage(self):
        """Read input voltage"""
        self.send_command(0x03)
        response = self.read_response(8)

        if len(response) == 8 and response[2] == 0x03:
            # Reverse bytes 3-6 (big-endian to little-endian)
            data = bytes([response[6], response[5], response[4], response[3]])
            raw_value = struct.unpack('<i', data)[0]
            voltage = (raw_value / 100.0) + 0.0
            print(f"Voltage: {voltage:.2f} V")
            return voltage
        return None

    def read_temperature(self, sensor_type='ambient'):
        """
        Read temperature
        sensor_type: 'lens' (0x04) or 'ambient' (0x05)
        """
        cmd_id = 0x04 if sensor_type == 'lens' else 0x05
        self.send_command(cmd_id)
        response = self.read_response(8)

        if len(response) == 8 and response[2] == cmd_id:
            data = bytes([response[6], response[5], response[4], response[3]])
            raw_value = struct.unpack('<i', data)[0]
            temperature = (raw_value / 100.0) - 255.5
            print(f"Temperature ({sensor_type}): {temperature:.2f} °C")
            return temperature
        return None

    def read_humidity(self):
        """Read relative humidity"""
        self.send_command(0x06)
        response = self.read_response(8)

        if len(response) == 8 and response[2] == 0x06:
            data = bytes([response[6], response[5], response[4], response[3]])
            raw_value = struct.unpack('<i', data)[0]
            humidity = (raw_value / 100.0) - 254.0
            print(f"Humidity: {humidity:.1f} %")
            return humidity
        return None

    def read_power(self, voltage):
        """Read power consumption (requires voltage reading first)"""
        self.send_command(0x07)
        response = self.read_response(8)

        if len(response) == 8 and response[2] == 0x07:
            data = bytes([response[6], response[5], response[4], response[3]])
            raw_value = struct.unpack('<i', data)[0]
            power = (15.57 * (voltage * raw_value / 100.0) + 269.39) / 1000.0
            print(f"Power: {power:.2f} W")
            return power
        return None

    def sync_all_states(self):
        """Read all DC and PWM states from device"""
        self.send_command(0x08)
        response = self.read_response(14)

        if len(response) == 14 and response[2] == 0x08:
            print("\n=== Device State ===")
            dc_names = ["DC1", "DC2", "DC3", "DC4", "DC5", "USB12", "USB345"]
            for i in range(7):
                state = "ON" if response[3 + i] > 0 else "OFF"
                print(f"  {dc_names[i]}: {state}")

            print("\n  PWM13: {0} (Voltage: {1:.2f} V)".format(
                response[10],
                (response[10] * 15.3) / 253.0
            ))
            print(f"  PWM14: {response[11]}")
            print(f"  PWM15: {response[12]}")
            print("="*20)
            return response
        return None

    def read_all_sensors(self):
        """Read all sensor values"""
        print("\n=== Reading All Sensors ===")
        voltage = self.read_voltage()
        time.sleep(0.1)

        lens_temp = self.read_temperature('lens')
        time.sleep(0.1)

        ambient_temp = self.read_temperature('ambient')
        time.sleep(0.1)

        humidity = self.read_humidity()
        time.sleep(0.1)

        if voltage:
            power = self.read_power(voltage)
        print("="*30)


def main():
    import sys

    if len(sys.argv) < 2:
        print("Usage: python test_sv241_protocol.py <COM_PORT>")
        print("Example: python test_sv241_protocol.py COM3")
        sys.exit(1)

    port = sys.argv[1]

    print("=== SV241 Protocol Test ===\n")

    device = SV241(port)

    if not device.connect():
        sys.exit(1)

    try:
        # Test 1: Sync all states
        print("\n--- Test 1: Sync All States ---")
        device.sync_all_states()

        # Test 2: Read all sensors
        print("\n--- Test 2: Read All Sensors ---")
        device.read_all_sensors()

        # Test 3: Toggle DC1
        print("\n--- Test 3: Toggle DC1 ---")
        print("Turning DC1 ON...")
        device.write_dc_state(6, True)
        time.sleep(1)

        print("Turning DC1 OFF...")
        device.write_dc_state(6, False)

        # Test 4: Set PWM
        print("\n--- Test 4: Set PWM13 to 50% ---")
        device.write_pwm(13, 127)

        print("\nAll tests complete!")

    except KeyboardInterrupt:
        print("\n\nInterrupted by user")
    except Exception as e:
        print(f"\nError: {e}")
        import traceback
        traceback.print_exc()
    finally:
        device.disconnect()


if __name__ == "__main__":
    main()
