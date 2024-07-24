#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
	std::cout << "====================== ClapTrap ======================" << std::endl;
	ClapTrap jungle_ct("LiXin");
	ClapTrap bottom_ct("Ash");
	ClapTrap jungle_ct_copy(jungle_ct);

	jungle_ct_copy.attack(jungle_ct.getName());
	bottom_ct = jungle_ct;

	std::cout << "\n====================== ScavTrap ======================" << std::endl;
	ScavTrap jungle_st(jungle_ct);
	ScavTrap bottom_st(jungle_ct);
	bottom_st.attack("attack!");
	bottom_st.guardGate();

	std::cout << "\n====================== FragTrap ======================" << std::endl;
	FragTrap obj1;
	FragTrap obj2 = obj1;
	FragTrap obj3(obj2);

	// Construction && Destruction chain...
	// [Case::ScavTrap]
	// std::cout << "building ScavTrap..." << std::endl;
	// ScavTrap c;
	// std:: cout << "exiting main..." << std::endl;
	// [Case::FragTrap]
	// std::cout << "building FragTrap..." << std::endl;
	// FragTrap c;
	// std:: cout << "exiting main..." << std::endl;
	return 0;
}
