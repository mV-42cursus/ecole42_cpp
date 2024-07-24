#include "Character.hpp"

// OCCF
Character::Character() {
	std::cout << "[Character] Default Constructor called." << std::endl;
}

Character::~Character() {
	std::cout << "[Character] Destructor called." << std::endl;
	for (int i=0; i<4; i++) {
		delete inventory[i];
		inventory[i] = NULL;
	}
}

Character::Character(const Character& other) {
	std::cout << "[Character] Copy Constructor called." << std::endl;
	this->name = other.name;
	for (int i=0; i<4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		if (other.inventory[i] == NULL)
			this->inventory[i] = NULL;
		else
			this->inventory[i] = other.inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& other) {
	std::cout << "[Character] Copy Assignment operator called." << std::endl;
	if (this != &other) {
		this->name = other.name;
		for (int i=0; i<4; i++) {
			if (this->inventory[i] != NULL) {
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
			if (other.inventory[i] == NULL)
				this->inventory[i] = NULL;
			else
				this->inventory[i] = other.inventory[i]->clone();
		}
	}
	return *this;
}

// CONSTRUCTORS
Character::Character(const std::string& newName) : name(newName) {
	std::cout << "[Character] Parameterized Constructor called." << std::endl;
	for (int i=0; i<4; i++)
		inventory[i] = NULL;
}

// ACCESSORS [GETTER && SETTER]
std::string const& Character::getName() const {
	return this->name;
}

// MEMBER || METHOD FUNCTIONS
void Character::equip(AMateria *m) {
	int flag = 0; // whether there is space in the inventory 
				  // [0] => there is no space 
				  // [1] => there is space

	if (m == NULL)
		return ;
	for (int i=0; i<4; i++) {
		if (inventory[i] == NULL)
			flag = 1;
	}
	if (flag == 0) {
		delete m;
		return ;
	}
	for (int i=0; i<4; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (!(idx >= 0 && idx <= 3))
		return ;
	if (inventory[idx] == NULL)
		return ;
	std::cout << name << " unequip " << inventory[idx]->getType() << std::endl;
	delete inventory[idx];
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (!(idx >= 0 && idx <= 3))
		return ;
	if (inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
	delete inventory[idx];
	inventory[idx] = NULL;
}
