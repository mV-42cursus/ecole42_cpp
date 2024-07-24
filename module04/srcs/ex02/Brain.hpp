#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
private:
	std::string ideas[100];
public:
	// OCCF
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);

	// ACCESSORS [GETTER && SETTER]
	void setIdea(const int idx, const std::string& idea);
	const std::string &getIdea(const int idx) const;
};

#endif
