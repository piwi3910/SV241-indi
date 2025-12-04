/*******************************************************************************
 * INDI Driver for SVBONY SV241 Powerbox
 *
 * Copyright (C) 2025 Pascal Watteel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 ******************************************************************************/

#pragma once

#include <libindi/defaultdevice.h>
#include <libindi/indilightboxinterface.h>

#include <cstdint>
#include <cstring>
#include <poll.h>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <vector>

/**
 * @brief INDI Driver for SVBONY SV241 Powerbox
 *
 * The SV241 is a USB-controlled power distribution box with:
 * - 5x DC outputs (12V switchable)
 * - 2x USB groups (switchable)
 * - 3x PWM outputs (dew heaters + adjustable voltage)
 * - Sensors: voltage, power, ambient temp, lens temp, humidity
 */
class SV241 : public INDI::DefaultDevice
{
public:
    SV241();
    virtual ~SV241() = default;

    // INDI::DefaultDevice overrides
    virtual bool initProperties() override;
    virtual bool updateProperties() override;
    virtual bool ISNewNumber(const char *dev, const char *name, double values[], char *names[], int n) override;
    virtual bool ISNewSwitch(const char *dev, const char *name, ISState *states, char *names[], int n) override;
    virtual bool ISNewText(const char *dev, const char *name, char *texts[], char *names[], int n) override;
    virtual void TimerHit() override;

    virtual const char *getDefaultName() override;

protected:
    virtual bool Connect() override;
    virtual bool Disconnect() override;
    virtual bool saveConfigItems(FILE *fp) override;

private:
    // Serial communication
    int PortFD{-1};
    bool sendCommand(uint8_t cmdId, uint8_t param1 = 0x00, uint8_t param2 = 0x00);
    bool readResponse(uint8_t *buffer, size_t len, uint8_t expectedCmd);
    uint8_t calcChecksum(const uint8_t *cmd);
    bool openSerialPort();
    void closeSerialPort();

    // Extended protocol (JSON) communication
    bool sendExtendedCommand(const std::string &jsonCmd, std::string &response);
    bool detectExtendedFirmware();
    bool parseJsonResponse(const std::string &json, std::string &error);

    // Extended protocol functions
    bool extGetStatus();
    bool extGetDewStatus();
    bool extSetDewConfig(int channel, bool autoMode, double margin);
    bool extGetStats();
    bool extStatsReset();
    bool extGetAlerts();
    bool extGetAlertConfig();
    bool extSetAlertConfig();
    bool extGetDiagnostics();
    bool extGetCalibration();
    bool extSetCalibration(double vOffset, double tOffset, double hOffset);
    bool extI2CRecovery();
    bool extGetNames();
    bool extSetName(int idx, const std::string &name);

    // Phase 3: Profiles
    bool extGetProfiles();
    bool extSaveProfile(int slot, const std::string &name);
    bool extLoadProfile(int slot);
    bool extDeleteProfile(int slot);

    // Phase 3: Timers
    bool extGetTimers();
    bool extSetTimer(const std::string &port, const std::string &action, int minutes, int value = 0);
    bool extCancelTimer(int id);

    // Phase 3: Temperature rate
    bool extGetTempRate();

    // Phase 3: PID tuning
    bool extGetDewPid(int channel);
    bool extSetDewPid(int channel, double kp, double ki, double kd);

    // Phase 4: Watchdog
    bool extGetWatchdog();
    bool extSetWatchdog(bool enabled, int timeout, const std::string &action, int profile);

    // Phase 4: Current alert
    bool extGetCurrentAlert();
    bool extSetCurrentAlert(bool enabled, double threshold);

    // Device control functions
    bool setDCOutput(int channel, bool enabled);
    bool setPWMValue(int channel, uint8_t value);
    bool syncAllStates();

    // Sensor reading functions
    bool readVoltage();
    bool readTemperature(bool ambient);
    bool readHumidity();
    bool readPower();
    bool readAllSensors();

    // Connection properties
    INDI::PropertyText PortTP{1};

    // DC Output switches (DC1-DC5)
    INDI::PropertySwitch DC1SP{2};
    INDI::PropertySwitch DC2SP{2};
    INDI::PropertySwitch DC3SP{2};
    INDI::PropertySwitch DC4SP{2};
    INDI::PropertySwitch DC5SP{2};

    // USB Group switches
    INDI::PropertySwitch USB12SP{2};
    INDI::PropertySwitch USB345SP{2};

    // PWM controls
    INDI::PropertyNumber PWM13NP{1};  // Adjustable voltage (0-15.3V)
    INDI::PropertyNumber PWM14NP{1};  // Dew heater 1
    INDI::PropertyNumber PWM15NP{1};  // Dew heater 2

