cmake_minimum_required(VERSION 3.16.3)
project(test_calculator)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Connecting the library, specify where to get the header files
include_directories("../libcalculator")

add_executable(
  test_calculator
  test_calculator.cpp
)
target_link_libraries(
  test_calculator
  libcalculator
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_calculator)

