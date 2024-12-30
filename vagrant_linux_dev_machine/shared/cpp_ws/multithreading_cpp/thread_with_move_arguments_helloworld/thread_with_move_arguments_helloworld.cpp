// Example of passing an argument to a thread function by move
#include <thread>
#include <iostream>
#include <string>

// Thread entry point function
// Requires an rvalue argument
void hello(std::string&& str){
  std::cout << "Ownership of \""<< str << "\" transferred to thread"<< std::endl;
}

int main(){

    std::string str = "moveable";
    std::cout << "Starting thread" << std::endl;

    //  hello() takes a string argument
    std::thread thr(hello, std::move(str));
    
    // Wait for the thread to finish
    thr.join();

    // Verify that str has been modified
    std::cout << "Do I still have any data?" << ' ';
    std::cout << (str.empty() ? "No" : "Yes") << ".\n";
}
