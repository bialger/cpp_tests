add_library(mylib STATIC
        MyClass.cpp
)

target_include_directories(mylib PUBLIC "${PROJECT_SOURCE_DIR}/includes")