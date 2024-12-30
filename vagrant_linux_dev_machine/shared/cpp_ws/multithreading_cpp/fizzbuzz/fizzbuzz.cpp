// First program with std::thread
#include <thread>
#include <iostream>
#include <vector>

static int fizzBuzzNumber = 1;

// Functor class for students
class Student {
private:
    std::string mName;
public:
    Student(std::string name) { this->mName = name; }
    void operator()() {
        std::string response;
        if((fizzBuzzNumber % 3 == 0) && (fizzBuzzNumber % 5 == 0))
            response = "fizzbuzz";
        else if (fizzBuzzNumber % 3 == 0)
            response = "fizz";
        else if (fizzBuzzNumber % 5 == 0)
            response = "buzz";
        else
            response = std::to_string(fizzBuzzNumber);

        std::cout << this->mName << " says " << response << "!\n";
        ++fizzBuzzNumber;
    }
};

int main(void){
    std::vector<Student> kids{Student("Miksa"), Student("Layla"), Student("Stefan"), Student("Heidi")};

    while(fizzBuzzNumber <= 30) {
        for (auto kid : kids) {
            std::thread thr(kid);
            thr.join();
        }
    }
    return EXIT_SUCCESS;
}
