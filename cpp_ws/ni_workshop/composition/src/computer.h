#pragma once

#include "interfaces/i_printer.h"

class Computer
{
    private:
        IPrinter *m_printer;

    public:
        Computer(IPrinter *printer); // TODO pass by reference
        /* nitpick:
            1. private
            2. public
            3. protected
        */
        void print_to_console(const char* input);
        ~Computer();
    
};