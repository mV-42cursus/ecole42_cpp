#include "Cure.hpp"

// OCCF
Cure::Cure() : AMateria("Cure") {
	std::cout << "[Cure] Default Construtor called." << std::endl;
}

Cure::~Cure() {
	std::cout << "[Cure] Destructor called." << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << "[Cure] Copy Constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	std::cout << "Cure Copy Assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

// MEMBER || METHOD FUNCTION
Cure *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
}