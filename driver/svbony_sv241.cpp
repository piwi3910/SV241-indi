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

#include "svbony_sv241.h"

#include "indicom.h"
#include "connectionplugins/connectionserial.h"

#include <cmath>
#include <cstring>
#include <memory>
#include <termios.h>
#include <unistd.h>

static std::unique_ptr<SvbonySV241> sv241(new SvbonySV241());

SvbonySV241::SvbonySV241()
{
    setVersion(1, 0);
}

const char *SvbonySV241::getDefaultName()
{
    return "SVBONY SV241";
}

bool SvbonySV241::initProperties()
{
    INDI::DefaultDevice::initProperties();

    ////////////////////////////////////////////////////////////////////////////////////
    /// DC Output Switches
    ////////////////////////////////////////////////////////////////////////////////////
    DC1SP[0].fill("DC1_ON", "On", ISS_OFF);
    DC1SP[1].fill("DC1_OFF", "Off", ISS_ON);
    DC1SP.fill(getDeviceName(), "DC1", "DC1 Output", MAIN_CONTROL_TAB, IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    DC2SP[0].fill("DC2_ON", "On", ISS_OFF);
    DC2SP[1].fill("DC2_OFF", "Off", ISS_ON);
    DC2SP.fill(getDeviceName(), "DC2", "DC2 Output", MAIN_CONTROL_TAB, IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    DC3SP[0].fill("DC3_ON", "On", ISS_OFF);
    DC3SP[1].fill("DC3_OFF", "Off", ISS_ON);
    DC3SP.fill(getDeviceName(), "DC3", "DC3 Output", MAIN_CONTROL_TAB, IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    DC4SP[0].fill("DC4_ON", "On", ISS_OFF);
    DC4SP[1].fill("DC4_OFF", "Off", ISS_ON);
    DC4SP.fill(getDeviceName(), "DC4", "DC4 Output", MAIN_CONTROL_TAB, IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    DC5SP[0].fill("DC5_ON", "On", ISS_OFF);
    DC5SP[1].fill("DC5_OFF", "Off", ISS_ON);
    DC5SP.fill(getDeviceName(), "DC5", "DC5 Output", MAIN_CONTROL_TAB, IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    ////////////////////////////////////////////////////////////////////////////////////
    /// USB Group Switches
    ////////////////////////////////////////////////////////////////////////////////////
    USB12SP[0].fill("USB12_ON", "On", ISS_OFF);
    USB12SP[1].fill("USB12_OFF", "Off", ISS_ON);
    USB12SP.fill(getDeviceName(), "USB12", "USB 1-2", MAIN_CONTROL_TAB, IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    USB345SP[0].fill("USB345_ON", "On", ISS_OFF);
    USB345SP[1].fill("USB345_OFF", "Off", ISS_ON);
    USB345SP.fill(getDeviceName(), "USB345", "USB 3-4-5", MAIN_CONTROL_TAB, IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    ////////////////////////////////////////////////////////////////////////////////////
    /// PWM Controls
    ////////////////////////////////////////////////////////////////////////////////////
    PWM13NP[0].fill("PWM13_VALUE", "Value (0-253)", "%.0f", 0, 253, 1, 0);
    PWM13NP.fill(getDeviceName(), "PWM13", "PWM13 (Adj. Voltage)", MAIN_CONTROL_TAB, IP_RW, 60, IPS_IDLE);

    PWM14NP[0].fill("PWM14_VALUE", "Duty Cycle (%)", "%.0f", 0, 100, 1, 0);
    PWM14NP.fill(getDeviceName(), "PWM14", "Dew Heater 1", MAIN_CONTROL_TAB, IP_RW, 60, IPS_IDLE);

    PWM15NP[0].fill("PWM15_VALUE", "Duty Cycle (%)", "%.0f", 0, 100, 1, 0);
    PWM15NP.fill(getDeviceName(), "PWM15", "Dew Heater 2", MAIN_CONTROL_TAB, IP_RW, 60, IPS_IDLE);

    // PWM13 voltage display (read-only)
    PWM13VoltageNP[0].fill("PWM13_VOLTAGE", "Output (V)", "%.2f", 0, 15.3, 0.1, 0);
    PWM13VoltageNP.fill(getDeviceName(), "PWM13_OUTPUT", "PWM13 Voltage", MAIN_CONTROL_TAB, IP_RO, 60, IPS_IDLE);

    ////////////////////////////////////////////////////////////////////////////////////
    /// Sensor Readings
    ////////////////////////////////////////////////////////////////////////////////////
    VoltageNP[0].fill("INPUT_VOLTAGE", "Input (V)", "%.2f", 0, 20, 0.01, 0);
    VoltageNP.fill(getDeviceName(), "VOLTAGE", "Voltage", "Sensors", IP_RO, 60, IPS_IDLE);

    PowerNP[0].fill("POWER_CONSUMPTION", "Power (W)", "%.2f", 0, 500, 0.01, 0);
    PowerNP.fill(getDeviceName(), "POWER", "Power", "Sensors", IP_RO, 60, IPS_IDLE);

    AmbientTempNP[0].fill("AMBIENT_TEMP", "Ambient (C)", "%.1f", -40, 85, 0.1, 0);
    AmbientTempNP.fill(getDeviceName(), "AMBIENT_TEMPERATURE", "Ambient Temp", "Sensors", IP_RO, 60, IPS_IDLE);

    LensTempNP[0].fill("LENS_TEMP", "Lens (C)", "%.1f", -40, 85, 0.1, 0);
    LensTempNP.fill(getDeviceName(), "LENS_TEMPERATURE", "Lens Temp", "Sensors", IP_RO, 60, IPS_IDLE);

    HumidityNP[0].fill("HUMIDITY", "Humidity (%)", "%.1f", 0, 100, 0.1, 0);
    HumidityNP.fill(getDeviceName(), "HUMIDITY", "Humidity", "Sensors", IP_RO, 60, IPS_IDLE);

    ////////////////////////////////////////////////////////////////////////////////////
    /// Serial Connection
    ////////////////////////////////////////////////////////////////////////////////////
    serialConnection = new Connection::Serial(this);
    serialConnection->registerHandshake([&]()
    {
        return Handshake();
    });
    serialConnection->setDefaultBaudRate(Connection::Serial::B_115200);
    registerConnection(serialConnection);

    addAuxControls();
    setDriverInterface(AUX_INTERFACE);

    return true;
}

bool SvbonySV241::updateProperties()
{
    INDI::DefaultDevice::updateProperties();

    if (isConnected())
    {
        defineProperty(DC1SP);
        defineProperty(DC2SP);
        defineProperty(DC3SP);
        defineProperty(DC4SP);
        defineProperty(DC5SP);
        defineProperty(USB12SP);
        defineProperty(USB345SP);
        defineProperty(PWM13NP);
        defineProperty(PWM14NP);
        defineProperty(PWM15NP);
        defineProperty(PWM13VoltageNP);
        defineProperty(VoltageNP);
        defineProperty(PowerNP);
        defineProperty(AmbientTempNP);
        defineProperty(LensTempNP);
        defineProperty(HumidityNP);

        syncAllStates();
        readAllSensors();

        SetTimer(POLL_INTERVAL_MS);
    }
    else
    {
        deleteProperty(DC1SP);
        deleteProperty(DC2SP);
        deleteProperty(DC3SP);
        deleteProperty(DC4SP);
        deleteProperty(DC5SP);
        deleteProperty(USB12SP);
        deleteProperty(USB345SP);
        deleteProperty(PWM13NP);
        deleteProperty(PWM14NP);
        deleteProperty(PWM15NP);
        deleteProperty(PWM13VoltageNP);
        deleteProperty(VoltageNP);
        deleteProperty(PowerNP);
        deleteProperty(AmbientTempNP);
        deleteProperty(LensTempNP);
        deleteProperty(HumidityNP);
    }

    return true;
}

bool SvbonySV241::Handshake()
{
    PortFD = serialConnection->getPortFD();

    // Try to sync states to verify communication
    if (!syncAllStates())
    {
        LOG_ERROR("Handshake failed - unable to communicate with SV241");
        return false;
    }

    LOG_INFO("SV241 detected successfully");
    return true;
}

////////////////////////////////////////////////////////////////////////////////////
/// Communication
////////////////////////////////////////////////////////////////////////////////////

uint8_t SvbonySV241::calcChecksum(const uint8_t *cmd)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += cmd[i];
    }
    if (sum > 255)
    {
        sum = sum % 255;
    }
    return static_cast<uint8_t>(sum);
}

bool SvbonySV241::sendCommand(uint8_t cmdId, uint8_t param1, uint8_t param2)
{
    if (PortFD < 0)
        return false;

    uint8_t cmd[6] = {CMD_HEADER, CMD_LENGTH, cmdId, param1, param2, 0x00};
    cmd[5] = calcChecksum(cmd);

    LOGF_DEBUG("TX: %02X %02X %02X %02X %02X %02X",
               cmd[0], cmd[1], cmd[2], cmd[3], cmd[4], cmd[5]);

    tcflush(PortFD, TCIFLUSH);

    int nbytes_written = 0;
    int rc = tty_write(PortFD, reinterpret_cast<char *>(cmd), 6, &nbytes_written);

    if (rc != TTY_OK)
    {
        char errstr[MAXRBUF] = {0};
        tty_error_msg(rc, errstr, MAXRBUF);
        LOGF_ERROR("Write error: %s", errstr);
        return false;
    }

    usleep(COMMAND_DELAY_US);
    return true;
}

bool SvbonySV241::readResponse(uint8_t *buffer, size_t len, uint8_t expectedCmd)
{
    if (PortFD < 0)
        return false;

    int nbytes_read = 0;
    int rc = tty_read(PortFD, reinterpret_cast<char *>(buffer), len, 1, &nbytes_read);

    if (rc != TTY_OK)
    {
        char errstr[MAXRBUF] = {0};
        tty_error_msg(rc, errstr, MAXRBUF);
        LOGF_ERROR("Read error: %s", errstr);
        return false;
    }

    if (nbytes_read > 0)
    {
        LOGF_DEBUG("RX (%d bytes): %02X %02X %02X %02X %02X %02X %02X %02X",
                   nbytes_read,
                   nbytes_read > 0 ? buffer[0] : 0,
                   nbytes_read > 1 ? buffer[1] : 0,
                   nbytes_read > 2 ? buffer[2] : 0,
                   nbytes_read > 3 ? buffer[3] : 0,
                   nbytes_read > 4 ? buffer[4] : 0,
                   nbytes_read > 5 ? buffer[5] : 0,
                   nbytes_read > 6 ? buffer[6] : 0,
                   nbytes_read > 7 ? buffer[7] : 0);
    }

    if (static_cast<size_t>(nbytes_read) != len)
    {
        LOGF_ERROR("Expected %zu bytes, got %d", len, nbytes_read);
        return false;
    }

    if (buffer[2] != expectedCmd)
    {
        LOGF_ERROR("Unexpected response command: expected %02X, got %02X", expectedCmd, buffer[2]);
        return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////////
/// Device Control
////////////////////////////////////////////////////////////////////////////////////

bool SvbonySV241::setDCOutput(int channel, bool enabled)
{
    uint8_t stateValue = enabled ? 0xFF : 0x00;

    if (!sendCommand(CMD_WRITE, static_cast<uint8_t>(channel), stateValue))
        return false;

    m_DCStates[channel] = enabled;
    LOGF_INFO("DC channel %d set to %s", channel + 1, enabled ? "ON" : "OFF");
    return true;
}

bool SvbonySV241::setPWMValue(int channel, uint8_t value)
{
    int hwChannel = channel + 7;

    if (!sendCommand(CMD_WRITE, static_cast<uint8_t>(hwChannel), value))
        return false;

    m_PWMValues[channel] = value;
    LOGF_INFO("PWM channel %d set to %d", channel + 13, value);
    return true;
}

bool SvbonySV241::syncAllStates()
{
    if (!sendCommand(CMD_SYNC_STATES))
        return false;

    uint8_t response[14];
    if (!readResponse(response, 14, CMD_SYNC_STATES))
        return false;

    // Parse DC states (bytes 3-9)
    for (int i = 0; i < 7; i++)
    {
        m_DCStates[i] = (response[3 + i] > 0);
    }

    // Parse PWM values (bytes 10-12)
    m_PWMValues[0] = response[10];
    m_PWMValues[1] = response[11];
    m_PWMValues[2] = response[12];

    // Update DC switch states
    DC1SP[0].setState(m_DCStates[CH_DC1] ? ISS_ON : ISS_OFF);
    DC1SP[1].setState(m_DCStates[CH_DC1] ? ISS_OFF : ISS_ON);
    DC1SP.setState(IPS_OK);
    DC1SP.apply();

    DC2SP[0].setState(m_DCStates[CH_DC2] ? ISS_ON : ISS_OFF);
    DC2SP[1].setState(m_DCStates[CH_DC2] ? ISS_OFF : ISS_ON);
    DC2SP.setState(IPS_OK);
    DC2SP.apply();

    DC3SP[0].setState(m_DCStates[CH_DC3] ? ISS_ON : ISS_OFF);
    DC3SP[1].setState(m_DCStates[CH_DC3] ? ISS_OFF : ISS_ON);
    DC3SP.setState(IPS_OK);
    DC3SP.apply();

    DC4SP[0].setState(m_DCStates[CH_DC4] ? ISS_ON : ISS_OFF);
    DC4SP[1].setState(m_DCStates[CH_DC4] ? ISS_OFF : ISS_ON);
    DC4SP.setState(IPS_OK);
    DC4SP.apply();

    DC5SP[0].setState(m_DCStates[CH_DC5] ? ISS_ON : ISS_OFF);
    DC5SP[1].setState(m_DCStates[CH_DC5] ? ISS_OFF : ISS_ON);
    DC5SP.setState(IPS_OK);
    DC5SP.apply();

    USB12SP[0].setState(m_DCStates[CH_USB12] ? ISS_ON : ISS_OFF);
    USB12SP[1].setState(m_DCStates[CH_USB12] ? ISS_OFF : ISS_ON);
    USB12SP.setState(IPS_OK);
    USB12SP.apply();

    USB345SP[0].setState(m_DCStates[CH_USB345] ? ISS_ON : ISS_OFF);
    USB345SP[1].setState(m_DCStates[CH_USB345] ? ISS_OFF : ISS_ON);
    USB345SP.setState(IPS_OK);
    USB345SP.apply();

    // Update PWM values
    PWM13NP[0].setValue(m_PWMValues[0]);
    PWM13NP.setState(IPS_OK);
    PWM13NP.apply();

    // Convert PWM14/15 to percentage (0-253 -> 0-100%)
    PWM14NP[0].setValue((m_PWMValues[1] * 100.0) / 253.0);
    PWM14NP.setState(IPS_OK);
    PWM14NP.apply();

    PWM15NP[0].setValue((m_PWMValues[2] * 100.0) / 253.0);
    PWM15NP.setState(IPS_OK);
    PWM15NP.apply();

    // Calculate PWM13 output voltage: (value * 15.3) / 253
    double pwm13Voltage = (m_PWMValues[0] * 15.3) / 253.0;
    PWM13VoltageNP[0].setValue(pwm13Voltage);
    PWM13VoltageNP.setState(IPS_OK);
    PWM13VoltageNP.apply();

    LOG_DEBUG("Device states synchronized");
    return true;
}

////////////////////////////////////////////////////////////////////////////////////
/// Sensor Reading
////////////////////////////////////////////////////////////////////////////////////

bool SvbonySV241::readVoltage()
{
    if (!sendCommand(CMD_READ_VOLTAGE))
        return false;

    uint8_t response[8];
    if (!readResponse(response, 8, CMD_READ_VOLTAGE))
        return false;

    // Reverse bytes 3-6 (big-endian to little-endian)
    uint8_t data[4] = {response[6], response[5], response[4], response[3]};
    int32_t rawValue;
    memcpy(&rawValue, data, 4);

    m_CurrentVoltage = rawValue / 100.0;

    VoltageNP[0].setValue(m_CurrentVoltage);
    VoltageNP.setState(IPS_OK);
    VoltageNP.apply();

    LOGF_DEBUG("Voltage: %.2f V", m_CurrentVoltage);
    return true;
}

bool SvbonySV241::readTemperature(bool ambient)
{
    uint8_t cmdId = ambient ? CMD_READ_AMBIENT_TEMP : CMD_READ_LENS_TEMP;

    if (!sendCommand(cmdId))
        return false;

    uint8_t response[8];
    if (!readResponse(response, 8, cmdId))
        return false;

    uint8_t data[4] = {response[6], response[5], response[4], response[3]};
    int32_t rawValue;
    memcpy(&rawValue, data, 4);

    double temperature = (rawValue / 100.0) + TEMP_OFFSET;

    if (ambient)
    {
        m_AmbientTemperature = temperature;
        AmbientTempNP[0].setValue(m_AmbientTemperature);
        AmbientTempNP.setState(IPS_OK);
        AmbientTempNP.apply();
        LOGF_DEBUG("Ambient temp: %.1f C", m_AmbientTemperature);
    }
    else
    {
        m_LensTemperature = temperature;
        LensTempNP[0].setValue(m_LensTemperature);
        LensTempNP.setState(IPS_OK);
        LensTempNP.apply();
        LOGF_DEBUG("Lens temp: %.1f C", m_LensTemperature);
    }

    return true;
}

bool SvbonySV241::readHumidity()
{
    if (!sendCommand(CMD_READ_HUMIDITY))
        return false;

    uint8_t response[8];
    if (!readResponse(response, 8, CMD_READ_HUMIDITY))
        return false;

    uint8_t data[4] = {response[6], response[5], response[4], response[3]};
    int32_t rawValue;
    memcpy(&rawValue, data, 4);

    m_Humidity = (rawValue / 100.0) + HUMIDITY_OFFSET;

    HumidityNP[0].setValue(m_Humidity);
    HumidityNP.setState(IPS_OK);
    HumidityNP.apply();

    LOGF_DEBUG("Humidity: %.1f %%", m_Humidity);
    return true;
}

bool SvbonySV241::readPower()
{
    if (!sendCommand(CMD_READ_POWER))
        return false;

    uint8_t response[8];
    if (!readResponse(response, 8, CMD_READ_POWER))
        return false;

    uint8_t data[4] = {response[6], response[5], response[4], response[3]};
    int32_t rawValue;
    memcpy(&rawValue, data, 4);

    // Power calculation from protocol
    m_CurrentPower = (15.57 * (m_CurrentVoltage * rawValue / 100.0) + 269.39) / 1000.0;

    PowerNP[0].setValue(m_CurrentPower);
    PowerNP.setState(IPS_OK);
    PowerNP.apply();

    LOGF_DEBUG("Power: %.2f W", m_CurrentPower);
    return true;
}

bool SvbonySV241::readAllSensors()
{
    bool success = true;

    success &= readVoltage();
    usleep(COMMAND_DELAY_US);

    success &= readTemperature(false);
    usleep(COMMAND_DELAY_US);

    success &= readTemperature(true);
    usleep(COMMAND_DELAY_US);

    success &= readHumidity();
    usleep(COMMAND_DELAY_US);

    success &= readPower();

    return success;
}

void SvbonySV241::TimerHit()
{
    if (!isConnected())
        return;

    readAllSensors();
    SetTimer(POLL_INTERVAL_MS);
}

////////////////////////////////////////////////////////////////////////////////////
/// ISNewNumber / ISNewSwitch
////////////////////////////////////////////////////////////////////////////////////

bool SvbonySV241::ISNewNumber(const char *dev, const char *name, double values[], char *names[], int n)
{
    if (dev != nullptr && strcmp(dev, getDeviceName()) == 0)
    {
        // PWM13 control
        if (PWM13NP.isNameMatch(name))
        {
            uint8_t value = static_cast<uint8_t>(values[0]);
            if (setPWMValue(0, value))
            {
                PWM13NP[0].setValue(value);
                PWM13NP.setState(IPS_OK);

                double voltage = (value * 15.3) / 253.0;
                PWM13VoltageNP[0].setValue(voltage);
                PWM13VoltageNP.setState(IPS_OK);
                PWM13VoltageNP.apply();
            }
            else
            {
                PWM13NP.setState(IPS_ALERT);
            }
            PWM13NP.apply();
            return true;
        }

        // PWM14 control (convert percentage to 0-253)
        if (PWM14NP.isNameMatch(name))
        {
            uint8_t value = static_cast<uint8_t>((values[0] * 253.0) / 100.0);
            if (setPWMValue(1, value))
            {
                PWM14NP[0].setValue(values[0]);
                PWM14NP.setState(IPS_OK);
            }
            else
            {
                PWM14NP.setState(IPS_ALERT);
            }
            PWM14NP.apply();
            return true;
        }

        // PWM15 control (convert percentage to 0-253)
        if (PWM15NP.isNameMatch(name))
        {
            uint8_t value = static_cast<uint8_t>((values[0] * 253.0) / 100.0);
            if (setPWMValue(2, value))
            {
                PWM15NP[0].setValue(values[0]);
                PWM15NP.setState(IPS_OK);
            }
            else
            {
                PWM15NP.setState(IPS_ALERT);
            }
            PWM15NP.apply();
            return true;
        }
    }

    return INDI::DefaultDevice::ISNewNumber(dev, name, values, names, n);
}

bool SvbonySV241::ISNewSwitch(const char *dev, const char *name, ISState *states, char *names[], int n)
{
    if (dev != nullptr && strcmp(dev, getDeviceName()) == 0)
    {
        // DC1 switch
        if (DC1SP.isNameMatch(name))
        {
            DC1SP.update(states, names, n);
            bool enabled = (DC1SP[0].getState() == ISS_ON);
            DC1SP.setState(setDCOutput(CH_DC1, enabled) ? IPS_OK : IPS_ALERT);
            DC1SP.apply();
            return true;
        }

        // DC2 switch
        if (DC2SP.isNameMatch(name))
        {
            DC2SP.update(states, names, n);
            bool enabled = (DC2SP[0].getState() == ISS_ON);
            DC2SP.setState(setDCOutput(CH_DC2, enabled) ? IPS_OK : IPS_ALERT);
            DC2SP.apply();
            return true;
        }

        // DC3 switch
        if (DC3SP.isNameMatch(name))
        {
            DC3SP.update(states, names, n);
            bool enabled = (DC3SP[0].getState() == ISS_ON);
            DC3SP.setState(setDCOutput(CH_DC3, enabled) ? IPS_OK : IPS_ALERT);
            DC3SP.apply();
            return true;
        }

        // DC4 switch
        if (DC4SP.isNameMatch(name))
        {
            DC4SP.update(states, names, n);
            bool enabled = (DC4SP[0].getState() == ISS_ON);
            DC4SP.setState(setDCOutput(CH_DC4, enabled) ? IPS_OK : IPS_ALERT);
            DC4SP.apply();
            return true;
        }

        // DC5 switch
        if (DC5SP.isNameMatch(name))
        {
            DC5SP.update(states, names, n);
            bool enabled = (DC5SP[0].getState() == ISS_ON);
            DC5SP.setState(setDCOutput(CH_DC5, enabled) ? IPS_OK : IPS_ALERT);
            DC5SP.apply();
            return true;
        }

        // USB12 switch
        if (USB12SP.isNameMatch(name))
        {
            USB12SP.update(states, names, n);
            bool enabled = (USB12SP[0].getState() == ISS_ON);
            USB12SP.setState(setDCOutput(CH_USB12, enabled) ? IPS_OK : IPS_ALERT);
            USB12SP.apply();
            return true;
        }

        // USB345 switch
        if (USB345SP.isNameMatch(name))
        {
            USB345SP.update(states, names, n);
            bool enabled = (USB345SP[0].getState() == ISS_ON);
            USB345SP.setState(setDCOutput(CH_USB345, enabled) ? IPS_OK : IPS_ALERT);
            USB345SP.apply();
            return true;
        }
    }

    return INDI::DefaultDevice::ISNewSwitch(dev, name, states, names, n);
}

bool SvbonySV241::saveConfigItems(FILE *fp)
{
    INDI::DefaultDevice::saveConfigItems(fp);

    PWM13NP.save(fp);
    PWM14NP.save(fp);
    PWM15NP.save(fp);

    return true;
}
