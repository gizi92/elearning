#include <iostream>
#include <string>
// TODO add comments later
class Implementation {
	public:
		virtual ~Implementation(){}
		virtual std::string OperationImplementation() const = 0;
};

class ConcreteImplementationA : public Implementation {
	public:
		std::string OperationImplementation() const override {
			return "ConcreteImplementationA: Here's the result on platform A.\n";
		}
};

class ConcreteImplementationB : public Implementation {
	public:
		std::string OperationImplementation() const override {
			return "ConcreteImplementationB: Here's the result on platform B.\n";
		}
};

class Abstraction {
	protected:
		Implementation* implementation_;
	public:
		Abstraction(Implementation* impl) : implementation_(impl){}
		virtual ~Abstraction(){}
		virtual std::string Operation() const {
			return "Abstraction: Base operation with:\n" +
				this->implementation_->OperationImplementation();
		}
};

class ExtendedAbstraction : public Abstraction {
	public:
		ExtendedAbstraction(Implementation* impl) : Abstraction(impl) {}
		std::string Operation() const override {
			return "ExtendedAbstraction: Extended operation with:\n" +
				this->implementation_->OperationImplementation();
		}
};

void ClientCode(const Abstraction& abstraction) {
	std::cout << abstraction.Operation();
}

int main(void) {
	Implementation* impl = new ConcreteImplementationA;
	Abstraction* abst = new Abstraction(impl);
	ClientCode(*abst);
	std::cout << std::endl;
	delete impl;
	delete abst;

	impl = new ConcreteImplementationB;
	abst = new ExtendedAbstraction(impl);
	ClientCode(*abst);
	delete impl;
	delete abst;

	return 0;
}
