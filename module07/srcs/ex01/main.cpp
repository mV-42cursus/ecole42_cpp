#include "iter.hpp"
#include <iostream>

template <typename T>
void display(const T& item) {
	std::cout << item << std::endl;
}

int main()
{
	// Test with an array of integers
	std::cout << "===== [Testing with an array of integers] =====" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
	iter(intArray, intArrayLength, display<int>);

	// Test with an array of strings
	std::cout << "===== [Testing with an array of strings] =====" << std::endl;
	std::string strArray[] = {"one", "two", "three", "four", "five"};
	size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);
	iter(strArray, strArrayLength, display<std::string>);
	
	return (0);
}
