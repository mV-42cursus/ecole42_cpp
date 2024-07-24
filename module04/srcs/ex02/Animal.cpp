#include "Animal.hpp"

// OCCF
Animal::Animal() { std::cout << "[Animal] Default Constructor called." << std::endl; this->type = "Animal"; }
Animal::~Animal() { std::cout << "[Animal] Default Destructor called." << std::endl; }
Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "[Animal] Copy Constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "[Animal] Copy Assignment called." << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

// ACCESSORS [GETTER && SETTER]
std::string Animal::getType() const {
	return this->type;
}

// METHOD || MEMBER FUNCTIONS
void Animal::makeSound() const {
	std::cout << "???????" << std::endl;
}
