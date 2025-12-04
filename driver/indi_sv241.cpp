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

#include <algorithm>
#include <cmath>
#include <cstring>
#include <fcntl.h>
#include <memory>
#include <sstream>
#include <termios.h>
#include <unistd.h>

// Simple JSON parsing helpers (minimal implementation to avoid dependencies)
namespace {
    std::string getJsonString(const std::string &json, const std::string &key) {
        std::string search = "\"" + key + "\":\"";
        size_t pos = json.find(search);
        if (pos == std::string::npos) return "";
        pos += search.length();
        size_t end = json.find("\"", pos);
        if (end == std::string::npos) return "";
        return json.substr(pos, end - pos);
    }

    double getJsonDouble(const std::string &json, const std::string &key, double defaultVal = 0.0) {
        std::string search = "\"" + key + "\":";
        size_t pos = json.find(search);
        if (pos == std::string::npos) return defaultVal;
        pos += search.length();
        // Skip whitespace
        while (pos < json.length() && (json[pos] == ' ' || json[pos] == '\t')) pos++;
        // Find end of number
        size_t end = pos;
        while (end < json.length() && (isdigit(json[end]) || json[end] == '.' || json[end] == '-')) end++;
        if (end == pos) return defaultVal;
        try {
            return std::stod(json.substr(pos, end - pos));
        } catch (...) {
            return defaultVal;
        }
    }

    bool getJsonBool(const std::string &json, const std::string &key, bool defaultVal = false) {
        std::string search = "\"" + key + "\":";
        size_t pos = json.find(search);
        if (pos == std::string::npos) return defaultVal;
        pos += search.length();
        while (pos < json.length() && (json[pos] == ' ' || json[pos] == '\t')) pos++;
        if (pos + 4 <= json.length() && json.substr(pos, 4) == "true") return true;
        if (pos + 5 <= json.length() && json.substr(pos, 5) == "false") return false;
        return defaultVal;
    }

    int getJsonInt(const std::string &json, const std::string &key, int defaultVal = 0) {
        return static_cast<int>(getJsonDouble(json, key, defaultVal));
    }

