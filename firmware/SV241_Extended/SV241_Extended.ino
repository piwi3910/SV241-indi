/**
 * SVBONY SV241 Power Box - Extended Firmware v2.0
 *
 * Features:
 * - Full backward compatibility with original binary protocol (0x01-0x08)
 * - Extended JSON protocol (0x10) for advanced features
 * - Auto dew heater control with PID
 * - Session statistics tracking
 * - Voltage and thermal alerts
 * - Sensor calibration offsets
 * - I2C bus recovery (inherited from v1.x)
 *
 * Hardware:
 * - ESP32-PICO-D4
 * - INA219 power monitor (I2C 0x40)
 * - SHT4x temperature/humidity sensor (I2C 0x44)
 * - 7x digital outputs (DC1-5, USB12, USB345)
 * - 3x PWM outputs (variable voltage, 2x dew heaters)
 *
 * Protocol:
 * - Binary commands 0x01-0x08: Original SVBONY protocol (Windows app compatible)
 * - JSON command 0x10: Extended protocol for INDI driver
 *
 * See docs/EXTENDED_PROTOCOL.md for full protocol specification.
 */

#include <Wire.h>
#include <ArduinoJson.h>
#include <EEPROM.h>
#include <esp_task_wdt.h>
#include <driver/periph_ctrl.h>
#include <math.h>

// ============================================================================
// VERSION INFO
// ============================================================================

#define FIRMWARE_NAME    "SV241-EXT"
#define FIRMWARE_VERSION "2.0.0"

// ============================================================================
// PIN DEFINITIONS
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
#define PWM_FREQ       5000
#define PWM_RESOLUTION 8
#define PWM_MAX_VALUE  253

// Protocol Constants
#define PROTO_START    0x24  // '$' character
#define PROTO_FIXED    0x06

// Command IDs - Original protocol
#define CMD_WRITE_OUTPUT    0x01
#define CMD_READ_VOLTAGE    0x03
#define CMD_READ_LENS_TEMP  0x04
#define CMD_READ_AMBIENT_TEMP 0x05
#define CMD_READ_HUMIDITY   0x06
#define CMD_READ_POWER      0x07
#define CMD_SYNC_STATES     0x08

// Command ID - Extended JSON protocol
#define CMD_EXTENDED        0x10

// I2C recovery settings
#define I2C_RECOVERY_RETRIES  3
#define I2C_CLOCK_CYCLES      9

// EEPROM layout
#define EEPROM_SIZE           512
#define EEPROM_MAGIC          0xSV41
#define EEPROM_ADDR_MAGIC     0
#define EEPROM_ADDR_CAL       4    // Calibration offsets (12 bytes)
#define EEPROM_ADDR_DEW       20   // Dew config (32 bytes)
#define EEPROM_ADDR_ALERTS    60   // Alert config (16 bytes)
#define EEPROM_ADDR_NAMES     80   // Port names (7x16 = 112 bytes)
#define EEPROM_ADDR_PROFILES  200  // Profiles (3x32 = 96 bytes)

// ============================================================================
// DATA STRUCTURES
// ============================================================================

// Calibration offsets
struct CalibrationData {
    float v_offset;
    float t_offset;
    float h_offset;
};

// Dew heater configuration (per channel)
struct DewConfig {
    bool autoMode;
    float margin;      // Degrees above dew point
    float kp, ki, kd;  // PID parameters
    float i_max;       // Integral limit
    // Runtime state (not saved)
    float integral;
    float lastError;
    unsigned long lastUpdate;
};

// Alert configuration
struct AlertConfig {
    bool lowVoltageEnabled;
    float lowVoltageThreshold;
    bool critVoltageEnabled;
    float critVoltageThreshold;
    bool critAutoOff;
};

// Session statistics
struct SessionStats {
    unsigned long startTime;
    float v_min, v_max, v_sum;
    float p_max, p_total;
    float t_min, t_max;
    uint32_t sampleCount;
    uint16_t i2cRecoveries;
};

// Alert state
struct AlertState {
    bool lowVoltage;
    bool critVoltage;
    bool thermal;
    bool i2cFail;
};

// Port names (stored in EEPROM)
#define PORT_NAME_MAX_LEN 15
struct PortNames {
    char dc[7][PORT_NAME_MAX_LEN + 1];   // DC1-5, USB12, USB345
    char pwm[3][PORT_NAME_MAX_LEN + 1];  // PWM13, PWM14, PWM15
};

// ============================================================================
// GLOBAL STATE
// ============================================================================

// Output states
bool dcStates[7] = {false, false, false, false, false, false, false};
uint8_t pwmValues[3] = {0, 0, 0};

// Sensor values (raw from sensors)
float inputVoltage = 0.0;
float inputCurrent = 0.0;
float ambientTemp = 0.0;
float humidity = 0.0;
float lensTemp = 0.0;
float dewPoint = 0.0;

// Calibration
CalibrationData calibration = {0.0, 0.0, 0.0};

// Dew heater config (PWM14 and PWM15)
DewConfig dewConfig[2] = {
    {false, 5.0, 2.0, 0.5, 0.1, 50.0, 0.0, 0.0, 0},
    {false, 5.0, 2.0, 0.5, 0.1, 50.0, 0.0, 0.0, 0}
};

// Alerts
AlertConfig alertConfig = {true, 11.5, true, 11.0, true};
AlertState alertState = {false, false, false, false};

// Port names (with defaults)
PortNames portNames = {
    {"DC1", "DC2", "DC3", "DC4", "DC5", "USB12", "USB345"},
    {"PWM13", "PWM14", "PWM15"}
};

