#include "ClapTrap.hpp"

// ORTHODOX CANONICAL FORM
ClapTrap::ClapTrap() : hit_point(10), energy_point(10), attack_damage(0)  {
	std::cout << "[ClapTrap] Default Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "[ClapTrap] Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hit_point(other.hit_point), energy_point(other.energy_point), attack_damage(other.attack_damage)  {
	std::cout << "[ClapTrap] Copy Constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "[ClapTrap] Copy Assignment operator called" << std::endl;
	if (this != &other)	{
		this->name = other.name;
		this->hit_point = 10;
		this->energy_point = 10;
		this->attack_damage = 0;
	}
	return *this;
}

// CONSTRUCTORS
ClapTrap::ClapTrap(const std::string newName) : name(newName), hit_point(10), energy_point(10), attack_damage(0) {
	std::cout << "[ClapTrap] Parameterized Constructor called [consts std::string newName => " << newName << "]" << std::endl; 
}

// ACCESSORS [GETTER && SETTER]
std::string ClapTrap::getName() {
	return this->name;
}

int ClapTrap::getHitPoint() {
	return this->hit_point;
}

int ClapTrap::getEnergyPoint() {
	return this->energy_point;
}

int ClapTrap::getAttackDamage() {
	return this->attack_damage;
}

// METHOD || MEMBER FUNCTION
void ClapTrap::attack(const std::string& target) {
	if (this->getHitPoint() <= 0) { std::cout << "no more hit points :: [" << getHitPoint() << "]" << std::endl; return ; }
	if (this->getEnergyPoint() <= 0) { std::cout << "no more energy :: [" << getEnergyPoint() << "]" << std::endl; return ; }
	std::cout 
		<< "ClapTrap " << this->getName() << " attacks " 
		<< target << ", causing " << this->attack_damage 
		<< " points of damage!" << std::endl;
	this->energy_point -= 1;
	std::cout << "ClapTrap " << "has lost 1 point" << std::endl;
}

void ClapTrap::beRepaired(int amount) {
	if (this->getHitPoint() <= 0) { std::cout << "no more hit points :: [" << getHitPoint() << "]" << std::endl; return ; }
	if (this->getEnergyPoint() <= 0) { std::cout << "no more energy :: [" << getEnergyPoint() << "]" << std::endl; return ; }
	std::cout << "Repaired " << amount << " hit points!" << std::endl;
	this->hit_point += amount;
}

void ClapTrap::takeDamage(int amount) {
	if (this->getHitPoint() <= 0) { std::cout << "no more hit points :: [" << getHitPoint() << "]" << std::endl; return ; }
	if (this->getEnergyPoint() <= 0) { std::cout << "no more energy :: [" << getEnergyPoint() << "]" << std::endl; return ; }
	this->hit_point -= amount;
	std::cout
		<< "ClapTrap " << this->name << " took " << amount << " damage!" << std::endl;
}
