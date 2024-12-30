#include <iostream>
#include <ostream>
#include <thread>

/*
 # std::thread ID
 - Each execution thread has a thread identifier
   - Used internally by the system's implementation
 - Guaranteed to be unique
   - If two thread identifiers are equal, the related objects are identical
   - Could be used to store std::thread objects in associative containers
   - A new thread may get the ID of an earlier thread which has completed

 // Return the identifier of the current thread
 std::this_thread::get_id();

 // Return the identifier associated with an std::thread object
 thr.get_id();
 */

// Task function
// Displays the thread's ID
void hello() {
  std::cout << "Hello from thread with ID " << std::this_thread::get_id()
            << std::endl;
}

int main() {
  // Display the main thread's ID
  std::cout << "Main thread has ID " << std::this_thread::get_id() << std::endl;

  // Create a thread object
  std::thread thr(hello);

  // Display the child thread's ID
  std::cout << "Hello thread has ID " << thr.get_id() << std::endl;

  // Wait for the thread to complete
  thr.join();

  // Display the child thread's ID again
  std::cout << "Hello thread now has ID " << thr.get_id() << std::endl;
}
