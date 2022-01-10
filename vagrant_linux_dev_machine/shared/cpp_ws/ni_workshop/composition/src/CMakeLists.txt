cmake_minimum_required(VERSION 3.16.3)
set(This computer)
project(${This} VERSION 0.1.0)

# TODO find a solution to detect all subfolders in the project
file(GLOB src_files ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/windows/*.cpp ${PROJECT_SOURCE_DIR}/linux/*.cpp)
file(GLOB header_files ${PROJECT_SOURCE_DIR}/*.h ${PROJECT_SOURCE_DIR}/interfaces/*.h ${PROJECT_SOURCE_DIR}/windows/*.h ${PROJECT_SOURCE_DIR}/linux/*.h) 

# We declare the project as a static library and add all the source code files to it.
add_library(${This} STATIC ${header_files} ${src_files})