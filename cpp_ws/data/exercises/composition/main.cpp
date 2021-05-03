#include <iostream>
#include "src/computer.h"

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
