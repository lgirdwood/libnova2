# tools/kconfig.cmake
# Helper script to integrate Kconfig with CMake

# Find configuration tools
find_program(KCONFIG_MCONF NAMES kconfig-mconf mconf)
find_program(KCONFIG_CONF NAMES kconfig-conf conf)

set(KCONFIG_ROOT "${CMAKE_SOURCE_DIR}/Kconfig")

# Check for .config in build directory first, then source directory
if(EXISTS "${CMAKE_BINARY_DIR}/.config")
    set(DOT_CONFIG "${CMAKE_BINARY_DIR}/.config")
else()
    set(DOT_CONFIG "${CMAKE_SOURCE_DIR}/.config")
endif()

# Add menuconfig target
if(KCONFIG_MCONF)
    add_custom_target(menuconfig
        COMMAND ${KCONFIG_MCONF} ${KCONFIG_ROOT}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running Kconfig menuconfig..."
    )
else()
    add_custom_target(menuconfig
        COMMAND ${CMAKE_COMMAND} -E echo "Error: kconfig-mconf or mconf not found. Please install kconfig-frontends."
        COMMAND ${CMAKE_COMMAND} -E false
    )
endif()

# Function to read .config into CMake variables
function(read_kconfig_config)
    if(EXISTS "${DOT_CONFIG}")
        file(STRINGS "${DOT_CONFIG}" ConfigLines)
        foreach(Line IN LISTS ConfigLines)
            # Match CONFIG_VAR=y
            if(Line MATCHES "^CONFIG_([A-Za-z0-9_]+)=y$")
                set(${CMAKE_MATCH_1} ON PARENT_SCOPE)
            # Match # CONFIG_VAR is not set
            elseif(Line MATCHES "^# CONFIG_([A-Za-z0-9_]+) is not set$")
                set(${CMAKE_MATCH_1} OFF PARENT_SCOPE)
            endif()
        endforeach()
    endif()
endfunction()
