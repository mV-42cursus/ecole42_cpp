#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon& weapon;
public:
	HumanA(const std::string &HumanName, Weapon& newWeapon);
	~HumanA();
	void attack();
};


#endif