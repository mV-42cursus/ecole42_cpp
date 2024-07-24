#include "MateriaSource.hpp"

// OCCF
MateriaSource::MateriaSource() {
	std::cout << "[MateriaSource] Default Constructor called." << std::endl;
	for (int i=0; i<4; i++)
		Materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
	std::cout << "[MateriaSource] Destructor called." << std::endl;
	for (int i=0; i<4; i++) {
		if (Materias[i])
			delete Materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "[MateriaSource] Copy Constructor called." << std::endl;
	if (this != &other) {
		for (int i=0; i<4; i++) {
			if (other.Materias[i] == NULL)
				Materias[i] = NULL;
			else
				Materias[i] = other.Materias[i]->clone();
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "[MateriaSource] Copy Assignment called." << std::endl;
	if (this != &other) {
		for (int i=0; i<4; i++) {
			delete Materias[i];
			Materias[i] = NULL;
			if (other.Materias[i] == NULL)
				Materias[i] = NULL;
			else
				Materias[i] = other.Materias[i]->clone();
		}
	}
	return *this;
}

// METHOD || MEMBER FUNCTIONS
void MateriaSource::learnMateria(AMateria *m) {
	if (m == NULL)
		return ;
	for (int i=0; i<4; i++) {
		if (Materias[i] == NULL) {
			Materias[i] = m;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i=0; i<4; i++) {
		if (this->Materias[i] && this->Materias[i]->getType() == type)
			return this->Materias[i]->clone();
	}
	return NULL;
}
