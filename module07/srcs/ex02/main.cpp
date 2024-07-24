#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> defaultConstructor;
	Array<std::string> paramConstructor(5);
	std::string str = "Hello World!";
	paramConstructor.setElements(str);
	Array<std::string> copyConstructor(paramConstructor);
	paramConstructor.rotateElements();
	copyConstructor.rotateElements();
	try
	{
		paramConstructor[-1] = "Hello";
		paramConstructor.rotateElements();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try {
		Array<std::string> copyAssignment;
		copyAssignment = paramConstructor;
		copyAssignment.rotateElements();
		std::cout << copyAssignment[0] << std::endl;
	}	catch(std::exception& e) {}
    return (0);
};
