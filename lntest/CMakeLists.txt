add_executable(libnova_test_exec 
    main_test.c
    test_helpers.c
    test_julian.c
    test_dynamical.c
    test_heliocentric.c
    test_sidereal.c
    test_nutation.c
    test_aber_prec_nut.c
    test_transform.c
    test_solar.c
    test_aberration.c
    test_precession.c
    test_apparent_position.c
    test_vsop87.c
    test_vsop87.c
    test_mercury.c
    test_venus.c
    test_earth.c
    test_mars.c
    test_jupiter.c
    test_saturn.c
    test_uranus.c
    test_neptune.c
    test_pluto.c
    test_lunar.c
    test_elliptic_motion.c
    test_parabolic_motion.c
    test_hyperbolic_motion.c
    test_elliptic_parabolic.c
    test_rst.c
    test_parallax.c
    test_angular.c
    test_utility.c
    test_asteroid.c
    test_airmass.c
    test_constellation.c
    test_aberration.c
)
target_link_libraries(libnova_test_exec PRIVATE nova m)
if(UNIX)
    target_link_libraries(libnova_test_exec PRIVATE m)
endif()

add_executable(libnova_test_old test.c
    test_helpers.c
    test_mercury.c
    test_venus.c
    test_earth.c
    test_mars.c
    test_jupiter.c
    test_saturn.c
    test_uranus.c
    test_neptune.c
    test_pluto.c
)
target_link_libraries(libnova_test_old PRIVATE nova PRIVATE m)

if(WIN32)
    set_property(TARGET libnova_test_exec PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    set_property(TARGET libnova_test_old PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    if(MSVC)
        set_target_properties(libnova_test_exec PROPERTIES PREFIX "../")
    endif()
endif()
# Tests are typically not installed, but if needed:
# install(TARGETS libnova_test_exec RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
