#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter 
{
private:
	std::string name;
	AMateria *inventory[4];
public:
	// OCCF
	Character();
	~Character();
	Character(const Character& other);
	Character &operator=(const Character &other);

	// CONSTRUCTORS
	Character(const std::string& newName);

	// ACCESSORS [GETTER && SETTER]
	std::string const& getName() const;

	// MEMBER || METHOD FUNCTIONS
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif