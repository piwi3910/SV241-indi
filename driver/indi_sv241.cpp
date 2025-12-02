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

#include "indi_sv241.h"

#include <libindi/indicom.h>
#include <libindi/connectionplugins/connectionserial.h>

#include <cmath>
#include <cstring>
#include <fcntl.h>
#include <memory>
#include <termios.h>
#include <unistd.h>

// Singleton instance
static std::unique_ptr<SV241> sv241(new SV241());

SV241::SV241()
{
    setVersion(1, 0);
}

const char *SV241::getDefaultName()
{
    return "SVBONY SV241";
}

bool SV241::initProperties()
{
    INDI::DefaultDevice::initProperties();

    // Connection port
    PortTP[0].fill("PORT", "Port", "/dev/ttyUSB0");
    PortTP.fill(getDeviceName(), "DEVICE_PORT", "Connection", CONNECTION_TAB, IP_RW, 60, IPS_IDLE);

    // DC Output switches
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

    // USB Group switches
    USB12SP[0].fill("USB12_ON", "On", ISS_OFF);
    USB12SP[1].fill("USB12_OFF", "Off", ISS_ON);
    USB12SP.fill(getDeviceName(), "USB12", "USB 1-2", MAIN_CONTROL_TAB, IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    USB345SP[0].fill("USB345_ON", "On", ISS_OFF);
    USB345SP[1].fill("USB345_OFF", "Off", ISS_ON);
    USB345SP.fill(getDeviceName(), "USB345", "USB 3-4-5", MAIN_CONTROL_TAB, IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    // PWM controls
    PWM13NP[0].fill("PWM13_VALUE", "Value (0-253)", "%.0f", 0, PWM_MAX_VALUE, 1, 0);
    PWM13NP.fill(getDeviceName(), "PWM13", "PWM13 (Adj. Voltage)", MAIN_CONTROL_TAB, IP_RW, PROPERTY_TIMEOUT, IPS_IDLE);

    PWM14NP[0].fill("PWM14_VALUE", "Value (0-253)", "%.0f", 0, PWM_MAX_VALUE, 1, 0);
    PWM14NP.fill(getDeviceName(), "PWM14", "PWM14 (Dew Heater 1)", MAIN_CONTROL_TAB, IP_RW, PROPERTY_TIMEOUT, IPS_IDLE);

    PWM15NP[0].fill("PWM15_VALUE", "Value (0-253)", "%.0f", 0, PWM_MAX_VALUE, 1, 0);
    PWM15NP.fill(getDeviceName(), "PWM15", "PWM15 (Dew Heater 2)", MAIN_CONTROL_TAB, IP_RW, PROPERTY_TIMEOUT, IPS_IDLE);

    // PWM13 voltage display (read-only)
    PWM13VoltageNP[0].fill("PWM13_VOLTAGE", "Output (V)", "%.2f", 0, PWM13_MAX_VOLTAGE, 0.1, 0);
    PWM13VoltageNP.fill(getDeviceName(), "PWM13_OUTPUT", "PWM13 Voltage", MAIN_CONTROL_TAB, IP_RO, PROPERTY_TIMEOUT, IPS_IDLE);

    // Sensor readings
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

    // Set driver info
    addAuxControls();

    setDriverInterface(AUX_INTERFACE);

    // Define port property (needed before connection)
    defineProperty(PortTP);

    return true;
}

bool SV241::updateProperties()
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

        // Sync states from device
        syncAllStates();
        readAllSensors();

        // Start polling timer
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

bool SV241::Connect()
{
    if (!openSerialPort())
    {
        LOG_ERROR("Failed to open serial port");
        return false;
    }

    LOG_INFO("Successfully connected to SV241 Powerbox");
    return true;
}

bool SV241::Disconnect()
{
    closeSerialPort();
    LOG_INFO("Disconnected from SV241 Powerbox");
    return true;
}

bool SV241::openSerialPort()
{
    const char *portName = PortTP[0].getText();

    PortFD = open(portName, O_RDWR | O_NOCTTY);
    if (PortFD < 0)
    {
        LOGF_ERROR("Error opening serial port %s: %s", portName, strerror(errno));
        return false;
    }

    // Clear non-blocking mode (ensure blocking reads with timeout)
    fcntl(PortFD, F_SETFL, 0);

    // Configure serial port: 115200 8N1
    struct termios options;
    tcgetattr(PortFD, &options);

    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);

    options.c_cflag &= ~PARENB;  // No parity
    options.c_cflag &= ~CSTOPB;  // 1 stop bit
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;       // 8 data bits
    options.c_cflag |= CLOCAL;    // Ignore modem control lines
    options.c_cflag |= CREAD;     // Enable receiver

    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  // Raw input
    options.c_iflag &= ~(IXON | IXOFF | IXANY);          // No software flow control
    options.c_oflag &= ~OPOST;                            // Raw output

    options.c_cc[VMIN] = 0;
    options.c_cc[VTIME] = 10;  // 1 second timeout

    tcsetattr(PortFD, TCSANOW, &options);
    tcflush(PortFD, TCIOFLUSH);

    // Allow USB serial device to initialize
    usleep(500000);  // 500ms delay

    LOGF_INFO("Opened serial port %s at 115200 baud", portName);
    return true;
}

void SV241::closeSerialPort()
{
    if (PortFD >= 0)
    {
        close(PortFD);
        PortFD = -1;
    }
}

uint8_t SV241::calcChecksum(const uint8_t *cmd)
{
    // SV241 protocol uses sum % 255 (not % 256) when sum exceeds 255.
    // This is intentional device behavior - do not change to standard modulo 256.
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

bool SV241::sendCommand(uint8_t cmdId, uint8_t param1, uint8_t param2)
{
    if (PortFD < 0)
        return false;

    uint8_t cmd[6] = {CMD_HEADER, CMD_LENGTH, cmdId, param1, param2, 0x00};
    cmd[5] = calcChecksum(cmd);

    LOGF_DEBUG("TX: %02X %02X %02X %02X %02X %02X",
               cmd[0], cmd[1], cmd[2], cmd[3], cmd[4], cmd[5]);

    tcflush(PortFD, TCIFLUSH);  // Clear input buffer

    ssize_t written = write(PortFD, cmd, 6);
    if (written != 6)
    {
        LOG_ERROR("Failed to write command");
        return false;
    }

    usleep(COMMAND_DELAY_US);  // Wait 50ms for device to process
    return true;
}

bool SV241::readResponse(uint8_t *buffer, size_t len, uint8_t expectedCmd)
{
    if (PortFD < 0)
        return false;

    ssize_t bytesRead = read(PortFD, buffer, len);

    if (bytesRead > 0)
    {
        LOGF_DEBUG("RX (%zd bytes): %02X %02X %02X %02X %02X %02X %02X %02X",
                   bytesRead,
                   bytesRead > 0 ? buffer[0] : 0,
                   bytesRead > 1 ? buffer[1] : 0,
                   bytesRead > 2 ? buffer[2] : 0,
                   bytesRead > 3 ? buffer[3] : 0,
                   bytesRead > 4 ? buffer[4] : 0,
                   bytesRead > 5 ? buffer[5] : 0,
                   bytesRead > 6 ? buffer[6] : 0,
                   bytesRead > 7 ? buffer[7] : 0);
    }

    if (bytesRead != static_cast<ssize_t>(len))
    {
        LOGF_ERROR("Expected %zu bytes, got %zd", len, bytesRead);
        return false;
    }

    if (buffer[2] != expectedCmd)
    {
        LOGF_ERROR("Unexpected response command: expected %02X, got %02X", expectedCmd, buffer[2]);
        return false;
    }

    return true;
}

bool SV241::setDCOutput(int channel, bool enabled)
{
    uint8_t stateValue = enabled ? 0xFF : 0x00;

    if (!sendCommand(CMD_WRITE, static_cast<uint8_t>(channel), stateValue))
        return false;

    dcStates[channel] = enabled;
    LOGF_INFO("DC channel %d set to %s", channel + 1, enabled ? "ON" : "OFF");
    return true;
}

bool SV241::setPWMValue(int channel, uint8_t value)
{
    // PWM channels are indexed 7-9 in the protocol
    int hwChannel = channel + 7;

    if (!sendCommand(CMD_WRITE, static_cast<uint8_t>(hwChannel), value))
        return false;

    pwmValues[channel] = value;
    LOGF_INFO("PWM channel %d set to %d", channel + 13, value);
    return true;
}

bool SV241::syncAllStates()
{
    if (!sendCommand(CMD_SYNC_STATES))
        return false;

    uint8_t response[SYNC_RESPONSE_SIZE];
    if (!readResponse(response, SYNC_RESPONSE_SIZE, CMD_SYNC_STATES))
        return false;

    // Parse DC states (bytes 3-9)
    for (int i = 0; i < 7; i++)
    {
        dcStates[i] = (response[3 + i] > 0);
    }

    // Parse PWM values (bytes 10-12)
    pwmValues[0] = response[10];  // PWM13
    pwmValues[1] = response[11];  // PWM14
    pwmValues[2] = response[12];  // PWM15

    // Update UI state
    DC1SP[0].setState(dcStates[static_cast<int>(Channel::DC1)] ? ISS_ON : ISS_OFF);
    DC1SP[1].setState(dcStates[static_cast<int>(Channel::DC1)] ? ISS_OFF : ISS_ON);
    DC1SP.setState(IPS_OK);
    DC1SP.apply();

    DC2SP[0].setState(dcStates[static_cast<int>(Channel::DC2)] ? ISS_ON : ISS_OFF);
    DC2SP[1].setState(dcStates[static_cast<int>(Channel::DC2)] ? ISS_OFF : ISS_ON);
    DC2SP.setState(IPS_OK);
    DC2SP.apply();

    DC3SP[0].setState(dcStates[static_cast<int>(Channel::DC3)] ? ISS_ON : ISS_OFF);
    DC3SP[1].setState(dcStates[static_cast<int>(Channel::DC3)] ? ISS_OFF : ISS_ON);
    DC3SP.setState(IPS_OK);
    DC3SP.apply();

    DC4SP[0].setState(dcStates[static_cast<int>(Channel::DC4)] ? ISS_ON : ISS_OFF);
    DC4SP[1].setState(dcStates[static_cast<int>(Channel::DC4)] ? ISS_OFF : ISS_ON);
    DC4SP.setState(IPS_OK);
    DC4SP.apply();

    DC5SP[0].setState(dcStates[static_cast<int>(Channel::DC5)] ? ISS_ON : ISS_OFF);
    DC5SP[1].setState(dcStates[static_cast<int>(Channel::DC5)] ? ISS_OFF : ISS_ON);
    DC5SP.setState(IPS_OK);
    DC5SP.apply();

    USB12SP[0].setState(dcStates[static_cast<int>(Channel::USB12)] ? ISS_ON : ISS_OFF);
    USB12SP[1].setState(dcStates[static_cast<int>(Channel::USB12)] ? ISS_OFF : ISS_ON);
    USB12SP.setState(IPS_OK);
    USB12SP.apply();

    USB345SP[0].setState(dcStates[static_cast<int>(Channel::USB345)] ? ISS_ON : ISS_OFF);
    USB345SP[1].setState(dcStates[static_cast<int>(Channel::USB345)] ? ISS_OFF : ISS_ON);
    USB345SP.setState(IPS_OK);
    USB345SP.apply();

    PWM13NP[0].setValue(pwmValues[0]);
    PWM13NP.setState(IPS_OK);
    PWM13NP.apply();

    PWM14NP[0].setValue(pwmValues[1]);
    PWM14NP.setState(IPS_OK);
    PWM14NP.apply();

    PWM15NP[0].setValue(pwmValues[2]);
    PWM15NP.setState(IPS_OK);
    PWM15NP.apply();

    // Calculate PWM13 output voltage
    double pwm13Voltage = (pwmValues[0] * PWM13_MAX_VOLTAGE) / PWM_MAX_VALUE;
    PWM13VoltageNP[0].setValue(pwm13Voltage);
    PWM13VoltageNP.setState(IPS_OK);
    PWM13VoltageNP.apply();

    LOG_INFO("Device states synchronized");
    return true;
}

bool SV241::readVoltage()
{
    if (!sendCommand(CMD_READ_VOLTAGE))
        return false;

    uint8_t response[SENSOR_RESPONSE_SIZE];
    if (!readResponse(response, SENSOR_RESPONSE_SIZE, CMD_READ_VOLTAGE))
        return false;

    // Reverse bytes 3-6 (big-endian to little-endian)
    uint8_t data[4] = {response[6], response[5], response[4], response[3]};
    int32_t rawValue;
    memcpy(&rawValue, data, 4);

    currentVoltage = (rawValue / 100.0);

    VoltageNP[0].setValue(currentVoltage);
    VoltageNP.setState(IPS_OK);
    VoltageNP.apply();

    LOGF_DEBUG("Voltage: %.2f V", currentVoltage);
    return true;
}

bool SV241::readTemperature(bool ambient)
{
    uint8_t cmdId = ambient ? CMD_READ_AMBIENT_TEMP : CMD_READ_LENS_TEMP;

    if (!sendCommand(cmdId))
        return false;

    uint8_t response[SENSOR_RESPONSE_SIZE];
    if (!readResponse(response, SENSOR_RESPONSE_SIZE, cmdId))
        return false;

    // Reverse bytes 3-6 (big-endian to little-endian)
    uint8_t data[4] = {response[6], response[5], response[4], response[3]};
    int32_t rawValue;
    memcpy(&rawValue, data, 4);

    double temperature = (rawValue / 100.0) + TEMP_OFFSET;

    if (ambient)
    {
        ambientTemperature = temperature;
        AmbientTempNP[0].setValue(ambientTemperature);
        AmbientTempNP.setState(IPS_OK);
        AmbientTempNP.apply();
        LOGF_DEBUG("Ambient temp: %.1f C", ambientTemperature);
    }
    else
    {
        lensTemperature = temperature;
        LensTempNP[0].setValue(lensTemperature);
        LensTempNP.setState(IPS_OK);
        LensTempNP.apply();
        LOGF_DEBUG("Lens temp: %.1f C", lensTemperature);
    }

    return true;
}

bool SV241::readHumidity()
{
    if (!sendCommand(CMD_READ_HUMIDITY))
        return false;

    uint8_t response[SENSOR_RESPONSE_SIZE];
    if (!readResponse(response, SENSOR_RESPONSE_SIZE, CMD_READ_HUMIDITY))
        return false;

    // Reverse bytes 3-6 (big-endian to little-endian)
    uint8_t data[4] = {response[6], response[5], response[4], response[3]};
    int32_t rawValue;
    memcpy(&rawValue, data, 4);

    humidity = (rawValue / 100.0) + HUMIDITY_OFFSET;

    HumidityNP[0].setValue(humidity);
    HumidityNP.setState(IPS_OK);
    HumidityNP.apply();

    LOGF_DEBUG("Humidity: %.1f %%", humidity);
    return true;
}

bool SV241::readPower()
{
    if (!sendCommand(CMD_READ_POWER))
        return false;

    uint8_t response[SENSOR_RESPONSE_SIZE];
    if (!readResponse(response, SENSOR_RESPONSE_SIZE, CMD_READ_POWER))
        return false;

    // Reverse bytes 3-6 (big-endian to little-endian)
    uint8_t data[4] = {response[6], response[5], response[4], response[3]};
    int32_t rawValue;
    memcpy(&rawValue, data, 4);

    // Power calculation from protocol: (15.57 * (voltage * raw / 100) + 269.39) / 1000
    currentPower = (15.57 * (currentVoltage * rawValue / 100.0) + 269.39) / 1000.0;

    PowerNP[0].setValue(currentPower);
    PowerNP.setState(IPS_OK);
    PowerNP.apply();

    LOGF_DEBUG("Power: %.2f W", currentPower);
    return true;
}

bool SV241::readAllSensors()
{
    bool success = true;

    success &= readVoltage();
    usleep(COMMAND_DELAY_US);

    success &= readTemperature(false);  // Lens temp
    usleep(COMMAND_DELAY_US);

    success &= readTemperature(true);   // Ambient temp
    usleep(COMMAND_DELAY_US);

    success &= readHumidity();
    usleep(COMMAND_DELAY_US);

    success &= readPower();

    return success;
}

void SV241::TimerHit()
{
    if (!isConnected())
        return;

    // Read sensors periodically
    readAllSensors();

    SetTimer(POLL_INTERVAL_MS);
}

bool SV241::ISNewNumber(const char *dev, const char *name, double values[], char *names[], int n)
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

                // Update voltage display
                double voltage = (value * PWM13_MAX_VOLTAGE) / PWM_MAX_VALUE;
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

        // PWM14 control
        if (PWM14NP.isNameMatch(name))
        {
            uint8_t value = static_cast<uint8_t>(values[0]);
            if (setPWMValue(1, value))
            {
                PWM14NP[0].setValue(value);
                PWM14NP.setState(IPS_OK);
            }
            else
            {
                PWM14NP.setState(IPS_ALERT);
            }
            PWM14NP.apply();
            return true;
        }

        // PWM15 control
        if (PWM15NP.isNameMatch(name))
        {
            uint8_t value = static_cast<uint8_t>(values[0]);
            if (setPWMValue(2, value))
            {
                PWM15NP[0].setValue(value);
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

bool SV241::ISNewSwitch(const char *dev, const char *name, ISState *states, char *names[], int n)
{
    if (dev != nullptr && strcmp(dev, getDeviceName()) == 0)
    {
        // DC1 switch
        if (DC1SP.isNameMatch(name))
        {
            DC1SP.update(states, names, n);
            bool enabled = (DC1SP[0].getState() == ISS_ON);
            if (setDCOutput(static_cast<int>(Channel::DC1), enabled))
            {
                DC1SP.setState(IPS_OK);
            }
            else
            {
                DC1SP.setState(IPS_ALERT);
            }
            DC1SP.apply();
            return true;
        }

        // DC2 switch
        if (DC2SP.isNameMatch(name))
        {
            DC2SP.update(states, names, n);
            bool enabled = (DC2SP[0].getState() == ISS_ON);
            if (setDCOutput(static_cast<int>(Channel::DC2), enabled))
            {
                DC2SP.setState(IPS_OK);
            }
            else
            {
                DC2SP.setState(IPS_ALERT);
            }
            DC2SP.apply();
            return true;
        }

        // DC3 switch
        if (DC3SP.isNameMatch(name))
        {
            DC3SP.update(states, names, n);
            bool enabled = (DC3SP[0].getState() == ISS_ON);
            if (setDCOutput(static_cast<int>(Channel::DC3), enabled))
            {
                DC3SP.setState(IPS_OK);
            }
            else
            {
                DC3SP.setState(IPS_ALERT);
            }
            DC3SP.apply();
            return true;
        }

        // DC4 switch
        if (DC4SP.isNameMatch(name))
        {
            DC4SP.update(states, names, n);
            bool enabled = (DC4SP[0].getState() == ISS_ON);
            if (setDCOutput(static_cast<int>(Channel::DC4), enabled))
            {
                DC4SP.setState(IPS_OK);
            }
            else
            {
                DC4SP.setState(IPS_ALERT);
            }
            DC4SP.apply();
            return true;
        }

        // DC5 switch
        if (DC5SP.isNameMatch(name))
        {
            DC5SP.update(states, names, n);
            bool enabled = (DC5SP[0].getState() == ISS_ON);
            if (setDCOutput(static_cast<int>(Channel::DC5), enabled))
            {
                DC5SP.setState(IPS_OK);
            }
            else
            {
                DC5SP.setState(IPS_ALERT);
            }
            DC5SP.apply();
            return true;
        }

        // USB12 switch
        if (USB12SP.isNameMatch(name))
        {
            USB12SP.update(states, names, n);
            bool enabled = (USB12SP[0].getState() == ISS_ON);
            if (setDCOutput(static_cast<int>(Channel::USB12), enabled))
            {
                USB12SP.setState(IPS_OK);
            }
            else
            {
                USB12SP.setState(IPS_ALERT);
            }
            USB12SP.apply();
            return true;
        }

        // USB345 switch
        if (USB345SP.isNameMatch(name))
        {
            USB345SP.update(states, names, n);
            bool enabled = (USB345SP[0].getState() == ISS_ON);
            if (setDCOutput(static_cast<int>(Channel::USB345), enabled))
            {
                USB345SP.setState(IPS_OK);
            }
            else
            {
                USB345SP.setState(IPS_ALERT);
            }
            USB345SP.apply();
            return true;
        }
    }

    return INDI::DefaultDevice::ISNewSwitch(dev, name, states, names, n);
}

bool SV241::ISNewText(const char *dev, const char *name, char *texts[], char *names[], int n)
{
    if (dev != nullptr && strcmp(dev, getDeviceName()) == 0)
    {
        // Port selection
        if (PortTP.isNameMatch(name))
        {
            PortTP.update(texts, names, n);
            PortTP.setState(IPS_OK);
            PortTP.apply();
            return true;
        }
    }

    return INDI::DefaultDevice::ISNewText(dev, name, texts, names, n);
}

bool SV241::saveConfigItems(FILE *fp)
{
    INDI::DefaultDevice::saveConfigItems(fp);

    PortTP.save(fp);
    PWM13NP.save(fp);
    PWM14NP.save(fp);
    PWM15NP.save(fp);

    return true;
}
