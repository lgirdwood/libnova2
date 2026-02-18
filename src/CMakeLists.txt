set(HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libnova)

set(LIBRARY_PUBLIC_HEADERS
	${HEADER_PATH}/julian_day.h
	${HEADER_PATH}/dynamical_time.h
	${HEADER_PATH}/sidereal_time.h
	${HEADER_PATH}/transform.h
	${HEADER_PATH}/nutation.h
	${HEADER_PATH}/libnova.h
	${HEADER_PATH}/aberration.h  
	${HEADER_PATH}/apparent_position.h
	${HEADER_PATH}/solar.h
	${HEADER_PATH}/precession.h 
	${HEADER_PATH}/proper_motion.h
	${HEADER_PATH}/mercury.h
	${HEADER_PATH}/venus.h 
	${HEADER_PATH}/earth.h 
	${HEADER_PATH}/mars.h  
	${HEADER_PATH}/jupiter.h
	${HEADER_PATH}/saturn.h 
	${HEADER_PATH}/uranus.h 
	${HEADER_PATH}/neptune.h 
	${HEADER_PATH}/pluto.h
	${HEADER_PATH}/vsop87.h
	${HEADER_PATH}/lunar.h 
	${HEADER_PATH}/elliptic_motion.h
	${HEADER_PATH}/asteroid.h
	${HEADER_PATH}/comet.h
	${HEADER_PATH}/parabolic_motion.h
	${HEADER_PATH}/refraction.h
	${HEADER_PATH}/rise_set.h
	${HEADER_PATH}/angular_separation.h
	${HEADER_PATH}/ln_types.h
	${HEADER_PATH}/utility.h
	${HEADER_PATH}/hyperbolic_motion.h
	${HEADER_PATH}/parallax.h
	${HEADER_PATH}/airmass.h
	${HEADER_PATH}/heliocentric_time.h
	${HEADER_PATH}/constellation.h
)

# Kconfig Logic: Defaults if no configuration found
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/.config" AND NOT EXISTS "${CMAKE_BINARY_DIR}/.config")
    set(DEFAULT_ENABLE ON)
else()
    set(DEFAULT_ENABLE OFF)
endif()

set(NOVA_SOURCES "")

# Helper macro to conditionally add sources
macro(add_module_source CONFIG_VAR SOURCE_FILE)
    if((${CONFIG_VAR}) OR (${DEFAULT_ENABLE}))
        list(APPEND NOVA_SOURCES ${SOURCE_FILE})
    endif()
endmacro()

# Always include utility
list(APPEND NOVA_SOURCES utility.c)

# Conditional Sources
add_module_source(LIBNOVA_JULIAN_DAY julian_day.c)
add_module_source(LIBNOVA_DYNAMICAL_TIME dynamical_time.c)
add_module_source(LIBNOVA_SIDEREAL_TIME sidereal_time.c)
add_module_source(LIBNOVA_TRANSFORM transform.c)
add_module_source(LIBNOVA_NUTATION nutation.c)
add_module_source(LIBNOVA_ABERRATION aberration.c)
add_module_source(LIBNOVA_APPARENT_POSITION apparent_position.c)
add_module_source(LIBNOVA_SUN solar.c)
add_module_source(LIBNOVA_PRECESSION precession.c)
add_module_source(LIBNOVA_PROPER_MOTION proper_motion.c)
add_module_source(LIBNOVA_MERCURY mercury.c)
add_module_source(LIBNOVA_VENUS venus.c)
add_module_source(LIBNOVA_EARTH earth.c)
add_module_source(LIBNOVA_MARS mars.c)
add_module_source(LIBNOVA_JUPITER jupiter.c)
add_module_source(LIBNOVA_SATURN saturn.c)
add_module_source(LIBNOVA_URANUS uranus.c)
add_module_source(LIBNOVA_NEPTUNE neptune.c)
add_module_source(LIBNOVA_PLUTO pluto.c)
add_module_source(LIBNOVA_VSOP87 vsop87.c)
add_module_source(LIBNOVA_MOON lunar.c)
add_module_source(LIBNOVA_ELLIPTIC_MOTION elliptic_motion.c)
add_module_source(LIBNOVA_ASTEROID asteroid.c)
add_module_source(LIBNOVA_COMET comet.c)
add_module_source(LIBNOVA_PARABOLIC_MOTION parabolic_motion.c)
add_module_source(LIBNOVA_REFRACTION refraction.c)
add_module_source(LIBNOVA_RISE_SET rise_set.c)
add_module_source(LIBNOVA_ANGULAR_SEPARATION angular_separation.c)
add_module_source(LIBNOVA_HYPERBOLIC_MOTION hyperbolic_motion.c)
add_module_source(LIBNOVA_PARALLAX parallax.c)
add_module_source(LIBNOVA_AIRMASS airmass.c)
add_module_source(LIBNOVA_HELIOCENTRIC_TIME heliocentric_time.c)
add_module_source(LIBNOVA_CONSTELLATION constellation.c)

add_library(nova ${NOVA_SOURCES})

# ELP (Lunar Theory)
if(LIBNOVA_MOON OR DEFAULT_ENABLE)
    add_subdirectory(elp)
endif()

target_include_directories(nova PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set_target_properties(nova PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "${LIBRARY_PUBLIC_HEADERS}")

install(TARGETS nova
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libnova)

if(UNIX)
    target_link_libraries(nova PRIVATE m)
endif()
