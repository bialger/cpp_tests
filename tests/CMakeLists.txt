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

set(MSVC_LIBRARY_PATH lib)
set(MINGW_LIBRARY_EXTENSION a)
set(GTEST_DIR "${CMAKE_BINARY_DIR}/lib")

if (NOT GITHUB_ACTIONS)
    set(MSVC_LIBRARY_EXTENSION dll)
    set(MINGW_LIBRARY_EXTENSION dll)
    set(GTEST_DIR "${CMAKE_BINARY_DIR}/bin")
endif ()

if(WIN32)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        add_custom_command(TARGET ${PROJECT_NAME}_tests POST_BUILD
                COMMAND "cp" ARGS "${GTEST_DIR}/Debug/gtest.${MSVC_LIBRARY_EXTENSION}" "${CMAKE_BINARY_DIR}/Debug/gtest.${MSVC_LIBRARY_EXTENSION}"
                COMMAND "cp" ARGS "${GTEST_DIR}/Debug/gtest_main.${MSVC_LIBRARY_EXTENSION}" "${CMAKE_BINARY_DIR}/Debug/gtest_main.${MSVC_LIBRARY_EXTENSION}"
                COMMENT "Copying to output directory")
    else ()
        add_custom_command(TARGET ${PROJECT_NAME}_tests POST_BUILD
                COMMAND "cp" ARGS "${GTEST_DIR}/libgtest.${MINGW_LIBRARY_EXTENSION}" "${CMAKE_BINARY_DIR}/libgtest.${MINGW_LIBRARY_EXTENSION}"
                COMMAND "cp" ARGS "${GTEST_DIR}/libgtest_main.${MINGW_LIBRARY_EXTENSION}" "${CMAKE_BINARY_DIR}/libgtest_main.${MINGW_LIBRARY_EXTENSION}"
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