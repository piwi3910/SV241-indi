#!/bin/bash

DRIVER_PATH=$1
DRIVER_NAME=$2

if [ -z "$DRIVER_PATH" ]; then
    echo "Usage: $0 <driver_path> <driver_name>"
    exit 1
fi

pkill -9 indiserver 2>/dev/null
sleep 2

echo "========================================================"
echo "          $DRIVER_NAME DRIVER TEST - 3 CYCLES"
echo "========================================================"

indiserver "$DRIVER_PATH" 2>&1 &
SERVERPID=$!
sleep 4

test_cycle() {
    local CYCLE=$1

    echo ""
    echo "==================== CYCLE $CYCLE ===================="
    echo "--- Connecting ---"
    indi_setprop "SVBONY SV241.CONNECTION.CONNECT=On"
    sleep 6

    echo ""
    echo "=== CONNECTION STATE ==="
    indi_getprop -t 3 "SVBONY SV241.CONNECTION.*" 2>/dev/null || echo "(timeout)"

    echo ""
    echo "=== SWITCHES (DC1-5, USB) ==="
    indi_getprop -t 2 "SVBONY SV241.DC1.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.DC2.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.DC3.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.DC4.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.DC5.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.USB12.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.USB345.*" 2>/dev/null || true

    echo ""
    echo "=== PWM VALUES ==="
    indi_getprop -t 2 "SVBONY SV241.PWM13.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.PWM14.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.PWM15.*" 2>/dev/null || true

    echo ""
    echo "=== SENSORS ==="
    indi_getprop -t 2 "SVBONY SV241.VOLTAGE.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.POWER.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.AMBIENT_TEMPERATURE.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.LENS_TEMPERATURE.*" 2>/dev/null || true
    indi_getprop -t 2 "SVBONY SV241.HUMIDITY.*" 2>/dev/null || true

    echo ""
    echo "--- Disconnecting ---"
    indi_setprop "SVBONY SV241.CONNECTION.DISCONNECT=On"
    sleep 3
}

test_cycle 1
test_cycle 2
test_cycle 3

echo ""
echo "========================================================"
echo "          $DRIVER_NAME DRIVER TEST COMPLETE"
echo "========================================================"

pkill -9 indiserver 2>/dev/null
