w#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria 
{
private:
	// OCCF
public:
	// OCCF
	Ice();
	~Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);

	// MEMBER || METHOD FUNCTION
	void use(ICharacter& target);
	Ice *clone() const;
};

#endif