    std::vector<std::string> getJsonStringArray(const std::string &json, const std::string &key) {
        std::vector<std::string> result;
        std::string search = "\"" + key + "\":[";
        size_t pos = json.find(search);
        if (pos == std::string::npos) return result;
        pos += search.length();
        size_t end = json.find("]", pos);
        if (end == std::string::npos) return result;
        std::string arr = json.substr(pos, end - pos);
        // Parse array elements
        size_t start = 0;
        while ((start = arr.find("\"", start)) != std::string::npos) {
            start++;
            size_t strEnd = arr.find("\"", start);
            if (strEnd == std::string::npos) break;
            result.push_back(arr.substr(start, strEnd - start));
            start = strEnd + 1;
        }
        return result;
    }
}

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
    PortTP[0].fill("PORT", "Port", "/dev/tty.usbserial-1133440");
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

    // Extended firmware properties (initialized but only shown if extended firmware detected)
    // Dew point
    DewPointNP[0].fill("DEW_POINT", "Dew Point (C)", "%.1f", -40, 85, 0.1, 0);
    DewPointNP.fill(getDeviceName(), "DEW_POINT", "Dew Point", "Sensors", IP_RO, 60, IPS_IDLE);

    // Auto dew switches
    AutoDew14SP[0].fill("AUTO_DEW14_ON", "On", ISS_OFF);
    AutoDew14SP[1].fill("AUTO_DEW14_OFF", "Off", ISS_ON);
    AutoDew14SP.fill(getDeviceName(), "AUTO_DEW14", "Auto Dew CH14", "Dew Control", IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    AutoDew15SP[0].fill("AUTO_DEW15_ON", "On", ISS_OFF);
    AutoDew15SP[1].fill("AUTO_DEW15_OFF", "Off", ISS_ON);
    AutoDew15SP.fill(getDeviceName(), "AUTO_DEW15", "Auto Dew CH15", "Dew Control", IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    // Dew margin controls
    DewMargin14NP[0].fill("DEW_MARGIN14", "Margin (C)", "%.1f", 0, 20, 0.5, 5.0);
    DewMargin14NP.fill(getDeviceName(), "DEW_MARGIN14", "CH14 Margin", "Dew Control", IP_RW, 60, IPS_IDLE);

    DewMargin15NP[0].fill("DEW_MARGIN15", "Margin (C)", "%.1f", 0, 20, 0.5, 5.0);
    DewMargin15NP.fill(getDeviceName(), "DEW_MARGIN15", "CH15 Margin", "Dew Control", IP_RW, 60, IPS_IDLE);

    // Session statistics
    StatsVoltageNP[0].fill("STATS_V_MIN", "Min (V)", "%.2f", 0, 20, 0.01, 0);
    StatsVoltageNP[1].fill("STATS_V_MAX", "Max (V)", "%.2f", 0, 20, 0.01, 0);
    StatsVoltageNP[2].fill("STATS_V_AVG", "Avg (V)", "%.2f", 0, 20, 0.01, 0);
    StatsVoltageNP.fill(getDeviceName(), "STATS_VOLTAGE", "Voltage Stats", "Statistics", IP_RO, 60, IPS_IDLE);

    StatsPowerNP[0].fill("STATS_P_MAX", "Peak (W)", "%.2f", 0, 500, 0.01, 0);
    StatsPowerNP[1].fill("STATS_P_TOTAL", "Total (Wh)", "%.2f", 0, 10000, 0.01, 0);
    StatsPowerNP.fill(getDeviceName(), "STATS_POWER", "Power Stats", "Statistics", IP_RO, 60, IPS_IDLE);

    StatsTempNP[0].fill("STATS_T_MIN", "Min (C)", "%.1f", -40, 85, 0.1, 0);
    StatsTempNP[1].fill("STATS_T_MAX", "Max (C)", "%.1f", -40, 85, 0.1, 0);
    StatsTempNP.fill(getDeviceName(), "STATS_TEMP", "Temp Stats", "Statistics", IP_RO, 60, IPS_IDLE);

    UptimeNP[0].fill("UPTIME", "Uptime (s)", "%.0f", 0, 1000000, 1, 0);
    UptimeNP.fill(getDeviceName(), "UPTIME", "Uptime", "Statistics", IP_RO, 60, IPS_IDLE);

    // Alert status lights
    AlertsLP[0].fill("ALERT_LOW_V", "Low Voltage", IPS_IDLE);
    AlertsLP[1].fill("ALERT_CRIT_V", "Critical Voltage", IPS_IDLE);
    AlertsLP[2].fill("ALERT_THERMAL", "Thermal", IPS_IDLE);
    AlertsLP[3].fill("ALERT_I2C", "I2C Fail", IPS_IDLE);
    AlertsLP.fill(getDeviceName(), "ALERTS", "Alerts", "Diagnostics", IPS_IDLE);

    // Diagnostics
    DiagnosticsNP[0].fill("FREE_HEAP", "Free Heap (bytes)", "%.0f", 0, 500000, 1, 0);
    DiagnosticsNP.fill(getDeviceName(), "DIAGNOSTICS", "Diagnostics", "Diagnostics", IP_RO, 60, IPS_IDLE);

    // Sensor status lights
    SensorStatusLP[0].fill("I2C_OK", "I2C Bus", IPS_IDLE);
    SensorStatusLP[1].fill("INA219_OK", "INA219", IPS_IDLE);
    SensorStatusLP[2].fill("SHT4X_OK", "SHT4x", IPS_IDLE);
    SensorStatusLP.fill(getDeviceName(), "SENSOR_STATUS", "Sensor Status", "Diagnostics", IPS_IDLE);

    // Firmware info
    FirmwareTP[0].fill("FW_VERSION", "Version", "");
    FirmwareTP[1].fill("FW_CAPS", "Capabilities", "");
    FirmwareTP.fill(getDeviceName(), "FIRMWARE", "Firmware", OPTIONS_TAB, IP_RO, 60, IPS_IDLE);

    // Calibration offsets
    CalibrationNP[0].fill("CAL_V_OFFSET", "Voltage (V)", "%.2f", -2.0, 2.0, 0.01, 0);
    CalibrationNP[1].fill("CAL_T_OFFSET", "Temperature (C)", "%.1f", -10.0, 10.0, 0.1, 0);
    CalibrationNP[2].fill("CAL_H_OFFSET", "Humidity (%)", "%.1f", -20.0, 20.0, 0.5, 0);
    CalibrationNP.fill(getDeviceName(), "CALIBRATION", "Calibration", "Calibration", IP_RW, 60, IPS_IDLE);

    // Alert configuration
    AlertConfigNP[0].fill("ALERT_LOW_V_THRESH", "Low V Threshold", "%.1f", 10.0, 14.0, 0.1, 11.5);
    AlertConfigNP[1].fill("ALERT_CRIT_V_THRESH", "Critical V Threshold", "%.1f", 9.0, 12.0, 0.1, 11.0);
    AlertConfigNP[2].fill("ALERT_CRIT_V_THRESH2", "Reserved", "%.1f", 0, 0, 0, 0);  // placeholder for future
    AlertConfigNP.fill(getDeviceName(), "ALERT_CONFIG", "Alert Thresholds", "Alerts", IP_RW, 60, IPS_IDLE);

    AlertLowVSP[0].fill("ALERT_LOW_V_ON", "Enabled", ISS_ON);
    AlertLowVSP[1].fill("ALERT_LOW_V_OFF", "Disabled", ISS_OFF);
    AlertLowVSP.fill(getDeviceName(), "ALERT_LOW_V_EN", "Low Voltage Alert", "Alerts", IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    AlertCritVSP[0].fill("ALERT_CRIT_V_ON", "Enabled", ISS_ON);
    AlertCritVSP[1].fill("ALERT_CRIT_V_OFF", "Disabled", ISS_OFF);
    AlertCritVSP.fill(getDeviceName(), "ALERT_CRIT_V_EN", "Critical Voltage Alert", "Alerts", IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    AlertAutoOffSP[0].fill("ALERT_AUTO_OFF_ON", "Enabled", ISS_ON);
    AlertAutoOffSP[1].fill("ALERT_AUTO_OFF_OFF", "Disabled", ISS_OFF);
    AlertAutoOffSP.fill(getDeviceName(), "ALERT_AUTO_OFF", "Auto-Off on Critical", "Alerts", IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    // I2C Recovery button
    I2CRecoverySP[0].fill("I2C_RECOVER", "Recover", ISS_OFF);
    I2CRecoverySP.fill(getDeviceName(), "I2C_RECOVERY", "I2C Recovery", "Diagnostics", IP_RW, ISR_ATMOST1, 60, IPS_IDLE);

    // Stats reset button
    StatsResetSP[0].fill("STATS_RESET", "Reset", ISS_OFF);
    StatsResetSP.fill(getDeviceName(), "STATS_RESET", "Reset Statistics", "Statistics", IP_RW, ISR_ATMOST1, 60, IPS_IDLE);

    // Port names (custom labels)
    PortNamesTP[0].fill("PORT_DC1", "DC1", "DC1");
    PortNamesTP[1].fill("PORT_DC2", "DC2", "DC2");
    PortNamesTP[2].fill("PORT_DC3", "DC3", "DC3");
    PortNamesTP[3].fill("PORT_DC4", "DC4", "DC4");
    PortNamesTP[4].fill("PORT_DC5", "DC5", "DC5");
    PortNamesTP[5].fill("PORT_USB12", "USB12", "USB12");
    PortNamesTP[6].fill("PORT_USB345", "USB345", "USB345");
    PortNamesTP[7].fill("PORT_PWM13", "PWM13", "PWM13");
    PortNamesTP[8].fill("PORT_PWM14", "PWM14", "PWM14");
    PortNamesTP[9].fill("PORT_PWM15", "PWM15", "PWM15");
    PortNamesTP.fill(getDeviceName(), "PORT_NAMES", "Port Names", "Port Labels", IP_RW, 60, IPS_IDLE);

    // Phase 3: Profiles
    ProfilesTP[0].fill("PROFILE_0", "Slot 0", "(empty)");
    ProfilesTP[1].fill("PROFILE_1", "Slot 1", "(empty)");
    ProfilesTP[2].fill("PROFILE_2", "Slot 2", "(empty)");
    ProfilesTP[3].fill("PROFILE_3", "Slot 3", "(empty)");
    ProfilesTP.fill(getDeviceName(), "PROFILES", "Saved Profiles", "Profiles", IP_RO, 60, IPS_IDLE);

    ProfileLoadSP[0].fill("LOAD_0", "Load 0", ISS_OFF);
    ProfileLoadSP[1].fill("LOAD_1", "Load 1", ISS_OFF);
    ProfileLoadSP[2].fill("LOAD_2", "Load 2", ISS_OFF);
    ProfileLoadSP[3].fill("LOAD_3", "Load 3", ISS_OFF);
    ProfileLoadSP.fill(getDeviceName(), "PROFILE_LOAD", "Load Profile", "Profiles", IP_RW, ISR_ATMOST1, 60, IPS_IDLE);

    ProfileSaveSP[0].fill("SAVE_0", "Save to 0", ISS_OFF);
    ProfileSaveSP[1].fill("SAVE_1", "Save to 1", ISS_OFF);
    ProfileSaveSP[2].fill("SAVE_2", "Save to 2", ISS_OFF);
    ProfileSaveSP[3].fill("SAVE_3", "Save to 3", ISS_OFF);
    ProfileSaveSP.fill(getDeviceName(), "PROFILE_SAVE", "Save Profile", "Profiles", IP_RW, ISR_ATMOST1, 60, IPS_IDLE);

    ProfileDeleteSP[0].fill("DELETE_0", "Delete 0", ISS_OFF);
    ProfileDeleteSP[1].fill("DELETE_1", "Delete 1", ISS_OFF);
    ProfileDeleteSP[2].fill("DELETE_2", "Delete 2", ISS_OFF);
    ProfileDeleteSP[3].fill("DELETE_3", "Delete 3", ISS_OFF);
    ProfileDeleteSP.fill(getDeviceName(), "PROFILE_DELETE", "Delete Profile", "Profiles", IP_RW, ISR_ATMOST1, 60, IPS_IDLE);

    ProfileNameTP[0].fill("PROFILE_NAME", "Profile Name", "New Profile");
    ProfileNameTP.fill(getDeviceName(), "PROFILE_NAME_INPUT", "Save As", "Profiles", IP_RW, 60, IPS_IDLE);

    ActiveProfileNP[0].fill("ACTIVE_PROFILE", "Active", "%.0f", -1, 3, 1, -1);
    ActiveProfileNP.fill(getDeviceName(), "ACTIVE_PROFILE", "Active Profile", "Profiles", IP_RO, 60, IPS_IDLE);

    // Phase 3: Timers
    TimerStatusTP[0].fill("TIMER_0", "Timer 1", "");
    TimerStatusTP[1].fill("TIMER_1", "Timer 2", "");
    TimerStatusTP[2].fill("TIMER_2", "Timer 3", "");
    TimerStatusTP[3].fill("TIMER_3", "Timer 4", "");
    TimerStatusTP.fill(getDeviceName(), "TIMER_STATUS", "Active Timers", "Timers", IP_RO, 60, IPS_IDLE);

    TimerPortTP[0].fill("TIMER_PORT", "Port", "dc1");
    TimerPortTP.fill(getDeviceName(), "TIMER_PORT_INPUT", "Port", "Timers", IP_RW, 60, IPS_IDLE);

    TimerActionSP[0].fill("ACTION_ON", "On", ISS_ON);
    TimerActionSP[1].fill("ACTION_OFF", "Off", ISS_OFF);
    TimerActionSP[2].fill("ACTION_SET", "Set PWM", ISS_OFF);
    TimerActionSP.fill(getDeviceName(), "TIMER_ACTION", "Action", "Timers", IP_RW, ISR_1OFMANY, 60, IPS_IDLE);

    TimerMinutesNP[0].fill("TIMER_MINUTES", "Minutes", "%.0f", 1, 1440, 1, 60);
    TimerMinutesNP.fill(getDeviceName(), "TIMER_MINUTES", "Delay", "Timers", IP_RW, 60, IPS_IDLE);

    TimerValueNP[0].fill("TIMER_VALUE", "PWM Value", "%.0f", 0, 253, 1, 0);
    TimerValueNP.fill(getDeviceName(), "TIMER_VALUE", "PWM Value", "Timers", IP_RW, 60, IPS_IDLE);

    TimerSetSP[0].fill("TIMER_CREATE", "Create Timer", ISS_OFF);
    TimerSetSP.fill(getDeviceName(), "TIMER_SET", "Create", "Timers", IP_RW, ISR_ATMOST1, 60, IPS_IDLE);

    TimerCancelSP[0].fill("CANCEL_0", "Cancel 1", ISS_OFF);
    TimerCancelSP[1].fill("CANCEL_1", "Cancel 2", ISS_OFF);
    TimerCancelSP[2].fill("CANCEL_2", "Cancel 3", ISS_OFF);
    TimerCancelSP[3].fill("CANCEL_3", "Cancel 4", ISS_OFF);
    TimerCancelSP.fill(getDeviceName(), "TIMER_CANCEL", "Cancel Timer", "Timers", IP_RW, ISR_ATMOST1, 60, IPS_IDLE);

    // Phase 3: Temperature rate
    TempRateNP[0].fill("TEMP_RATE", "Rate (C/hour)", "%.2f", -10, 10, 0.1, 0);
    TempRateNP.fill(getDeviceName(), "TEMP_RATE", "Temp Change Rate", "Sensors", IP_RO, 60, IPS_IDLE);

    // Phase 3: PID tuning
    PID14NP[0].fill("PID14_KP", "Kp", "%.2f", 0, 10, 0.1, 2.0);
    PID14NP[1].fill("PID14_KI", "Ki", "%.2f", 0, 5, 0.05, 0.5);
    PID14NP[2].fill("PID14_KD", "Kd", "%.2f", 0, 2, 0.01, 0.1);
    PID14NP.fill(getDeviceName(), "PID_CH14", "PID CH14", "Dew Control", IP_RW, 60, IPS_IDLE);

    PID15NP[0].fill("PID15_KP", "Kp", "%.2f", 0, 10, 0.1, 2.0);
    PID15NP[1].fill("PID15_KI", "Ki", "%.2f", 0, 5, 0.05, 0.5);
    PID15NP[2].fill("PID15_KD", "Kd", "%.2f", 0, 2, 0.01, 0.1);
    PID15NP.fill(getDeviceName(), "PID_CH15", "PID CH15", "Dew Control", IP_RW, 60, IPS_IDLE);

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
        // Basic properties (always shown)
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

        // Detect extended firmware and show additional properties if available
        if (detectExtendedFirmware())
        {
            LOG_INFO("Extended firmware detected - enabling advanced features");

            // Show firmware info
            defineProperty(FirmwareTP);

            // Dew control properties
            defineProperty(DewPointNP);
            defineProperty(AutoDew14SP);
            defineProperty(AutoDew15SP);
            defineProperty(DewMargin14NP);
            defineProperty(DewMargin15NP);

            // Statistics properties
            defineProperty(StatsVoltageNP);
            defineProperty(StatsPowerNP);
            defineProperty(StatsTempNP);
            defineProperty(UptimeNP);

            // Diagnostics properties
            defineProperty(AlertsLP);
            defineProperty(DiagnosticsNP);
            defineProperty(SensorStatusLP);
            defineProperty(I2CRecoverySP);

            // Calibration properties
            defineProperty(CalibrationNP);

            // Alert config properties
            defineProperty(AlertConfigNP);
            defineProperty(AlertLowVSP);
            defineProperty(AlertCritVSP);
            defineProperty(AlertAutoOffSP);

            // Stats reset button
            defineProperty(StatsResetSP);

            // Port names
            defineProperty(PortNamesTP);

            // Phase 3: Profiles
            defineProperty(ProfilesTP);
            defineProperty(ProfileLoadSP);
            defineProperty(ProfileSaveSP);
            defineProperty(ProfileDeleteSP);
            defineProperty(ProfileNameTP);
            defineProperty(ActiveProfileNP);

            // Phase 3: Timers
            defineProperty(TimerStatusTP);
            defineProperty(TimerPortTP);
            defineProperty(TimerActionSP);
            defineProperty(TimerMinutesNP);
            defineProperty(TimerValueNP);
            defineProperty(TimerSetSP);
            defineProperty(TimerCancelSP);

            // Phase 3: Temperature rate
            defineProperty(TempRateNP);

            // Phase 3: PID tuning
            defineProperty(PID14NP);
            defineProperty(PID15NP);

            // Get initial extended status
            extGetStatus();
            extGetDewStatus();
            extGetStats();
            extGetAlerts();
            extGetDiagnostics();
            extGetCalibration();
            extGetAlertConfig();
            extGetNames();

            // Phase 3: Get initial profile, timer, temp rate, and PID status
            extGetProfiles();
            extGetTimers();
            extGetTempRate();
            extGetDewPid(14);
            extGetDewPid(15);
        }
        else
        {
            LOG_INFO("Standard firmware detected - basic features only");
        }

        // Start polling timer
        SetTimer(POLL_INTERVAL_MS);
    }
    else
    {
        // Basic properties
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

        // Extended properties (only if they were shown)
        if (hasExtendedFirmware)
        {
            deleteProperty(FirmwareTP);
            deleteProperty(DewPointNP);
            deleteProperty(AutoDew14SP);
            deleteProperty(AutoDew15SP);
            deleteProperty(DewMargin14NP);
            deleteProperty(DewMargin15NP);
            deleteProperty(StatsVoltageNP);
            deleteProperty(StatsPowerNP);
            deleteProperty(StatsTempNP);
            deleteProperty(UptimeNP);
            deleteProperty(AlertsLP);
            deleteProperty(DiagnosticsNP);
            deleteProperty(SensorStatusLP);
            deleteProperty(I2CRecoverySP);
            deleteProperty(CalibrationNP);
            deleteProperty(AlertConfigNP);
            deleteProperty(AlertLowVSP);
            deleteProperty(AlertCritVSP);
            deleteProperty(AlertAutoOffSP);
            deleteProperty(StatsResetSP);
            deleteProperty(PortNamesTP);

            // Phase 3: Profiles
            deleteProperty(ProfilesTP);
            deleteProperty(ProfileLoadSP);
            deleteProperty(ProfileSaveSP);
            deleteProperty(ProfileDeleteSP);
            deleteProperty(ProfileNameTP);
            deleteProperty(ActiveProfileNP);

            // Phase 3: Timers
            deleteProperty(TimerStatusTP);
            deleteProperty(TimerPortTP);
            deleteProperty(TimerActionSP);
            deleteProperty(TimerMinutesNP);
            deleteProperty(TimerValueNP);
            deleteProperty(TimerSetSP);
            deleteProperty(TimerCancelSP);

            // Phase 3: Temperature rate
            deleteProperty(TempRateNP);

            // Phase 3: PID tuning
            deleteProperty(PID14NP);
            deleteProperty(PID15NP);
        }

        hasExtendedFirmware = false;
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
    options.c_cflag &= ~HUPCL;    // IMPORTANT: Disable HUPCL to prevent DTR drop on close, which resets the ESP32
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

    // Loop-based write to handle partial writes
    size_t totalWritten = 0;
    while (totalWritten < 6)
    {
        ssize_t written = write(PortFD, cmd + totalWritten, 6 - totalWritten);
        if (written < 0)
        {
            LOGF_ERROR("Write error: %s", strerror(errno));
            return false;
        }
        if (written == 0)
        {
            LOG_ERROR("Write returned 0 bytes");
            return false;
        }
        totalWritten += written;
    }

    usleep(COMMAND_DELAY_US);  // Wait 50ms for device to process
    return true;
}

bool SV241::readResponse(uint8_t *buffer, size_t len, uint8_t expectedCmd)
{
    if (PortFD < 0)
        return false;

    // Use poll() for precise timeout handling
    struct pollfd pfd;
    pfd.fd = PortFD;
    pfd.events = POLLIN;

    // Loop-based read to handle partial reads with poll() timeout
    size_t totalRead = 0;
    while (totalRead < len)
    {
        // Wait for data with timeout
        int pollResult = poll(&pfd, 1, READ_TIMEOUT_MS);
        if (pollResult < 0)
        {
            LOGF_ERROR("Poll error: %s", strerror(errno));
            tcflush(PortFD, TCIOFLUSH);
            return false;
        }
        if (pollResult == 0)
        {
            // Timeout - no data available
            LOG_DEBUG("Read timeout waiting for data");
            break;
        }

        // Data is available, read it
        ssize_t bytesRead = read(PortFD, buffer + totalRead, len - totalRead);
        if (bytesRead < 0)
        {
            LOGF_ERROR("Read error: %s", strerror(errno));
            tcflush(PortFD, TCIOFLUSH);
            return false;
        }
        if (bytesRead == 0)
        {
            // EOF - connection closed
            LOG_ERROR("Read returned 0 bytes (EOF)");
            break;
        }
        totalRead += bytesRead;
    }

    if (totalRead > 0)
    {
        LOGF_DEBUG("RX (%zu bytes): %02X %02X %02X %02X %02X %02X %02X %02X",
                   totalRead,
                   totalRead > 0 ? buffer[0] : 0,
                   totalRead > 1 ? buffer[1] : 0,
                   totalRead > 2 ? buffer[2] : 0,
                   totalRead > 3 ? buffer[3] : 0,
                   totalRead > 4 ? buffer[4] : 0,
                   totalRead > 5 ? buffer[5] : 0,
                   totalRead > 6 ? buffer[6] : 0,
                   totalRead > 7 ? buffer[7] : 0);
    }

    if (totalRead != len)
    {
        LOGF_ERROR("Expected %zu bytes, got %zu", len, totalRead);
        tcflush(PortFD, TCIOFLUSH);
        return false;
    }

    if (buffer[2] != expectedCmd)
    {
        LOGF_ERROR("Unexpected response command: expected %02X, got %02X", expectedCmd, buffer[2]);
        tcflush(PortFD, TCIOFLUSH);
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

// ============================================================================
// Extended Protocol Implementation
// ============================================================================

bool SV241::sendExtendedCommand(const std::string &jsonCmd, std::string &response)
{
    if (PortFD < 0)
        return false;

    // Build frame: [0x24] [LEN] [0x10] [JSON...] [CHECKSUM]
    size_t jsonLen = jsonCmd.length();
    size_t totalLen = 1 + 1 + 1 + jsonLen + 1;  // header + len + cmd + json + checksum

    std::vector<uint8_t> frame(totalLen);
    frame[0] = CMD_HEADER;
    frame[1] = static_cast<uint8_t>(totalLen);
    frame[2] = CMD_EXTENDED;
    memcpy(&frame[3], jsonCmd.c_str(), jsonLen);

    // Calculate checksum
    int sum = 0;
    for (size_t i = 0; i < totalLen - 1; i++)
        sum += frame[i];
    if (sum > 255)
        sum = sum % 255;
    frame[totalLen - 1] = static_cast<uint8_t>(sum);

    LOGF_DEBUG("EXT TX: %s", jsonCmd.c_str());

    tcflush(PortFD, TCIFLUSH);

    // Write frame
    size_t totalWritten = 0;
    while (totalWritten < totalLen)
    {
        ssize_t written = write(PortFD, &frame[totalWritten], totalLen - totalWritten);
        if (written <= 0)
        {
            LOG_ERROR("Extended command write error");
            return false;
        }
        totalWritten += written;
    }

    usleep(200000);  // Wait 200ms for response

    // Read response - first read header to get length
    uint8_t header[3];
    struct pollfd pfd;
    pfd.fd = PortFD;
    pfd.events = POLLIN;

    if (poll(&pfd, 1, READ_TIMEOUT_MS) <= 0)
    {
        LOG_DEBUG("Extended command: no response (timeout)");
        return false;
    }

    ssize_t bytesRead = read(PortFD, header, 3);
    if (bytesRead < 3 || header[0] != CMD_HEADER || header[2] != CMD_EXTENDED)
    {
        LOG_DEBUG("Extended command: invalid response header");
        return false;
    }

    size_t respLen = header[1];
    if (respLen < 5 || respLen > 512)
    {
        LOGF_DEBUG("Extended command: invalid response length %zu", respLen);
        return false;
    }

    // Read remaining bytes
    std::vector<uint8_t> respBuf(respLen);
    memcpy(&respBuf[0], header, 3);

    size_t remaining = respLen - 3;
    size_t totalRead = 3;
    while (remaining > 0)
    {
        if (poll(&pfd, 1, READ_TIMEOUT_MS) <= 0)
            break;
        bytesRead = read(PortFD, &respBuf[totalRead], remaining);
        if (bytesRead <= 0)
            break;
        totalRead += bytesRead;
        remaining -= bytesRead;
    }

    if (totalRead != respLen)
    {
        LOGF_DEBUG("Extended command: incomplete response (%zu/%zu)", totalRead, respLen);
        return false;
    }

    // Extract JSON (from byte 3 to len-1)
    response = std::string(reinterpret_cast<char*>(&respBuf[3]), respLen - 4);

    LOGF_DEBUG("EXT RX: %s", response.c_str());
    return true;
}

bool SV241::detectExtendedFirmware()
{
    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"version\"}", response))
    {
        hasExtendedFirmware = false;
        return false;
    }

    // Parse version response
    std::string fw = getJsonString(response, "fw");
    if (fw.empty())
    {
        hasExtendedFirmware = false;
        return false;
    }

    firmwareVersion = fw;
    firmwareCapabilities = getJsonStringArray(response, "caps");

    // Update firmware info property
    FirmwareTP[0].setText(firmwareVersion.c_str());

    std::string capsStr;
    for (size_t i = 0; i < firmwareCapabilities.size(); i++)
    {
        if (i > 0) capsStr += ", ";
        capsStr += firmwareCapabilities[i];
    }
    FirmwareTP[1].setText(capsStr.c_str());
    FirmwareTP.setState(IPS_OK);

    hasExtendedFirmware = true;
    LOGF_INFO("Extended firmware: %s, capabilities: %s", firmwareVersion.c_str(), capsStr.c_str());

    return true;
}

bool SV241::extGetStatus()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"status\"}", response))
        return false;

    // Parse status values - these are more accurate than binary protocol
    dewPoint = getJsonDouble(response, "dew");

    DewPointNP[0].setValue(dewPoint);
    DewPointNP.setState(IPS_OK);
    DewPointNP.apply();

    // Update uptime
    int uptime = getJsonInt(response, "uptime");
    UptimeNP[0].setValue(uptime);
    UptimeNP.setState(IPS_OK);
    UptimeNP.apply();

    return true;
}

bool SV241::extGetDewStatus()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"dew_status\"}", response))
        return false;

    // Parse dew status
    dewPoint = getJsonDouble(response, "dew_point");
    DewPointNP[0].setValue(dewPoint);
    DewPointNP.setState(IPS_OK);
    DewPointNP.apply();

    // Parse channel 14 status - find ch14 object
    size_t ch14Pos = response.find("\"ch14\":");
    if (ch14Pos != std::string::npos)
    {
        std::string ch14Sub = response.substr(ch14Pos);
        autoDew14 = getJsonBool(ch14Sub, "auto");
        dewMargin14 = getJsonDouble(ch14Sub, "margin", 5.0);

        AutoDew14SP[0].setState(autoDew14 ? ISS_ON : ISS_OFF);
        AutoDew14SP[1].setState(autoDew14 ? ISS_OFF : ISS_ON);
        AutoDew14SP.setState(IPS_OK);
        AutoDew14SP.apply();

        DewMargin14NP[0].setValue(dewMargin14);
        DewMargin14NP.setState(IPS_OK);
        DewMargin14NP.apply();
    }

    // Parse channel 15 status
    size_t ch15Pos = response.find("\"ch15\":");
    if (ch15Pos != std::string::npos)
    {
        std::string ch15Sub = response.substr(ch15Pos);
        autoDew15 = getJsonBool(ch15Sub, "auto");
        dewMargin15 = getJsonDouble(ch15Sub, "margin", 5.0);

        AutoDew15SP[0].setState(autoDew15 ? ISS_ON : ISS_OFF);
        AutoDew15SP[1].setState(autoDew15 ? ISS_OFF : ISS_ON);
        AutoDew15SP.setState(IPS_OK);
        AutoDew15SP.apply();

        DewMargin15NP[0].setValue(dewMargin15);
        DewMargin15NP.setState(IPS_OK);
        DewMargin15NP.apply();
    }

    return true;
}