// Statistics
SessionStats stats;

// I2C health tracking
uint8_t i2cFailCount = 0;
bool i2cHealthy = false;
unsigned long lastI2CRecovery = 0;

// INA219 calibration
uint16_t ina219_calValue = 4096;

// Serial buffer
uint8_t rxBuffer[256];  // Larger buffer for JSON
uint8_t rxIndex = 0;

// Debug mode
bool debugMode = false;

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================

// Setup functions
void setupGPIO();
void setupPWM();
void setupI2C();
void setupEEPROM();

// I2C functions
bool i2cBusRecovery();
void i2cReset();
bool i2cProbe(uint8_t address);

// Sensor functions
bool ina219_init();
bool ina219_readVoltage(float* voltage);
bool ina219_readCurrent(float* current);
bool sht4x_read(float* temp, float* hum);
bool readSensorsWithRecovery();

// Protocol handlers
void processSerialCommand();
void handleCommand(uint8_t* cmd, uint8_t len);
void handleExtendedCommand(uint8_t* payload, uint8_t len);
void sendResponse(uint8_t cmdId, uint8_t* data, uint8_t dataLen);
void sendJsonResponse(const char* json);
uint8_t calcChecksum(uint8_t* data, uint8_t len);

// Original command handlers
void handleWriteOutput(uint8_t index, uint8_t value);
void handleReadVoltage();
void handleReadLensTemp();
void handleReadAmbientTemp();
void handleReadHumidity();
void handleReadPower();
void handleSyncStates();

// Extended command handlers
void handleCmdVersion(JsonDocument& doc);
void handleCmdStatus(JsonDocument& doc);
void handleCmdDewStatus(JsonDocument& doc);
void handleCmdDewConfig(JsonDocument& doc);
void handleCmdStats(JsonDocument& doc);
void handleCmdStatsReset(JsonDocument& doc);
void handleCmdAlertConfig(JsonDocument& doc);
void handleCmdAlerts(JsonDocument& doc);
void handleCmdDiag(JsonDocument& doc);
void handleCmdI2CRecovery(JsonDocument& doc);
void handleCmdCalGet(JsonDocument& doc);
void handleCmdCalSet(JsonDocument& doc);
void handleCmdNamesGet(JsonDocument& doc);
void handleCmdNamesSet(JsonDocument& doc);

// Output control
void setDCOutput(uint8_t index, bool state);
void setPWMOutput(uint8_t channel, uint8_t value);

// Dew control
float calculateDewPoint(float temp, float humidity);
void updateDewControl();

// Statistics
void updateStats();
void resetStats();

// EEPROM
void loadConfig();
void saveCalibration();
void saveDewConfig();
void saveAlertConfig();
void savePortNames();

// ============================================================================
// SETUP
// ============================================================================

void setup() {
    Serial.begin(115200);
    delay(100);

    if (debugMode) {
        Serial.println("\n\n=================================");
        Serial.printf("%s v%s\n", FIRMWARE_NAME, FIRMWARE_VERSION);
        Serial.println("Extended JSON Protocol Enabled");
        Serial.println("=================================\n");
    }

    setupEEPROM();
    setupGPIO();
    setupPWM();
    setupI2C();

    // Initialize outputs to OFF
    for (int i = 0; i < 7; i++) {
        setDCOutput(i, false);
    }
    for (int i = 0; i < 3; i++) {
        setPWMOutput(i, 0);
    }

    // Initialize statistics
    resetStats();

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

        if (!readSensorsWithRecovery()) {
            if (i2cFailCount >= I2C_RECOVERY_RETRIES) {
                i2cBusRecovery();
                i2cFailCount = 0;
                stats.i2cRecoveries++;
            }
        }

        // Calculate dew point
        dewPoint = calculateDewPoint(ambientTemp, humidity);

        // Update statistics
        updateStats();

        // Check alerts
        alertState.lowVoltage = alertConfig.lowVoltageEnabled &&
                                (inputVoltage > 0.1) &&
                                (inputVoltage < alertConfig.lowVoltageThreshold);
        alertState.critVoltage = alertConfig.critVoltageEnabled &&
                                 (inputVoltage > 0.1) &&
                                 (inputVoltage < alertConfig.critVoltageThreshold);
        alertState.i2cFail = !i2cHealthy;

        // Auto-shutdown on critical voltage
        if (alertState.critVoltage && alertConfig.critAutoOff) {
            // Turn off dew heaters to save power
            setPWMOutput(1, 0);  // PWM14
            setPWMOutput(2, 0);  // PWM15
            pwmValues[1] = 0;
            pwmValues[2] = 0;
        }
    }

    // Dew control update (every 5 seconds)
    static unsigned long lastDewUpdate = 0;
    if (millis() - lastDewUpdate > 5000) {
        lastDewUpdate = millis();
        updateDewControl();
    }

    delay(5);
}

// ============================================================================
// INITIALIZATION
// ============================================================================

void setupGPIO() {
    if (debugMode) Serial.println("Configuring GPIO pins...");

    pinMode(PIN_DC1, OUTPUT);
    pinMode(PIN_DC2, OUTPUT);
    pinMode(PIN_DC3, OUTPUT);
    pinMode(PIN_DC4, OUTPUT);
    pinMode(PIN_DC5, OUTPUT);
    pinMode(PIN_USB12, OUTPUT);
    pinMode(PIN_USB345, OUTPUT);

    digitalWrite(PIN_DC1, LOW);
    digitalWrite(PIN_DC2, LOW);
    digitalWrite(PIN_DC3, LOW);
    digitalWrite(PIN_DC4, LOW);
    digitalWrite(PIN_DC5, LOW);
    digitalWrite(PIN_USB12, LOW);
    digitalWrite(PIN_USB345, LOW);
}

