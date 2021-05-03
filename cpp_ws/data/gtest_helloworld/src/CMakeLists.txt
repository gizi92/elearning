cmake_minimum_required(VERSION 3.16.3)
set(This calculator)
project(${This} VERSION 0.1.0)

set(src_files "calculator.cpp")
set(header_files "calculator.h")
 
# We declare the project as a static library and add all the source code files to it.
add_library(${This} STATIC ${header_files} ${src_files})