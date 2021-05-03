#include "computer.h"

Computer::Computer(IPrinter *printer)
{
    this->m_printer = printer;
}

void Computer::print_to_console(const char* input)
{
    this->m_printer->print_to_console(input);
}

Computer::~Computer()
{
    //
}

LinuxPrinter::LinuxPrinter()
{
    //
}

std::string LinuxPrinter::print_to_console(const char* input)
{
    std::cout << input << std::endl;
    return "linux";
}

LinuxPrinter::~LinuxPrinter()
{
    //   
}

WindowsPrinter::WindowsPrinter()
{
    //
}

std::string WindowsPrinter::print_to_console(const char* input)
{
    std::cout << input << std::endl;
    return "windows";
}

WindowsPrinter::~WindowsPrinter()
{
    //   
}