void setupPWM() {
    if (debugMode) Serial.println("Configuring PWM channels...");

    ledcAttach(PIN_PWM13, PWM_FREQ, PWM_RESOLUTION);
    ledcAttach(PIN_PWM14, PWM_FREQ, PWM_RESOLUTION);
    ledcAttach(PIN_PWM15, PWM_FREQ, PWM_RESOLUTION);

    ledcWrite(PIN_PWM13, 0);
    ledcWrite(PIN_PWM14, 0);
    ledcWrite(PIN_PWM15, 0);
}

void setupI2C() {
    if (debugMode) Serial.println("Configuring I2C bus...");

    // Full peripheral reset on startup
    periph_module_disable(PERIPH_I2C0_MODULE);
    delay(50);
    periph_module_enable(PERIPH_I2C0_MODULE);
    delay(50);

    Wire.begin(PIN_SDA, PIN_SCL);
    Wire.setClock(100000);
    Wire.setTimeout(100);
    delay(100);

    bool ina219Found = i2cProbe(INA219_ADDR);
    bool sht4xFound = i2cProbe(SHT4X_ADDR);

    if (ina219Found) {
        ina219_init();
    }

    i2cHealthy = ina219Found || sht4xFound;

    if (debugMode) {
        Serial.printf("  INA219: %s, SHT4x: %s\n",
                      ina219Found ? "OK" : "NOT FOUND",
                      sht4xFound ? "OK" : "NOT FOUND");
    }
}

void setupEEPROM() {
    EEPROM.begin(EEPROM_SIZE);
    loadConfig();
}

// ============================================================================
// EEPROM FUNCTIONS
// ============================================================================

void loadConfig() {
    // Check magic number
    uint16_t magic;
    EEPROM.get(EEPROM_ADDR_MAGIC, magic);

    if (magic != 0x5641) {  // "VA" for validation
        // First run - initialize with defaults
        if (debugMode) Serial.println("EEPROM: First run, using defaults");
        EEPROM.put(EEPROM_ADDR_MAGIC, (uint16_t)0x5641);
        saveCalibration();
        saveDewConfig();
        saveAlertConfig();
        savePortNames();
        EEPROM.commit();
        return;
    }

    // Load calibration
    EEPROM.get(EEPROM_ADDR_CAL, calibration);

    // Load dew config
    EEPROM.get(EEPROM_ADDR_DEW, dewConfig);

    // Load alert config
    EEPROM.get(EEPROM_ADDR_ALERTS, alertConfig);

    // Load port names
    EEPROM.get(EEPROM_ADDR_NAMES, portNames);

    if (debugMode) Serial.println("EEPROM: Config loaded");
}

void saveCalibration() {
    EEPROM.put(EEPROM_ADDR_CAL, calibration);
    EEPROM.commit();
}

void saveDewConfig() {
    EEPROM.put(EEPROM_ADDR_DEW, dewConfig);
    EEPROM.commit();
}

void saveAlertConfig() {
    EEPROM.put(EEPROM_ADDR_ALERTS, alertConfig);
    EEPROM.commit();
}

void savePortNames() {
    EEPROM.put(EEPROM_ADDR_NAMES, portNames);
    EEPROM.commit();
}

// ============================================================================
// I2C BUS RECOVERY (inherited from v1.x)
// ============================================================================

