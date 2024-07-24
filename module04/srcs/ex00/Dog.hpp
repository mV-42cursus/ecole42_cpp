#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	// OCCF
	Dog();
	virtual ~Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog& other);

	// ACCESSORS [GETTER && SETTER]
	std::string getType() const;

	// METHOD || MEMBER FUNCTIONS
	void makeSound() const;
};

#endif