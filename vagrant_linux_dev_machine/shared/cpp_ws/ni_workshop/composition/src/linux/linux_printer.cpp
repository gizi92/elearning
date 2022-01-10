#include "linux_printer.h"

using std::cout;
using std::endl;

LinuxPrinter::LinuxPrinter()
{
    //
}

std::string LinuxPrinter::print_to_console(const char* input)
{
    cout << input << endl;
    return "linux";
}

LinuxPrinter::~LinuxPrinter()
{
    //
}