bool i2cBusRecovery() {
    if (debugMode) Serial.println("Performing I2C bus recovery...");

    if (millis() - lastI2CRecovery < 5000) {
        return false;
    }
    lastI2CRecovery = millis();

    Wire.end();
    delay(10);

    pinMode(PIN_SDA, INPUT_PULLUP);
    pinMode(PIN_SCL, OUTPUT);

    for (int i = 0; i < I2C_CLOCK_CYCLES; i++) {
        digitalWrite(PIN_SCL, LOW);
        delayMicroseconds(5);
        digitalWrite(PIN_SCL, HIGH);
        delayMicroseconds(5);

        if (digitalRead(PIN_SDA) == HIGH) {
            break;
        }
    }

    // Generate STOP condition
    pinMode(PIN_SDA, OUTPUT);
    digitalWrite(PIN_SDA, LOW);
    delayMicroseconds(5);
    digitalWrite(PIN_SCL, HIGH);
    delayMicroseconds(5);
    digitalWrite(PIN_SDA, HIGH);
    delayMicroseconds(5);

    delay(50);
    Wire.begin(PIN_SDA, PIN_SCL);
    Wire.setClock(100000);
    delay(100);

    bool ina219Found = i2cProbe(INA219_ADDR);
    bool sht4xFound = i2cProbe(SHT4X_ADDR);

    if (ina219Found) {
        // Software reset and reinitialize
        Wire.beginTransmission(INA219_ADDR);
        Wire.write(0x00);
        Wire.write(0x80);
        Wire.write(0x00);
        Wire.endTransmission();
        delay(10);
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
    Wire.end();
    delay(10);
    periph_module_disable(PERIPH_I2C0_MODULE);
    delay(10);
    periph_module_enable(PERIPH_I2C0_MODULE);
    delay(10);
    Wire.begin(PIN_SDA, PIN_SCL);
    Wire.setClock(100000);
    delay(50);
}

// ============================================================================
// SENSOR FUNCTIONS
// ============================================================================

bool ina219_init() {
    Wire.beginTransmission(INA219_ADDR);
    Wire.write(0x00);
    Wire.write(0x39);
    Wire.write(0x9F);
    if (Wire.endTransmission() != 0) return false;

    delay(10);

    Wire.beginTransmission(INA219_ADDR);
    Wire.write(0x05);
    Wire.write((ina219_calValue >> 8) & 0xFF);
    Wire.write(ina219_calValue & 0xFF);
    return (Wire.endTransmission() == 0);
}

bool ina219_readVoltage(float* voltage) {
    Wire.beginTransmission(INA219_ADDR);
    Wire.write(0x02);
    if (Wire.endTransmission() != 0) return false;

    Wire.requestFrom(INA219_ADDR, (uint8_t)2);
    if (Wire.available() < 2) return false;

    uint16_t raw = (Wire.read() << 8) | Wire.read();
    if (raw & 0x01) {
        *voltage = 0;
        return false;
    }

    *voltage = ((raw >> 3) * 4) / 1000.0;
    return true;
}

bool ina219_readCurrent(float* current) {
    Wire.beginTransmission(INA219_ADDR);
    Wire.write(0x04);
    if (Wire.endTransmission() != 0) return false;

    Wire.requestFrom(INA219_ADDR, (uint8_t)2);
    if (Wire.available() < 2) return false;

    int16_t raw = (Wire.read() << 8) | Wire.read();
    *current = raw * 0.1 / 1000.0;
    return true;
}

bool sht4x_read(float* temp, float* hum) {
    Wire.beginTransmission(SHT4X_ADDR);
    Wire.write(0xFD);
    if (Wire.endTransmission() != 0) return false;

    delay(10);

    Wire.requestFrom(SHT4X_ADDR, (uint8_t)6);
    if (Wire.available() < 6) return false;

    uint8_t data[6];
    for (int i = 0; i < 6; i++) {
        data[i] = Wire.read();
    }

    uint16_t rawTemp = (data[0] << 8) | data[1];
    *temp = -45.0 + 175.0 * (rawTemp / 65535.0);

    uint16_t rawHum = (data[3] << 8) | data[4];
    *hum = -6.0 + 125.0 * (rawHum / 65535.0);

    if (*hum < 0) *hum = 0;
    if (*hum > 100) *hum = 100;

    return true;
}

bool readSensorsWithRecovery() {
    bool success = true;

    float voltage, current;
    if (ina219_readVoltage(&voltage) && ina219_readCurrent(&current)) {
        if (voltage < 0.1 && inputVoltage > 1.0) {
            i2cFailCount++;
            success = false;
            if (i2cFailCount >= 2) {
                i2cBusRecovery();
            }
        } else {
            inputVoltage = voltage + calibration.v_offset;
            inputCurrent = current;
            i2cFailCount = 0;
        }
    } else {
        i2cFailCount++;
        success = false;
        if (i2cFailCount == 1) {
            i2cReset();
            ina219_init();
        } else if (i2cFailCount >= 3) {
            i2cBusRecovery();
        }
    }

    float temp, hum;
    if (sht4x_read(&temp, &hum)) {
        ambientTemp = temp + calibration.t_offset;
        humidity = hum + calibration.h_offset;
        lensTemp = ambientTemp;
    } else {
        i2cFailCount++;
        success = false;
    }

    return success;
}

// ============================================================================
// DEW POINT CALCULATION & CONTROL
// ============================================================================

float calculateDewPoint(float temp, float hum) {
    // Magnus-Tetens approximation
    const float a = 17.27;
    const float b = 237.7;

    if (hum <= 0) return -999;

    float gamma = (a * temp) / (b + temp) + log(hum / 100.0);
    return (b * gamma) / (a - gamma);
}

void updateDewControl() {
    // Only run if we have valid sensor data
    if (ambientTemp < -50 || humidity < 1) return;

    for (int ch = 0; ch < 2; ch++) {
        if (!dewConfig[ch].autoMode) continue;

        // Calculate target temperature
        float target = dewPoint + dewConfig[ch].margin;

        // For now, use ambient temp as proxy for heater temp
        // (A real implementation might have a separate sensor on the heater)
        float currentTemp = ambientTemp;

        // PID calculation
        float error = target - currentTemp;
        unsigned long now = millis();
        float dt = (now - dewConfig[ch].lastUpdate) / 1000.0;

        if (dt > 0 && dewConfig[ch].lastUpdate > 0) {
            // Proportional
            float P = dewConfig[ch].kp * error;

            // Integral
            dewConfig[ch].integral += error * dt;
            // Clamp integral
            if (dewConfig[ch].integral > dewConfig[ch].i_max)
                dewConfig[ch].integral = dewConfig[ch].i_max;
            if (dewConfig[ch].integral < -dewConfig[ch].i_max)
                dewConfig[ch].integral = -dewConfig[ch].i_max;
            float I = dewConfig[ch].ki * dewConfig[ch].integral;

            // Derivative
            float D = dewConfig[ch].kd * (error - dewConfig[ch].lastError) / dt;

            // Calculate output
            float output = P + I + D;

            // Clamp to PWM range
            if (output < 0) output = 0;
            if (output > PWM_MAX_VALUE) output = PWM_MAX_VALUE;

            // Apply PWM
            uint8_t pwmVal = (uint8_t)output;
            int pwmChannel = ch + 1;  // PWM14=ch1, PWM15=ch2
            setPWMOutput(pwmChannel, pwmVal);
            pwmValues[pwmChannel] = pwmVal;
        }

        dewConfig[ch].lastError = error;
        dewConfig[ch].lastUpdate = now;
    }
}

// ============================================================================
// STATISTICS
// ============================================================================

void resetStats() {
    stats.startTime = millis();
    stats.v_min = 999;
    stats.v_max = 0;
    stats.v_sum = 0;
    stats.p_max = 0;
    stats.p_total = 0;
    stats.t_min = 999;
    stats.t_max = -999;
    stats.sampleCount = 0;
    stats.i2cRecoveries = 0;
}

void updateStats() {
    if (inputVoltage < 0.1) return;  // Invalid reading

    stats.sampleCount++;

    // Voltage stats
    if (inputVoltage < stats.v_min) stats.v_min = inputVoltage;
    if (inputVoltage > stats.v_max) stats.v_max = inputVoltage;
    stats.v_sum += inputVoltage;

    // Power stats
    float power = inputVoltage * inputCurrent;
    if (power > stats.p_max) stats.p_max = power;
    stats.p_total += power * 2.0 / 3600.0;  // Wh (2 second interval)

    // Temperature stats
    if (ambientTemp > -50) {
        if (ambientTemp < stats.t_min) stats.t_min = ambientTemp;
        if (ambientTemp > stats.t_max) stats.t_max = ambientTemp;
    }
}

// ============================================================================
// SERIAL PROTOCOL HANDLER
// ============================================================================

void processSerialCommand() {
    while (Serial.available()) {
        uint8_t b = Serial.read();

        if (rxIndex == 0 && b != PROTO_START) {
            continue;
        }

        rxBuffer[rxIndex++] = b;

        // Check for complete command
        if (rxIndex >= 2) {
            uint8_t expectedLen = rxBuffer[1];

            // For extended JSON commands, length includes JSON payload
            if (rxIndex >= expectedLen && expectedLen >= 4) {
                // Verify checksum
                uint8_t expectedChecksum = calcChecksum(rxBuffer, expectedLen - 1);
                if (rxBuffer[expectedLen - 1] == expectedChecksum) {
                    handleCommand(rxBuffer, expectedLen);
                }
                rxIndex = 0;
                continue;
            }
        }

        // Legacy 6-byte command check
        if (rxIndex >= 6 && rxBuffer[1] == PROTO_FIXED) {
            uint8_t expectedChecksum = calcChecksum(rxBuffer, 5);
            if (rxBuffer[5] == expectedChecksum) {
                handleCommand(rxBuffer, 6);
            }
            rxIndex = 0;
        }

        if (rxIndex >= sizeof(rxBuffer)) {
            rxIndex = 0;
        }
    }
}

void handleCommand(uint8_t* cmd, uint8_t len) {
    uint8_t cmdId = cmd[2];

    if (cmdId == CMD_EXTENDED) {
        // Extended JSON command
        handleExtendedCommand(cmd + 3, len - 4);  // Skip header, length, cmd, checksum
    } else {
        // Original binary commands
        uint8_t param1 = cmd[3];
        uint8_t param2 = cmd[4];

        switch (cmdId) {
            case CMD_WRITE_OUTPUT:   handleWriteOutput(param1, param2); break;
            case CMD_READ_VOLTAGE:   handleReadVoltage(); break;
            case CMD_READ_LENS_TEMP: handleReadLensTemp(); break;
            case CMD_READ_AMBIENT_TEMP: handleReadAmbientTemp(); break;
            case CMD_READ_HUMIDITY:  handleReadHumidity(); break;
            case CMD_READ_POWER:     handleReadPower(); break;
            case CMD_SYNC_STATES:    handleSyncStates(); break;
        }
    }
}

// ============================================================================
// EXTENDED JSON COMMAND HANDLER
// ============================================================================

void handleExtendedCommand(uint8_t* payload, uint8_t len) {
    // Parse JSON
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, payload, len);

    if (error) {
        sendJsonResponse("{\"err\":\"json_parse\"}");
        return;
    }

    const char* cmd = doc["cmd"];
    if (!cmd) {
        sendJsonResponse("{\"err\":\"no_cmd\"}");
        return;
    }

    // Route to appropriate handler
    if (strcmp(cmd, "version") == 0) {
        handleCmdVersion(doc);
    } else if (strcmp(cmd, "status") == 0) {
        handleCmdStatus(doc);
    } else if (strcmp(cmd, "dew_status") == 0) {
        handleCmdDewStatus(doc);
    } else if (strcmp(cmd, "dew_config") == 0) {
        handleCmdDewConfig(doc);
    } else if (strcmp(cmd, "stats") == 0) {
        handleCmdStats(doc);
    } else if (strcmp(cmd, "stats_reset") == 0) {
        handleCmdStatsReset(doc);
    } else if (strcmp(cmd, "alert_config") == 0) {
        handleCmdAlertConfig(doc);
    } else if (strcmp(cmd, "alerts") == 0) {
        handleCmdAlerts(doc);
    } else if (strcmp(cmd, "diag") == 0) {
        handleCmdDiag(doc);
    } else if (strcmp(cmd, "i2c_recovery") == 0) {
        handleCmdI2CRecovery(doc);
    } else if (strcmp(cmd, "cal_get") == 0) {
        handleCmdCalGet(doc);
    } else if (strcmp(cmd, "cal_set") == 0) {
        handleCmdCalSet(doc);
    } else if (strcmp(cmd, "names_get") == 0) {
        handleCmdNamesGet(doc);
    } else if (strcmp(cmd, "names_set") == 0) {
        handleCmdNamesSet(doc);
    } else {
        sendJsonResponse("{\"err\":\"unknown_cmd\"}");
    }
}

