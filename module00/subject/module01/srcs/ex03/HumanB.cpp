#include "HumanB.hpp"

HumanB::HumanB(const std::string &HumanName) : name(HumanName), weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
	if (this->weapon == NULL) {
		std::cout << this->name << " no weapon, unable to attack." << std::endl;
		return ;
	}
	std::cout << name << " attacks with " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	this->weapon = &newWeapon;
}