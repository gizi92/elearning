#include "windows_printer.h"

using std::cout;
using std::endl;

WindowsPrinter::WindowsPrinter()
{
    //
}

std::string WindowsPrinter::print_to_console(const char* input)
{
    cout << input << endl;
    return "windows";
}

WindowsPrinter::~WindowsPrinter()
{
    //
}