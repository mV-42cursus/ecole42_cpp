#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	int hit_point;
	int energy_point;
	int attack_damage;

public:
	// ORTHODOX CANONICAL FORM
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);

	// CONSTRUCTORS
	ClapTrap(const std::string newName);

	// ACCESSORS [GETTER && SETTER]
	std::string getName();
	int getHitPoint();
	int getEnergyPoint();
	int getAttackDamage();

	// METHOD || MEMBER FUNCTIONS
	void attack(const std::string& target);
	void takeDamage(int amount);
	void beRepaired(int amount);
};

#endif
