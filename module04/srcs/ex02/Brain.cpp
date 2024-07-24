#include "Brain.hpp"

// OCCF
Brain::Brain() {
	std::cout << "[Brain] Default Constructor called." << std::endl;
}

Brain::~Brain() {
	std::cout << "[Brain] Default Destructor called." << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "[Brain] Copy Constructor called." << std::endl;
	for (int i=0; i < 100; i++)	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "[Brain] Copy Assignment called." << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

// ACCESSORS [GETTER && SETTER]
void Brain::setIdea(const int idx, const std::string& idea) {
	if (idx < 0 || idx >= 100) {
		std::cout << "Wrong index." << std::endl;
		return ;
	}
	this->ideas[idx] = idea;
}

const std::string& Brain::getIdea(const int idx) const {
	if (idx < 0 || idx >= 100) {
		std::cout << "Wrong index. We will give you the first Idea by default." << std::endl;
		return this->ideas[0];
	}
	return this->ideas[idx];
}
