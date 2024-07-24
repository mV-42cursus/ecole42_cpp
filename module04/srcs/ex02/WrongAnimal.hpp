#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	// OCCF
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal& operator=(const WrongAnimal& other);

	// ACCESSORS [GETTER && SETTER]
	std::string getType() const;

	// METHOD || MEMBER FUNCTIONS
	void makeSound() const;
};

#endif
