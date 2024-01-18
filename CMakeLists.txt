cmake_minimum_required(VERSION 3.12)

project(
        cpp_tests # Rename the project here and in ci_tests.yml
        VERSION 0.1
        DESCRIPTION "C++ Project with Google tests"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug) # Change this to Release when you're ready to release
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd /fsanitize=address")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else ()
    set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_subdirectory(lib)
add_subdirectory(bin)


enable_testing()
add_subdirectory(tests)
