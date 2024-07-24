#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string newType);
	~Weapon();
	void setType(std::string newType);
	const std::string& getType() const;
};

#endif