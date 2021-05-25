#include <iostream>
#include "src/computer.h"
#include "src/linux/linux_printer.h"
#include "src/windows/windows_printer.h"

#ifdef __linux__
    Computer c(new LinuxPrinter);
#else
    Computer c(new WindowsPrinter);
#endif

int main(){
    const char* test_input = "imma poser!";
    c.print_to_console(test_input);
    return EXIT_SUCCESS;
}
