#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// OCCF
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat& operator=(const WrongCat& other);

	// ACCESSORS [GETTER && SETTER]
	std::string getType() const;

	// METHOD || MEMBER FUNCTIONS
	void makeSound() const;
};

#endif
