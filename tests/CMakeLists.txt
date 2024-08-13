include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
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

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug) # Tests should be built with Debug
endif ()

message(STATUS "Tests build type: ${CMAKE_BUILD_TYPE}")

target_include_directories(${PROJECT_NAME}_tests PUBLIC ${PROJECT_SOURCE_DIR})

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME}_tests)