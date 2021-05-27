#include <iostream>
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
    std::cout << "computer destructor" << std::endl;
    //Q: release resources done right?
    delete m_printer;
}

// relation between "is a" and "has a"