#pragma once
#include <iostream>
#include <string>

class IPrinter
{
    public:
        virtual std::string print_to_console(const char* input) = 0;
        virtual ~IPrinter()
        {
            std::cout << "IPrinter destructor" << std::endl;
        }
};

//TODO virtual destructor