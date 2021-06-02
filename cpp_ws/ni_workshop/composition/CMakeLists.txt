cmake_minimum_required(VERSION 3.16.3)
set(This ClientApp)
project(${This} VERSION 0.1.0)

set(src_files "main.cpp")

add_subdirectory(src)
add_subdirectory(tests)

add_executable (${This} ${src_files})
# Connecting the library, specify where to get the header files
include_directories("../computer")
# And also we specify dependence on static library
target_link_libraries(${This} computer)