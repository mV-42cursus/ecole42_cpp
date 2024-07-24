#include "WrongAnimal.hpp"

// OCCF
WrongAnimal::WrongAnimal() { std::cout << "[WrongAnimal] Default Constructor called." << std::endl; this->type = "WrongAnimal"; }
WrongAnimal::~WrongAnimal() { std::cout << "[WrongAnimal] Default Destructor called." << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "[WrongAnimal] Copy Constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "[WrongAnimal] Copy Assignment called." << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

// ACCESSORS [GETTER && SETTER]
std::string WrongAnimal::getType() const {
	return this->type;
}

// METHOD || MEMBER FUNCTIONS
void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound... Hmmm" << std::endl;
}
