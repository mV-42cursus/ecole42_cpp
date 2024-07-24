#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	// OCCF
	Cure();
	~Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);

	// MEMBER || METHOD FUNCTION
	void use(ICharacter& target);
	Cure *clone() const;
};

#endif