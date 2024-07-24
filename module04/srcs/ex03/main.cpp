#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() 
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("DYK");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "---- [equipment QA] -----" << std::endl;
		ICharacter *Champion = new Character("dong-kim");
		Champion->equip(new Ice());
		Champion->equip(new Ice());
		Champion->equip(new Cure()); 
		Champion->equip(new Cure());
		Champion->equip(new Cure());
		Champion->unequip(0);
		Champion->unequip(0);
		Champion->unequip(1);
		Champion->unequip(2);
		Champion->unequip(3);
		Champion->unequip(4);

		delete Champion;
	}
	return 0;
}
