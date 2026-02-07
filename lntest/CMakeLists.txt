add_executable(libnova_test_exec test.c)
target_link_libraries(libnova_test_exec PRIVATE nova)
if(UNIX)
    target_link_libraries(libnova_test_exec PRIVATE m)
endif()

if(WIN32)
    set_target_properties(libnova_test_exec PROPERTIES DEBUG_POSTFIX "${CMAKE_DEBUG_POSTFIX}")
    if(MSVC)
        set_target_properties(libnova_test_exec PROPERTIES PREFIX "../")
    endif()
endif()
# Tests are typically not installed, but if needed:
# install(TARGETS libnova_test_exec RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
