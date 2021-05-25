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
    //TODO release resources
    //TODO make sure base class is deleted
}