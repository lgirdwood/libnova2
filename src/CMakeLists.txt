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

add_library(nova
	${LIBRARY_PUBLIC_HEADERS}
	julian_day.c
	dynamical_time.c
	sidereal_time.c
	transform.c
	nutation.c
	aberration.c  
	apparent_position.c
	solar.c
	precession.c 
	proper_motion.c
	mercury.c
	venus.c 
	earth.c 
	mars.c  
	jupiter.c
	saturn.c 
	uranus.c 
	neptune.c 
	pluto.c
	vsop87.c
	lunar.c 
	elliptic_motion.c
	asteroid.c
	comet.c
	parabolic_motion.c
	utility.c
	refraction.c
	rise_set.c
	angular_separation.c
	hyperbolic_motion.c
	parallax.c
	airmass.c
	heliocentric_time.c
	constellation.c
)

# ELP seems to be a subdirectory that might contain some code or data?
# The original CMakeLists.txt had subdirs(elp) but no linking to it in add_library(nova ...).
# Let's check what was in elp.
add_subdirectory(elp)

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
