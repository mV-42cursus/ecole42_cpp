#include "Cat.hpp"

// OCCF
Cat::Cat() {
	std::cout << "[Cat] Default Constructor called." << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal() {
	std::cout << "[Cat] Copy Constructor called." << std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "[Cat] Copy Assignment called." << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

// ACCESSORS [GETTER && SETTER]
std::string Cat::getType() const {
	return this->type;
}

// METHOD || MEMBER FUNCTIONS
void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}