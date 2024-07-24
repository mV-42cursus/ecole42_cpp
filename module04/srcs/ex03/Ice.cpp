#include "Ice.hpp"

// OCCF
Ice::Ice() : AMateria("Ice") {
	std::cout << "[Ice] Default Construtor called." << std::endl;
}

Ice::~Ice() {
	std::cout << "[Ice] Destructor called." << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "[Ice] Copy Constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	std::cout << "Ice Copy Assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

// MEMBER || METHOD FUNCTION
Ice *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
