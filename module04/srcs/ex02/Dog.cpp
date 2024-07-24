#include "Dog.hpp"

// OCCF
Dog::Dog() : Animal()
{
	std::cout << "[Dog] Default Constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::~Dog() { 
	std::cout << "[Dog] Default Destructor called." << std::endl;
	delete brain;
}

Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "[Dog] Copy Constructor called." << std::endl;
	this->type = other.type;
	this->brain = new Brain();
	*(this->brain) = *(other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] Copy Assignment called." << std::endl;
	if (this != &other)	{
		this->type = other.type;
		*(this->brain) = *(other.brain);
	}
	return *this;
}

// ACCESSORS [GETTER && SETTER]
std::string Dog::getType() const {
	return this->type;
}

void Dog::setIdea(const int idx, const std::string& idea) {
	this->brain->setIdea(idx, idea);
}

const std::string& Dog::getIdea(const int idx) const {
	return this->brain->getIdea(idx);
}

// METHOD || MEMBER FUNCTIONS
void Dog::makeSound() const {
	std::cout << "Bark" << std::endl;	
}
