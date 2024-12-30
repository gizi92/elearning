// Example of passing an argument to a thread function
#include <thread>
#include <iostream>

void hello(std::string str){
  std::cout << str << std::endl;
}

int main(){

    //  hello() takes a string argument
    std::thread thr(hello, "Hello, from thread argument!");
    
    // Wait for the thread to finish
    thr.join();
}
