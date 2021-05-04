#include "computer.h"

using std::cout;
using std::endl;

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
    //TODO release resources
    //TODO make sure base class is deleted
}

LinuxPrinter::LinuxPrinter()
{
    //
}

std::string LinuxPrinter::print_to_console(const char* input)
{
    cout << input << endl; //not ok to expose namespaces, using namespace std::cout, std::endl, just for sources, not for headers
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