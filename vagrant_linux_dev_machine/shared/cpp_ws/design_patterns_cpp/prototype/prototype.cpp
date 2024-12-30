#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

/*
 * Prototype design pattern
 *
 * Intent: Lets you copy existing objects without making your code
 * dependent on their classes.
 */
enum Type {
	PROTOTYPE_1 = 0,
	PROTOTYPE_2
};

/*
 * The example class that has cloning ability. 
 * We'll see how the values of field with different types will be cloned.
 */
class Prototype {
	protected:
		std::string prototype_name_;
		float prototype_field_;
	public:
		Prototype(){}
		Prototype(std::string prototype_name) : prototype_name_(prototype_name) {}
		virtual ~Prototype(){}
		virtual std::unique_ptr<Prototype> Clone() const = 0;
		virtual void Method(float prototype_field) {
			this->prototype_field_ = prototype_field;
			std::cout << "Call Method from " << prototype_name_ << " with field: "
				<< prototype_field << std::endl;
		}
};

/*
 * ConcretePrototype1 is a subclass of Prototype and implements
 * the Clone method. In this example all data members of
 * Prototype class are in the Stack.
 * If you have pointers in your properties, for ex: std::string* name_,
 * you will need to implement the copy constructor to make sure
 * you have a deep copy from the clone method.
 */
class ConcretePrototype1 : public Prototype {
	private:
		float concrete_prototype_field1_;
	public:
		ConcretePrototype1(std::string prototype_name, float concrete_prototype_field)
			: Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {}
		/*
		 * Notice that the Clone method returns a pointer to a new ConcretePrototype1 replica.
		 * So, the client ( who calls the clone method ) has the responsability 
		 * to free that memory. If you have smart pointer knowledge you may prefer to
		 * use unique_ptr here.
		 */
		std::unique_ptr<Prototype> Clone() const override {
			return std::make_unique<ConcretePrototype1>(*this);
		}
};

class ConcretePrototype2 : public Prototype {
	private:
		int concrete_prototype_field2_;
	public:
		ConcretePrototype2(std::string prototype_name, int concrete_prototype_field)
			: Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field) {}
		std::unique_ptr<Prototype> Clone() const override {
			return std::make_unique<ConcretePrototype2>(*this);
		}
};

/*
 * In PrototypeFactory you have two concrete prototypes,
 * one for each concrete prototype class, so each time you want to create a bullet,
 * you can use the existing ones and clone those.
 */
class PrototypeFactory {
	private:
		std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;
	public:
		PrototypeFactory() {
			prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1", 50.f);
			prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2", 42);
		}
		~PrototypeFactory() {
			delete prototypes_[Type::PROTOTYPE_1];
			delete prototypes_[Type::PROTOTYPE_2];
		}
		/*
		 * Notice here that you just need to specify the type
		 * of the prototype you want and the method will create
		 * frp, the object with this type.
		 */
		std::unique_ptr<Prototype> CreatePrototype(Type type) {
			return prototypes_[type]->Clone();
		}
};

void Client(PrototypeFactory& prototype_factory) {
	std::cout << "Let's create a Prototype 1\n";

	auto prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
	prototype->Method(3.14);
	// delete prototype;

	std::cout << "\nLet's create a Prototype 2\n";
	auto prototype2 = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
	prototype2->Method(62);
	// delete prototype;
}

int main(void) {
	PrototypeFactory* prototype_factory = new PrototypeFactory();
	Client(*prototype_factory);
	delete prototype_factory;
	return 0;
}
