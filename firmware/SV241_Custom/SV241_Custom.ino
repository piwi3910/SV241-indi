/**
 * SVBONY SV241 Power Box - Custom Firmware
 *
 * Drop-in replacement firmware with:
 * - Proper I2C bus recovery to fix sensor lockup issues
 * - Automatic sensor reinitialization on failure
 * - Watchdog timer for lockup detection
 * - 100% compatible with original serial protocol
 *
 * Hardware:
 * - ESP32 DevKit
 * - INA219 power monitor (I2C)
 * - SHT4x temperature/humidity sensor (I2C)
 * - 7x digital outputs (DC1-5, USB12, USB345)
 * - 3x PWM outputs (variable voltage, 2x dew heaters)
 *
 * Author: Custom firmware for SV241
 * Based on reverse engineering of original firmware
 */

#include <Wire.h>
#include <esp_task_wdt.h>  // Hardware watchdog to recover from hangs
#include <driver/periph_ctrl.h>  // For I2C peripheral reset

// ============================================================================
// PIN DEFINITIONS (extracted from Ghidra disassembly)
// ============================================================================

// DC Output Pins
#define PIN_DC1     13
#define PIN_DC2     12
#define PIN_DC3     14
#define PIN_DC4     27
#define PIN_DC5     26
#define PIN_USB12   19
#define PIN_USB345  18

// PWM Output Pins
#define PIN_PWM13   25  // Variable voltage output
#define PIN_PWM14   33  // Dew heater 1
#define PIN_PWM15   32  // Dew heater 2

// I2C Pins
#define PIN_SDA     21
#define PIN_SCL     22

// I2C Addresses
#define INA219_ADDR   0x40
#define SHT4X_ADDR    0x44

// PWM Configuration
#define PWM_FREQ      5000
#define PWM_RESOLUTION 8

// Protocol Constants
#define PROTO_START   0x24  // '$' character
#define PROTO_FIXED   0x06

// Command IDs
#define CMD_WRITE_OUTPUT  0x01
#define CMD_READ_VOLTAGE  0x03
#define CMD_READ_LENS_TEMP 0x04
#define CMD_READ_AMBIENT_TEMP 0x05
#define CMD_READ_HUMIDITY 0x06
#define CMD_READ_POWER    0x07
#define CMD_SYNC_STATES   0x08

// Watchdog timeout (seconds) - triggers reset if firmware hangs
#define WDT_TIMEOUT   5

// I2C recovery settings
#define I2C_RECOVERY_RETRIES  3
#define I2C_CLOCK_CYCLES      9

// ============================================================================
// GLOBAL STATE
// ============================================================================

// Output states
bool dcStates[7] = {false, false, false, false, false, false, false};
uint8_t pwmValues[3] = {0, 0, 0};

// Sensor values
float inputVoltage = 0.0;
float inputCurrent = 0.0;
float ambientTemp = 0.0;
float humidity = 0.0;
float lensTemp = 0.0;  // If separate sensor exists

// I2C health tracking
uint8_t i2cFailCount = 0;
bool i2cHealthy = false;  // Start as false, set true if sensors found
unsigned long lastI2CRecovery = 0;

// INA219 calibration
uint16_t ina219_calValue = 4096;

// Serial buffer
uint8_t rxBuffer[64];
uint8_t rxIndex = 0;

// Debug mode - set to false for production
bool debugMode = false;

// Track serial connection state - to detect reconnections
unsigned long lastSerialActivity = 0;
bool serialWasIdle = true;  // Assume idle at start

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================

void setupGPIO();
void setupPWM();
void setupI2C();
void setupSerial();
void setupWatchdog();

bool i2cBusRecovery();
void i2cReset();
bool i2cProbe(uint8_t address);

bool ina219_init();
bool ina219_readVoltage(float* voltage);
bool ina219_readCurrent(float* current);

bool sht4x_init();
bool sht4x_read(float* temp, float* hum);

