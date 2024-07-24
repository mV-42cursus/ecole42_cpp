#include "WrongCat.hpp"

// OCCF
WrongCat::WrongCat() : WrongAnimal() { std::cout << "[WrongCat] Default Constructor called." << std::endl; this->type = "WrongCat"; }
WrongCat::~WrongCat() { std::cout << "[WrongCat] Default Destructor called." << std::endl; }
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	std::cout << "WrongCat Copy Constructor called." << std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "[WrongCat Copy Assignment called." << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

// // ACCESSORS [GETTER && SETTER]
std::string WrongCat::getType() const {
	return this->type;
}

// METHOD || MEMBER FUNCTIONS
void WrongCat::makeSound() const {
	std::cout << "WrongCat sound... Hmmm" << std::endl;
}
