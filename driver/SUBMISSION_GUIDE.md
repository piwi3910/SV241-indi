# SVBONY SV241 Driver Submission Guide

This guide explains how to submit the SV241 driver to the official INDI repository.

## Files to Submit

The following files need to be added to `https://github.com/indilib/indi`:

### 1. Driver Source Files

Copy to `drivers/power/`:
- `svbony_sv241.cpp`
- `svbony_sv241.h`

### 2. CMakeLists.txt Addition

Add this block to `drivers/power/CMakeLists.txt`:

```cmake
# ########## SVBONY SV241 Power Box ###############
SET(indi_svbony_sv241_SRC
    svbony_sv241.cpp)

add_executable(indi_svbony_sv241 ${indi_svbony_sv241_SRC})
target_link_libraries(indi_svbony_sv241 indidriver)
install(TARGETS indi_svbony_sv241 RUNTIME DESTINATION bin)
```

### 3. XML Driver Descriptor

Add to `drivers/power.xml` (or create new file `drivers/svbony_sv241.xml`):

```xml
<device label="SVBONY SV241" manufacturer="SVBONY">
    <driver name="SVBONY SV241">indi_svbony_sv241</driver>
    <version>1.0</version>
</device>
```

This entry should be placed inside the `<devGroup group="Power">` section.

## Submission Steps

1. **Fork the INDI repository**
   ```bash
   # Go to https://github.com/indilib/indi and click "Fork"
   ```

2. **Clone your fork**
   ```bash
   git clone https://github.com/YOUR_USERNAME/indi.git
   cd indi
   git checkout -b add-svbony-sv241
   ```

3. **Add the driver files**
   ```bash
   cp /path/to/svbony_sv241.cpp drivers/power/
   cp /path/to/svbony_sv241.h drivers/power/
   ```

4. **Edit CMakeLists.txt**
   ```bash
   # Add the CMake block above to drivers/power/CMakeLists.txt
   ```

5. **Edit power.xml**
   ```bash
   # Add the XML device entry to drivers/power.xml
   ```

6. **Build and test**
   ```bash
   mkdir build && cd build
   cmake ..
   make indi_svbony_sv241
   ```

7. **Commit and push**
   ```bash
   git add drivers/power/svbony_sv241.*
   git add drivers/power/CMakeLists.txt
   git add drivers/power.xml
   git commit -m "Add SVBONY SV241 power box driver

   - 5x DC outputs (12V switchable)
   - 2x USB groups (switchable)
   - 3x PWM outputs (dew heaters + adjustable voltage)
   - Sensors: voltage, power, temperature, humidity"
   git push origin add-svbony-sv241
   ```

8. **Create Pull Request**
   - Go to your fork on GitHub
   - Click "Compare & pull request"
   - Fill in the PR description with device details and testing info

## Pull Request Template

```markdown
## Description
Add driver for SVBONY SV241 Power Box

## Features
- 5x DC 12V switchable outputs
- 2x USB group switches
- 3x PWM outputs (2 dew heaters + 1 adjustable voltage 0-15.3V)
- Input voltage monitoring
- Power consumption monitoring
- Ambient temperature sensor
- Lens temperature sensor
- Humidity sensor

## Testing
- Tested on macOS with real hardware
- All DC outputs toggle correctly
- PWM control working
- All sensors reading correctly
- State synchronization on connect working

## Protocol
Binary serial protocol at 115200 baud, 8N1.
Protocol was reverse-engineered from the Windows desktop application.

## Author
Pascal Watteel
```

## Contact

For questions about the submission process, check:
- INDI Forum: https://indilib.org/forum/
- INDI GitHub Issues: https://github.com/indilib/indi/issues