bool SV241::extSetDewConfig(int channel, bool autoMode, double margin)
{
    if (!hasExtendedFirmware)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"dew_config\",\"ch\":" << channel
        << ",\"auto\":" << (autoMode ? "true" : "false")
        << ",\"margin\":" << margin << "}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        LOGF_INFO("Dew config updated: channel %d, auto=%s, margin=%.1f",
                  channel, autoMode ? "on" : "off", margin);
    }

    return ok;
}

bool SV241::extGetStats()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"stats\"}", response))
        return false;

    // Parse statistics
    StatsVoltageNP[0].setValue(getJsonDouble(response, "v_min"));
    StatsVoltageNP[1].setValue(getJsonDouble(response, "v_max"));
    StatsVoltageNP[2].setValue(getJsonDouble(response, "v_avg"));
    StatsVoltageNP.setState(IPS_OK);
    StatsVoltageNP.apply();

    StatsPowerNP[0].setValue(getJsonDouble(response, "p_max"));
    StatsPowerNP[1].setValue(getJsonDouble(response, "p_total"));
    StatsPowerNP.setState(IPS_OK);
    StatsPowerNP.apply();

    StatsTempNP[0].setValue(getJsonDouble(response, "t_min"));
    StatsTempNP[1].setValue(getJsonDouble(response, "t_max"));
    StatsTempNP.setState(IPS_OK);
    StatsTempNP.apply();

    UptimeNP[0].setValue(getJsonDouble(response, "uptime"));
    UptimeNP.setState(IPS_OK);
    UptimeNP.apply();

    return true;
}

