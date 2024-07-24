#include "Weapon.hpp"

Weapon::Weapon(std::string newType) : type(newType) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}
