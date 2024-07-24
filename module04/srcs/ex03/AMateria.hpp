#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria 
{
protected:
	std::string type;
public:
	// OCCF
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);

	// CONSTRUCTORS
	AMateria(std::string const& type);

	// ACCESSORS [GETTER && SETTER]
	std::string const& getType() const; // Returns the materia type

	// METHOD || MEMBER FUNCTIONS
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif