#ifndef _COMPUTER_H
#define _COMPUTER_H
#include <iostream>

class IPrinter
{
    public:
        virtual std::string print_to_console(const char* input) = 0;   
};

class Computer
{
    public:
        Computer(IPrinter *printer);
        void print_to_console(const char* input);
        ~Computer();
    private:
        IPrinter *m_printer;

};

class WindowsPrinter: public IPrinter
{
    public:
        WindowsPrinter();
        std::string print_to_console(const char* input);
        ~WindowsPrinter();
};

class LinuxPrinter: public IPrinter
{
    public:
        LinuxPrinter();
        std::string print_to_console(const char* input);
        ~LinuxPrinter();
};

#endif /* _COMPUTER_H */