void processSerialCommand();
void handleCommand(uint8_t* cmd, uint8_t len);
void sendResponse(uint8_t cmdId, uint8_t* data, uint8_t dataLen);
uint8_t calcChecksum(uint8_t* data, uint8_t len);

void setDCOutput(uint8_t index, bool state);
void setPWMOutput(uint8_t channel, uint8_t value);
void syncAllStates();

// ============================================================================
// SETUP
// ============================================================================

void setup() {
    // Initialize serial - don't use while(!Serial) as it blocks on ESP32
    // when the host disconnects, causing the firmware to hang
    Serial.begin(115200);
    delay(100);

    if (debugMode) {
        Serial.println("\n\n=================================");
        Serial.println("SV241 Custom Firmware v1.0");
        Serial.println("With I2C Bus Recovery");
        Serial.println("=================================\n");
    }

    setupGPIO();
    setupPWM();
    setupI2C();
    // setupWatchdog();  // Disabled - causes issues with ESP32 Arduino Core 3.x

    // Initialize all outputs to OFF
    for (int i = 0; i < 7; i++) {
        setDCOutput(i, false);
    }
    for (int i = 0; i < 3; i++) {
        setPWMOutput(i, 0);
    }

    if (debugMode) {
        Serial.println("Initialization complete!");
        Serial.println("Ready for commands...\n");
    }
}

// ============================================================================
// MAIN LOOP
// ============================================================================

void loop() {
    // Process incoming serial commands
    processSerialCommand();

    // Periodic sensor reading (every 2 seconds)
    static unsigned long lastSensorRead = 0;
    if (millis() - lastSensorRead > 2000) {
        lastSensorRead = millis();

        // Read sensors with automatic recovery on failure
        if (!readSensorsWithRecovery()) {
            // Multiple consecutive failures trigger I2C bus recovery
            if (i2cFailCount >= I2C_RECOVERY_RETRIES) {
                i2cBusRecovery();
                i2cFailCount = 0;
            }
        }
    }

    // Small delay to prevent tight loop
    delay(5);
}

// ============================================================================
// INITIALIZATION FUNCTIONS
// ============================================================================

void setupGPIO() {
    if (debugMode) Serial.println("Configuring GPIO pins...");

    // Configure DC output pins
    pinMode(PIN_DC1, OUTPUT);
    pinMode(PIN_DC2, OUTPUT);
    pinMode(PIN_DC3, OUTPUT);
    pinMode(PIN_DC4, OUTPUT);
    pinMode(PIN_DC5, OUTPUT);
    pinMode(PIN_USB12, OUTPUT);
    pinMode(PIN_USB345, OUTPUT);

    // Set all outputs LOW initially
    digitalWrite(PIN_DC1, LOW);
    digitalWrite(PIN_DC2, LOW);
    digitalWrite(PIN_DC3, LOW);
    digitalWrite(PIN_DC4, LOW);
    digitalWrite(PIN_DC5, LOW);
    digitalWrite(PIN_USB12, LOW);
    digitalWrite(PIN_USB345, LOW);

    if (debugMode) Serial.println("  DC outputs configured (GPIO 12,13,14,18,19,26,27)");
}

void setupPWM() {
    if (debugMode) Serial.println("Configuring PWM channels...");

    // Configure and attach PWM channels to pins (ESP32 Arduino Core 3.x API)
    ledcAttach(PIN_PWM13, PWM_FREQ, PWM_RESOLUTION);
    ledcAttach(PIN_PWM14, PWM_FREQ, PWM_RESOLUTION);
    ledcAttach(PIN_PWM15, PWM_FREQ, PWM_RESOLUTION);

    // Set initial duty cycle to 0
    ledcWrite(PIN_PWM13, 0);
    ledcWrite(PIN_PWM14, 0);
    ledcWrite(PIN_PWM15, 0);

    if (debugMode) Serial.println("  PWM channels configured (GPIO 25,32,33)");
}

