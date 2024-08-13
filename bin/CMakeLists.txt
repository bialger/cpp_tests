add_executable(${PROJECT_NAME} main.cpp)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release) # Main executable should be built with Release
endif ()

message(STATUS "Main executable build type: ${CMAKE_BUILD_TYPE}")

target_link_libraries(${PROJECT_NAME} PUBLIC
        ui
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})