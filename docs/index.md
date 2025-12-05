# SV241 INDI Driver Documentation

Custom INDI driver and extended firmware for the SVBONY SV241 Dew Heater Controller.

## Documentation

- [Extended Protocol Reference](EXTENDED_PROTOCOL.md) - Complete JSON protocol specification for extended firmware v2.3
- [INDI Driver Guide](INDI_DRIVER_GUIDE.md) - Installation and usage guide for the INDI driver
- [Original Protocol](ORIGINAL_PROTOCOL.md) - Stock firmware protocol reference

## Quick Links

- [GitHub Repository](https://github.com/piwi3910/SV241-indi)
- [Firmware README](https://github.com/piwi3910/SV241-indi/tree/master/firmware/SV241_Extended)
- [Releases](https://github.com/piwi3910/SV241-indi/releases)

## Current Version

**Firmware:** v2.3.0
**Features:**
- 4 independent heater channels with PWM control
- Temperature monitoring with dew point calculation
- Auto-dew mode with configurable aggressiveness
- 4 configuration profiles with save/load
- Countdown timers per channel
- PID tuning support
- Watchdog safety mode
- Current threshold alerts
- Boot profile auto-loading
- Persistent statistics (Wh tracking)

## License

MIT License - See repository for details.