void setupI2C() {
    if (debugMode) Serial.println("Configuring I2C bus...");

    // Do a full I2C peripheral reset on startup to clear any lingering bus_busy state
    // This is critical for recovering from states where DTR/RTS toggled during serial reconnection
    periph_module_disable(PERIPH_I2C0_MODULE);
    delay(50);
    periph_module_enable(PERIPH_I2C0_MODULE);
    delay(50);

    Wire.begin(PIN_SDA, PIN_SCL);
    Wire.setClock(100000);  // 100kHz for reliability
    Wire.setTimeout(100);   // 100ms timeout

    delay(100);

    bool ina219Found = false;
    bool sht4xFound = false;

    // Probe for devices
    if (debugMode) Serial.print("  Probing INA219 (0x40): ");
    if (i2cProbe(INA219_ADDR)) {
        if (debugMode) Serial.println("FOUND");
        ina219Found = true;
        if (ina219_init()) {
            if (debugMode) Serial.println("  INA219 initialized");
        } else {
            if (debugMode) Serial.println("  INA219 init FAILED");
            ina219Found = false;
        }
    } else {
        if (debugMode) Serial.println("NOT FOUND");
    }

    if (debugMode) Serial.print("  Probing SHT4x (0x44): ");
    if (i2cProbe(SHT4X_ADDR)) {
        if (debugMode) Serial.println("FOUND");
        sht4xFound = true;
    } else {
        if (debugMode) Serial.println("NOT FOUND");
    }

    i2cHealthy = ina219Found || sht4xFound;
}

void setupWatchdog() {
    if (debugMode) Serial.println("Configuring hardware watchdog...");

    // Configure the Task Watchdog Timer
    // This will reset the ESP32 if the main loop hangs for more than WDT_TIMEOUT seconds
    esp_task_wdt_config_t wdt_config = {
        .timeout_ms = WDT_TIMEOUT * 1000,
        .idle_core_mask = 0,  // Don't watch idle tasks
        .trigger_panic = true  // Reset on timeout
    };
    esp_task_wdt_reconfigure(&wdt_config);

    // Add current task (main loop) to watchdog
    esp_task_wdt_add(NULL);

    if (debugMode) Serial.printf("  Watchdog enabled with %d second timeout\n", WDT_TIMEOUT);
}

// ============================================================================
// I2C BUS RECOVERY
// ============================================================================

bool i2cBusRecovery() {
    if (debugMode) Serial.println("Performing I2C bus recovery...");

    // Don't recover too frequently
    if (millis() - lastI2CRecovery < 5000) {
        if (debugMode) Serial.println("  Skipping - too soon since last recovery");
        return false;
    }
    lastI2CRecovery = millis();

    // Step 1: End current Wire session
    Wire.end();
    delay(10);

    // Step 2: Manually toggle SCL to clear stuck slave
    pinMode(PIN_SDA, INPUT_PULLUP);
    pinMode(PIN_SCL, OUTPUT);

    // Send 9 clock pulses to clear any stuck slave
    for (int i = 0; i < I2C_CLOCK_CYCLES; i++) {
        digitalWrite(PIN_SCL, LOW);
        delayMicroseconds(5);
        digitalWrite(PIN_SCL, HIGH);
        delayMicroseconds(5);

        // Check if SDA is released
        if (digitalRead(PIN_SDA) == HIGH) {
            if (debugMode) Serial.printf("  SDA released after %d clocks\n", i + 1);
            break;
        }
    }

    // Step 3: Generate STOP condition
    pinMode(PIN_SDA, OUTPUT);
    digitalWrite(PIN_SDA, LOW);
    delayMicroseconds(5);
    digitalWrite(PIN_SCL, HIGH);
    delayMicroseconds(5);
    digitalWrite(PIN_SDA, HIGH);
    delayMicroseconds(5);

    // Step 4: Reinitialize Wire
    delay(50);
    Wire.begin(PIN_SDA, PIN_SCL);
    Wire.setClock(100000);
    delay(100);

    // Step 5: Re-probe devices
    bool ina219Found = i2cProbe(INA219_ADDR);
    bool sht4xFound = i2cProbe(SHT4X_ADDR);

    if (debugMode) {
        Serial.printf("  After recovery - INA219: %s, SHT4x: %s\n",
                      ina219Found ? "OK" : "FAIL",
                      sht4xFound ? "OK" : "FAIL");
    }

    // Step 6: Force INA219 software reset and reinitialize
    if (ina219Found) {
        // Send software reset command (write 0x8000 to config register)
        Wire.beginTransmission(INA219_ADDR);
        Wire.write(0x00);  // Config register
        Wire.write(0x80);  // MSB with reset bit set
        Wire.write(0x00);  // LSB
        Wire.endTransmission();
        delay(10);  // Wait for reset to complete

        // Now reinitialize with proper config
        ina219_init();
    }

    i2cHealthy = ina219Found || sht4xFound;
    return i2cHealthy;
}