bool SV241::extGetAlerts()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"alerts\"}", response))
        return false;

    // Parse alert flags
    bool lowV = getJsonBool(response, "low_v");
    bool critV = getJsonBool(response, "crit_v");
    bool thermal = getJsonBool(response, "thermal");
    bool i2cFail = getJsonBool(response, "i2c_fail");

    AlertsLP[0].setState(lowV ? IPS_ALERT : IPS_OK);
    AlertsLP[1].setState(critV ? IPS_ALERT : IPS_OK);
    AlertsLP[2].setState(thermal ? IPS_ALERT : IPS_OK);
    AlertsLP[3].setState(i2cFail ? IPS_ALERT : IPS_OK);

    // Overall status
    if (critV || thermal || i2cFail)
        AlertsLP.setState(IPS_ALERT);
    else if (lowV)
        AlertsLP.setState(IPS_BUSY);
    else
        AlertsLP.setState(IPS_OK);

    AlertsLP.apply();

    return true;
}

bool SV241::extGetDiagnostics()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"diag\"}", response))
        return false;

    // Parse diagnostics
    DiagnosticsNP[0].setValue(getJsonDouble(response, "free_heap"));
    DiagnosticsNP.setState(IPS_OK);
    DiagnosticsNP.apply();

    // Sensor status
    bool i2cOk = getJsonBool(response, "i2c_ok");
    bool ina219Ok = getJsonBool(response, "ina219_ok");
    bool sht4xOk = getJsonBool(response, "sht4x_ok");

    SensorStatusLP[0].setState(i2cOk ? IPS_OK : IPS_ALERT);
    SensorStatusLP[1].setState(ina219Ok ? IPS_OK : IPS_ALERT);
    SensorStatusLP[2].setState(sht4xOk ? IPS_OK : IPS_ALERT);

    if (i2cOk && ina219Ok && sht4xOk)
        SensorStatusLP.setState(IPS_OK);
    else
        SensorStatusLP.setState(IPS_ALERT);

    SensorStatusLP.apply();

    return true;
}

