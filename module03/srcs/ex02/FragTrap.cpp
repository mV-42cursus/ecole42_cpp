#include "FragTrap.hpp"

// ORTHODOX CANONICAL FORM
FragTrap::FragTrap() : ClapTrap() {
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "[FragTrap] Default Constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "[FragTrap] Copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "[FragTrap] Copy Assignment operator called" << std::endl;
	if (this != &other) {
		name = other.name;
		attack_damage = other.attack_damage;
		hit_point = other.hit_point;
		energy_point = other.energy_point;
	}
	return *this;
}

// CONSTRUCTORS
FragTrap::FragTrap(const std::string& newName) : ClapTrap(newName)
{
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "[FragTrap] Parameterized Constructor called [consts std::string newName => " << newName << "]" << std::endl; 
}

// METHOD || MEMBER FUNCTIONS
void FragTrap::highFivesGuys() {
	std::cout << "A positive high fives request!" << std::endl;
}