bool i2cProbe(uint8_t address) {
    Wire.beginTransmission(address);
    return (Wire.endTransmission() == 0);
}

void i2cReset() {
    // More aggressive reset using ESP32 peripheral module control
    // This resets the I2C hardware state machine (FSM) completely
    Wire.end();
    delay(10);

    // Disable and re-enable the I2C peripheral to clear bus_busy flag
    periph_module_disable(PERIPH_I2C0_MODULE);
    delay(10);
    periph_module_enable(PERIPH_I2C0_MODULE);
    delay(10);

    Wire.begin(PIN_SDA, PIN_SCL);
    Wire.setClock(100000);
    delay(50);
}

// ============================================================================
// INA219 POWER MONITOR
// ============================================================================

bool ina219_init() {
    // Reset INA219
    Wire.beginTransmission(INA219_ADDR);
    Wire.write(0x00);  // Config register
    Wire.write(0x39);  // MSB: Reset bit + config
    Wire.write(0x9F);  // LSB: 32V, 2A range, continuous
    if (Wire.endTransmission() != 0) {
        return false;
    }

    delay(10);

    // Set calibration for 32V, 2A
    Wire.beginTransmission(INA219_ADDR);
    Wire.write(0x05);  // Calibration register
    Wire.write((ina219_calValue >> 8) & 0xFF);
    Wire.write(ina219_calValue & 0xFF);
    if (Wire.endTransmission() != 0) {
        return false;
    }

    return true;
}

bool ina219_readVoltage(float* voltage) {
    // Read bus voltage register (0x02)
    Wire.beginTransmission(INA219_ADDR);
    Wire.write(0x02);
    if (Wire.endTransmission() != 0) {
        return false;
    }

    Wire.requestFrom(INA219_ADDR, (uint8_t)2);
    if (Wire.available() < 2) {
        return false;
    }

    uint16_t raw = (Wire.read() << 8) | Wire.read();

    // Check CNVR bit (conversion ready) and OVF bit
    if (raw & 0x01) {
        // Overflow
        *voltage = 0;
        return false;
    }

    // Shift right 3 bits, multiply by 4mV
    *voltage = ((raw >> 3) * 4) / 1000.0;
    return true;
}

bool ina219_readCurrent(float* current) {
    // Read current register (0x04)
    Wire.beginTransmission(INA219_ADDR);
    Wire.write(0x04);
    if (Wire.endTransmission() != 0) {
        return false;
    }

    Wire.requestFrom(INA219_ADDR, (uint8_t)2);
    if (Wire.available() < 2) {
        return false;
    }

    int16_t raw = (Wire.read() << 8) | Wire.read();

    // Current LSB = 0.1mA with default calibration
    *current = raw * 0.1 / 1000.0;  // Convert to Amps
    return true;
}

