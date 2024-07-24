#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

// #include <stdlib.h>

// void leaks() {
// 	system("leaks ex01");
// }

int main() 
{
	// atexit(leaks);
	{
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		delete dog;
		delete cat;
	}
	{
		std::cout << "-------------------- [ARRAY TESTS] -------------------------" << std::endl;
		int numberOfAnimals  = 2;

		Animal **animals = new Animal*[numberOfAnimals];

		for (int i = 0; i < numberOfAnimals; i++) {
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < numberOfAnimals; i++) {
			delete animals[i];
		}
		delete[] animals;
	}
	{
		std::cout << "-------------------- [COPY TESTS] -------------------------" << std::endl;
		Cat cat;
		Cat catCpyAssignment;

		cat.setIdea(0, "Cat's Idea 0");
		cat.setIdea(1, "Cat's Idea 1");
		catCpyAssignment = cat;
		Cat catCpyConstructor(cat);
		for (int i = 0; i < 3; i++) {
			std::cout << "cat's ideas[" << i << "] : "  << "\t\t[" << &cat.getIdea(i) << "] " << cat.getIdea(i) << std::endl;
			std::cout << "catCpyAssignment's ideas[" << i << "] : " << "\t[" << &catCpyAssignment.getIdea(i) << "] " << catCpyAssignment.getIdea(i) << std::endl;
			std::cout << "catCpyConstructor's ideas[" << i << "] : " << "\t[" << &catCpyConstructor.getIdea(i) << "] " << catCpyConstructor.getIdea(i) << std::endl;
		}

		Dog dog;
		Dog dogCpyAssignment;

		dog.setIdea(0, "Dog's Idea 0");
		dog.setIdea(1, "Dog's Idea 1");
		dogCpyAssignment = dog;
		Dog dogCpyConstructor(dog);
		for (int i = 0; i < 3; i++) {
			std::cout << "dog's ideas[" << i << "] : "  << "\t\t[" << &dog.getIdea(i) << "] " << dog.getIdea(i) << std::endl;
			std::cout << "dogCpyAssignment's ideas[" << i << "] : " << "\t[" << &dogCpyAssignment.getIdea(i) << "] " << dogCpyAssignment.getIdea(i) << std::endl;
			std::cout << "dogCpyConstructor's ideas[" << i << "] : " << "\t[" << &dogCpyConstructor.getIdea(i) << "] " << dogCpyConstructor.getIdea(i) << std::endl;
		}
	}
	return 0;
}
