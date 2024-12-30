#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

// The Target defines the domain-specific interface used by the client code.
class Target {
	public:
		virtual ~Target() = default;
		virtual std::string Request() const {
			return "Target: the default target's behavior.";
		}
};

/*
 * The Adapter contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation
 * before the client code can use it.
 */
class Adaptee {
	public:
		std::string SpecificRequest() const {
			return ".eetpadA eht fo roivaheb laicepS";
		}
};

/*
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface using multiple inheritance.
 */
class Adapter : public Target, public Adaptee {
	public:
		Adapter(){}
		std::string Request() const override {
			std::string to_reverse = SpecificRequest();
			std::reverse(to_reverse.begin(), to_reverse.end());
			return "Adapter: (TRANSLATED) " + to_reverse;
		}
};

/*
 * The client code supports all classes that follow the Target interface.
 */
void ClientCode(std::shared_ptr<Target> target) {
	std::cout << target->Request();
}

int main(void) {
	std::cout << "Client: I can work just fine with the Target objects:\n";
	auto target = std::make_shared<Target>();
	ClientCode(target);
	std::cout << "\n\n";
	
	std::shared_ptr<Adaptee> adaptee(new Adaptee());
	std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
	std::cout << "Adaptee: " << adaptee->SpecificRequest();
	std::cout << "\n\n";
	
	std::cout << "Client: But I can work with it via the Adapter:\n";
	std::shared_ptr<Adapter> adapter(new Adapter());
	ClientCode(adapter);
	std::cout << "\n";

	return 0;
}
