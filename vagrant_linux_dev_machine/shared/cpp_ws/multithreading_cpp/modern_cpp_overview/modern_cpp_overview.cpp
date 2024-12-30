#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <utility>
#include <random>

//Two functions which are overloaded
void func(int i) {
    std::cout << "func(int) called\n";
}

void func(int* i) {
    std::cout << "func(int*) called\n";
}

// Pass by Value
// arg will be a copy of the object passed by the caller
void funcMoveSemantics(std::vector<std::string> arg) {
   std::cout << "Argument vector has " << arg.size() << " elements" << std::endl;
}

// The caller's object will be moved into x
void funcRvalue(int&& x) {
    std::cout << "Rvalue reference" << std::endl;
}

// Define a moveable type
// (The compiler will provide move operators)
class MoveTest {};

// Function which takes lvalue reference
void funcMoveTest(const MoveTest& test) {
    std::cout << "Lvalue reference\n";
}

// Function which takes rvalue reference
void funcMoveTest(MoveTest&& test) {
    std::cout << "Rvalue reference\n";
}

// Example of a class with defaulted and deleted operators
class MoveOnlyTest {
public:
    // =delete means the function exists but cannot be called
    // In older C++, we had to declare the member function private
    MoveOnlyTest(const MoveOnlyTest&) = delete;  // copy constructor deleted, it cannot be called
    MoveOnlyTest& operator =(const MoveOnlyTest&) = delete; // copy assignment operator deleted

    // =default means the compiler will synthesize
    // the default version of the operator, in other words
    // we want the compiler to define it for us
    MoveOnlyTest(MoveOnlyTest&&) noexcept = default; // Move constructor
    MoveOnlyTest& operator=(MoveOnlyTest&&) noexcept = default; // Move assignment operator

    MoveOnlyTest() = default; // compiler defines a constructor with no arguments
};

