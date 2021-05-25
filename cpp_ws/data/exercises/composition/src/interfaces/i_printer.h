#pragma once

#include <string>

class IPrinter
{
    public:
        virtual std::string print_to_console(const char* input) = 0;
};