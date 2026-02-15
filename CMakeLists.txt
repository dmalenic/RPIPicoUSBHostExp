cmake_minimum_required(VERSION 3.23)

# Pull in SDK (must be before project)
include("$ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake")

# Project name
project(RPIPicoUSBHostExp C CXX ASM)

# Set C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add subdirectories for each module
add_subdirectory(exp/PicoUSBHost)
add_subdirectory(exp/PicoUSBHostSerial)
add_subdirectory(exp/Pico2USBHostSerial)
add_subdirectory(exp/RP2040ZeroFlashClient)
add_subdirectory(exp/Tiny2040FlashClient)