bool SV241::parseJsonResponse(const std::string &json, std::string &error)
{
    error = getJsonString(json, "err");
    return error.empty();
}

bool SV241::extGetCalibration()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"cal_get\"}", response))
        return false;

    // Parse calibration offsets
    calVOffset = getJsonDouble(response, "v_offset");
    calTOffset = getJsonDouble(response, "t_offset");
    calHOffset = getJsonDouble(response, "h_offset");

    CalibrationNP[0].setValue(calVOffset);
    CalibrationNP[1].setValue(calTOffset);
    CalibrationNP[2].setValue(calHOffset);
    CalibrationNP.setState(IPS_OK);
    CalibrationNP.apply();

    LOGF_INFO("Calibration loaded: V=%.2f, T=%.1f, H=%.1f", calVOffset, calTOffset, calHOffset);
    return true;
}

bool SV241::extSetCalibration(double vOffset, double tOffset, double hOffset)
{
    if (!hasExtendedFirmware)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"cal_set\",\"v_offset\":" << vOffset
        << ",\"t_offset\":" << tOffset
        << ",\"h_offset\":" << hOffset << "}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        calVOffset = vOffset;
        calTOffset = tOffset;
        calHOffset = hOffset;
        LOGF_INFO("Calibration saved: V=%.2f, T=%.1f, H=%.1f", vOffset, tOffset, hOffset);
    }

    return ok;
}

bool SV241::extGetAlertConfig()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"alert_config\"}", response))
        return false;

    // Parse low_v config
    size_t lowVPos = response.find("\"low_v\":");
    if (lowVPos != std::string::npos)
    {
        std::string lowVSub = response.substr(lowVPos);
        alertLowVEnabled = getJsonBool(lowVSub, "en", true);
        alertLowVThreshold = getJsonDouble(lowVSub, "thresh", 11.5);
    }

    // Parse crit_v config
    size_t critVPos = response.find("\"crit_v\":");
    if (critVPos != std::string::npos)
    {
        std::string critVSub = response.substr(critVPos);
        alertCritVEnabled = getJsonBool(critVSub, "en", true);
        alertCritVThreshold = getJsonDouble(critVSub, "thresh", 11.0);
        alertAutoOff = getJsonBool(critVSub, "auto_off", true);
    }

    // Update UI
    AlertConfigNP[0].setValue(alertLowVThreshold);
    AlertConfigNP[1].setValue(alertCritVThreshold);
    AlertConfigNP.setState(IPS_OK);
    AlertConfigNP.apply();

    AlertLowVSP[0].setState(alertLowVEnabled ? ISS_ON : ISS_OFF);
    AlertLowVSP[1].setState(alertLowVEnabled ? ISS_OFF : ISS_ON);
    AlertLowVSP.setState(IPS_OK);
    AlertLowVSP.apply();

    AlertCritVSP[0].setState(alertCritVEnabled ? ISS_ON : ISS_OFF);
    AlertCritVSP[1].setState(alertCritVEnabled ? ISS_OFF : ISS_ON);
    AlertCritVSP.setState(IPS_OK);
    AlertCritVSP.apply();

    AlertAutoOffSP[0].setState(alertAutoOff ? ISS_ON : ISS_OFF);
    AlertAutoOffSP[1].setState(alertAutoOff ? ISS_OFF : ISS_ON);
    AlertAutoOffSP.setState(IPS_OK);
    AlertAutoOffSP.apply();

    return true;
}

