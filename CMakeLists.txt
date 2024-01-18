cmake_minimum_required(VERSION 3.12)

project(
        cpp_tests # Rename the project here and in ci_tests.yml
        VERSION 0.1
        DESCRIPTION "C++ Project with Google tests"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else ()
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

add_subdirectory(lib)
add_subdirectory(bin)


enable_testing()
add_subdirectory(tests)
