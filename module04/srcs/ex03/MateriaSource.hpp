#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* Materias[4];
public:
	// OCCF
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);

	// METHOD || MEMBER FUNCTIONS
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const& type);
};

#endif