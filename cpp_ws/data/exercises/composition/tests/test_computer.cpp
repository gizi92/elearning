#include <gtest/gtest.h>
#include "../src/computer.h"

class ComputerFixture: public ::testing::Test
{
  public:
    Computer *m_c;
    IPrinter *m_printer;
    const char* m_test_input;
    ComputerFixture(){};
    void SetUp()
    {
      m_test_input = "Test Console Output";
      //todo handle platform specific flags and object creations in ctor
      #ifdef __linux__
        m_printer = new LinuxPrinter;
      #else
        m_printer = new WindowsPrinter;
      #endif
    }
    void TearDown()
    {
      
    }
};

TEST_F(ComputerFixture, CallsCorrectPrintFunction)
{
  std::string result = m_printer->print_to_console(m_test_input);
  #ifdef __linux__
    ASSERT_EQ(result, "linux");
  #else
    ASSERT_EQ(result, "windows");
  #endif
}

TEST(ComputerTestSuite, CanDefinePointerToLinuxPrinter) {
  LinuxPrinter *ptr = new LinuxPrinter();
  ASSERT_TRUE(ptr);
}

TEST(ComputerTestSuite, CanDefinePointerToWindowsPrinter) {
  WindowsPrinter *ptr = new WindowsPrinter();
  ASSERT_TRUE(ptr);
}