bool SV241::extSetAlertConfig()
{
    if (!hasExtendedFirmware)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"alert_config\","
        << "\"low_v\":{\"en\":" << (alertLowVEnabled ? "true" : "false")
        << ",\"thresh\":" << alertLowVThreshold << "},"
        << "\"crit_v\":{\"en\":" << (alertCritVEnabled ? "true" : "false")
        << ",\"thresh\":" << alertCritVThreshold
        << ",\"auto_off\":" << (alertAutoOff ? "true" : "false") << "}}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        LOG_INFO("Alert configuration saved");
    }

    return ok;
}

bool SV241::extI2CRecovery()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"i2c_recovery\"}", response))
        return false;

    bool ok = getJsonBool(response, "ok");
    bool sdaReleased = getJsonBool(response, "sda_released");

    if (ok)
    {
        LOGF_INFO("I2C recovery %s, SDA line %s",
                  ok ? "successful" : "failed",
                  sdaReleased ? "released" : "stuck");
    }
    else
    {
        LOG_WARN("I2C recovery failed");
    }

    return ok;
}

bool SV241::extStatsReset()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"stats_reset\"}", response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        LOG_INFO("Session statistics reset");
        extGetStats();  // Refresh stats display
    }

    return ok;
}

bool SV241::extGetNames()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"names_get\"}", response))
        return false;

    // Parse DC names array
    std::vector<std::string> dcNames = getJsonStringArray(response, "dc");
    for (size_t i = 0; i < dcNames.size() && i < 7; i++)
    {
        portNames[i] = dcNames[i];
        PortNamesTP[i].setText(dcNames[i].c_str());
    }

    // Parse PWM names array
    std::vector<std::string> pwmNames = getJsonStringArray(response, "pwm");
    for (size_t i = 0; i < pwmNames.size() && i < 3; i++)
    {
        portNames[7 + i] = pwmNames[i];
        PortNamesTP[7 + i].setText(pwmNames[i].c_str());
    }

    PortNamesTP.setState(IPS_OK);
    PortNamesTP.apply();

    LOG_INFO("Port names loaded from device");
    return true;
}

bool SV241::extSetName(int idx, const std::string &name)
{
    if (!hasExtendedFirmware)
        return false;

    if (idx < 0 || idx > 9)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"names_set\",\"idx\":" << idx << ",\"name\":\"" << name << "\"}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        portNames[idx] = name;
        LOGF_INFO("Port %d name set to '%s'", idx, name.c_str());
    }

    return ok;
}

// ============================================================================
// Phase 3: Profiles Implementation
// ============================================================================

bool SV241::extGetProfiles()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"profile_list\"}", response))
        return false;

    // Parse profiles array
    std::vector<std::string> profiles = getJsonStringArray(response, "profiles");
    for (size_t i = 0; i < profiles.size() && i < 4; i++)
    {
        profileNames[i] = profiles[i];
        ProfilesTP[i].setText(profiles[i].empty() ? "(empty)" : profiles[i].c_str());
    }

    // Fill remaining slots
    for (size_t i = profiles.size(); i < 4; i++)
    {
        profileNames[i] = "";
        ProfilesTP[i].setText("(empty)");
    }

    activeProfile = getJsonInt(response, "active", -1);
    ActiveProfileNP[0].setValue(activeProfile);
    ActiveProfileNP.setState(IPS_OK);
    ActiveProfileNP.apply();

    ProfilesTP.setState(IPS_OK);
    ProfilesTP.apply();

    LOG_INFO("Profile list updated");
    return true;
}

bool SV241::extSaveProfile(int slot, const std::string &name)
{
    if (!hasExtendedFirmware)
        return false;

    if (slot < 0 || slot > 3)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"profile_save\",\"slot\":" << slot << ",\"name\":\"" << name << "\"}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        profileNames[slot] = name;
        LOGF_INFO("Profile saved to slot %d: '%s'", slot, name.c_str());
        extGetProfiles();  // Refresh profile list
    }

    return ok;
}

bool SV241::extLoadProfile(int slot)
{
    if (!hasExtendedFirmware)
        return false;

    if (slot < 0 || slot > 3)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"profile_load\",\"slot\":" << slot << "}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        activeProfile = slot;
        LOGF_INFO("Profile %d loaded: '%s'", slot, profileNames[slot].c_str());

        // Refresh device state after loading profile
        syncAllStates();
        extGetDewStatus();
    }

    return ok;
}

bool SV241::extDeleteProfile(int slot)
{
    if (!hasExtendedFirmware)
        return false;

    if (slot < 0 || slot > 3)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"profile_delete\",\"slot\":" << slot << "}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        LOGF_INFO("Profile %d deleted", slot);
        extGetProfiles();  // Refresh profile list
    }

    return ok;
}

// ============================================================================
// Phase 3: Timers Implementation
// ============================================================================

bool SV241::extGetTimers()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"timer_list\"}", response))
        return false;

    // Clear existing timers
    activeTimers.clear();

    // Parse timers array - simple parsing for this structure
    // Response format: {"timers":[{"id":1,"port":"dc3","action":"off","remaining":165},...]
    size_t pos = response.find("\"timers\":[");
    if (pos != std::string::npos)
    {
        pos += 10;  // Skip "timers":[
        while (pos < response.length())
        {
            size_t objStart = response.find("{", pos);
            if (objStart == std::string::npos) break;

            size_t objEnd = response.find("}", objStart);
            if (objEnd == std::string::npos) break;

            std::string timerObj = response.substr(objStart, objEnd - objStart + 1);

            TimerInfo timer;
            timer.id = getJsonInt(timerObj, "id");
            timer.port = getJsonString(timerObj, "port");
            timer.action = getJsonString(timerObj, "action");
            timer.remaining = getJsonInt(timerObj, "remaining");

            if (timer.id > 0)
            {
                activeTimers.push_back(timer);
            }

            pos = objEnd + 1;
        }
    }

    // Update timer status display (up to 4 timers shown)
    for (int i = 0; i < 4; i++)
    {
        if (i < static_cast<int>(activeTimers.size()))
        {
            std::ostringstream status;
            status << "#" << activeTimers[i].id << " " << activeTimers[i].port
                   << " " << activeTimers[i].action
                   << " in " << activeTimers[i].remaining << "s";
            TimerStatusTP[i].setText(status.str().c_str());
        }
        else
        {
            TimerStatusTP[i].setText("");
        }
    }
    TimerStatusTP.setState(activeTimers.empty() ? IPS_IDLE : IPS_OK);
    TimerStatusTP.apply();

    // Update cancel buttons - enable only for active timers
    for (int i = 0; i < 4; i++)
    {
        TimerCancelSP[i].setState(ISS_OFF);
    }
    TimerCancelSP.setState(activeTimers.empty() ? IPS_IDLE : IPS_OK);
    TimerCancelSP.apply();

    return true;
}

bool SV241::extSetTimer(const std::string &port, const std::string &action, int minutes, int value)
{
    if (!hasExtendedFirmware)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"timer_set\",\"port\":\"" << port
        << "\",\"action\":\"" << action
        << "\",\"minutes\":" << minutes;

    if (action == "set")
    {
        cmd << ",\"value\":" << value;
    }
    cmd << "}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        int id = getJsonInt(response, "id");
        LOGF_INFO("Timer #%d created: %s %s in %d minutes", id, port.c_str(), action.c_str(), minutes);
        extGetTimers();  // Refresh timer list
    }

    return ok;
}

bool SV241::extCancelTimer(int id)
{
    if (!hasExtendedFirmware)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"timer_cancel\",\"id\":" << id << "}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        LOGF_INFO("Timer #%d cancelled", id);
        extGetTimers();  // Refresh timer list
    }

    return ok;
}

// ============================================================================
// Phase 3: Temperature Rate Implementation
// ============================================================================

