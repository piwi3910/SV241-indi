# USB Traffic Capture Guide for SV241 Debugging

## Problem Summary

The SVBONY SV241 Powerbox responds perfectly to the .NET application on Windows but returns **zero bytes** to all commands on Linux, despite:
- Correct serial configuration (115200 8N1, no flow control)
- Working CH340 USB-serial adapter (kernel driver loaded, no errors)
- Commands being transmitted successfully (write() succeeds, tcdrain() completes)
- Testing multiple USB ports, baud rates, wait times, and initialization sequences

## Hypothesis

The device firmware requires USB-level initialization that only the Windows CH340 driver provides, possibly:
- USB control transfers (SET_LINE_CODING, SET_CONTROL_LINE_STATE, etc.)
- Vendor-specific USB commands
- Different USB descriptor settings

## Capture USB Traffic on Windows

### Method 1: USBPcap (Recommended)

1. Download USBPcap: https://desowin.org/usbpcap/
2. Install and reboot Windows
3. Open Wireshark
4. Select the USB bus where SV241 is connected
5. Apply filter: `usb.device_address == X` (find X in Device Manager)
6. Start capture
7. **Important**: Capture from the moment you plug in the device
8. Run the .NET SVBONY application
9. Send a SYNC command (0x08) and a voltage read command (0x03)
10. Stop capture and save as `windows_sv241_capture.pcapng`

### Method 2: Wireshark Native USB Capture

1. Install Wireshark with USBPcap support
2. Follow same steps as Method 1

## Capture USB Traffic on Linux

### Using usbmon

```bash
# Find the USB bus number
lsusb | grep 1a86:7523

# Start capture (replace X with bus number)
sudo cat /sys/kernel/debug/usb/usbmon/Xu > /tmp/linux_sv241_capture.mon
# OR use tcpdump format:
sudo tcpdump -i usbmonX -w /tmp/linux_sv241_capture.pcap

# In another terminal:
# Run the test program
/tmp/test_merged_driver

# Stop capture (Ctrl+C)
```

### Using Wireshark

```bash
# Start Wireshark with root
sudo wireshark

# Select usbmonX interface (where X is the bus number)
# Apply filter: usb.device_address == Y (find in lsusb -v)
# Run test program
# Save capture
```

## What to Look For in Captures

### 1. Device Enumeration
Compare USB descriptor requests and responses:
- GET_DESCRIPTOR requests
- Configuration, Interface, Endpoint descriptors

### 2. Control Transfers
Look for USB Control Transfers (URB_CONTROL):
- **SET_LINE_CODING** - baud rate, data bits, parity, stop bits
- **SET_CONTROL_LINE_STATE** - DTR/RTS state
- **Vendor-specific commands** - any control transfers with bmRequestType in vendor range (0x40-0x5F)

### 3. Bulk Transfers
Compare actual data sent/received:
- URB_BULK OUT - commands sent to device
- URB_BULK IN - responses from device

### 4. Timing
Check if Windows has longer delays or specific timing patterns

## Expected Differences

If Linux is missing something, we'll likely see:
- Windows sending USB control transfer(s) that Linux doesn't
- Different SET_LINE_CODING values despite same 115200 8N1 config
- Vendor-specific USB commands (VID 0x1A86 specific)
- Different DTR/RTS assertion timing

## Analysis Tools

```bash
# View usbmon capture in text format
sudo cat /sys/kernel/debug/usb/usbmon/3u | grep 1a86

# Use tshark to filter pcap
tshark -r windows_sv241_capture.pcapng -Y "usb.src == X || usb.dst == X"

# Compare side-by-side
diff -u <(tshark -r windows.pcapng -V) <(tshark -r linux.pcapng -V)
```

## Next Steps After Capture

1. Compare Windows vs Linux USB control transfers
2. Identify any missing initialization in Linux
3. Implement missing USB commands using libusb if needed
4. Update driver with required initialization sequence

## Alternative: Run Windows App on Linux

If all else fails, try running the Windows .NET app under Wine to see if it works:

```bash
sudo apt-get install wine mono-complete
wine SVBONYHub.exe
```

If it works under Wine, we can use `usbmon` to see what Wine/Windows driver does differently.
