#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	// ORTHODOX CANONICAL FORM
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ClapTrap& other);
	ScavTrap& operator=(const ScavTrap& other);

	// ACCESSORS [GETTER && SETTER]
	ScavTrap(const std::string& name);

	// METHOD || MEMBER FUNCTIONS
	void guardGate();
	void attack(const std::string& target);
};

#endif