bool SV241::extGetTempRate()
{
    if (!hasExtendedFirmware)
        return false;

    std::string response;
    if (!sendExtendedCommand("{\"cmd\":\"temp_rate\"}", response))
        return false;

    tempRate = getJsonDouble(response, "rate");

    TempRateNP[0].setValue(tempRate);
    TempRateNP.setState(IPS_OK);
    TempRateNP.apply();

    LOGF_DEBUG("Temperature rate: %.2f C/hour", tempRate);
    return true;
}

// ============================================================================
// Phase 3: PID Tuning Implementation
// ============================================================================

bool SV241::extGetDewPid(int channel)
{
    if (!hasExtendedFirmware)
        return false;

    if (channel != 14 && channel != 15)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"dew_pid\",\"ch\":" << channel << "}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    double kp = getJsonDouble(response, "kp", 2.0);
    double ki = getJsonDouble(response, "ki", 0.5);
    double kd = getJsonDouble(response, "kd", 0.1);

    if (channel == 14)
    {
        pid14Kp = kp;
        pid14Ki = ki;
        pid14Kd = kd;
        PID14NP[0].setValue(kp);
        PID14NP[1].setValue(ki);
        PID14NP[2].setValue(kd);
        PID14NP.setState(IPS_OK);
        PID14NP.apply();
    }
    else
    {
        pid15Kp = kp;
        pid15Ki = ki;
        pid15Kd = kd;
        PID15NP[0].setValue(kp);
        PID15NP[1].setValue(ki);
        PID15NP[2].setValue(kd);
        PID15NP.setState(IPS_OK);
        PID15NP.apply();
    }

    LOGF_DEBUG("PID CH%d: Kp=%.2f Ki=%.2f Kd=%.2f", channel, kp, ki, kd);
    return true;
}

bool SV241::extSetDewPid(int channel, double kp, double ki, double kd)
{
    if (!hasExtendedFirmware)
        return false;

    if (channel != 14 && channel != 15)
        return false;

    std::ostringstream cmd;
    cmd << "{\"cmd\":\"dew_pid\",\"ch\":" << channel
        << ",\"kp\":" << kp
        << ",\"ki\":" << ki
        << ",\"kd\":" << kd << "}";

    std::string response;
    if (!sendExtendedCommand(cmd.str(), response))
        return false;

    bool ok = getJsonBool(response, "ok");
    if (ok)
    {
        if (channel == 14)
        {
            pid14Kp = kp;
            pid14Ki = ki;
            pid14Kd = kd;
        }
        else
        {
            pid15Kp = kp;
            pid15Ki = ki;
            pid15Kd = kd;
        }
        LOGF_INFO("PID CH%d updated: Kp=%.2f Ki=%.2f Kd=%.2f", channel, kp, ki, kd);
    }

    return ok;
}