// ============================================================================
// EXTENDED COMMAND HANDLERS
// ============================================================================

void handleCmdVersion(JsonDocument& doc) {
    JsonDocument resp;
    resp["fw"] = FIRMWARE_NAME;
    resp["ver"] = FIRMWARE_VERSION;

    JsonArray caps = resp["caps"].to<JsonArray>();
    caps.add("dew");
    caps.add("stats");
    caps.add("alerts");
    caps.add("cal");

    char json[256];
    serializeJson(resp, json, sizeof(json));
    sendJsonResponse(json);
}

void handleCmdStatus(JsonDocument& doc) {
    JsonDocument resp;

    resp["v"] = roundf(inputVoltage * 100) / 100;
    resp["p"] = roundf(inputVoltage * inputCurrent * 100) / 100;
    resp["t"] = roundf(ambientTemp * 10) / 10;
    resp["h"] = roundf(humidity * 10) / 10;
    resp["dew"] = roundf(dewPoint * 10) / 10;

    JsonArray dc = resp["dc"].to<JsonArray>();
    for (int i = 0; i < 7; i++) {
        dc.add(dcStates[i] ? 1 : 0);
    }

    JsonArray pwm = resp["pwm"].to<JsonArray>();
    for (int i = 0; i < 3; i++) {
        pwm.add(pwmValues[i]);
    }

    JsonArray autoDew = resp["auto_dew"].to<JsonArray>();
    autoDew.add(dewConfig[0].autoMode);
    autoDew.add(dewConfig[1].autoMode);

    resp["uptime"] = (millis() - stats.startTime) / 1000;
    resp["i2c_err"] = stats.i2cRecoveries;

    char json[384];
    serializeJson(resp, json, sizeof(json));
    sendJsonResponse(json);
}

