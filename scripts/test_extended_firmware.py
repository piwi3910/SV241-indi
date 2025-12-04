#!/usr/bin/env python3
"""
Test script for SV241 Extended Firmware v2.0.
Tests JSON-based extended commands while maintaining backward compatibility.
"""
import serial
import sys
import time
import struct
import json
import termios


def calc_checksum(data):
    """Calculate checksum using the SV241 protocol."""
    s = sum(data)
    if s > 255:
        s = s % 255
    return s


def open_serial(port, baudrate=115200):
    """Open serial port with settings to prevent ESP32 reset."""
    ser = serial.Serial()
    ser.port = port
    ser.baudrate = baudrate
    ser.timeout = 2
    ser.rtscts = False
    ser.dsrdtr = True

    ser.setDTR(False)
    ser.setRTS(False)
    ser.open()
    ser.setDTR(False)
    ser.setRTS(False)

    fd = ser.fileno()
    attrs = termios.tcgetattr(fd)
    attrs[2] = attrs[2] & ~termios.HUPCL
    termios.tcsetattr(fd, termios.TCSANOW, attrs)

    return ser


def send_binary_command(ser, cmd_id, param1=0, param2=0, wait_ms=100):
    """Send a binary command (backward compatible)."""
    cmd = bytes([0x24, 0x06, cmd_id, param1, param2])
    checksum = calc_checksum(cmd)
    cmd = cmd + bytes([checksum])

    if ser.in_waiting > 0:
        ser.read(ser.in_waiting)

    ser.write(cmd)
    time.sleep(wait_ms / 1000.0)

    if ser.in_waiting > 0:
        return ser.read(ser.in_waiting)
    return None


def send_json_command(ser, json_obj, wait_ms=200):
    """Send an extended JSON command (0x10)."""
    json_str = json.dumps(json_obj, separators=(',', ':'))
    json_bytes = json_str.encode('utf-8')

    # Frame: [0x24] [LEN] [0x10] [JSON...] [CHECKSUM]
    # LEN = 1 (header) + 1 (len) + 1 (cmd) + json_len + 1 (checksum)
    total_len = 1 + 1 + 1 + len(json_bytes) + 1

    frame = bytearray([0x24, total_len, 0x10])
    frame.extend(json_bytes)
    checksum = calc_checksum(frame)
    frame.append(checksum)

    if ser.in_waiting > 0:
        ser.read(ser.in_waiting)

    ser.write(bytes(frame))
    time.sleep(wait_ms / 1000.0)

    # Read response
    if ser.in_waiting > 0:
        resp = ser.read(ser.in_waiting)
        return parse_json_response(resp)
    return None


def parse_json_response(resp):
    """Parse a JSON response from the device."""
    if not resp or len(resp) < 5:
        return None

    if resp[0] != 0x24:
        return {"error": "Invalid header", "raw": resp.hex()}

    length = resp[1]
    if resp[2] != 0x10:
        return {"error": "Not an extended response", "raw": resp.hex()}

    # Extract JSON (from byte 3 to length-1 for checksum)
    json_bytes = resp[3:length-1]

    try:
        return json.loads(json_bytes.decode('utf-8'))
    except Exception as e:
        return {
            "error": str(e),
            "raw": resp.hex(),
            "json_bytes": json_bytes.hex()
        }


def parse_sensor_value(data, offset=0):
    """Parse sensor value from binary response."""
    if len(data) < 4 + offset:
        return None
    value = struct.unpack('>i', data[offset:offset+4])[0]
    return value


def test_binary_sensors(ser):
    """Test all binary sensor read commands."""
    print("\n=== Testing Binary: Sensor Commands ===\n")

    tests = [
        (0x03, "Voltage", lambda r: r / 100.0, "V"),
        (0x04, "Lens Temp", lambda r: (r / 100.0) - 255.5, "C"),
        (0x05, "Ambient Temp", lambda r: (r / 100.0) - 255.5, "C"),
        (0x06, "Humidity", lambda r: (r / 100.0) - 254.0, "%"),
        (0x07, "Power", lambda r: r / 100.0, "W"),
    ]

    success = 0
    for cmd_id, name, convert, unit in tests:
        resp = send_binary_command(ser, cmd_id, wait_ms=500)
        if resp and len(resp) >= 8 and resp[0] == 0x24:
            raw = parse_sensor_value(resp, 3)
            value = convert(raw) if raw else 0
            print(f"  0x{cmd_id:02X} {name}: {value:.2f} {unit}")
            success += 1
        else:
            print(f"  0x{cmd_id:02X} {name}: FAILED (no response)")

    print(f"\nSensor commands: {success}/{len(tests)} passed")
    return success == len(tests)


