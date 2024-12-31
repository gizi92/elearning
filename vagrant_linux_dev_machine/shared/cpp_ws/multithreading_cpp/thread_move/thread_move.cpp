
#include <iostream>
#include <thread>

/*
 # std::thread Class
 - Implemented using RAII
   - Similar to std::unique_ptr, std::fstream, etc.
   - The construtor acquires a resource
   - The destructors releases the resource
 - An std::thread object has ownership of an execution thread
   - Only one object can be bound to an execution thread at a time

 # std::thread and Move Semantics
 - Move-only class
   - std::thread objects cannot be copied
 - Move operations
   - Transfer ownership of the execution thread
   - The moved-from object is no longer associated with an execution thread
 # Passing a std::trhead Object
 - Must use p
 ```cpp
 // Function taking a thread object as argument
 void func(std::thread thr);

 // Pass a named object
 // Use std::move() to cast it to rvalue
 std::thread thr(...);
 func(std::move(thr));

 // Pass a temporary object
 func(std::thread(...));
 ```
*/

// Example of passing a std::thread object to a function
using namespace std::literals;

void hello() {
  std::this_thread::sleep_for(1s);
  std::cout << "Hello, Thread!\n";
}

// Function taking a thread object as argument
// The object must be moved into the argument
void func(std::thread &&thr) {
  std::cout << "Received thread with ID " << thr.get_id() << std::endl;

  // The function argument now "owns" the system thread
  // It is responsible for calling join()
  thr.join();
}

int main() {
  // sts::thread is a Move-only object
  std::thread thr(hello);

  // Display the child thread's ID
  std::cout << "Hello thread has ID " << thr.get_id() << std::endl;

  // Pass a named object using std::move()
  func(std::move(thr));

  // Pass a temporary object
  // func(std::thread(hello));
}
