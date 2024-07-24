#include "ClapTrap.hpp"

int main() {
    ClapTrap jungle("LiXin");
    ClapTrap bottom("Ash");
    ClapTrap jungle_copy(jungle);

    for (int i = 0; i < 11; i++) {
        jungle.attack(bottom.getName());
        bottom.takeDamage(jungle.getAttackDamage());
        bottom.beRepaired(1);
		std::cout << std::endl << std::endl;
    }

    jungle_copy.attack(jungle.getName());
    bottom = jungle;

    return 0;
}