def test_binary_sync_states(ser):
    """Test sync states command (0x08)."""
    print("\n=== Testing Binary: Sync States (0x08) ===\n")

    resp = send_binary_command(ser, 0x08, wait_ms=500)
    if resp and len(resp) >= 14 and resp[0] == 0x24:
        # Parse DC states (bytes 3-9)
        dc_states = [resp[3 + i] for i in range(7)]
        # Parse PWM values (bytes 10-12)
        pwm_values = [resp[10], resp[11], resp[12]]

        print("  DC States:")
        dc_names = ["DC1", "DC2", "DC3", "DC4", "DC5", "USB12", "USB345"]
        for i, name in enumerate(dc_names):
            state = "ON" if dc_states[i] else "OFF"
            print(f"    {name}: {state}")

        print("  PWM Values:")
        pwm_names = ["PWM13 (Adj V)", "PWM14 (Dew 1)", "PWM15 (Dew 2)"]
        for i, name in enumerate(pwm_names):
            print(f"    {name}: {pwm_values[i]}")

        return True
    else:
        print(f"  FAILED: {resp.hex() if resp else 'no response'}")
        return False


def test_binary_dc_outputs(ser):
    """Test all DC output control commands (0x01).

    NOTE: Write commands (0x01) do NOT return a response per the original
    SVBONY protocol. We verify the command worked by reading back state
    using sync states (0x08).
    """
    print("\n=== Testing Binary: DC Output Control (0x01) ===\n")

    # DC channels: 0=DC1, 1=DC2, 2=DC3, 3=DC4, 4=DC5, 5=USB12, 6=USB345
    dc_names = ["DC1", "DC2", "DC3", "DC4", "DC5", "USB12", "USB345"]
    success = 0
    total = len(dc_names) * 2  # ON and OFF for each

    for idx, name in enumerate(dc_names):
        # Test turning ON (no response expected - fire and forget)
        send_binary_command(ser, 0x01, param1=idx, param2=1, wait_ms=100)

        # Verify with sync states
        resp = send_binary_command(ser, 0x08, wait_ms=200)
        if resp and len(resp) >= 14 and resp[0] == 0x24:
            state = resp[3 + idx]
            if state == 1:
                print(f"  {name} ON: OK (verified)")
                success += 1
            else:
                print(f"  {name} ON: FAILED (state={state}, expected 1)")
        else:
            print(f"  {name} ON: FAILED (sync states failed)")

        time.sleep(0.05)

        # Test turning OFF (no response expected)
        send_binary_command(ser, 0x01, param1=idx, param2=0, wait_ms=100)

        # Verify with sync states
        resp = send_binary_command(ser, 0x08, wait_ms=200)
        if resp and len(resp) >= 14 and resp[0] == 0x24:
            state = resp[3 + idx]
            if state == 0:
                print(f"  {name} OFF: OK (verified)")
                success += 1
            else:
                print(f"  {name} OFF: FAILED (state={state}, expected 0)")
        else:
            print(f"  {name} OFF: FAILED (sync states failed)")

        time.sleep(0.05)

    print(f"\nDC output commands: {success}/{total} passed")
    return success == total


def test_binary_pwm_outputs(ser):
    """Test all PWM output control commands (0x01).

    NOTE: Write commands (0x01) do NOT return a response per the original
    SVBONY protocol. We verify the command worked by reading back state
    using sync states (0x08).
    """
    print("\n=== Testing Binary: PWM Output Control (0x01) ===\n")

    # PWM channels: 7=PWM13, 8=PWM14, 9=PWM15
    # In sync response, PWM values are at bytes 10, 11, 12
    pwm_channels = [
        (7, 0, "PWM13 (Adj Voltage)"),
        (8, 1, "PWM14 (Dew Heater 1)"),
        (9, 2, "PWM15 (Dew Heater 2)")
    ]
    test_values = [0, 50, 127, 200, 253, 0]  # Test various values, end at 0
    success = 0
    total = len(pwm_channels) * len(test_values)

    for cmd_idx, sync_idx, name in pwm_channels:
        print(f"  {name}:")
        for value in test_values:
            # Send PWM command (no response expected)
            send_binary_command(ser, 0x01, param1=cmd_idx, param2=value, wait_ms=100)

            # Verify with sync states
            resp = send_binary_command(ser, 0x08, wait_ms=200)
            if resp and len(resp) >= 14 and resp[0] == 0x24:
                actual = resp[10 + sync_idx]
                if actual == value:
                    print(f"    Set to {value}: OK (verified)")
                    success += 1
                else:
                    print(f"    Set to {value}: FAILED (actual={actual})")
            else:
                print(f"    Set to {value}: FAILED (sync states failed)")
            time.sleep(0.05)

    print(f"\nPWM output commands: {success}/{total} passed")
    return success == total


