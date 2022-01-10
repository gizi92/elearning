#include <gtest/gtest.h>
#include "../src/computer.h"
#include "../src/windows/windows_printer.h"
#include "../src/linux/linux_printer.h"

enum ePlatform
{
  linux,
  windows,
  mac,
  platform_not_supported
};
// from now on we 
class ComputerFixture: public ::testing::Test
{
  public:
    Computer *m_c;
    IPrinter *m_printer; // test using mock printer; how to mock classes; put them in header, since they don't have implementation
    ePlatform m_platform; 
    const char* m_test_input;
    ComputerFixture()
    {
      
    };

   

    void SetUp()
    {
      #if __linux__
        platform = linux;
        m_printer = new LinuxPrinter();
      #elif _WIN64
        m_platform = windows;
        m_printer = new WindowsPrinter();
      #else
        platform = platform_not_supported;
        EXPECT_TRUE(false) << "Platform is not supported!";
      #endif
      // general purpose setup
      m_test_input = "Test Console Output";
    }

    void TearDown()
    {
      if(m_printer != nullptr)
        delete m_printer;
    }
};

TEST_F(ComputerFixture, CallsCorrectPrintFunction)
{
  std::string result = m_printer->print_to_console(m_test_input);
  switch (m_platform)
  {
  case linux:
    ASSERT_EQ(result, "linux");
    break;
  case windows:
    ASSERT_EQ(result, "windows");
    break;
  default:
    EXPECT_TRUE(false) << "Platform is not supported!";
    break;
  }
}

TEST(ComputerTestSuite, CanDefinePointerToLinuxPrinter) {
  LinuxPrinter *ptr = new LinuxPrinter();
  ASSERT_TRUE(ptr);
}

TEST(ComputerTestSuite, CanDefinePointerToWindowsPrinter) {
  WindowsPrinter *ptr = new WindowsPrinter();
  ASSERT_TRUE(ptr);
}