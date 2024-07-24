#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	{
		// Demonstrating proper polymorphism
		std::cout << "Building Animal" << std::endl;
		const Animal* meta = new Animal();
		std::cout << "Building Dog" << std::endl;
		const Animal* dog = new Dog();
		std::cout << "Building Cat" << std::endl;
		const Animal* cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound(); // Outputs "Meow"
		dog->makeSound(); // Outputs "Bark"
		meta->makeSound();
		std::cout << "Deleting meta" << std::endl;
		delete meta;
		std::cout << "Deleting dog" << std::endl;
		delete dog;
		std::cout << "Deleting cat" << std::endl;
		delete cat;
	}
	{
		// Demonstrating the WrongCat scenario
		const WrongAnimal* wrongCat = new WrongCat();
		wrongCat->makeSound(); // Outputs "WrongAnimal sound"
    	delete wrongCat;
	}
    return 0;
}