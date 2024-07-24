#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	// OCCF
	Dog();
	virtual ~Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog& other);

	// ACCESSORS [GETTER && SETTER]
	std::string getType() const;

	// METHOD || MEMBER FUNCTIONS
	virtual void makeSound() const;
	void setIdea(const int idx, const std::string& idea);
	const std::string& getIdea(const int idx) const;
};

#endif
