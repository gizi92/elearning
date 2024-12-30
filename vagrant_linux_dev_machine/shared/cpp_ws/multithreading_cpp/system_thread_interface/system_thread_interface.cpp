// First program with std::thread
#include <iostream>
#include <thread>

/*
 # System Thread Interface
 - std::thread uses the system's thread implementation
 - We may need to use the thread implementation directly
 - Some functionality is not available in standard C++
 - Thread priority
   - Give a thread higher or lower share of processor time
 - Thread affinity
   - "Pin" a thread on a specific processor core

 ## native_handle()
 - Each execution thread has a "handle"
   - Used internally by the system's thread implementation
   - Needed when making calls into the implementation's API
 - Returned by the native_handle() member function

 // Get the handle associated with an std::thread object
 thr.native_handle()

 */

void hello() { std::cout << "Hello, thread!\n"; }

int main() {
  // Create an std::thread object
  std::thread thr(hello);

  // Display the child thread's native handle
  std::cout << "Hello thread has native handle " << thr.native_handle()
            << std::endl;

  // Wait for the thread to finish
  thr.join();

  // Display the child thread's native handle again
  std::cout << "Hello thread now has native handle " << thr.native_handle()
            << std::endl;
}