    // Sensor readings
    INDI::PropertyNumber VoltageNP{1};
    INDI::PropertyNumber PowerNP{1};
    INDI::PropertyNumber AmbientTempNP{1};
    INDI::PropertyNumber LensTempNP{1};
    INDI::PropertyNumber HumidityNP{1};

    // Calculated PWM13 voltage display
    INDI::PropertyNumber PWM13VoltageNP{1};

    // Extended firmware features (only shown if extended firmware detected)
    // Dew point and auto-dew controls
    INDI::PropertyNumber DewPointNP{1};
    INDI::PropertySwitch AutoDew14SP{2};
    INDI::PropertySwitch AutoDew15SP{2};
    INDI::PropertyNumber DewMargin14NP{1};
    INDI::PropertyNumber DewMargin15NP{1};

    // Session statistics
    INDI::PropertyNumber StatsVoltageNP{3};  // min, max, avg
    INDI::PropertyNumber StatsPowerNP{2};    // max, total (Wh)
    INDI::PropertyNumber StatsTempNP{2};     // min, max
    INDI::PropertyNumber UptimeNP{1};

    // Alert status
    INDI::PropertyLight AlertsLP{4};  // low_v, crit_v, thermal, i2c_fail

    // Diagnostics
    INDI::PropertyNumber DiagnosticsNP{1};   // free heap
    INDI::PropertyLight SensorStatusLP{3};   // i2c_ok, ina219_ok, sht4x_ok

    // Firmware info
    INDI::PropertyText FirmwareTP{2};  // version, capabilities

    // Calibration offsets
    INDI::PropertyNumber CalibrationNP{3};  // v_offset, t_offset, h_offset

    // Alert configuration
    INDI::PropertyNumber AlertConfigNP{3};  // low_v_thresh, crit_v_thresh
    INDI::PropertySwitch AlertLowVSP{2};    // enable/disable low voltage alert
    INDI::PropertySwitch AlertCritVSP{2};   // enable/disable critical voltage alert
    INDI::PropertySwitch AlertAutoOffSP{2}; // enable/disable auto-off on critical

    // I2C Recovery button
    INDI::PropertySwitch I2CRecoverySP{1};  // trigger I2C recovery

    // Stats reset button
    INDI::PropertySwitch StatsResetSP{1};   // reset session statistics

    // Port names (custom labels)
    INDI::PropertyText PortNamesTP{10};  // DC1-DC5, USB12, USB345, PWM13-PWM15

    // Phase 3: Profiles
    INDI::PropertyText ProfilesTP{4};         // Profile names (4 slots)
    INDI::PropertySwitch ProfileLoadSP{4};    // Load profile buttons
    INDI::PropertySwitch ProfileSaveSP{4};    // Save to profile slot buttons
    INDI::PropertySwitch ProfileDeleteSP{4};  // Delete profile buttons
    INDI::PropertyText ProfileNameTP{1};      // Name for saving new profile
    INDI::PropertyNumber ActiveProfileNP{1};  // Currently active profile index

    // Phase 3: Timers
    INDI::PropertyText TimerStatusTP{4};      // Active timer status (up to 4 displayed)
    INDI::PropertyText TimerPortTP{1};        // Port name for new timer
    INDI::PropertySwitch TimerActionSP{3};    // Timer action: On, Off, Set
    INDI::PropertyNumber TimerMinutesNP{1};   // Minutes until action
    INDI::PropertyNumber TimerValueNP{1};     // PWM value (for Set action)
    INDI::PropertySwitch TimerSetSP{1};       // Create timer button
    INDI::PropertySwitch TimerCancelSP{4};    // Cancel timer buttons

    // Phase 3: Temperature rate
    INDI::PropertyNumber TempRateNP{1};       // Temperature change rate (C/hour)

    // Phase 3: PID tuning
    INDI::PropertyNumber PID14NP{3};          // Kp, Ki, Kd for channel 14
    INDI::PropertyNumber PID15NP{3};          // Kp, Ki, Kd for channel 15

    // Phase 4: Watchdog
    INDI::PropertySwitch WatchdogEnableSP{2};   // Enable/disable watchdog
    INDI::PropertyNumber WatchdogTimeoutNP{1};  // Timeout in seconds
    INDI::PropertySwitch WatchdogActionSP{3};   // none, all_off, profile
    INDI::PropertyNumber WatchdogProfileNP{1};  // Profile slot for action
    INDI::PropertyLight WatchdogStatusLP{1};    // Watchdog triggered status
    INDI::PropertyNumber WatchdogRemainingNP{1}; // Seconds remaining