void handleCmdDewStatus(JsonDocument& doc) {
    JsonDocument resp;

    resp["dew_point"] = roundf(dewPoint * 10) / 10;
    resp["ambient"] = roundf(ambientTemp * 10) / 10;
    resp["humidity"] = roundf(humidity * 10) / 10;

    JsonObject ch14 = resp["ch14"].to<JsonObject>();
    ch14["auto"] = dewConfig[0].autoMode;
    ch14["margin"] = dewConfig[0].margin;
    ch14["output"] = pwmValues[1];
    if (dewConfig[0].autoMode) {
        ch14["target"] = roundf((dewPoint + dewConfig[0].margin) * 10) / 10;
    }

    JsonObject ch15 = resp["ch15"].to<JsonObject>();
    ch15["auto"] = dewConfig[1].autoMode;
    ch15["margin"] = dewConfig[1].margin;
    ch15["output"] = pwmValues[2];
    if (dewConfig[1].autoMode) {
        ch15["target"] = roundf((dewPoint + dewConfig[1].margin) * 10) / 10;
    }

    char json[384];
    serializeJson(resp, json, sizeof(json));
    sendJsonResponse(json);
}

void handleCmdDewConfig(JsonDocument& doc) {
    int ch = doc["ch"] | -1;
    if (ch != 14 && ch != 15) {
        sendJsonResponse("{\"err\":\"invalid_param\",\"param\":\"ch\"}");
        return;
    }

    int idx = ch - 14;  // 0 or 1

    if (doc.containsKey("auto")) {
        dewConfig[idx].autoMode = doc["auto"];
    }
    if (doc.containsKey("margin")) {
        dewConfig[idx].margin = doc["margin"];
    }
    if (doc.containsKey("kp")) {
        dewConfig[idx].kp = doc["kp"];
    }
    if (doc.containsKey("ki")) {
        dewConfig[idx].ki = doc["ki"];
    }
    if (doc.containsKey("kd")) {
        dewConfig[idx].kd = doc["kd"];
    }

    // Reset PID state when config changes
    dewConfig[idx].integral = 0;
    dewConfig[idx].lastError = 0;
    dewConfig[idx].lastUpdate = 0;

    saveDewConfig();
    sendJsonResponse("{\"ok\":true}");
}

void handleCmdStats(JsonDocument& doc) {
    JsonDocument resp;

    unsigned long uptime = (millis() - stats.startTime) / 1000;
    resp["uptime"] = uptime;

    if (stats.sampleCount > 0) {
        resp["v_min"] = roundf(stats.v_min * 100) / 100;
        resp["v_max"] = roundf(stats.v_max * 100) / 100;
        resp["v_avg"] = roundf((stats.v_sum / stats.sampleCount) * 100) / 100;
        resp["p_max"] = roundf(stats.p_max * 100) / 100;
        resp["p_total"] = roundf(stats.p_total * 100) / 100;
        resp["t_min"] = roundf(stats.t_min * 10) / 10;
        resp["t_max"] = roundf(stats.t_max * 10) / 10;
    }

    resp["i2c_recoveries"] = stats.i2cRecoveries;

    char json[256];
    serializeJson(resp, json, sizeof(json));
    sendJsonResponse(json);
}

void handleCmdStatsReset(JsonDocument& doc) {
    resetStats();
    sendJsonResponse("{\"ok\":true}");
}

