#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	try {
		int found = easyfind(numbers, 3);
		std::cout << "Found :: [" << found << "]" << std::endl;
		found = easyfind(numbers, -1);
		std::cout << "Found :: [" << found << "]" << std::endl;
	}	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