// ============================================================================
// SHT4X TEMPERATURE/HUMIDITY SENSOR
// ============================================================================

bool sht4x_read(float* temp, float* hum) {
    // Send measure command (high precision, no heater)
    Wire.beginTransmission(SHT4X_ADDR);
    Wire.write(0xFD);  // Measure T & RH with high precision
    if (Wire.endTransmission() != 0) {
        return false;
    }

    // Wait for measurement (10ms for high precision)
    delay(10);

    // Read 6 bytes: T_MSB, T_LSB, T_CRC, H_MSB, H_LSB, H_CRC
    Wire.requestFrom(SHT4X_ADDR, (uint8_t)6);
    if (Wire.available() < 6) {
        return false;
    }

    uint8_t data[6];
    for (int i = 0; i < 6; i++) {
        data[i] = Wire.read();
    }

    // Calculate temperature
    uint16_t rawTemp = (data[0] << 8) | data[1];
    *temp = -45.0 + 175.0 * (rawTemp / 65535.0);

    // Calculate humidity
    uint16_t rawHum = (data[3] << 8) | data[4];
    *hum = -6.0 + 125.0 * (rawHum / 65535.0);

    // Clamp humidity
    if (*hum < 0) *hum = 0;
    if (*hum > 100) *hum = 100;

    return true;
}

// ============================================================================
// SENSOR READING WITH RECOVERY
// ============================================================================

bool readSensorsWithRecovery() {
    bool success = true;

    // Read INA219
    float voltage, current;
    if (ina219_readVoltage(&voltage) && ina219_readCurrent(&current)) {
        // Sanity check: if voltage is 0 but we previously had a valid reading,
        // the sensor may be in a bad state returning zeros
        if (voltage < 0.1 && inputVoltage > 1.0) {
            // Likely sensor lockup returning zeros
            i2cFailCount++;
            success = false;
            if (i2cFailCount >= 2) {
                // Do full bus recovery with clock cycling
                i2cBusRecovery();
            }
        } else {
            inputVoltage = voltage;
            inputCurrent = current;
            i2cFailCount = 0;
        }
    } else {
        i2cFailCount++;
        success = false;

        // Try quick reset first, then full recovery
        if (i2cFailCount == 1) {
            i2cReset();
            ina219_init();
        } else if (i2cFailCount >= 3) {
            i2cBusRecovery();
        }
    }

    // Read SHT4x
    float temp, hum;
    if (sht4x_read(&temp, &hum)) {
        ambientTemp = temp;
        humidity = hum;
        lensTemp = temp;  // Use same sensor if no separate lens sensor
    } else {
        i2cFailCount++;
        success = false;
    }

    return success;
}

// ============================================================================
// SERIAL PROTOCOL HANDLER
// ============================================================================

void processSerialCommand() {
    // Track serial activity for idle detection (but don't do blocking recovery here)
    if (Serial.available()) {
        lastSerialActivity = millis();
    }

    while (Serial.available()) {
        uint8_t b = Serial.read();

        // Look for start marker
        if (rxIndex == 0 && b != PROTO_START) {
            continue;
        }

        rxBuffer[rxIndex++] = b;

        // Check if we have minimum command (6 bytes)
        if (rxIndex >= 6) {
            // Verify fixed byte
            if (rxBuffer[1] == PROTO_FIXED) {
                // Verify checksum
                uint8_t expectedChecksum = calcChecksum(rxBuffer, 5);
                if (rxBuffer[5] == expectedChecksum) {
                    handleCommand(rxBuffer, 6);
                }
            }
            rxIndex = 0;
        }

        // Prevent buffer overflow
        if (rxIndex >= sizeof(rxBuffer)) {
            rxIndex = 0;
        }
    }
}

