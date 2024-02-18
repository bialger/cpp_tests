cmake_minimum_required(VERSION 3.12)

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif ()

if (WIN32)
    message("Windows")
elseif (LINUX)
    message("Linux")
else ()
    message("MacOS")
endif ()
