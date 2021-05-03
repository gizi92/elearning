cmake_minimum_required(VERSION 3.16.3)
project(calculator VERSION 0.1.0)

set(src_files "src/calculator.cpp")
set(header_files "src/calculator.h")
 
# We declare the project as a static library and add all the source code files to it.
add_library(libcalculator STATIC ${header_files} ${src_files})
add_subdirectory(tests)
