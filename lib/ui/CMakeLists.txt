add_library(ui STATIC
        ui_functions.cpp
        ui_functions.hpp
)

target_link_libraries(ui PUBLIC
        mylib
)

target_include_directories(ui PUBLIC ${PROJECT_SOURCE_DIR})