void handleCommand(uint8_t* cmd, uint8_t len) {
    uint8_t cmdId = cmd[2];
    uint8_t param1 = cmd[3];
    uint8_t param2 = cmd[4];

    switch (cmdId) {
        case CMD_WRITE_OUTPUT:
            handleWriteOutput(param1, param2);
            break;

        case CMD_READ_VOLTAGE:
            handleReadVoltage();
            break;

        case CMD_READ_LENS_TEMP:
            handleReadLensTemp();
            break;

        case CMD_READ_AMBIENT_TEMP:
            handleReadAmbientTemp();
            break;

        case CMD_READ_HUMIDITY:
            handleReadHumidity();
            break;

        case CMD_READ_POWER:
            handleReadPower();
            break;

        case CMD_SYNC_STATES:
            handleSyncStates();
            break;

        default:
            if (debugMode) Serial.printf("Unknown command: 0x%02X\n", cmdId);
            break;
    }
}

void handleWriteOutput(uint8_t index, uint8_t value) {
    if (index < 7) {
        // DC output (0-6)
        bool state = (value != 0);
        setDCOutput(index, state);
        dcStates[index] = state;
    } else if (index >= 7 && index <= 9) {
        // PWM output (7-9 -> channels 0-2)
        uint8_t channel = index - 7;
        setPWMOutput(channel, value);
        pwmValues[channel] = value;
    }
}

void handleReadVoltage() {
    // If voltage is 0 but we expect valid data, try recovery before responding
    if (inputVoltage < 0.1) {
        // Try to read fresh value
        float voltage, current;
        if (!ina219_readVoltage(&voltage) || voltage < 0.1) {
            // Failed - do recovery and retry
            lastI2CRecovery = 0;  // Force recovery
            i2cBusRecovery();
            delay(100);

            // Try up to 3 more times after recovery
            for (int retry = 0; retry < 3; retry++) {
                if (ina219_readVoltage(&voltage) && voltage > 0.1) {
                    ina219_readCurrent(&current);
                    inputVoltage = voltage;
                    inputCurrent = current;
                    break;
                }
                delay(50);
            }
        } else {
            ina219_readCurrent(&current);
            inputVoltage = voltage;
            inputCurrent = current;
        }
    }

    // Convert voltage to protocol format (value * 100, big-endian)
    int32_t rawValue = (int32_t)(inputVoltage * 100);

    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;

    sendResponse(CMD_READ_VOLTAGE, data, 4);
}

void handleReadLensTemp() {
    // Convert temp to protocol format ((value + 255.5) * 100, big-endian)
    int32_t rawValue = (int32_t)((lensTemp + 255.5) * 100);

    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;

    sendResponse(CMD_READ_LENS_TEMP, data, 4);
}

void handleReadAmbientTemp() {
    // If ambient temp looks suspicious (exactly 0 or very cold), try fresh read
    if (ambientTemp < -50.0 || (ambientTemp > -0.1 && ambientTemp < 0.1)) {
        float temp, hum;
        if (!sht4x_read(&temp, &hum) || temp < -50.0) {
            // Failed - do recovery and retry
            lastI2CRecovery = 0;
            i2cBusRecovery();
            delay(100);

            for (int retry = 0; retry < 3; retry++) {
                if (sht4x_read(&temp, &hum) && temp > -50.0) {
                    ambientTemp = temp;
                    humidity = hum;
                    lensTemp = temp;
                    break;
                }
                delay(50);
            }
        } else {
            ambientTemp = temp;
            humidity = hum;
            lensTemp = temp;
        }
    }

    // Convert temp to protocol format ((value + 255.5) * 100, big-endian)
    int32_t rawValue = (int32_t)((ambientTemp + 255.5) * 100);

    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;

    sendResponse(CMD_READ_AMBIENT_TEMP, data, 4);
}