// Example of std::unique_ptr
// Data structure representing a point on the screen
struct Point {
  int x;
  int y;
};
int main(void) {
    // # Universal Initialization
    // - Initializer(s) within a pair of braces
    // - Can be used with any type
    std::cout << "1. Universal Initialization\n";
    int x{7}; // Equivalent to int x = 7; except it doesn't allow narrowing conversion.
    // int x{7.7}; // Illegal
    std::string str{"Let us begin.."}; // Equivalent to std::string str("Let us begin..");
    std::cout << "Elmesz te a ...! " << str << x << std::endl;

    std::vector<int> vec{4,2,3,5,1}; // std::vector variable with elements 4,2,3,5,1.
    for(auto item : vec)
        std::cout << item << ", ";

    std::cout << std::endl;
    // # NULL
    // - Has the value 0
    // - Its type is implementation defined.
    // 
    // Two functions which are overloaded.
    // void func(int);
    // void func(int*);
    //
    // func(NULL);
    // - Calls func(int*) with clang
    // - Calls func(int) with VC++
    // - Does not compile with gcc
    // 
    // # nullptr
    // - A literal which represents a null pointer
    // - It has a special type
    //   - Compatible with any pointer type
    //   - Cannot be converted to an integer
    //
    // func(nullptr);
    // - Calls func(int*) as expected
    
    // func(NULL); // throws compile error on gcc, msvc just throws a warning
    std::cout << "2. NULL vs nullptr\n";
    func(nullptr);

    // # std::chrono Durations
    // - Types which represent time intervals
    // - Defined in <chrono>
    // - In the std::chrono namespace
    //   std::chrono::seconds            // 1 second
    //   std::chrono::milliseconds       // 1/1000 second
    //   std::chrono::microseconds       // 1/1000,000 second
    //   std::chrono::seconds(2);        // 2 second interval
    //   std::chrono::milliseconds(20);  // 20 millisecond interval
    //   std::chrono::microseconds(50);  // 50 microsecond interval

    // # std::chrono literals
    // - C++14 provides literals for these time intervals
    // in the std::chrono::literals namespace.
    // - This is an inline namespace.
    //
    // using namespace std::literals;
    //
    // 2s    // 2 second interval
    // 20ms  // 20 millisecond interval
    // 50us  // 50 microsecond interval

    // Interval types defined in the std::chrono library
    std::cout << "3. std::chrono Durations and literals\n";
    std::chrono::seconds(2);
    std::chrono::milliseconds(20);
    std::chrono::microseconds(50);

    // Literal suffixes added in C++14
    using namespace std::literals;
    2s;
    20ms;
    50us;
    
    // # The `auto` Type Specifier
    // - The compiler deduces the type from the initializer.
    //   auto x = 6;    // Equivalent to int x = 6;
    //   auto x{6};     // Equivalent to int x{6};
    // - This is very useful with complicated types.
    //   std::vector<std::string> vec;
    //   auto it = vec.begin(); // Equivalent to std::vector<std::string>::iterator it = vec.begin();
    // - In modern C++, there are some cases where the type cannot be known by the programmer.
    //
    // # `auto` Specifier and Qualifiers
    // - auto will only give the underlying type.
    //   auto x = 6;     // x deduced as non-const
    // - const, reference, etc are ignored
    //   const std::string& str = "Hello"; // Reference to const
    //   auto hello = str;   // `hello` has type std::string, it is a mutable copy of `str`.
    // - If we need them, we must add them ourselves
    //   const auto& str = hello;   // `hello` is a const reference to std::string.
    //
    // # `auto` Specifier and `for` Loops
    // - We can use auto to simplify loops.
    //   std::vector<int> vec.
    //   for(auto it = vec.begin(); it != vec.end(); ++it)
    //     std::cout << *it << ", ";
    //
    //   for(auto it = vec.begin(); it != vec.end(); ++it)
    //    *it += 2;
    std::cout << "4. `auto` specifier and `for` loops\n";
    std::vector<int> myVec{4, 2, 3, 11, 5, 1};

    for(auto it = myVec.begin(); it != myVec.end(); ++it)
        *it += 3;

    for(auto it = myVec.begin(); it != myVec.end(); ++it)
        std::cout << *it << ", ";

    std::cout << std::endl;
    // # Range `for` loops
    // - Special syntax for iterating over containers
    //   for(auto i : vec)
    //     std::cout << i << ", ";  // Prints out each element of vec
    //
    //   // We need to use a reference to modify the elements
    //   for(auto& i : vec)
    //     i+=2;  // Add 2 to each element of vec
    // 
    // - To visit each element once, in order, without adding or removing elements
    // - Otherwise, use a traditional loop
    std::cout << "5. Range `for` loops\n";
    std::vector<int> myVector{6,2,3,5,13,9};
    
    std::cout << "Vector elements before: ";
    for(auto i : myVector)
        std::cout << i << ", ";
    std::cout << std::endl;
    // We need to use a reference to modify the elements
    for(auto& i : myVector)
        i += 2;

    std::cout << "Vector elements after: ";
    for(auto i : myVector)
        std::cout << i << ", ";
    std::cout << std::endl;

    // # Lambda Expression.
    // - Similar to `closures` in other languages
    // - Can be thought of as `local functions`
    //   - Anonymous functions
    //   - Defined inline in a single statement
    // - Ideal for short, simple helper functions which are only used once
    // - Useful for passing as function arguments
    //   - More convenient than functors or function pointers
    // - Can also be returned by functions
    // - Very useful as predicates for algorithm calls
    //
    // # Lambda Expression Syntax
    // - Similar to functions
    // - Put [] instead of the function name
    // - Write the arguments in the usual way
    // - Write its body inline
    //   [](int arg){ return 2 * arg; };
    //
    // # Return Type
    // - Deduced by the compiler in C++14
    //   - The return type must be the same in all paths
    //   - In C++17, can differ
    // - In C++11, deduced for a single statement which returns a value
    //   [](int arg){ return 2*arg; };
    // - Otherwise, must be sepcified with a trailing return type
    //   [](int arg)->int{ arg=2*arg; return arg; };
    // 
    // # Callable Object
    // - A lambda expression is a callable object
    // - To invoke it, put () after the body, with any arguments
    //   [](int arg){ return 2* arg; }(3);
    // - It can be stored in a variable of type `auto`
    //   // The compiler will provide the type (not known to us)
    //   auto lam = [](int arg){ return 2*arg; };
    std::cout << "6. Lambda expressions\n";

    // In C++14. the compiler can deduce the return type
    [](int arg){ return 2*arg; };

    // In C++11, it must be specified with a trailing return type
    [](int arg) -> int { arg = 2 * arg; return arg; };
    
    // A lambda expression is callable object
    // It can be invoked by putting () after the body, with any arguments
    [](int arg) { return 2 * arg; }(3);

    // A lambda expression can be stored in a variable of type "auto"
    auto lam = [](int arg) { return 2 * arg; };

    std::cout << "Calling lam with argument 12\n";
    std::cout << "Returns " << lam(12) << std::endl;

    // # Capture
    // - A lambda expression can "capture" a local variable
    //   - Makes it available in the lambda's body
    //   - Put the name of the variable(s) inside the []
    //   - The lambda body contains an immutable copy of the local variable
    //     int n = 2;
    //     // Captures the local variable n
    //     [n](int arg){ return(n*arg); };
    //
    // # Capture by Reference
    // - The lambda can change a captured variable
    // - Put & before the variable's name
    //   int n = 2;
    //
    //   // Captures the local variable n by reference
    //   [&n](int arg){ return(++n * arg); }

    std::cout << "7. Capture by Reference.\n";
    int n = 2;

    // Captures the local variable n by reference
    std::cout << "Lambda returns " << [&n](int arg){ return (++n * arg); }(5) << std::endl;
    std::cout << "n = " << n << std::endl;

    // # Implicit Capture
    // - Captures all variables in scope
    //   - [=] captures all variables by value
    //   - [&] captures all variables by reference
    // - We can be more selective
    //   - [=,&x] captures x by reference, all others by value
    //   - [&,=a,=b] captures a and b by alue, all others by reference
    //
    // # Lambda Expressions in Member Functions
    // - To access the data members, capture "this"
    //   [this](){ return m_data % 2; }; //Captures all data members
    // - The object is captured as a reference to *this
    // - The lambda expression is able to modify data members
    //   [this](int arg){ return (++m_data * arg; };
    // # Lambda Expression Example
    // // Call count_if() algorithm using a lambda expression as predicate
    // auto n_even = std::count_if(vec.begin(), vec.end(),
    // [](int n) {
    //   return (n%2 == 0);
    // });
    
    std::cout << "8. Lambda in a control loop.\n";
    std::cout << "Elements of vector: ";
    for (auto i : vec)
        std::cout << i << ", ";
    std::cout << std::endl;

    // Call std::count_if() algorithm using a lambda expression as predicate
    auto n_even = std::count_if(vec.begin(), vec.end(),
      [](int n){
        return (n % 2 == 0);
      }
    );
    std::cout << "Vector has " << n_even << " element(s) with even values\n" << std::endl;

    // # Move Semantics
    // - C++11 optimization for copying objects
    //   - In some cases the data can be moved into the target
    //   - Similar to moving files between folders
    // - This is an important optimization, since C++ copies by default.
    std::cout << "9. Pass by value.\n";
    std::vector<std::string> vec3(1000000);
    std::cout << "Before calling func, vector has " << vec3.size() << " elements.\n";
    // This function is pass by value
    funcMoveSemantics(vec3);
    std::cout << "After calling func, vector has " << vec3.size() << " elements.\n";

    // # lvalue and rvalue before C++
    // - A value can either be an lvalue or an rvalue
    // - An lvalue may appear on the left of an assignment
    // - An rvalue can only appear on the right side
    //  x = 2;  // x is an lvalue, 2 is an rvalue
    //  2 = x;  // Not legal in C
    //  x = func();  // x is an lvalue, func() is an rvalue
    //  func() = x;  // Not legal in C
    //
    // # lvalue and rvalue in C++
    // - In C++, an lvalue represents a named memory location
    //   - It has a name
    //   - We can take its address using the & operator
    //   - x is an lvalue  // name is x, &x is legal
    // - Anything else is an rvalue
    //   - 2 is an rvalue  // 2 has no name, &2 is not legal
    //   - func() is an rvalue  // return value from function calls has no name
    //                          // &func() is not legal
    // 
    // # Reference
    // - A reference is typically implemented as a pointer
    // - The compiler adds code to deference the pointer
    //   int x;
    //   int& y = x;  // Equivalent to int *y = &x;
    //   y = 3;  // Equivalent to *y = 3;
    // - This requires that x has an address
    //   - x must be an lvalue
    // - This is now known as an "lvalue reference"
    //
    // # rvalue Reference
    // - C++11 has the concept of an "rvalue reference"
    // - An rvalue reference has '&&' after the type
    //   void func(int&& x);  // func's argument is an "rvalue reference"
    //   func(2);  // 2 is an rvalue. OK
    //   func(y);  // Error: y is an lvalue
    // - This is a syntactic device.
    //   - Indicates that a function argument must be moveable rvalue.
    
    // The caller's object will be moved into the function's parameter
    std::cout << "10. Enforcing rvalue reference as function parameter.\n";
    funcRvalue(2);
    int y = 2;
    // funcRvalue(y); // error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
    
    // # Moving into a Function Argument
    // - A function argument can be an "rvalue reference"
    // - The passed object will be moved into the argument if
    //   - The object is an rvalue
    //   - And its type is moveable
    // - Otherwise the call does not compile
    // 
    // # The Solution?
    // - Make func()'s argument an rvalue reference
    //   void func(std::vector<std::string>&& arg);
    //   std::vector<std::string> vec(1000000);  // Vector of 1 million strings
    //   func(vec);  // Does not compile
    // - An lvalue cannot be moved
    // 
    // # std::move
    // - std::move() will cast ists argument to rvalue
    //   // Casts vec to an rvalue
    //   func(std::move(vec));
    // - This will move vec's data into the function argument
    // - This should only be done if vec's data is expendable
    //   - After calling func(), vec's data may be empty or unusable
    //   - If we want to use vec again, we must re-assign its data
    funcRvalue(std::move(y));

    // # Rvalue References and Overloading
    // - Functions can be overloaded on the value type
    //   - Different behaviour for lvalues and rvalues
    //     void func(const Test& test);  // Called when we pass an lvalue
    //     void func(Test&& test);  // Called when we pass an rvalue
    // - Usually, the lvalue version will be called
    //   - When we pass a variable
    // - The rvalue overload will be called
    //   - If we pass a literal or a temporary object
    //   - If we use std::move() to cast a variable
    //
    // # Move Semantics and Ownership
    // - Consider these overloads
    //   void func(const Test& test);  // Called when we pass an lvalue
    //   void func(Test&& test);  // Called when we pass an rvalue
    // - lvalue argument
    //   - Refers to an object outside func()
    //   - The function can inspect this object
    //   - It can make its own copy of the object
    // - rvalue argument
    //   - not owned by any variable
    //   - Or the variable has lost ownership after a call to std::move()
    //   - The "test" object becomes the owner.
    // 
    // # Move Operators
    // - C++11 has two new special member functions
    //   - The arguments are rvalue references
    // - Overload of the copy constructor
    //   // Move constructor
    //   Test(Test&& other) noexcept;
    // - Overload of the assignment operator
    //   // Move assignment operator
    //   Test& operator = (Test&& other) noexcept;
    // - These operators are called during move operations
    //   - An object is only moveable if the class defines move operators.
    std::cout << "11. Example of overloading on value type.\n";
    MoveTest test;
    std::cout << "Argument is test variable:\t\t";
    funcMoveTest(test);

    std::cout << "Argument is temporary object:\t\t";
    funcMoveTest(MoveTest());

    std::cout << "Argument through std::move():\t\t";
    funcMoveTest(std::move(test));
    std::cout << std::endl;

    // # Move-only Types
    // - Some types can be moved, but not copied
    //   - std::fstream, std::iostream
    //   - std::unique_ptr
    //   - (Classes used in multi-threading)
    // - These types follow the RAII idiom
    //   - Only one object can own a given resource instance at a time
    //   - The object acquires ownership in the constructor
    //   - The object releases ownership in the destructor
    //   - The resource instance can be moved from one object to another
    // 
    // # std::fstream
    // - std::fstream has a file handle as a data member
    //   - The constructor opens the file
    //   - The destructor closes the file
    // - A std::fstream object cannot be copied, but it can be moved
    //   - The moved-from object no longer owns the file handle
    //   - The moved-to object becomes the owner of the file handle
    //   - The file will be closed when the moved-to object is destroyed
    //
    // # Deleted and Defaulted Operators
    // - In C++11, special member functions can be deleted
    //   Test(const Test& other) = delete;  // Deleted copy constructor
    // - This prevents an object from being copied
    //   - The function is defined, but cannot be called
    // - Special member functions can also be defaulted
    //   Test(const Test& other) = default;  // Default copy constructor
    // - This causes the compiler to generate a default member function
    //   - e.g. The default copy constructor copies all the class members
    //
    std::cout << "12. Move-only class operator test.\n";
    MoveOnlyTest test1, test2, test3;

    // MoveOnlyTest test5(test1); // copy constructor test, error: use of deleted function
    // test2 = test3; // copy assignment operator, error: use of deleted function
    MoveOnlyTest test4(std::move(test1)); // move constructor test 
    test3 = std::move(test2); // move assignment operator test
    
    // # Lambda-local Variables
    // - Variables which are local to the lambda body
    // - Declared in the capture specifier
    //   - Implicitly `auto`
    //   - Must be initialized
    // - Requires C++14
    //   // y is local to the lambda body
    //   [y=2](int x){
    //      return x+y;
    //   };
    // - Can be initialized from captured variables
    // - No special syntax is needed
    //   // Local variable z in this scope
    //   int z = 1;
    //   // Lambda body's local variable
    //   [y=z+1](int x){
    //      return x + y;
    //   };
    std::cout << "13. Lambda-local Variables\n";

    // y is local to the lambda body
    auto add_two = [y = 2](int x){
        return x + y;
    };

    std::cout << "Calling add_two(2) gives " << add_two(2) << std::endl;
    std::cout << "Calling add_two(5) gives " << add_two(5) << std::endl;

    // z is a local variable in the containing scope of the lambda
    int z = 2;

    // y1 is local to the lambda body
    // It is initialized using the local variable z
    auto add_z_plus1 = [y = z + 1](int x){
        return x + y;
    };

    std::cout << "Calling add_z_plus1(2) gives " << add_z_plus1(2) << std::endl;
    std::cout << "Calling add_z_plus1(5) gives " << add_z_plus1(5) << std::endl;

    // # Lambda-local Variables and Capture by Move
    // - Lambda-local variables can be move initialized
    //   std::vector<std::string> strings(5);
    //
    //   // Lambda expression which captures "strings"
    //   // by moving it into "vec_strings"
    //   [vec_strings = std::move(strings)]{
    //      ...
    //   };
    //
    // - This allows capture by move
    //   - The type of vec_strings is deduces as std::vector<std::string>
    //   - std::vector's move constructor is called to initialize vec_strings
    //   - The vector elements are now owned by vec_strings

    std::cout << "14. Lambda expression which capture by move\n";
    std::vector<std::string> strings(5);
    std::cout << "Capture by reference\n";
    // Lambda expression which captures "strings" by reference
    [&strings](){
        std::cout << "Size in lambda = " << strings.size() << std::endl;
    }();

    std::cout << "After calling lambda, size in main = " << strings.size() << std::endl;
    std::cout << "\nCapture by move\n" << std::endl;
    [vec_strings = std::move(strings)](){
        std::cout << "Size in lambda = " << vec_strings.size() << std::endl;
    }();
    std::cout << "After calling lambda, size in main = " << strings.size() << "\n\n";

    // # Random Numbers in C++11
    // - New classes defined in <random>
    //   - Avoid a number of issues with std::rand()
    // - Random number engines
    //   - Generate a sequence of random numbers
    // - Distribution objects
    //   - Scale a sequence of numbers
    //   - Fit them into a given statistical distribution
    // - We use the uniform distribution
    //   - Every random number should be equally like
    //
    // # Random Number Classes
    // - Functors which overload operator()
    // - Random number engine
    //   - std::mt19937 is usually the best choice
    //   - Should be declared static
    // - Distribution object
    //   - std::uniform_int_distribution<T> for integers
    //   - std::uniform_real_distribution<T> for floating-point
    // - To get a random number
    //   - Call the distribution's operator()
    //   - Pass the engine object as argument
    std::cout << "15. Example of using the features in <random>.\n";
    // Create an engine object, usually static global
    std::mt19937 mt;

    // We want ints in the range of 0 to 100
    std::cout << "5 random integers between 0 and 100:\n";
    std::uniform_int_distribution<int> uid(0,100);
    
    // Get 5 random numbers
    for(int i = 0; i < 5; ++i){
        // Invoking the distribution point returns the next number in the sequence
        std:: cout << uid(mt) << ", ";
    }
    std::cout << std::endl;

    // We want doubles in the range 0 to 1
    std::cout << "5 random floating-point numbers between 0 and 1:\n";
    std::uniform_real_distribution<double> did(0,1);

    // Get 5 random numbers
    for(int i = 0; i < 5; ++i){
        // Invoking the distribution point returns the next number in the sequence
        std::cout << did(mt) << ", ";
    }
    std::cout << std::endl;

    // # std::unique_ptr
    // - Template class defined in <memory>
    //   - Has a traditional pointer as a member
    // - Supports most pointer operations
    //   - But not increment/decrement
    // - Move-only class which uses the RAII idiom
    //   - Automatically releases the memory when it goes out of scope
    //   - Allows heap-allocated memory to be used like a stack object
    //   - Has no more overhead than a traditional pointer
    //
    // # std::unique_ptr initialization
    // - In C++11, we have to provide the pointer
    //   // Allocate a single int with value 42
    //   std::unique_ptr<int> uniq_ptr(new int(42));
    // - C++14 has std::make_unique()
    // - This calls new() internally
    //   auto uniq_ptr = std::make_unique<int>(42);i
    std::cout << "16. Example of std::unique_ptr.\n";

    // Create a unique_ptr to a Point object which has initial values {3,6}
    auto uniq_ptr = std::make_unique<Point>(Point{3,6});

    // std::unique_ptr<Point> uniq_ptr(new Point{3,6});  // C++11
    std::cout << uniq_ptr->x << ", " << uniq_ptr->y << std::endl;
    return 0;
}
