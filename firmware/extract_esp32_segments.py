#!/usr/bin/env python3
"""Extract ESP32 firmware segments for Ghidra analysis"""
import struct
import sys

def extract_segments(firmware_path, output_dir):
    with open(firmware_path, 'rb') as f:
        data = f.read()
    
    # ESP32 image header
    magic = data[0]
    segment_count = data[1]
    flash_mode = data[2]
    flash_config = data[3]
    entry_point = struct.unpack('<I', data[4:8])[0]
    
    print(f"Magic: 0x{magic:02x}")
    print(f"Segments: {segment_count}")
    print(f"Entry point: 0x{entry_point:08x}")
    
    # Extended header at offset 0x10
    wp_pin = data[16]
    chip_id = struct.unpack('<H', data[22:24])[0]
    
    print(f"Chip ID: {chip_id}")
    
    # Segments start at offset 0x18
    offset = 0x18
    segments = []
    
    for i in range(segment_count):
        load_addr = struct.unpack('<I', data[offset:offset+4])[0]
        seg_size = struct.unpack('<I', data[offset+4:offset+8])[0]
        seg_data = data[offset+8:offset+8+seg_size]
        
        segments.append({
            'index': i,
            'load_addr': load_addr,
            'size': seg_size,
            'data': seg_data,
            'file_offset': offset
        })
        
        print(f"Segment {i}: addr=0x{load_addr:08x}, size=0x{seg_size:x} ({seg_size} bytes)")
        
        # Write segment to file
        seg_filename = f"{output_dir}/segment_{i}_0x{load_addr:08x}.bin"
        with open(seg_filename, 'wb') as sf:
            sf.write(seg_data)
        print(f"  -> Written to {seg_filename}")
        
        offset += 8 + seg_size
        # Align to 4 bytes
        if offset % 4:
            offset += 4 - (offset % 4)
    
    # Create combined IRAM+IROM binary for analysis
    # IROM is typically at 0x400d0000, IRAM at 0x40080000
    irom_seg = None
    iram_seg = None
    drom_seg = None
    
    for seg in segments:
        if 0x400d0000 <= seg['load_addr'] < 0x40400000:
            irom_seg = seg
            print(f"\nIROM segment found: 0x{seg['load_addr']:08x}")
        elif 0x40080000 <= seg['load_addr'] < 0x400a0000:
            iram_seg = seg
            print(f"IRAM segment found: 0x{seg['load_addr']:08x}")
        elif 0x3f400000 <= seg['load_addr'] < 0x3f800000:
            drom_seg = seg
            print(f"DROM segment found: 0x{seg['load_addr']:08x}")
    
    # Write info file for Ghidra import
    with open(f"{output_dir}/import_info.txt", 'w') as f:
        f.write("ESP32 Firmware Segments for Ghidra Import\n")
        f.write("=" * 50 + "\n\n")
        f.write(f"Entry point: 0x{entry_point:08x}\n\n")
        f.write("Import each segment with these settings:\n")
        f.write("Language: Xtensa:LE:32:default\n\n")
        for seg in segments:
            f.write(f"Segment {seg['index']}:\n")
            f.write(f"  File: segment_{seg['index']}_0x{seg['load_addr']:08x}.bin\n")
            f.write(f"  Base Address: 0x{seg['load_addr']:08x}\n")
            f.write(f"  Size: {seg['size']} bytes\n\n")
    
    print(f"\nImport instructions written to {output_dir}/import_info.txt")
    return segments

if __name__ == "__main__":
    firmware = sys.argv[1] if len(sys.argv) > 1 else "main.ino.bin"
    output = sys.argv[2] if len(sys.argv) > 2 else "."
    extract_segments(firmware, output)