void handleCmdAlertConfig(JsonDocument& doc) {
    // If only reading (no parameters except cmd)
    if (doc.size() == 1) {
        JsonDocument resp;

        JsonObject lowV = resp["low_v"].to<JsonObject>();
        lowV["en"] = alertConfig.lowVoltageEnabled;
        lowV["thresh"] = alertConfig.lowVoltageThreshold;

        JsonObject critV = resp["crit_v"].to<JsonObject>();
        critV["en"] = alertConfig.critVoltageEnabled;
        critV["thresh"] = alertConfig.critVoltageThreshold;
        critV["auto_off"] = alertConfig.critAutoOff;

        char json[192];
        serializeJson(resp, json, sizeof(json));
        sendJsonResponse(json);
        return;
    }

    // Setting config
    if (doc.containsKey("low_v")) {
        JsonObject lowV = doc["low_v"];
        if (lowV.containsKey("en")) alertConfig.lowVoltageEnabled = lowV["en"];
        if (lowV.containsKey("thresh")) alertConfig.lowVoltageThreshold = lowV["thresh"];
    }
    if (doc.containsKey("crit_v")) {
        JsonObject critV = doc["crit_v"];
        if (critV.containsKey("en")) alertConfig.critVoltageEnabled = critV["en"];
        if (critV.containsKey("thresh")) alertConfig.critVoltageThreshold = critV["thresh"];
        if (critV.containsKey("auto_off")) alertConfig.critAutoOff = critV["auto_off"];
    }

    saveAlertConfig();
    sendJsonResponse("{\"ok\":true}");
}

void handleCmdAlerts(JsonDocument& doc) {
    JsonDocument resp;

    resp["low_v"] = alertState.lowVoltage;
    resp["crit_v"] = alertState.critVoltage;
    resp["thermal"] = alertState.thermal;
    resp["i2c_fail"] = alertState.i2cFail;

    char json[128];
    serializeJson(resp, json, sizeof(json));
    sendJsonResponse(json);
}

void handleCmdDiag(JsonDocument& doc) {
    JsonDocument resp;

    resp["free_heap"] = ESP.getFreeHeap();
    resp["i2c_ok"] = i2cHealthy;
    resp["ina219_ok"] = i2cProbe(INA219_ADDR);
    resp["sht4x_ok"] = i2cProbe(SHT4X_ADDR);
    resp["last_i2c_err"] = i2cFailCount;

    char json[128];
    serializeJson(resp, json, sizeof(json));
    sendJsonResponse(json);
}

void handleCmdI2CRecovery(JsonDocument& doc) {
    lastI2CRecovery = 0;  // Force recovery
    bool success = i2cBusRecovery();
    stats.i2cRecoveries++;

    JsonDocument resp;
    resp["ok"] = success;
    resp["sda_released"] = digitalRead(PIN_SDA) == HIGH;

    char json[64];
    serializeJson(resp, json, sizeof(json));
    sendJsonResponse(json);
}

void handleCmdCalGet(JsonDocument& doc) {
    JsonDocument resp;

    resp["v_offset"] = calibration.v_offset;
    resp["t_offset"] = calibration.t_offset;
    resp["h_offset"] = calibration.h_offset;

    char json[96];
    serializeJson(resp, json, sizeof(json));
    sendJsonResponse(json);
}

void handleCmdCalSet(JsonDocument& doc) {
    if (doc.containsKey("v_offset")) {
        calibration.v_offset = doc["v_offset"];
    }
    if (doc.containsKey("t_offset")) {
        calibration.t_offset = doc["t_offset"];
    }
    if (doc.containsKey("h_offset")) {
        calibration.h_offset = doc["h_offset"];
    }

    saveCalibration();
    sendJsonResponse("{\"ok\":true}");
}

void handleCmdNamesGet(JsonDocument& doc) {
    JsonDocument resp;

    JsonArray dc = resp["dc"].to<JsonArray>();
    for (int i = 0; i < 7; i++) {
        dc.add(portNames.dc[i]);
    }

    JsonArray pwm = resp["pwm"].to<JsonArray>();
    for (int i = 0; i < 3; i++) {
        pwm.add(portNames.pwm[i]);
    }

    char json[384];
    serializeJson(resp, json, sizeof(json));
    sendJsonResponse(json);
}

void handleCmdNamesSet(JsonDocument& doc) {
    // Set DC port names (index 0-6)
    if (doc.containsKey("idx") && doc.containsKey("name")) {
        int idx = doc["idx"];
        const char* name = doc["name"];

        if (idx >= 0 && idx < 7) {
            // DC port
            strncpy(portNames.dc[idx], name, PORT_NAME_MAX_LEN);
            portNames.dc[idx][PORT_NAME_MAX_LEN] = '\0';
            savePortNames();
            sendJsonResponse("{\"ok\":true}");
            return;
        } else if (idx >= 7 && idx < 10) {
            // PWM port (7=PWM13, 8=PWM14, 9=PWM15)
            int pwmIdx = idx - 7;
            strncpy(portNames.pwm[pwmIdx], name, PORT_NAME_MAX_LEN);
            portNames.pwm[pwmIdx][PORT_NAME_MAX_LEN] = '\0';
            savePortNames();
            sendJsonResponse("{\"ok\":true}");
            return;
        }
    }

    sendJsonResponse("{\"err\":\"invalid_param\"}");
}

// ============================================================================
// ORIGINAL COMMAND HANDLERS (Binary Protocol)
// ============================================================================

void handleWriteOutput(uint8_t index, uint8_t value) {
    if (index < 7) {
        bool state = (value != 0);
        setDCOutput(index, state);
        dcStates[index] = state;
    } else if (index >= 7 && index <= 9) {
        uint8_t channel = index - 7;
        setPWMOutput(channel, value);
        pwmValues[channel] = value;

        // Disable auto mode when manually setting dew heater
        if (channel >= 1 && channel <= 2) {
            dewConfig[channel - 1].autoMode = false;
        }
    }
}

