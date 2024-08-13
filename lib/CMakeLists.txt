cmake_minimum_required(VERSION 3.12)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug) # Change this to Release when you're ready to release
endif ()

message(STATUS "Libraries build type: ${CMAKE_BUILD_TYPE}")

add_subdirectory(mylib)
add_subdirectory(ui)
