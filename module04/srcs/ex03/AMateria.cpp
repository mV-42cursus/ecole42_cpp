#include "AMateria.hpp"

// OCCF
AMateria::AMateria() {
	std::cout << "[AMateria] Default Constructor called." << std::endl;
}

AMateria::~AMateria() {
	std::cout << "[AMateria] Destructor called." << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	std::cout << "[AMateria] Copy Constructor called." << std::endl;
	this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other) {
	std::cout << "[AMateria] Copy Assignment called." << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

// CONSTRUCTORS
AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << "[AMateria] Parameterized Constructor called." << std::endl;
}

// ACCESSORS [GETTER && SETTER]
std::string const& AMateria::getType() const {
	return this->type;
}

// MEMBER || METHOD FUNCTIONS
void AMateria::use(ICharacter& target) {
	std::cout << "AMateria " << target.getName() << " USE" << std::endl;
}
