#include "HumanA.hpp"

HumanA::HumanA(const std::string& HumanName, Weapon& newWeapon) : name(HumanName), weapon(newWeapon) {}
HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << name << " attacks with " << weapon.getType() << std::endl;
}