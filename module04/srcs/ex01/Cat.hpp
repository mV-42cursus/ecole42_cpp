#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
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
	void setIdea(const int idx, const std::string& idea);
	const std::string& getIdea(const int idx) const;
};

#endif