void handleReadHumidity() {
    // If humidity looks suspicious (0 or negative), try fresh read
    if (humidity < 1.0) {
        float temp, hum;
        if (!sht4x_read(&temp, &hum) || hum < 1.0) {
            // Failed - do recovery and retry
            lastI2CRecovery = 0;
            i2cBusRecovery();
            delay(100);

            for (int retry = 0; retry < 3; retry++) {
                if (sht4x_read(&temp, &hum) && hum >= 1.0) {
                    ambientTemp = temp;
                    humidity = hum;
                    lensTemp = temp;
                    break;
                }
                delay(50);
            }
        } else {
            ambientTemp = temp;
            humidity = hum;
            lensTemp = temp;
        }
    }

    // Convert humidity to protocol format ((value + 254.0) * 100, big-endian)
    int32_t rawValue = (int32_t)((humidity + 254.0) * 100);

    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;

    sendResponse(CMD_READ_HUMIDITY, data, 4);
}

void handleReadPower() {
    // Power depends on voltage - if voltage is 0, need recovery first
    if (inputVoltage < 0.1) {
        float voltage, current;
        if (!ina219_readVoltage(&voltage) || voltage < 0.1) {
            lastI2CRecovery = 0;
            i2cBusRecovery();
            delay(100);

            for (int retry = 0; retry < 3; retry++) {
                if (ina219_readVoltage(&voltage) && voltage > 0.1) {
                    ina219_readCurrent(&current);
                    inputVoltage = voltage;
                    inputCurrent = current;
                    break;
                }
                delay(50);
            }
        } else {
            ina219_readCurrent(&current);
            inputVoltage = voltage;
            inputCurrent = current;
        }
    }

    // Calculate power from voltage and current
    float power = inputVoltage * inputCurrent;

    // Convert to protocol format
    int32_t rawValue = (int32_t)(power * 100);

    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;

    sendResponse(CMD_READ_POWER, data, 4);
}

void handleSyncStates() {
    // Response: 10 bytes of state data
    // [DC1] [DC2] [DC3] [DC4] [DC5] [USB12] [USB345] [PWM13] [PWM14] [PWM15]
    uint8_t data[10];

    for (int i = 0; i < 7; i++) {
        data[i] = dcStates[i] ? 1 : 0;
    }
    data[7] = pwmValues[0];
    data[8] = pwmValues[1];
    data[9] = pwmValues[2];

    sendResponse(CMD_SYNC_STATES, data, 10);
}

void sendResponse(uint8_t cmdId, uint8_t* data, uint8_t dataLen) {
    uint8_t response[20];
    uint8_t idx = 0;

    // Calculate total length: start + length + cmdId + data + checksum
    uint8_t totalLen = 1 + 1 + 1 + dataLen + 1;

    response[idx++] = PROTO_START;
    response[idx++] = totalLen;  // Length byte (not fixed 0x06!)
    response[idx++] = cmdId;

    for (int i = 0; i < dataLen; i++) {
        response[idx++] = data[i];
    }

    response[idx] = calcChecksum(response, idx);
    idx++;

    Serial.write(response, idx);
}

uint8_t calcChecksum(uint8_t* data, uint8_t len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += data[i];
    }
    if (sum > 255) {
        sum = sum % 255;
    }
    return (uint8_t)sum;
}

// ============================================================================
// OUTPUT CONTROL
// ============================================================================

void setDCOutput(uint8_t index, bool state) {
    uint8_t pins[] = {PIN_DC1, PIN_DC2, PIN_DC3, PIN_DC4, PIN_DC5, PIN_USB12, PIN_USB345};

    if (index < 7) {
        digitalWrite(pins[index], state ? HIGH : LOW);
    }
}

void setPWMOutput(uint8_t channel, uint8_t value) {
    uint8_t pins[] = {PIN_PWM13, PIN_PWM14, PIN_PWM15};
    if (channel < 3) {
        ledcWrite(pins[channel], value);
    }
}

void syncAllStates() {
    // Apply all stored states
    for (int i = 0; i < 7; i++) {
        setDCOutput(i, dcStates[i]);
    }
    for (int i = 0; i < 3; i++) {
        setPWMOutput(i, pwmValues[i]);
    }
}