def test_extended_version(ser):
    """Test the version command."""
    print("\n=== Testing Extended: version ===\n")

    resp = send_json_command(ser, {"cmd": "version"})
    if resp and "fw" in resp:
        print(f"  Firmware: {resp.get('fw')}")
        print(f"  HW: {resp.get('hw')}")
        print(f"  Protocol: {resp.get('proto')}")
        print(f"  Capabilities: {resp.get('caps', [])}")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_status(ser):
    """Test the status command."""
    print("\n=== Testing Extended: status ===\n")

    resp = send_json_command(ser, {"cmd": "status"})
    if resp and "v" in resp:
        print(f"  Voltage: {resp.get('v')} V")
        print(f"  Power: {resp.get('p')} W")
        print(f"  Ambient Temp: {resp.get('t')} C")
        print(f"  Humidity: {resp.get('h')} %")
        print(f"  Dew Point: {resp.get('dew')} C")
        print(f"  Uptime: {resp.get('uptime')} s")
        print(f"  DC States: {resp.get('dc')}")
        print(f"  PWM Values: {resp.get('pwm')}")
        print(f"  Auto Dew: {resp.get('auto_dew')}")
        print(f"  I2C Errors: {resp.get('i2c_err')}")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_dew_status(ser):
    """Test the dew_status command."""
    print("\n=== Testing Extended: dew_status ===\n")

    resp = send_json_command(ser, {"cmd": "dew_status"})
    if resp and "dew_point" in resp:
        print(f"  Dew Point: {resp.get('dew_point')} C")
        print(f"  Ambient Temp: {resp.get('ambient')} C")
        print(f"  Humidity: {resp.get('humidity')} %")
        ch14 = resp.get('ch14', {})
        ch15 = resp.get('ch15', {})
        print(f"  CH14: auto={ch14.get('auto')}, "
              f"margin={ch14.get('margin')}C, output={ch14.get('output')}")
        print(f"  CH15: auto={ch15.get('auto')}, "
              f"margin={ch15.get('margin')}C, output={ch15.get('output')}")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_dew_config(ser):
    """Test dew_config get and set."""
    print("\n=== Testing Extended: dew_config ===\n")

    # Get config for channel 14
    resp = send_json_command(ser, {"cmd": "dew_config", "ch": 14})
    if resp and resp.get("ok"):
        print("  Channel 14 config query OK (returns ok on get too)")

    # Set new config for channel 14 (keep auto off for safety)
    new_config = {
        "cmd": "dew_config",
        "ch": 14,
        "auto": False,
        "margin": 3.0,
        "kp": 2.0,
        "ki": 0.1,
        "kd": 0.5
    }
    resp2 = send_json_command(ser, new_config)
    if resp2 and resp2.get("ok"):
        print("  Channel 14 config updated successfully")

        # Also test channel 15
        new_config["ch"] = 15
        resp3 = send_json_command(ser, new_config)
        if resp3 and resp3.get("ok"):
            print("  Channel 15 config updated successfully")
            return True
        else:
            print(f"  Channel 15 config FAILED: {resp3}")
            return False
    else:
        print(f"  Channel 14 config FAILED: {resp2}")
        return False


