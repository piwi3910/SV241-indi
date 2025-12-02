#!/usr/bin/env python3
"""
Analyze captured serial protocol data
"""

import sys
import re
from collections import defaultdict

def parse_log_file(filename):
    """Parse the serial log file"""
    print(f"\n=== Analyzing {filename} ===\n")

    with open(filename, 'r') as f:
        content = f.read()

    # Extract all hex data lines
    hex_pattern = r'\[([0-9:\.]+)\] ([A-Z\->]+): ([0-9A-F ]+)'
    matches = re.findall(hex_pattern, content)

    if not matches:
        print("No data found in log file")
        return

    print(f"Found {len(matches)} messages\n")
    print("="*70)

    # Analyze patterns
    commands = defaultdict(list)
    responses = defaultdict(list)

    for timestamp, direction, hex_data in matches:
        bytes_data = bytes.fromhex(hex_data.replace(' ', ''))

        print(f"\n[{timestamp}] {direction}")
        print(f"  Hex:   {hex_data}")
        print(f"  Bytes: {list(bytes_data)}")

        # Try to decode as ASCII
        try:
            ascii_str = bytes_data.decode('ascii', errors='ignore')
            if any(c.isprintable() for c in ascii_str):
                print(f"  ASCII: {ascii_str}")
        except:
            pass

        # Try to decode as JSON
        try:
            import json
            json_str = bytes_data.decode('utf-8', errors='ignore')
            if json_str.strip():
                json_obj = json.loads(json_str.strip())
                print(f"  JSON:  {json.dumps(json_obj, indent=10)}")
        except:
            pass

        # Collect patterns
        if "APP->DEV" in direction or "TX" in direction:
            # Command from app to device
            commands[bytes_data[:4]].append((timestamp, bytes_data))
        else:
            # Response from device to app
            responses[bytes_data[:4]].append((timestamp, bytes_data))

    # Summary
    print("\n\n" + "="*70)
    print("=== PROTOCOL SUMMARY ===\n")

    if commands:
        print(f"Command patterns ({len(commands)}):")
        for pattern, instances in sorted(commands.items()):
            print(f"  Pattern {pattern.hex()}: {len(instances)} occurrences")
            if instances:
                print(f"    Example: {instances[0][1].hex()}")

    if responses:
        print(f"\nResponse patterns ({len(responses)}):")
        for pattern, instances in sorted(responses.items()):
            print(f"  Pattern {pattern.hex()}: {len(instances)} occurrences")
            if instances:
                print(f"    Example: {instances[0][1].hex()}")

    # Check for common protocols
    print("\n=== Protocol Detection ===")

    # Check for text-based protocols
    text_count = sum(1 for _, _, data in matches if all(32 <= int(b, 16) <= 126 for b in data.split()))
    if text_count > len(matches) * 0.5:
        print("  Likely TEXT-BASED protocol (ASCII/UTF-8)")

    # Check for JSON
    json_count = sum(1 for _, _, data in matches if '{' in data or '}' in data)
    if json_count > 0:
        print("  Likely JSON protocol")

    # Check for binary
    if text_count < len(matches) * 0.3:
        print("  Likely BINARY protocol")

    # Detect baudrate patterns
    print("\n=== Recommendations ===")
    print("1. Look for message delimiters (newline, carriage return, null bytes)")
    print("2. Check if messages have fixed length or length prefix")
    print("3. Identify command/response pairs")
    print("4. Look for checksums or CRC values")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python analyze_protocol.py <LOG_FILE>")
        print("Example: python analyze_protocol.py serial_capture_20240101_120000.txt")
        sys.exit(1)

    parse_log_file(sys.argv[1])