    // Phase 4: Current alert
    INDI::PropertySwitch CurrentAlertEnableSP{2};  // Enable/disable
    INDI::PropertyNumber CurrentAlertThresholdNP{1}; // Threshold in amps
    INDI::PropertyLight CurrentAlertStatusLP{1};   // Alert status
    INDI::PropertyNumber CurrentDrawNP{1};         // Current reading

    // Internal state
    double currentVoltage{0.0};
    double currentPower{0.0};
    double ambientTemperature{0.0};
    double lensTemperature{0.0};
    double humidity{0.0};

    // DC/PWM state cache
    bool dcStates[7]{false};  // DC1-DC5, USB12, USB345
    uint8_t pwmValues[3]{0};  // PWM13, PWM14, PWM15

    // Extended firmware state
    bool hasExtendedFirmware{false};
    std::string firmwareVersion;
    std::vector<std::string> firmwareCapabilities;
    double dewPoint{0.0};
    bool autoDew14{false};
    bool autoDew15{false};
    double dewMargin14{5.0};
    double dewMargin15{5.0};

    // Calibration state
    double calVOffset{0.0};
    double calTOffset{0.0};
    double calHOffset{0.0};

    // Alert config state
    bool alertLowVEnabled{true};
    double alertLowVThreshold{11.5};
    bool alertCritVEnabled{true};
    double alertCritVThreshold{11.0};
    bool alertAutoOff{true};

    // Port names state
    std::string portNames[10];  // DC1-DC5, USB12, USB345, PWM13-PWM15

    // Phase 3: Profiles state
    std::string profileNames[4];
    int activeProfile{-1};

    // Phase 3: Timers state (for display)
    struct TimerInfo {
        int id{0};
        std::string port;
        std::string action;
        int remaining{0};
    };
    std::vector<TimerInfo> activeTimers;

    // Phase 3: Temperature rate state
    double tempRate{0.0};

    // Phase 3: PID state
    double pid14Kp{2.0}, pid14Ki{0.5}, pid14Kd{0.1};
    double pid15Kp{2.0}, pid15Ki{0.5}, pid15Kd{0.1};

    // Phase 4: Watchdog state
    bool watchdogEnabled{false};
    int watchdogTimeout{300};
    std::string watchdogAction{"all_off"};
    int watchdogProfile{0};
    bool watchdogTriggered{false};
    int watchdogRemaining{-1};

    // Phase 4: Current alert state
    bool currentAlertEnabled{false};
    double currentAlertThreshold{5.0};
    double currentDraw{0.0};
    bool overCurrentAlert{false};

    // Protocol constants
    static constexpr uint8_t CMD_HEADER = 0x24;
    static constexpr uint8_t CMD_LENGTH = 0x06;
    static constexpr uint8_t CMD_WRITE = 0x01;
    static constexpr uint8_t CMD_READ_VOLTAGE = 0x03;
    static constexpr uint8_t CMD_READ_LENS_TEMP = 0x04;
    static constexpr uint8_t CMD_READ_AMBIENT_TEMP = 0x05;
    static constexpr uint8_t CMD_READ_HUMIDITY = 0x06;
    static constexpr uint8_t CMD_READ_POWER = 0x07;
    static constexpr uint8_t CMD_SYNC_STATES = 0x08;
    static constexpr uint8_t CMD_EXTENDED = 0x10;  // Extended JSON protocol

    // Response sizes
    static constexpr size_t SYNC_RESPONSE_SIZE = 14;
    static constexpr size_t SENSOR_RESPONSE_SIZE = 8;

    // PWM constants
    static constexpr uint8_t PWM_MAX_VALUE = 253;
    static constexpr double PWM13_MAX_VOLTAGE = 15.3;

    // Property timeout (seconds)
    static constexpr int PROPERTY_TIMEOUT = 60;

    // Channel mappings (hardware index) - type-safe enum
    enum class Channel : int
    {
        DC1 = 0,
        DC2 = 1,
        DC3 = 2,
        DC4 = 3,
        DC5 = 4,
        USB12 = 5,
        USB345 = 6,
        PWM13 = 7,
        PWM14 = 8,
        PWM15 = 9
    };

    // Sensor offsets
    static constexpr double TEMP_OFFSET = -255.5;
    static constexpr double HUMIDITY_OFFSET = -254.0;

    // Timing
    static constexpr int COMMAND_DELAY_US = 50000;  // 50ms
    static constexpr int POLL_INTERVAL_MS = 5000;   // 5 seconds
    static constexpr int READ_TIMEOUT_MS = 1000;    // 1 second read timeout
};
