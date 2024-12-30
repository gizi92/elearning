#include <iostream>
#include <thread>

/*
 # Pausing Threads
 - We can pause a thread or make it "sleep"
   std::this_thread::sleep_for()
 - Takes an argument of typw std::chrono::duration
   // C++14
   std::this_thread::sleep_for(2s);

   // C++11
   std::this_thread::sleep_for(std::chrono::seconds(2));
 - This also works with single-threaded programs
   - Pauses the thread wich executes main()
*/

using namespace std::literals;

void hello() {
  // std::this_thread::sleep_for(std::chrono::seconds(2));
  std::this_thread::sleep_for(2s);
  std::cout << "Hello, Thread!\n";
}

int main() {
  // Create an std::thread object
  std::cout << "Starting thread...\n";
  std::thread thr(hello);

  // Wait for the thread to complete
  thr.join();
}
