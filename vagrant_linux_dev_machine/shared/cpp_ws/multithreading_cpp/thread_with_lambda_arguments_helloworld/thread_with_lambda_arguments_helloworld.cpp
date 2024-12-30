// Example of using a lambda expression as thread's entry point
// The lambda takes arguments
#include <thread>
#include <iostream>


int main(){
    // Use a lambda expression as thread's entry point
    std::thread thr(
            [](int i1, int i2){
                std::cout << "The sum of " << i1 << " and " << i2 << " is "
                << i1 + i2 << std::endl;
            },
            //The remaining arguments are passed to the lambda expression
            2,3
    );
    
    // Wait for the thread to finish
    thr.join();
}
