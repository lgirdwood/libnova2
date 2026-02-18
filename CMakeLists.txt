cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(libnova2 VERSION 2.0.0 DESCRIPTION "Astrometry Library" LANGUAGES C)

include(GNUInstallDirs)
include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckSymbolExists)
include(CheckLibraryExists)

# Kconfig Integration
include(tools/kconfig.cmake)
read_kconfig_config()

# Shared/Static option
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

if(BUILD_SHARED_LIBS)
    add_compile_definitions(LIBNOVA_SHARED)
else()
    add_compile_definitions(LIBNOVA_STATIC)
endif()

# Windows/MSVC specific definitions
if(WIN32)
    add_compile_definitions(_USE_MATH_DEFINES)
    add_compile_definitions(_SCL_SECURE_NO_WARNINGS)
    add_compile_definitions(_CRT_SECURE_NO_DEPRECATE)
    add_compile_definitions(__WIN32__)
    
    if(MSVC)
        if(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release")
             add_compile_options($<$<CONFIG:Release>:/MD> $<$<CONFIG:Release>:/Ox> $<$<CONFIG:Release>:/Ob2>)
        endif()
        add_compile_options(/arch:SSE2 /GS-)
    endif()
    
    set(CMAKE_DEBUG_POSTFIX "d")
endif()

# Feature Checks
check_include_file("malloc.h" HAVE_MALLOC_H)
check_include_file("sys/time.h" HAVE_SYS_TIME_H)
check_include_file("time.h" HAVE_TIME_H)

check_function_exists("gettimeofday" HAVE_GETTIMEOFDAY)
check_function_exists("tzset" HAVE_TZSET)
check_function_exists("strchr" HAVE_STRCHR)
check_function_exists("strpbrk" HAVE_STRPBRK)
check_function_exists("strtol" HAVE_STRTOL)
check_function_exists("strtok_r" HAVE_STRTOK_R)
check_function_exists("modf" HAVE_MODF)
check_function_exists("pow" HAVE_POW)
check_function_exists("sqrt" HAVE_SQRT)
check_function_exists("cbrt" HAVE_CBRT)

# Math functions in libm or sunmath
check_library_exists(m round "" HAVE_ROUND)
check_library_exists(m pow "" HAVE_LIBM) # Just to check if we have libm
check_library_exists(sunmath acosl "" HAVE_LIBSUNMATH)

# Long double functions - Check in default libs and libm
set(CMAKE_REQUIRED_LIBRARIES m) 
check_symbol_exists(cosl "math.h" HAVE_COSL)
check_symbol_exists(sinl "math.h" HAVE_SINL)
check_symbol_exists(acosl "math.h" HAVE_ACOSL)
check_symbol_exists(asinl "math.h" HAVE_ASINL)
check_symbol_exists(atan2l "math.h" HAVE_ATAN2L)
unset(CMAKE_REQUIRED_LIBRARIES)

# Generate config.h
configure_file(config.h.in config.h)

# Helper function for examples
function(libnova_add_example EXECUTABLE_NAME)
    add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_NAME}.c)
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE nova2)
    if(HAVE_LIBM)
        target_link_libraries(${EXECUTABLE_NAME} PRIVATE m)
    endif()
    
    if(WIN32)
        set_target_properties(${EXECUTABLE_NAME} PROPERTIES DEBUG_POSTFIX "${CMAKE_DEBUG_POSTFIX}")
        if(MSVC)
            set_target_properties(${EXECUTABLE_NAME} PROPERTIES PREFIX "../")
        endif()
    endif()
    
    install(TARGETS ${EXECUTABLE_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endfunction()

# Include directories
add_subdirectory(src)

# Testing
# pkg-config generation
set(prefix ${CMAKE_INSTALL_PREFIX})
set(exec_prefix ${CMAKE_INSTALL_PREFIX})
set(libdir ${CMAKE_INSTALL_FULL_LIBDIR})
set(includedir ${CMAKE_INSTALL_FULL_INCLUDEDIR})

configure_file(libnova2.pc.in libnova2.pc @ONLY)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libnova2.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

# Doxygen Documentation
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
endif()

# Build Options
option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_TESTING "Build tests" ON)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(lntest)
    add_test(NAME libnova_test COMMAND $<TARGET_FILE:libnova_test_exec>)
endif()

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()