def test_extended_stats(ser):
    """Test the stats command."""
    print("\n=== Testing Extended: stats ===\n")

    resp = send_json_command(ser, {"cmd": "stats"})
    if resp and "uptime" in resp:
        print(f"  Uptime: {resp.get('uptime')} s")
        v_min = resp.get('v_min', 'N/A')
        v_max = resp.get('v_max', 'N/A')
        v_avg = resp.get('v_avg', 'N/A')
        print(f"  Voltage min/max/avg: {v_min}/{v_max}/{v_avg} V")
        print(f"  Power max: {resp.get('p_max', 'N/A')} W")
        print(f"  Energy total: {resp.get('p_total', 'N/A')} Wh")
        t_min = resp.get('t_min', 'N/A')
        t_max = resp.get('t_max', 'N/A')
        print(f"  Temp min/max: {t_min}/{t_max} C")
        print(f"  I2C recoveries: {resp.get('i2c_recoveries', 0)}")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_alerts(ser):
    """Test alert_config and alerts commands."""
    print("\n=== Testing Extended: alerts ===\n")

    # Get current alerts (returns boolean flags)
    resp = send_json_command(ser, {"cmd": "alerts"})
    if resp and "low_v" in resp:
        print("  Current alert states:")
        print(f"    Low voltage: {resp.get('low_v')}")
        print(f"    Critical voltage: {resp.get('crit_v')}")
        print(f"    Thermal: {resp.get('thermal')}")
        print(f"    I2C fail: {resp.get('i2c_fail')}")

        # Get alert config
        resp2 = send_json_command(ser, {"cmd": "alert_config"})
        if resp2 and "low_v" in resp2:
            low_v = resp2.get('low_v', {})
            crit_v = resp2.get('crit_v', {})
            print("  Alert config:")
            print(f"    Low voltage: {low_v.get('thresh')}V "
                  f"(enabled: {low_v.get('en')})")
            print(f"    Critical voltage: {crit_v.get('thresh')}V "
                  f"(enabled: {crit_v.get('en')})")
            print(f"    Auto-off on critical: {crit_v.get('auto_off')}")
            return True

    print(f"  FAILED: {resp}")
    return False


def test_extended_calibration(ser):
    """Test calibration get/set."""
    print("\n=== Testing Extended: calibration ===\n")

    resp = send_json_command(ser, {"cmd": "cal_get"})
    if resp and "v_offset" in resp:
        print("  Current calibration:")
        print(f"    Voltage offset: {resp.get('v_offset')} V")
        print(f"    Temp offset: {resp.get('t_offset')} C")
        print(f"    Humidity offset: {resp.get('h_offset')} %")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_diagnostics(ser):
    """Test diagnostic commands."""
    print("\n=== Testing Extended: diagnostics ===\n")

    resp = send_json_command(ser, {"cmd": "diag"})
    if resp and "free_heap" in resp:
        print(f"  Free heap: {resp.get('free_heap')} bytes")
        print(f"  I2C bus OK: {resp.get('i2c_ok')}")
        print(f"  INA219 OK: {resp.get('ina219_ok')}")
        print(f"  SHT4x OK: {resp.get('sht4x_ok')}")
        print(f"  Last I2C errors: {resp.get('last_i2c_err')}")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_i2c_recovery(ser):
    """Test I2C recovery command."""
    print("\n=== Testing Extended: i2c_recovery ===\n")

    resp = send_json_command(ser, {"cmd": "i2c_recovery"}, wait_ms=500)
    if resp and "ok" in resp:
        print(f"  Recovery result: {resp.get('ok')}")
        print(f"  SDA released: {resp.get('sda_released')}")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_stats_reset(ser):
    """Test stats_reset command."""
    print("\n=== Testing Extended: stats_reset ===\n")

    resp = send_json_command(ser, {"cmd": "stats_reset"})
    if resp and resp.get("ok"):
        print("  Stats reset: OK")

        # Verify by getting stats again
        resp2 = send_json_command(ser, {"cmd": "stats"})
        if resp2 and resp2.get("uptime", -1) >= 0:
            print(f"  Verified: uptime after reset = {resp2.get('uptime')}s")
            return True
        else:
            print("  Verification failed")
            return False
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_names_get(ser):
    """Test names_get command."""
    print("\n=== Testing Extended: names_get ===\n")

    resp = send_json_command(ser, {"cmd": "names_get"})
    if resp and "dc" in resp:
        dc_names = resp.get('dc', [])
        pwm_names = resp.get('pwm', [])
        print("  DC Port Names:")
        port_labels = ["DC1", "DC2", "DC3", "DC4", "DC5", "USB12", "USB345"]
        for i, label in enumerate(port_labels):
            name = dc_names[i] if i < len(dc_names) else "N/A"
            print(f"    {label}: {name}")
        print("  PWM Port Names:")
        pwm_labels = ["PWM13", "PWM14", "PWM15"]
        for i, label in enumerate(pwm_labels):
            name = pwm_names[i] if i < len(pwm_names) else "N/A"
            print(f"    {label}: {name}")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_names_set(ser):
    """Test names_set command."""
    print("\n=== Testing Extended: names_set ===\n")

    # Set a custom name for DC1 (idx=0)
    test_name = "Mount"
    resp = send_json_command(ser, {"cmd": "names_set", "idx": 0, "name": test_name})
    if resp and resp.get("ok"):
        print(f"  Set DC1 name to '{test_name}': OK")

        # Verify by reading back
        resp2 = send_json_command(ser, {"cmd": "names_get"})
        if resp2 and "dc" in resp2:
            dc_names = resp2.get('dc', [])
            if len(dc_names) > 0 and dc_names[0] == test_name:
                print(f"  Verified: DC1 name = '{dc_names[0]}'")

                # Test PWM name (idx=7 = PWM13)
                test_pwm_name = "Heater"
                resp3 = send_json_command(ser, {"cmd": "names_set", "idx": 7, "name": test_pwm_name})
                if resp3 and resp3.get("ok"):
                    print(f"  Set PWM13 name to '{test_pwm_name}': OK")
                    return True
                else:
                    print(f"  PWM13 name set FAILED: {resp3}")
                    return False
            else:
                print(f"  Verification FAILED: expected '{test_name}', got '{dc_names[0] if dc_names else 'empty'}'")
                return False
        else:
            print(f"  names_get verification FAILED: {resp2}")
            return False
    else:
        print(f"  FAILED: {resp}")
        return False


