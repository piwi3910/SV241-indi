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
#include <termios.h>
#include <unistd.h>

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

    // Internal state
    double currentVoltage{0.0};
    double currentPower{0.0};
    double ambientTemperature{0.0};
    double lensTemperature{0.0};
    double humidity{0.0};

    // DC/PWM state cache
    bool dcStates[7]{false};  // DC1-DC5, USB12, USB345
    uint8_t pwmValues[3]{0};  // PWM13, PWM14, PWM15

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