void handleReadVoltage() {
    if (inputVoltage < 0.1) {
        float voltage, current;
        if (!ina219_readVoltage(&voltage) || voltage < 0.1) {
            lastI2CRecovery = 0;
            i2cBusRecovery();
            delay(100);
            for (int retry = 0; retry < 3; retry++) {
                if (ina219_readVoltage(&voltage) && voltage > 0.1) {
                    ina219_readCurrent(&current);
                    inputVoltage = voltage + calibration.v_offset;
                    inputCurrent = current;
                    break;
                }
                delay(50);
            }
        } else {
            ina219_readCurrent(&current);
            inputVoltage = voltage + calibration.v_offset;
            inputCurrent = current;
        }
    }

    int32_t rawValue = (int32_t)(inputVoltage * 100);
    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;
    sendResponse(CMD_READ_VOLTAGE, data, 4);
}

void handleReadLensTemp() {
    int32_t rawValue = (int32_t)((lensTemp + 255.5) * 100);
    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;
    sendResponse(CMD_READ_LENS_TEMP, data, 4);
}

void handleReadAmbientTemp() {
    if (ambientTemp < -50.0 || (ambientTemp > -0.1 && ambientTemp < 0.1)) {
        float temp, hum;
        if (!sht4x_read(&temp, &hum) || temp < -50.0) {
            lastI2CRecovery = 0;
            i2cBusRecovery();
            delay(100);
            for (int retry = 0; retry < 3; retry++) {
                if (sht4x_read(&temp, &hum) && temp > -50.0) {
                    ambientTemp = temp + calibration.t_offset;
                    humidity = hum + calibration.h_offset;
                    lensTemp = ambientTemp;
                    break;
                }
                delay(50);
            }
        } else {
            ambientTemp = temp + calibration.t_offset;
            humidity = hum + calibration.h_offset;
            lensTemp = ambientTemp;
        }
    }

    int32_t rawValue = (int32_t)((ambientTemp + 255.5) * 100);
    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;
    sendResponse(CMD_READ_AMBIENT_TEMP, data, 4);
}

void handleReadHumidity() {
    if (humidity < 1.0) {
        float temp, hum;
        if (!sht4x_read(&temp, &hum) || hum < 1.0) {
            lastI2CRecovery = 0;
            i2cBusRecovery();
            delay(100);
            for (int retry = 0; retry < 3; retry++) {
                if (sht4x_read(&temp, &hum) && hum >= 1.0) {
                    ambientTemp = temp + calibration.t_offset;
                    humidity = hum + calibration.h_offset;
                    lensTemp = ambientTemp;
                    break;
                }
                delay(50);
            }
        } else {
            ambientTemp = temp + calibration.t_offset;
            humidity = hum + calibration.h_offset;
            lensTemp = ambientTemp;
        }
    }

    int32_t rawValue = (int32_t)((humidity + 254.0) * 100);
    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;
    sendResponse(CMD_READ_HUMIDITY, data, 4);
}

void handleReadPower() {
    if (inputVoltage < 0.1) {
        float voltage, current;
        if (!ina219_readVoltage(&voltage) || voltage < 0.1) {
            lastI2CRecovery = 0;
            i2cBusRecovery();
            delay(100);
            for (int retry = 0; retry < 3; retry++) {
                if (ina219_readVoltage(&voltage) && voltage > 0.1) {
                    ina219_readCurrent(&current);
                    inputVoltage = voltage + calibration.v_offset;
                    inputCurrent = current;
                    break;
                }
                delay(50);
            }
        } else {
            ina219_readCurrent(&current);
            inputVoltage = voltage + calibration.v_offset;
            inputCurrent = current;
        }
    }

    float power = inputVoltage * inputCurrent;
    int32_t rawValue = (int32_t)(power * 100);
    uint8_t data[4];
    data[0] = (rawValue >> 24) & 0xFF;
    data[1] = (rawValue >> 16) & 0xFF;
    data[2] = (rawValue >> 8) & 0xFF;
    data[3] = rawValue & 0xFF;
    sendResponse(CMD_READ_POWER, data, 4);
}

void handleSyncStates() {
    uint8_t data[10];
    for (int i = 0; i < 7; i++) {
        data[i] = dcStates[i] ? 1 : 0;
    }
    data[7] = pwmValues[0];
    data[8] = pwmValues[1];
    data[9] = pwmValues[2];
    sendResponse(CMD_SYNC_STATES, data, 10);
}

// ============================================================================
// RESPONSE FUNCTIONS
// ============================================================================

void sendResponse(uint8_t cmdId, uint8_t* data, uint8_t dataLen) {
    uint8_t response[20];
    uint8_t idx = 0;

    uint8_t totalLen = 1 + 1 + 1 + dataLen + 1;

    response[idx++] = PROTO_START;
    response[idx++] = totalLen;
    response[idx++] = cmdId;

    for (int i = 0; i < dataLen; i++) {
        response[idx++] = data[i];
    }

    response[idx] = calcChecksum(response, idx);
    idx++;

    Serial.write(response, idx);
}

void sendJsonResponse(const char* json) {
    uint8_t jsonLen = strlen(json);
    uint8_t totalLen = 1 + 1 + 1 + jsonLen + 1;  // header + len + cmd + json + checksum

    uint8_t response[300];
    uint8_t idx = 0;

    response[idx++] = PROTO_START;
    response[idx++] = totalLen;
    response[idx++] = CMD_EXTENDED;

    for (int i = 0; i < jsonLen; i++) {
        response[idx++] = json[i];
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
