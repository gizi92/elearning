// Example of using a lambda expression as thread's entry point
// The lambda captures a local variable
#include <thread>
#include <iostream>


int main(){
    int i = 3;

    // Use a lambda expression as thread's entry point
    std::thread thr([&i](){ // The first argument is the lambda expression
                i *= 2;
            });
    
    // Wait for the thread to finish
    thr.join();

    std::cout << "Value i is now " << i << std::endl; 
}
