#pragma once

#include <iostream>
#include "../interfaces/i_printer.h"
class LinuxPrinter: public IPrinter
{
    public:
        LinuxPrinter();
        std::string print_to_console(const char* input);
        ~LinuxPrinter();
};