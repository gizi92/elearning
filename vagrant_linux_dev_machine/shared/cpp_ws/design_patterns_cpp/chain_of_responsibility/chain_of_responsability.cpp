#include <iostream>
#include <string>
#include <vector>

/*
 * The Handler interface declares a method for building the chain of handlers.
 * It also declares a method for executing a request.
 */
class Handler {
    public:
        virtual Handler* SetNext(Handler* handler) = 0;
        virtual std::string Handle(std::string request) = 0;
};

// The default chaining behavior can be implemented inside a base handler class.
class AbstractHandler : public Handler {
    private:
        Handler* next_handler_;
    public:
        AbstractHandler() : next_handler_(nullptr) {}
        Handler* SetNext(Handler* handler) override {
            this->next_handler_ = handler;
            /*
             * Returning a handler from here will let us link handlers in a convenient
             * way like this:
             * $monkey->SetNext($squirell)->setNext($dog);
             */
            return handler;
        }
        std::string Handle(std::string request) override {
            if(this->next_handler_) {
                return this->next_handler_->Handle(request);
            }
            return {};
        }
};

/*
 * All Concrete Handlers either handle a request or pass it to the next handler
 * in the chain.
 */
class MonkeyHandler : public AbstractHandler {
    std::string Handle(std::string request) override {
        if(request == "Banana") {
            return "Monkey: I'll eat the " + request + ".\n";
        } else {
            return AbstractHandler::Handle(request);
        }
    }
};

class DogHandler : public AbstractHandler {
    std::string Handle(std::string request) override {
        if(request == "Meatball") {
            return "Dog: I'll eat the " + request + ".\n";
        } else {
            return AbstractHandler::Handle(request);
        }
    }
};

class SquirrelHandler : public AbstractHandler {
    std::string Handle(std::string request) override {
        if(request == "Nut") {
            return "Squirrel: I'll eat the " + request + ".\n";
        } else {
            return AbstractHandler::Handle(request);
        }
    }
};

/*
 * The client code is usually suited to work with a single handler.
 * In most cases, it is not even aware that the handler is part of a chain.
 */
void ClientCode(Handler& handler) {
    std::vector<std::string> food = {"Nut", "Meatball", "Coffee"};
    for (const std::string& f : food) {
        std::cout << "Client: Who wants a " << f << "?\n";
        const std::string result = handler.Handle(f);
        if(!result.empty()) {
            std::cout << " " << result;
        } else {
            std::cout << " " << f << " was left untouched.\n";
        }
    }
}

// The other part of the client code constructs the actual chain.
int main(void) {
    MonkeyHandler* monkey = new MonkeyHandler;
    SquirrelHandler* squirrel = new SquirrelHandler;
    DogHandler* dog = new DogHandler;
    dog->SetNext(squirrel)->SetNext(monkey);

    /*
     * The client should be able to send a request to any handler, not just
     * the first one in the chain.
     */
    std::cout << "Chain: Dog > Squirrel > Monkey\n\n";
    ClientCode(*dog);
    std::cout << std::endl;
    std::cout << "Subchain: Squirrel > Monkey\n\n";
    ClientCode(*squirrel);
    
    delete monkey;
    delete squirrel;
    delete dog;

    return 0;
}
