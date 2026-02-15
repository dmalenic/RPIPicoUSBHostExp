# Module: Tiny2040FlashClient

set(NAME Tiny2040FlashClient)
set(PICO_BOARD pimoroni_tiny2040)

# Make sure version >= 2.2.0
if (${PICO_SDK_VERSION_MAJOR} EQUAL 2)
    if (${PICO_SDK_VERSION_MINOR} LESS 2)
        message(FATAL_ERROR "Pico SDK Version 2.2.0 required")
    endif()
elseif(${PICO_SDK_VERSION_MAJOR} LESS 2)
    message(FATAL_ERROR "Pico SDK Version 2.2.0 required")
endif()

add_subdirectory(src)

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.uf2
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)