# ============================================================================
# PHASE 3 TESTS
# ============================================================================

def test_extended_profile_list(ser):
    """Test profile_list command."""
    print("\n=== Testing Extended: profile_list ===\n")

    resp = send_json_command(ser, {"cmd": "profile_list"})
    if resp and "profiles" in resp:
        profiles = resp.get('profiles', [])
        active = resp.get('active', -1)
        print(f"  Profiles found: {len(profiles)}")
        for p in profiles:
            print(f"    Slot {p.get('slot')}: {p.get('name')}")
        print(f"  Active profile: {active}")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_profile_save_load(ser):
    """Test profile_save and profile_load commands."""
    print("\n=== Testing Extended: profile_save/load ===\n")

    # First, set a known state: DC1 ON, PWM14 to 100
    send_json_command(ser, {"cmd": "status"})  # Just to sync
    send_binary_command(ser, 0x01, param1=0, param2=1, wait_ms=100)  # DC1 ON
    send_binary_command(ser, 0x01, param1=8, param2=100, wait_ms=100)  # PWM14=100

    # Save current state as profile
    resp = send_json_command(ser, {"cmd": "profile_save", "slot": 0, "name": "TestProfile"})
    if not resp or not resp.get("ok"):
        print(f"  profile_save FAILED: {resp}")
        return False
    print("  Saved profile to slot 0: OK")

    # Change state: DC1 OFF, PWM14 to 0
    send_binary_command(ser, 0x01, param1=0, param2=0, wait_ms=100)  # DC1 OFF
    send_binary_command(ser, 0x01, param1=8, param2=0, wait_ms=100)  # PWM14=0

    # Load the profile back
    resp = send_json_command(ser, {"cmd": "profile_load", "slot": 0})
    if not resp or not resp.get("ok"):
        print(f"  profile_load FAILED: {resp}")
        return False
    print("  Loaded profile from slot 0: OK")

    # Verify state was restored
    resp = send_binary_command(ser, 0x08, wait_ms=200)
    if resp and len(resp) >= 14 and resp[0] == 0x24:
        dc1_state = resp[3]
        pwm14_value = resp[11]
        if dc1_state == 1 and pwm14_value == 100:
            print(f"  Verified: DC1={dc1_state} (expected 1), PWM14={pwm14_value} (expected 100)")

            # Verify profile list shows our profile
            resp2 = send_json_command(ser, {"cmd": "profile_list"})
            if resp2 and "profiles" in resp2:
                profiles = resp2.get('profiles', [])
                found = any(p.get('name') == 'TestProfile' for p in profiles)
                if found:
                    print("  Profile 'TestProfile' found in list: OK")
                    # Reset state
                    send_binary_command(ser, 0x01, param1=0, param2=0, wait_ms=100)
                    send_binary_command(ser, 0x01, param1=8, param2=0, wait_ms=100)
                    return True
                else:
                    print("  Profile not found in list")
            return False
        else:
            print(f"  Verification FAILED: DC1={dc1_state}, PWM14={pwm14_value}")
            return False
    else:
        print(f"  Sync states FAILED")
        return False


