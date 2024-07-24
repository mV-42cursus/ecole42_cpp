#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	// OCCF
	Cat();
	virtual ~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);

	// ACCESSORS [GETTER && SETTER]
	std::string getType() const;

	// METHOD || MEMBER FUNCTIONS
	void makeSound() const;
};

#endif