void SV241::TimerHit()
{
    if (!isConnected())
        return;

    // Read sensors periodically
    readAllSensors();

    // If extended firmware, also update extended status
    if (hasExtendedFirmware)
    {
        extGetStatus();
        extGetDewStatus();
        extGetAlerts();

        // Phase 3: Update timer status and temperature rate
        extGetTimers();
        extGetTempRate();
    }

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

        // Extended firmware: Dew margin controls
        if (hasExtendedFirmware)
        {
            if (DewMargin14NP.isNameMatch(name))
            {
                double margin = values[0];
                if (extSetDewConfig(14, autoDew14, margin))
                {
                    dewMargin14 = margin;
                    DewMargin14NP[0].setValue(margin);
                    DewMargin14NP.setState(IPS_OK);
                }
                else
                {
                    DewMargin14NP.setState(IPS_ALERT);
                }
                DewMargin14NP.apply();
                return true;
            }

            if (DewMargin15NP.isNameMatch(name))
            {
                double margin = values[0];
                if (extSetDewConfig(15, autoDew15, margin))
                {
                    dewMargin15 = margin;
                    DewMargin15NP[0].setValue(margin);
                    DewMargin15NP.setState(IPS_OK);
                }
                else
                {
                    DewMargin15NP.setState(IPS_ALERT);
                }
                DewMargin15NP.apply();
                return true;
            }

            // Calibration offsets
            if (CalibrationNP.isNameMatch(name))
            {
                double vOffset = values[0];
                double tOffset = values[1];
                double hOffset = values[2];
                if (extSetCalibration(vOffset, tOffset, hOffset))
                {
                    CalibrationNP[0].setValue(vOffset);
                    CalibrationNP[1].setValue(tOffset);
                    CalibrationNP[2].setValue(hOffset);
                    CalibrationNP.setState(IPS_OK);
                }
                else
                {
                    CalibrationNP.setState(IPS_ALERT);
                }
                CalibrationNP.apply();
                return true;
            }

            // Alert thresholds
            if (AlertConfigNP.isNameMatch(name))
            {
                alertLowVThreshold = values[0];
                alertCritVThreshold = values[1];
                if (extSetAlertConfig())
                {
                    AlertConfigNP[0].setValue(alertLowVThreshold);
                    AlertConfigNP[1].setValue(alertCritVThreshold);
                    AlertConfigNP.setState(IPS_OK);
                }
                else
                {
                    AlertConfigNP.setState(IPS_ALERT);
                }
                AlertConfigNP.apply();
                return true;
            }

            // Phase 3: Timer minutes setting
            if (TimerMinutesNP.isNameMatch(name))
            {
                TimerMinutesNP[0].setValue(values[0]);
                TimerMinutesNP.setState(IPS_OK);
                TimerMinutesNP.apply();
                return true;
            }

            // Phase 3: Timer PWM value setting
            if (TimerValueNP.isNameMatch(name))
            {
                TimerValueNP[0].setValue(values[0]);
                TimerValueNP.setState(IPS_OK);
                TimerValueNP.apply();
                return true;
            }

            // Phase 3: PID tuning CH14
            if (PID14NP.isNameMatch(name))
            {
                double kp = values[0];
                double ki = values[1];
                double kd = values[2];
                if (extSetDewPid(14, kp, ki, kd))
                {
                    PID14NP[0].setValue(kp);
                    PID14NP[1].setValue(ki);
                    PID14NP[2].setValue(kd);
                    PID14NP.setState(IPS_OK);
                }
                else
                {
                    PID14NP.setState(IPS_ALERT);
                }
                PID14NP.apply();
                return true;
            }

            // Phase 3: PID tuning CH15
            if (PID15NP.isNameMatch(name))
            {
                double kp = values[0];
                double ki = values[1];
                double kd = values[2];
                if (extSetDewPid(15, kp, ki, kd))
                {
                    PID15NP[0].setValue(kp);
                    PID15NP[1].setValue(ki);
                    PID15NP[2].setValue(kd);
                    PID15NP.setState(IPS_OK);
                }
                else
                {
                    PID15NP.setState(IPS_ALERT);
                }
                PID15NP.apply();
                return true;
            }
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

        // Extended firmware: Auto dew switches
        if (hasExtendedFirmware)
        {
            if (AutoDew14SP.isNameMatch(name))
            {
                AutoDew14SP.update(states, names, n);
                bool enabled = (AutoDew14SP[0].getState() == ISS_ON);
                if (extSetDewConfig(14, enabled, dewMargin14))
                {
                    autoDew14 = enabled;
                    AutoDew14SP.setState(IPS_OK);
                }
                else
                {
                    AutoDew14SP.setState(IPS_ALERT);
                }
                AutoDew14SP.apply();
                return true;
            }

            if (AutoDew15SP.isNameMatch(name))
            {
                AutoDew15SP.update(states, names, n);
                bool enabled = (AutoDew15SP[0].getState() == ISS_ON);
                if (extSetDewConfig(15, enabled, dewMargin15))
                {
                    autoDew15 = enabled;
                    AutoDew15SP.setState(IPS_OK);
                }
                else
                {
                    AutoDew15SP.setState(IPS_ALERT);
                }
                AutoDew15SP.apply();
                return true;
            }

            // Alert enable switches
            if (AlertLowVSP.isNameMatch(name))
            {
                AlertLowVSP.update(states, names, n);
                alertLowVEnabled = (AlertLowVSP[0].getState() == ISS_ON);
                if (extSetAlertConfig())
                {
                    AlertLowVSP.setState(IPS_OK);
                }
                else
                {
                    AlertLowVSP.setState(IPS_ALERT);
                }
                AlertLowVSP.apply();
                return true;
            }

            if (AlertCritVSP.isNameMatch(name))
            {
                AlertCritVSP.update(states, names, n);
                alertCritVEnabled = (AlertCritVSP[0].getState() == ISS_ON);
                if (extSetAlertConfig())
                {
                    AlertCritVSP.setState(IPS_OK);
                }
                else
                {
                    AlertCritVSP.setState(IPS_ALERT);
                }
                AlertCritVSP.apply();
                return true;
            }

            if (AlertAutoOffSP.isNameMatch(name))
            {
                AlertAutoOffSP.update(states, names, n);
                alertAutoOff = (AlertAutoOffSP[0].getState() == ISS_ON);
                if (extSetAlertConfig())
                {
                    AlertAutoOffSP.setState(IPS_OK);
                }
                else
                {
                    AlertAutoOffSP.setState(IPS_ALERT);
                }
                AlertAutoOffSP.apply();
                return true;
            }

            // I2C Recovery button
            if (I2CRecoverySP.isNameMatch(name))
            {
                I2CRecoverySP.setState(IPS_BUSY);
                I2CRecoverySP.apply();

                if (extI2CRecovery())
                {
                    I2CRecoverySP.setState(IPS_OK);
                    extGetDiagnostics();  // Refresh sensor status
                }
                else
                {
                    I2CRecoverySP.setState(IPS_ALERT);
                }
                I2CRecoverySP[0].setState(ISS_OFF);  // Reset button state
                I2CRecoverySP.apply();
                return true;
            }

            // Stats reset button
            if (StatsResetSP.isNameMatch(name))
            {
                StatsResetSP.setState(IPS_BUSY);
                StatsResetSP.apply();

                if (extStatsReset())
                {
                    StatsResetSP.setState(IPS_OK);
                }
                else
                {
                    StatsResetSP.setState(IPS_ALERT);
                }
                StatsResetSP[0].setState(ISS_OFF);  // Reset button state
                StatsResetSP.apply();
                return true;
            }

            // Phase 3: Profile load buttons
            if (ProfileLoadSP.isNameMatch(name))
            {
                ProfileLoadSP.update(states, names, n);
                int slot = -1;
                for (int i = 0; i < 4; i++)
                {
                    if (ProfileLoadSP[i].getState() == ISS_ON)
                    {
                        slot = i;
                        break;
                    }
                }

                if (slot >= 0 && extLoadProfile(slot))
                {
                    ProfileLoadSP.setState(IPS_OK);
                }
                else
                {
                    ProfileLoadSP.setState(IPS_ALERT);
                }

                // Reset all button states
                for (int i = 0; i < 4; i++)
                    ProfileLoadSP[i].setState(ISS_OFF);
                ProfileLoadSP.apply();
                return true;
            }

            // Phase 3: Profile save buttons
            if (ProfileSaveSP.isNameMatch(name))
            {
                ProfileSaveSP.update(states, names, n);
                int slot = -1;
                for (int i = 0; i < 4; i++)
                {
                    if (ProfileSaveSP[i].getState() == ISS_ON)
                    {
                        slot = i;
                        break;
                    }
                }

                if (slot >= 0)
                {
                    std::string profileName = ProfileNameTP[0].getText();
                    if (extSaveProfile(slot, profileName))
                    {
                        ProfileSaveSP.setState(IPS_OK);
                    }
                    else
                    {
                        ProfileSaveSP.setState(IPS_ALERT);
                    }
                }

                // Reset all button states
                for (int i = 0; i < 4; i++)
                    ProfileSaveSP[i].setState(ISS_OFF);
                ProfileSaveSP.apply();
                return true;
            }

            // Phase 3: Profile delete buttons
            if (ProfileDeleteSP.isNameMatch(name))
            {
                ProfileDeleteSP.update(states, names, n);
                int slot = -1;
                for (int i = 0; i < 4; i++)
                {
                    if (ProfileDeleteSP[i].getState() == ISS_ON)
                    {
                        slot = i;
                        break;
                    }
                }

                if (slot >= 0 && extDeleteProfile(slot))
                {
                    ProfileDeleteSP.setState(IPS_OK);
                }
                else
                {
                    ProfileDeleteSP.setState(IPS_ALERT);
                }

                // Reset all button states
                for (int i = 0; i < 4; i++)
                    ProfileDeleteSP[i].setState(ISS_OFF);
                ProfileDeleteSP.apply();
                return true;
            }

            // Phase 3: Timer action selection
            if (TimerActionSP.isNameMatch(name))
            {
                TimerActionSP.update(states, names, n);
                TimerActionSP.setState(IPS_OK);
                TimerActionSP.apply();
                return true;
            }

            // Phase 3: Timer create button
            if (TimerSetSP.isNameMatch(name))
            {
                TimerSetSP.setState(IPS_BUSY);
                TimerSetSP.apply();

                // Get action type
                std::string action = "on";
                if (TimerActionSP[1].getState() == ISS_ON)
                    action = "off";
                else if (TimerActionSP[2].getState() == ISS_ON)
                    action = "set";

                std::string port = TimerPortTP[0].getText();
                int minutes = static_cast<int>(TimerMinutesNP[0].getValue());
                int value = static_cast<int>(TimerValueNP[0].getValue());

                if (extSetTimer(port, action, minutes, value))
                {
                    TimerSetSP.setState(IPS_OK);
                }
                else
                {
                    TimerSetSP.setState(IPS_ALERT);
                }

                TimerSetSP[0].setState(ISS_OFF);
                TimerSetSP.apply();
                return true;
            }

            // Phase 3: Timer cancel buttons
            if (TimerCancelSP.isNameMatch(name))
            {
                TimerCancelSP.update(states, names, n);
                int timerIdx = -1;
                for (int i = 0; i < 4; i++)
                {
                    if (TimerCancelSP[i].getState() == ISS_ON)
                    {
                        timerIdx = i;
                        break;
                    }
                }

                if (timerIdx >= 0 && timerIdx < static_cast<int>(activeTimers.size()))
                {
                    int timerId = activeTimers[timerIdx].id;
                    if (extCancelTimer(timerId))
                    {
                        TimerCancelSP.setState(IPS_OK);
                    }
                    else
                    {
                        TimerCancelSP.setState(IPS_ALERT);
                    }
                }

                // Reset all button states
                for (int i = 0; i < 4; i++)
                    TimerCancelSP[i].setState(ISS_OFF);
                TimerCancelSP.apply();
                return true;
            }
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

        // Extended firmware: Port names
        if (hasExtendedFirmware && PortNamesTP.isNameMatch(name))
        {
            // Find which name(s) changed and update
            bool allOk = true;
            for (int i = 0; i < n; i++)
            {
                // Find which index this name corresponds to
                for (int idx = 0; idx < 10; idx++)
                {
                    if (strcmp(names[i], PortNamesTP[idx].getName()) == 0)
                    {
                        if (!extSetName(idx, texts[i]))
                        {
                            allOk = false;
                        }
                        else
                        {
                            PortNamesTP[idx].setText(texts[i]);
                        }
                        break;
                    }
                }
            }

            PortNamesTP.setState(allOk ? IPS_OK : IPS_ALERT);
            PortNamesTP.apply();
            return true;
        }

        // Phase 3: Profile name input
        if (hasExtendedFirmware && ProfileNameTP.isNameMatch(name))
        {
            ProfileNameTP.update(texts, names, n);
            ProfileNameTP.setState(IPS_OK);
            ProfileNameTP.apply();
            return true;
        }

        // Phase 3: Timer port input
        if (hasExtendedFirmware && TimerPortTP.isNameMatch(name))
        {
            TimerPortTP.update(texts, names, n);
            TimerPortTP.setState(IPS_OK);
            TimerPortTP.apply();
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
