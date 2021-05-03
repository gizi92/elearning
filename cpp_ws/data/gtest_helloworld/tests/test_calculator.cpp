#include <gtest/gtest.h>
#include "../src/calculator.h"

// Demonstrate some basic assertions.
TEST(CalculatorTests, AddTwoIntegers) {
  EXPECT_EQ(add(3,2), 5);
}

TEST(CalculatorTests, MultiplyTwoIntegers) {
  EXPECT_EQ(mul(3,2), 16);
}