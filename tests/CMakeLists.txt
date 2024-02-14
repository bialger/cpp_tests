include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        ${PROJECT_NAME}_tests
        main_test.cpp
        unit_tests.cpp
        test_functions.cpp
        test_functions.hpp
        ProjectIntegrationTestSuite.cpp
        ProjectIntegrationTestSuite.hpp
)

target_link_libraries(
        ${PROJECT_NAME}_tests # link used libraries from lib directory
        ui
        mylib
        GTest::gtest_main
)

set(MSVC_LIBRARY_EXTENSION lib)
set(MINGW_LIBRARY_EXTENSION a)
set(GTEST_DIR "${CMAKE_BINARY_DIR}/${GTEST_RELATIVE_DIR}")

if (NOT GTEST_RELATIVE_DIR)
    set(MSVC_LIBRARY_EXTENSION dll)
    set(MINGW_LIBRARY_EXTENSION dll)
    set(GTEST_DIR "${CMAKE_BINARY_DIR}/bin")
endif ()

# For Windows: prevents error with gtest.dll not found
if(WIN32)
    # If terminal emulator is not declared, then it is cmd.exe
    if (NOT TERMINAL_EMULATOR)
        set(TERMINAL_EMULATOR cmd)
    endif ()

    set(WIN_DIR_SEPARATOR "/")
    set(WIN_COPY_COMMAND cp)

    if (TERMINAL_EMULATOR  STREQUAL "cmd")
        set(WIN_DIR_SEPARATOR "\\")
        set(WIN_COPY_COMMAND copy)
    endif ()

    string(REPLACE "/" ${WIN_DIR_SEPARATOR} WIN_CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR})
    string(REPLACE "/" ${WIN_DIR_SEPARATOR} WIN_GTEST_DIR ${GTEST_DIR})
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        add_custom_command(TARGET ${PROJECT_NAME}_tests POST_BUILD
                COMMAND ${WIN_COPY_COMMAND} ARGS "${WIN_GTEST_DIR}${WIN_DIR_SEPARATOR}Debug${WIN_DIR_SEPARATOR}gtest.${MSVC_LIBRARY_EXTENSION}" "${WIN_CMAKE_BINARY_DIR}${WIN_DIR_SEPARATOR}Debug${WIN_DIR_SEPARATOR}gtest.${MSVC_LIBRARY_EXTENSION}"
                COMMAND ${WIN_COPY_COMMAND} ARGS "${WIN_GTEST_DIR}${WIN_DIR_SEPARATOR}Debug${WIN_DIR_SEPARATOR}gtest_main.${MSVC_LIBRARY_EXTENSION}" "${WIN_CMAKE_BINARY_DIR}${WIN_DIR_SEPARATOR}Debug${WIN_DIR_SEPARATOR}gtest_main.${MSVC_LIBRARY_EXTENSION}"
                COMMENT "Copying to output directory: ${WIN_COPY_COMMAND} ${WIN_GTEST_DIR}${WIN_DIR_SEPARATOR}Debug${WIN_DIR_SEPARATOR}gtest.${MSVC_LIBRARY_EXTENSION} ${WIN_CMAKE_BINARY_DIR}${WIN_DIR_SEPARATOR}Debug${WIN_DIR_SEPARATOR}gtest.${MSVC_LIBRARY_EXTENSION}")
    else ()
        add_custom_command(TARGET ${PROJECT_NAME}_tests POST_BUILD
                COMMAND ${WIN_COPY_COMMAND} ARGS "${WIN_GTEST_DIR}${WIN_DIR_SEPARATOR}libgtest.${MINGW_LIBRARY_EXTENSION}" "${WIN_CMAKE_BINARY_DIR}${WIN_DIR_SEPARATOR}libgtest.${MINGW_LIBRARY_EXTENSION}"
                COMMAND ${WIN_COPY_COMMAND} ARGS "${WIN_GTEST_DIR}${WIN_DIR_SEPARATOR}libgtest_main.${MINGW_LIBRARY_EXTENSION}" "${WIN_CMAKE_BINARY_DIR}${WIN_DIR_SEPARATOR}libgtest_main.${MINGW_LIBRARY_EXTENSION}"
                COMMAND ${WIN_COPY_COMMAND} ARGS "${WIN_CMAKE_BINARY_DIR}${WIN_DIR_SEPARATOR}${PROJECT_NAME}_tests.exe" "${WIN_CMAKE_BINARY_DIR}${WIN_DIR_SEPARATOR}${PROJECT_NAME}_tests_.exe"
                COMMENT "Copying to output directory")
    endif()
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug) # Tests should be built with Debug
endif()

message(STATUS "Tests build type: ${CMAKE_BUILD_TYPE}")

target_include_directories(${PROJECT_NAME}_tests PUBLIC ${PROJECT_SOURCE_DIR})

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME}_tests)