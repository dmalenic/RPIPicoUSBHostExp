# Module: PicoUSBHostSerial
set(NAME PicoUSBHostSerial)
set(FAMILY rp2040)
set(BOARD pico_sdk)

add_subdirectory(src)

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.uf2
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)
