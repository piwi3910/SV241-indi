import re

dll_path = "new-svbonyhubControl 1.5-eng/SerialControlApp.dll"

with open(dll_path, 'rb') as f:
    data = f.read()

# Extract ASCII strings (minimum 4 characters)
ascii_pattern = b'[\x20-\x7E]{4,}'
strings = re.findall(ascii_pattern, data)

# Decode and filter
decoded_strings = []
for s in strings:
    try:
        decoded = s.decode('ascii')
        decoded_strings.append(decoded)
    except:
        pass

# Filter for interesting patterns
keywords = ['com', 'serial', 'port', 'command', 'hub', 'power', 'usb', 'device',
            'write', 'read', 'send', 'receive', 'voltage', 'current', 'switch',
            'channel', 'pwm', '0x', 'byte', 'packet']

interesting = []
for s in decoded_strings:
    if any(keyword in s.lower() for keyword in keywords):
        interesting.append(s)

# Save all strings
with open("all_strings.txt", "w", encoding="utf-8") as f:
    for s in sorted(set(decoded_strings)):
        f.write(f"{s}\n")

# Save interesting strings
with open("interesting_strings.txt", "w", encoding="utf-8") as f:
    for s in sorted(set(interesting)):
        f.write(f"{s}\n")

print("=== Interesting Strings Found ===\n")
for s in sorted(set(interesting))[:100]:
    print(s)

print(f"\n\nTotal strings: {len(decoded_strings)}")
print(f"Interesting strings: {len(interesting)}")
print(f"\nAll strings saved to: all_strings.txt")
print(f"Interesting strings saved to: interesting_strings.txt")
