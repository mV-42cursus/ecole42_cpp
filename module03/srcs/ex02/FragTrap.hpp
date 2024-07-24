#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	// ORTHODOX CANONICAL FORM
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);

	// CONSTRUCTORS
	FragTrap(const std::string& name);

	// METHOD || MEMBER FUNCTIONS
	void highFivesGuys();
};

#endif
