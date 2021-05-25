#pragma once

#include "interfaces/i_printer.h"

class Computer
{
    public:
        Computer(IPrinter *printer);
        void print_to_console(const char* input);
        ~Computer();
    private:
        IPrinter *m_printer;
};