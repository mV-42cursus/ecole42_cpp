#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
	std::cout << "====================== ClapTrap ======================" << std::endl;
	ClapTrap jungle_ct("LiXin");
	ClapTrap bottom_ct("Ash");
	ClapTrap jungle_ct_copy(jungle_ct);

	for (int i = 0; i < 11; i++)
	{
		jungle_ct.attack(bottom_ct.getName());
		bottom_ct.takeDamage(jungle_ct.getAttackDamage());
		bottom_ct.beRepaired(1);
		std::cout << std::endl << std::endl;
	}

	jungle_ct_copy.attack(jungle_ct.getName());
	bottom_ct = jungle_ct;

	std::cout << std::endl << "====================== ScavTrap ======================" << std::endl;
	ScavTrap jungle_st(jungle_ct);
	ScavTrap bottom_st(jungle_ct);
	bottom_st.attack("attack!");
	bottom_st.guardGate();
	return 0;
}
