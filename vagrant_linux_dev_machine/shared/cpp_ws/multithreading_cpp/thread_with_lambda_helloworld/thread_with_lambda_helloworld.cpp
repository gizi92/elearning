// Example of using a lambda expression as thread's entry point
#include <thread>
#include <iostream>


int main(){
    // Use a lambda expression as thread's entry point
    std::thread thr([](){
            std::cout << "Hello, Lambda thread!\n";
            });
    
    // Wait for the thread to finish
    thr.join();
}
