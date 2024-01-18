cmake_minimum_required(VERSION 3.12)

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

message(STATUS "Libraries build type: ${CMAKE_BUILD_TYPE}")

add_subdirectory(mylib)
