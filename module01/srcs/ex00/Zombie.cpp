#include "Zombie.hpp"

Zombie::Zombie(const std::string& newName)
{
	this->setName(newName);
	std::cout << this->name << " has been Created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name)
{
	this->name = name;
}
