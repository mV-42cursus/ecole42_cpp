#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	// OCCF
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal& operator=(const Animal& other);

	// ACCESSORS [GETTER && SETTER]
	std::string getType() const;

	// METHOD || MEMBER FUNCTIONS
	virtual void makeSound() const;
};

#endif
