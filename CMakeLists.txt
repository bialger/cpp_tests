cmake_minimum_required(VERSION 3.12)

project(
        cpp_tests # Rename the project here and in ci_tests.yml
        VERSION 0.1
        DESCRIPTION "C++ Project with Google tests"
        LANGUAGES CXX
)

include(cmake/SetCompilerOptions.cmake)
include(cmake/IncludeExternalLibraries.cmake)

add_subdirectory(lib)
add_subdirectory(bin)


enable_testing()
add_subdirectory(tests)
