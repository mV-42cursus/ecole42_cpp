#include "Cat.hpp"

// OCCF
Cat::Cat() {
	std::cout << "[Cat] Default Constructor called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called." << std::endl;
	delete brain;
}

Cat::Cat(const Cat& other) : Animal() {
	std::cout << "[Cat] Copy Constructor called." << std::endl;
	this->type = other.type;
	this->brain = new Brain();
	*(this->brain) = *(other.brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "[Cat] Copy Assignment called." << std::endl;
	if (this != &other) {
		this->type = other.type;
		*(this->brain) = *(other.brain);
	}
	return *this;
}

// ACCESSORS [GETTER && SETTER]
std::string Cat::getType() const {
	return this->type;
}

void Cat::setIdea(const int idx, const std::string& idea) {
	this->brain->setIdea(idx, idea);
}

const std::string& Cat::getIdea(const int idx) const {
	return this->brain->getIdea(idx);
}

// METHOD || MEMBER FUNCTIONS
void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