def test_extended_profile_delete(ser):
    """Test profile_delete command."""
    print("\n=== Testing Extended: profile_delete ===\n")

    # First save a profile to delete
    resp = send_json_command(ser, {"cmd": "profile_save", "slot": 3, "name": "ToDelete"})
    if not resp or not resp.get("ok"):
        print(f"  profile_save FAILED: {resp}")
        return False

    # Delete it
    resp = send_json_command(ser, {"cmd": "profile_delete", "slot": 3})
    if not resp or not resp.get("ok"):
        print(f"  profile_delete FAILED: {resp}")
        return False
    print("  Deleted profile from slot 3: OK")

    # Verify it's gone
    resp = send_json_command(ser, {"cmd": "profile_list"})
    if resp and "profiles" in resp:
        profiles = resp.get('profiles', [])
        found = any(p.get('slot') == 3 for p in profiles)
        if not found:
            print("  Verified: slot 3 no longer in profile list")
            return True
        else:
            print("  FAILED: slot 3 still in list")
            return False
    return False


def test_extended_timer_set(ser):
    """Test timer_set command."""
    print("\n=== Testing Extended: timer_set ===\n")

    # Set a timer for 1 minute from now (we won't wait for it, just test the API)
    resp = send_json_command(ser, {
        "cmd": "timer_set",
        "port": "dc1",
        "action": "off",
        "minutes": 1
    })
    if resp and resp.get("ok") and "id" in resp:
        timer_id = resp.get("id")
        print(f"  Timer set: id={timer_id}, port=dc1, action=off, minutes=1")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_timer_list(ser):
    """Test timer_list command."""
    print("\n=== Testing Extended: timer_list ===\n")

    # First set a timer
    resp = send_json_command(ser, {
        "cmd": "timer_set",
        "port": "pwm14",
        "action": "set",
        "value": 127,
        "minutes": 2
    })

    # List timers
    resp = send_json_command(ser, {"cmd": "timer_list"})
    if resp and "timers" in resp:
        timers = resp.get('timers', [])
        print(f"  Active timers: {len(timers)}")
        for t in timers:
            print(f"    ID {t.get('id')}: {t.get('port')} -> {t.get('action')}, "
                  f"remaining={t.get('remaining')}s")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_timer_cancel(ser):
    """Test timer_cancel command."""
    print("\n=== Testing Extended: timer_cancel ===\n")

    # Set a timer
    resp = send_json_command(ser, {
        "cmd": "timer_set",
        "port": "dc2",
        "action": "on",
        "minutes": 5
    })
    if not resp or not resp.get("ok"):
        print(f"  timer_set FAILED: {resp}")
        return False

    timer_id = resp.get("id")
    print(f"  Created timer ID {timer_id}")

    # Cancel it
    resp = send_json_command(ser, {"cmd": "timer_cancel", "id": timer_id})
    if resp and resp.get("ok"):
        print(f"  Cancelled timer {timer_id}: OK")

        # Verify it's gone
        resp = send_json_command(ser, {"cmd": "timer_list"})
        if resp and "timers" in resp:
            timers = resp.get('timers', [])
            found = any(t.get('id') == timer_id for t in timers)
            if not found:
                print(f"  Verified: timer {timer_id} no longer in list")
                return True
            else:
                print(f"  FAILED: timer still in list")
                return False
        return False
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_temp_rate(ser):
    """Test temp_rate command."""
    print("\n=== Testing Extended: temp_rate ===\n")

    resp = send_json_command(ser, {"cmd": "temp_rate"})
    if resp and "rate" in resp:
        print(f"  Temperature rate: {resp.get('rate')} C/hour")
        print(f"  Measurement period: {resp.get('period')} seconds")
        print(f"  Samples collected: {resp.get('samples')}")
        return True
    else:
        print(f"  FAILED: {resp}")
        return False


