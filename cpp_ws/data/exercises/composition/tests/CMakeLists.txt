cmake_minimum_required(VERSION 3.16.3)
set(This test_computer)
project(${This})

set(src_files "test_computer.cpp")

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Connecting the library, specify where to get the header files
include_directories("../computer")

add_executable(
  ${This}
  ${src_files}
)
target_link_libraries(
  ${This}
  computer
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(${This})

