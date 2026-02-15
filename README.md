# RPIPicoUSBHostExp

Raspberry Pi Pico USB Host Experiments - A collection of USB Host examples for RP2040 and RP2350 boards.

## Project Structure

This project contains 4 modules/deliverables:

1. **PicoUSBHost** - Full USB Host implementation for RP2040 with HID, MSC, and CDC support
2. **PicoUSBHostSerial** - USB Host Serial implementation for RP2040
3. **Pico2USBHostSerial** - USB Host Serial implementation for RP2350 (Pico 2)
4. **RP2040ZeroFlashSlave** - Flash Slave implementation for Waveshare RP2040 Zero

## Building with CLion

### Prerequisites

1. Install the [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)
2. Set the `PICO_SDK_PATH` environment variable to point to your Pico SDK installation
3. Install CMake 3.12 or higher
4. Install ARM GCC toolchain

### Setup in CLion

1. Open the project root directory in CLion
2. CLion should automatically detect the CMakeLists.txt file
3. Configure CMake settings if needed (File → Settings → Build, Execution, Deployment → CMake)
4. Build the project (Build → Build Project) or build individual modules

### Building Individual Modules

The project is now structured as a single CMake project with 4 modules. Each module can be built independently:

```bash
# Build all modules
mkdir build
cd build
cmake ..
make

# Or build a specific module
make PicoUSBHost         # Builds PicoUSBHost
make PicoUSBHostSerial   # Builds PicoUSBHostSerial  
make Pico2USBHostSerial  # Builds Pico2USBHostSerial
make PicoFlash           # Builds RP2040ZeroFlashSlave
```

### Building from Command Line

```bash
# Create build directory
mkdir build && cd build
# Configure
cmake ..
# Build all modules
make -j4
# The output files (.uf2) will be in:
# - build/exp/PicoUSBHost/src/
# - build/exp/PicoUSBHostSerial/src/
# - build/exp/Pico2USBHostSerial/src/
# - build/exp/RP2040ZeroFlashSlave/src/
```

## Flashing to Device

1. Hold the BOOTSEL button while connecting your Pico to USB
2. Copy the appropriate .uf2 file to the RPI-RP2 drive
3. The device will reboot and run your program

## Module Details

### PicoUSBHost (RP2040)

- Board: Raspberry Pi Pico
- Features: HID, MSC, CDC support
- UART: TX on GPIO 16, RX on GPIO 17

### PicoUSBHostSerial (RP2040)  

- Board: Raspberry Pi Pico
- Features: CDC (Serial) support only
- UART: TX on GPIO 16, RX on GPIO 17

### Pico2USBHostSerial (RP2350)

- Board: Raspberry Pi Pico 2 W
- Platform: RP2350
- Features: CDC (Serial) support
- UART: TX on GPIO 16, RX on GPIO 17

### RP2040ZeroFlashSlave

- Board: Waveshare RP2040 Zero
- Features: Flash slave operations
- Requirements: Pico SDK version >= 2.2.0

## License

See individual module source files for license information.