def test_extended_dew_pid(ser):
    """Test dew_pid get/set command."""
    print("\n=== Testing Extended: dew_pid ===\n")

    # Get current PID settings for channel 14
    resp = send_json_command(ser, {"cmd": "dew_pid", "ch": 14})
    if resp and "kp" in resp:
        print("  Channel 14 PID settings:")
        print(f"    Kp: {resp.get('kp')}")
        print(f"    Ki: {resp.get('ki')}")
        print(f"    Kd: {resp.get('kd')}")
        print(f"    i_max: {resp.get('i_max')}")

        # Test setting new PID values
        resp2 = send_json_command(ser, {
            "cmd": "dew_pid",
            "ch": 14,
            "kp": 2.5,
            "ki": 0.3,
            "kd": 0.15
        })
        if resp2 and resp2.get("ok"):
            print("  Updated PID settings: OK")

            # Verify the change
            resp3 = send_json_command(ser, {"cmd": "dew_pid", "ch": 14})
            if resp3 and resp3.get("kp") == 2.5:
                print(f"  Verified: Kp = {resp3.get('kp')}")

                # Restore original values
                send_json_command(ser, {
                    "cmd": "dew_pid",
                    "ch": 14,
                    "kp": resp.get('kp'),
                    "ki": resp.get('ki'),
                    "kd": resp.get('kd')
                })
                return True
            else:
                print(f"  Verification FAILED: {resp3}")
                return False
        else:
            print(f"  Setting PID FAILED: {resp2}")
            return False
    else:
        print(f"  FAILED: {resp}")
        return False


def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/cu.usbserial-1133440"

    print("=" * 70)
    print("SV241 Extended Firmware v2.1 Test (with Phase 3)")
    print("=" * 70)
    print(f"Port: {port}")
    print("=" * 70)

    try:
        ser = open_serial(port)
        print("Connected!\n")
        time.sleep(0.5)  # Wait for device to settle

        results = {
            # Binary protocol tests (backward compatibility)
            "Binary Sensors": test_binary_sensors(ser),
            "Binary Sync States": test_binary_sync_states(ser),
            "Binary DC Outputs": test_binary_dc_outputs(ser),
            "Binary PWM Outputs": test_binary_pwm_outputs(ser),
            # Extended JSON protocol tests (Phase 1 & 2)
            "Ext Version": test_extended_version(ser),
            "Ext Status": test_extended_status(ser),
            "Ext Dew Status": test_extended_dew_status(ser),
            "Ext Dew Config": test_extended_dew_config(ser),
            "Ext Stats": test_extended_stats(ser),
            "Ext Alerts": test_extended_alerts(ser),
            "Ext Calibration": test_extended_calibration(ser),
            "Ext Diagnostics": test_extended_diagnostics(ser),
            "Ext I2C Recovery": test_extended_i2c_recovery(ser),
            "Ext Stats Reset": test_extended_stats_reset(ser),
            "Ext Names Get": test_extended_names_get(ser),
            "Ext Names Set": test_extended_names_set(ser),
            # Phase 3: Profiles
            "Ext Profile List": test_extended_profile_list(ser),
            "Ext Profile Save/Load": test_extended_profile_save_load(ser),
            "Ext Profile Delete": test_extended_profile_delete(ser),
            # Phase 3: Timers
            "Ext Timer Set": test_extended_timer_set(ser),
            "Ext Timer List": test_extended_timer_list(ser),
            "Ext Timer Cancel": test_extended_timer_cancel(ser),
            # Phase 3: Temperature Rate & PID
            "Ext Temp Rate": test_extended_temp_rate(ser),
            "Ext Dew PID": test_extended_dew_pid(ser),
        }

        ser.close()

        # Summary
        print("\n" + "=" * 70)
        print("TEST SUMMARY")
        print("=" * 70)
        passed = sum(1 for v in results.values() if v)
        total = len(results)
        for name, result in results.items():
            status = "PASS" if result else "FAIL"
            print(f"  {name}: {status}")

        print(f"\nTotal: {passed}/{total} passed")
        print("=" * 70)

        return 0 if passed == total else 1

    except serial.SerialException as e:
        print(f"Serial error: {e}")
        return 1
    except Exception as e:
        print(f"Error: {e}")
        import traceback
        traceback.print_exc()
        return 1


if __name__ == "__main__":
    sys.exit(main())
