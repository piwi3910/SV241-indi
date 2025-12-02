/*******************************************************************************
  Copyright(c) 2025 Pascal Watteel. All rights reserved.

  SVBONY SV241 Power Box

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation; either version 2 of the License, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; see the file COPYING.LIB.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.

  The full GNU General Public License is included in this distribution in the
  file called LICENSE.
*******************************************************************************/

#pragma once

#include "defaultdevice.h"

#include <vector>
#include <stdint.h>

namespace Connection
{
class Serial;
}

/**
 * @brief The SvbonySV241 class provides control for the SVBONY SV241 Power Box.
 *
 * The SV241 is a USB-controlled power distribution box with:
 * - 5x DC outputs (12V switchable)
 * - 2x USB groups (switchable)
 * - 3x PWM outputs (2 dew heaters + 1 adjustable voltage 0-15.3V)
 * - Sensors: input voltage, power consumption, ambient temp, lens temp, humidity
 *
 * @author Pascal Watteel
 */
class SvbonySV241 : public INDI::DefaultDevice
{
    public:
        SvbonySV241();
        virtual ~SvbonySV241() override = default;

        virtual const char *getDefaultName() override;
        virtual bool initProperties() override;
        virtual bool updateProperties() override;
        virtual bool ISNewNumber(const char *dev, const char *name, double values[], char *names[], int n) override;
        virtual bool ISNewSwitch(const char *dev, const char *name, ISState *states, char *names[], int n) override;

    protected:
        virtual bool Handshake();
        virtual void TimerHit() override;
        virtual bool saveConfigItems(FILE *fp) override;

    private:
        ////////////////////////////////////////////////////////////////////////////////////
        /// Communication
        ////////////////////////////////////////////////////////////////////////////////////
        /**
         * @brief sendCommand Send a command to the device
         * @param cmdId Command ID
         * @param param1 First parameter (default 0)
         * @param param2 Second parameter (default 0)
         * @return True if command was sent successfully
         */
        bool sendCommand(uint8_t cmdId, uint8_t param1 = 0x00, uint8_t param2 = 0x00);

        /**
         * @brief readResponse Read response from device
         * @param buffer Buffer to store response
         * @param len Expected response length
         * @param expectedCmd Expected command ID in response
         * @return True if response was read and validated successfully
         */
        bool readResponse(uint8_t *buffer, size_t len, uint8_t expectedCmd);

        /**
         * @brief calcChecksum Calculate checksum for command
         * @param cmd Command buffer (first 5 bytes)
         * @return Calculated checksum byte
         */
        uint8_t calcChecksum(const uint8_t *cmd);

        ////////////////////////////////////////////////////////////////////////////////////
        /// Device Control
        ////////////////////////////////////////////////////////////////////////////////////
        bool setDCOutput(int channel, bool enabled);
        bool setPWMValue(int channel, uint8_t value);
        bool syncAllStates();

        ////////////////////////////////////////////////////////////////////////////////////
        /// Sensor Reading
        ////////////////////////////////////////////////////////////////////////////////////
        bool readVoltage();
        bool readTemperature(bool ambient);
        bool readHumidity();
        bool readPower();
        bool readAllSensors();

        ////////////////////////////////////////////////////////////////////////////////////
        /// Properties
        ////////////////////////////////////////////////////////////////////////////////////

        // DC Output switches
        INDI::PropertySwitch DC1SP{2};
        INDI::PropertySwitch DC2SP{2};
        INDI::PropertySwitch DC3SP{2};
        INDI::PropertySwitch DC4SP{2};
        INDI::PropertySwitch DC5SP{2};

        // USB Group switches
        INDI::PropertySwitch USB12SP{2};
        INDI::PropertySwitch USB345SP{2};

        // PWM controls
        INDI::PropertyNumber PWM13NP{1};   // Adjustable voltage (0-15.3V)
        INDI::PropertyNumber PWM14NP{1};   // Dew heater 1
        INDI::PropertyNumber PWM15NP{1};   // Dew heater 2

        // Sensor readings
        INDI::PropertyNumber VoltageNP{1};
        INDI::PropertyNumber PowerNP{1};
        INDI::PropertyNumber AmbientTempNP{1};
        INDI::PropertyNumber LensTempNP{1};
        INDI::PropertyNumber HumidityNP{1};

        // Calculated PWM13 voltage display
        INDI::PropertyNumber PWM13VoltageNP{1};

        ////////////////////////////////////////////////////////////////////////////////////
        /// Private Variables
        ////////////////////////////////////////////////////////////////////////////////////
        Connection::Serial *serialConnection{nullptr};
        int PortFD{-1};

        // Internal state
        double m_CurrentVoltage{0.0};
        double m_CurrentPower{0.0};
        double m_AmbientTemperature{0.0};
        double m_LensTemperature{0.0};
        double m_Humidity{0.0};

        // DC/PWM state cache
        bool m_DCStates[7]{false};   // DC1-DC5, USB12, USB345
        uint8_t m_PWMValues[3]{0};   // PWM13, PWM14, PWM15

        ////////////////////////////////////////////////////////////////////////////////////
        /// Protocol Constants
        ////////////////////////////////////////////////////////////////////////////////////
        static constexpr uint8_t CMD_HEADER = 0x24;
        static constexpr uint8_t CMD_LENGTH = 0x06;
        static constexpr uint8_t CMD_WRITE = 0x01;
        static constexpr uint8_t CMD_READ_VOLTAGE = 0x03;
        static constexpr uint8_t CMD_READ_LENS_TEMP = 0x04;
        static constexpr uint8_t CMD_READ_AMBIENT_TEMP = 0x05;
        static constexpr uint8_t CMD_READ_HUMIDITY = 0x06;
        static constexpr uint8_t CMD_READ_POWER = 0x07;
        static constexpr uint8_t CMD_SYNC_STATES = 0x08;

        // Channel mappings (hardware index)
        enum
        {
            CH_DC1 = 0,
            CH_DC2 = 1,
            CH_DC3 = 2,
            CH_DC4 = 3,
            CH_DC5 = 4,
            CH_USB12 = 5,
            CH_USB345 = 6,
            CH_PWM13 = 7,
            CH_PWM14 = 8,
            CH_PWM15 = 9
        };

        // Sensor offsets
        static constexpr double TEMP_OFFSET = -255.5;
        static constexpr double HUMIDITY_OFFSET = -254.0;

        // Timing
        static constexpr uint32_t COMMAND_DELAY_US = 50000;   // 50ms
        static constexpr uint32_t POLL_INTERVAL_MS = 5000;    // 5 seconds
};
