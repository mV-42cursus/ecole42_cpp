#include "Zombie.hpp"

Zombie::Zombie()
{
	
}

Zombie::Zombie(std::string name) 
{
	setName(name);
}

Zombie::~Zombie()
{
	
}

void Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string& name)
{
	this->name = name;
}
