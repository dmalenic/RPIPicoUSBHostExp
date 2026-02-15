# Module: Pico2USBHostSerial
set(NAME PicoHost)
set(PICO_BOARD pico2_w)
set(PICO_PLATFORM rp2350)

add_subdirectory(src)

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.uf2
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)
