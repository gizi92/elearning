#pragma once

#include <iostream>
#include "../interfaces/i_printer.h"

class WindowsPrinter: public IPrinter
{
    public:
        WindowsPrinter();
        std::string print_to_console(const char* input);
        ~WindowsPrinter();
};