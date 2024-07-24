#include "Dog.hpp"

// OCCF
Dog::Dog() : Animal()
{
	std::cout << "[Dog] Default Constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog() { std::cout << "[Dog] Default Destructor called." << std::endl; }

Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "[Dog] Copy Constructor called." << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] Copy Assignment called." << std::endl;
	if (this != &other)	{
		this->type = other.type;
	}
	return *this;
}

// ACCESSORS [GETTER && SETTER]
std::string Dog::getType() const {
	return this->type;
}

// METHOD || MEMBER FUNCTIONS
void Dog::makeSound() const {
	std::cout << "Bark" << std::endl;	
}
