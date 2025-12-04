#!/bin/bash

DRIVER_PATH=$1
if [ -z "$DRIVER_PATH" ]; then
    echo "Usage: $0 <driver_path>"
    exit 1
fi

# Function to check sensor values
check_sensors() {
    echo "--- Checking Sensors ---"
    VOLTAGE=$(indi_getprop "SVBONY SV241.VOLTAGE.INPUT_VOLTAGE" | cut -d'=' -f2)
    POWER=$(indi_getprop "SVBONY SV241.POWER.POWER_CONSUMPTION" | cut -d'=' -f2)
    
    echo "Voltage: $VOLTAGE"
    echo "Power: $POWER"

    if (( $(echo "$VOLTAGE == 0" | bc -l) )) || (( $(echo "$POWER == 0" | bc -l) )); then
        echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        echo "!! SENSOR ERROR: Value is 0 !!"
        echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        exit 1
    fi
}

# Function to run a test cycle
run_cycle() {
    local CYCLE=$1
    echo ""
    echo "==================== MAIN CYCLE $CYCLE ===================="
    
    for i in {1..10}; do
        echo "--- Sub-cycle $i/10 ---"
        
        echo "Turning all ports OFF"
        indi_setprop "SVBONY SV241.DC1.DC1_OFF=On" \
                     "SVBONY SV241.DC2.DC2_OFF=On" \
                     "SVBONY SV241.DC3.DC3_OFF=On" \
                     "SVBONY SV241.DC4.DC4_OFF=On" \
                     "SVBONY SV241.DC5.DC5_OFF=On" \
                     "SVBONY SV241.USB12.USB12_OFF=On" \
                     "SVBONY SV241.USB345.USB345_OFF=On"
        sleep 2

        echo "Turning all ports ON"
        indi_setprop "SVBONY SV241.DC1.DC1_ON=On" \
                     "SVBONY SV241.DC2.DC2_ON=On" \
                     "SVBONY SV241.DC3.DC3_ON=On" \
                     "SVBONY SV241.DC4.DC4_ON=On" \
                     "SVBONY SV241.DC5.DC5_ON=On" \
                     "SVBONY SV241.USB12.USB12_ON=On" \
                     "SVBONY SV241.USB345.USB345_ON=On"
        sleep 2

        check_sensors
        sleep 1
    done
}

# Main test execution
pkill -9 indiserver 2>/dev/null
sleep 2

indiserver "$DRIVER_PATH" &
SERVERPID=$!
sleep 4

echo "--- Connecting to driver ---"
indi_setprop "SVBONY SV241.CONNECTION.CONNECT=On"
sleep 6

# Run first set of cycles
run_cycle 1

echo ""
echo "--- Disconnecting for 30 seconds ---"
indi_setprop "SVBONY SV241.CONNECTION.DISCONNECT=On"
sleep 30

echo ""
echo "--- Reconnecting ---"
indi_setprop "SVBONY SV241.CONNECTION.CONNECT=On"
sleep 6

# Run second set of cycles
run_cycle 2

echo ""
echo "========================================================"
echo "          LONG TERM STABILITY TEST COMPLETE"
echo "========================================================"

kill $SERVERPID
pkill -9 indiserver 2>/dev/null
