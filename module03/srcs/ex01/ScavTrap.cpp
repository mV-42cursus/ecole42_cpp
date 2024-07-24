#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// ORTHODOX CANONICAL FORM
ScavTrap::ScavTrap() : ClapTrap() {
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "[ScavTrap] Default Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "[" << name << "] [ScavTrap] Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ClapTrap& other) : ClapTrap(other) {
	std::cout << "[ScavTrap] Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "[ScavTrap] Copy Assignment operator called" << std::endl;
	if (this != &other) {
		name = other.name;
		attack_damage = other.attack_damage;
		hit_point = other.hit_point;
		energy_point = other.energy_point;
	}
	return *this;
}

// CONSTRUCTORS
ScavTrap::ScavTrap(const std::string& newName) : ClapTrap(newName) {
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "[ScavTrap] Parameterized Constructor called [consts std::string newName => " << newName << "]" << std::endl; 
}

// METHOD || MEMBER FUNCTIONS
void ScavTrap::guardGate()
{
	if (this->getHitPoint() <= 0) { std::cout << "no more hit points :: [" << getHitPoint() << "]" << std::endl; return ; }
	if (this->getEnergyPoint() <= 0) { std::cout << "no more energy :: [" << getEnergyPoint() << "]" << std::endl; return ; }
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoint() <= 0) { std::cout << "no more hit points :: [" << getHitPoint() << "]" << std::endl; return ; }
	if (this->getEnergyPoint() <= 0) { std::cout << "no more energy :: [" << getEnergyPoint() << "]" << std::endl; return ; }
	std::cout 
		<< "ScavTrap " << name << " attacks " << target 
		<< ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_point -= 1;
}
