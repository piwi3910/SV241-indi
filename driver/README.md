# SVBONY SV241 INDI Driver

INDI driver for the SVBONY SV241 Powerbox, enabling control from Linux/macOS astronomy software like KStars/Ekos.

## Features

- **5x DC Outputs** (DC1-DC5) - 12V switchable power outputs
- **2x USB Groups** (USB 1-2, USB 3-4-5) - Switchable USB power
- **3x PWM Outputs**:
  - PWM13: Adjustable voltage output (0-15.3V)
  - PWM14: Dew heater 1 (0-100%)
  - PWM15: Dew heater 2 (0-100%)
- **Sensors**:
  - Input voltage monitoring
  - Power consumption monitoring
  - Ambient temperature
  - Lens temperature
  - Humidity

## Prerequisites

### macOS

```bash
# Install Xcode command line tools
xcode-select --install

# Install Homebrew (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install dependencies
brew install cmake
```

### Linux (Ubuntu/Debian)

```bash
sudo apt-get update
sudo apt-get install build-essential cmake git libindi-dev
```

## Building INDI Library (if not installed)

If INDI is not available via package manager, build from source:

```bash
# Clone INDI library
git clone https://github.com/indilib/indi.git
cd indi

# Build and install
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local ..
make -j$(nproc)
sudo make install
```

## Building the SV241 Driver

```bash
cd driver
mkdir build && cd build
cmake ..
make
```

## Installation

```bash
sudo make install
```

This installs:
- `indi_sv241` binary to `/usr/local/bin/`
- `indi_sv241.xml` to INDI's data directory

## Usage

### Starting the Driver Manually

```bash
# Start INDI server with SV241 driver
indiserver -v indi_sv241
```

### Using with KStars/Ekos

1. Open KStars
2. Go to **Tools > Devices > Device Manager**
3. Select **Auxiliary** category
4. Find **SVBONY SV241** and click **Run Service**
5. Connect to the device

### Configuration

1. In the **Connection** tab, set the correct serial port:
   - Linux: `/dev/ttyUSB0` (or similar)
   - macOS: `/dev/tty.usbserial-*`
2. Click **Connect**

## Properties

### Main Control Tab

| Property | Type | Description |
|----------|------|-------------|
| DC1-DC5 | Switch | Toggle 12V DC outputs |
| USB12 | Switch | Toggle USB ports 1-2 |
| USB345 | Switch | Toggle USB ports 3-4-5 |
| PWM13 | Number | Adjustable voltage (0-253 = 0-15.3V) |
| PWM14 | Number | Dew heater 1 duty cycle (0-253) |
| PWM15 | Number | Dew heater 2 duty cycle (0-253) |
| PWM13 Voltage | Number | Calculated output voltage (read-only) |

### Sensors Tab

| Property | Type | Description |
|----------|------|-------------|
| Voltage | Number | Input voltage (V) |
| Power | Number | Power consumption (W) |
| Ambient Temp | Number | Ambient temperature (°C) |
| Lens Temp | Number | Lens temperature (°C) |
| Humidity | Number | Relative humidity (%) |

## Troubleshooting

### Driver not found

Ensure the XML file is in the correct location:
```bash
# Check INDI data directory
pkg-config --variable=datadir libindi
```

### Permission denied on serial port

Add your user to the dialout group (Linux):
```bash
sudo usermod -a -G dialout $USER
# Log out and back in for changes to take effect
```

On macOS, no additional permissions are typically needed.

### Connection issues

1. Verify the device is connected: `ls /dev/tty*`
2. Test with the Python script first:
   ```bash
   python3 ../tools/test_sv241_protocol.py /dev/ttyUSB0
   ```

## Protocol Reference

See [SV241_PROTOCOL.md](../docs/SV241_PROTOCOL.md) for complete protocol documentation.

## License

LGPL-2.1 - See source files for details.

## Author

Pascal Watteel

## Acknowledgments

- Protocol reverse-engineered from the SVBONY Windows desktop application
- Based on INDI driver development guidelines
