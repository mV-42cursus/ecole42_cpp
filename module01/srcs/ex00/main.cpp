#include "Zombie.hpp"

int main()
{
	Zombie stackZombie("stackZombie");
	stackZombie.announce();
	Zombie *heap = newZombie("heapZombie");
	heap->announce();
	randomChump("fool");
	delete heap;
	return 0;
}
