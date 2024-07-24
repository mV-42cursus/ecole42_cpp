#include "Span.hpp"
#include <iostream>
#include <set>

int main()
{
	// testcase 1
	{
		std::cout << "==================== [TESTCASE 1] ========================" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	// testcase 2
	{
		std::cout << "==================== [TESTCASE 2] ========================" << std::endl;
		Span a(5);
		try {
			a.addNumber(-2147483648);
			a.addNumber(20);
			a.addNumber(42);
			a.addNumber(2147483647);
		}	catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Shortest Span: " << a.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << a.longestSpan() << std::endl;
		}	catch (std::exception& e) {}
	}

	// // testcase 3
	// {
	// 	std::cout << "==================== [TESTCASE 3] ========================" << std::endl;
	// 	try {
	// 		Span mySpan(100000);

	// 		std::vector<int> numbers;
	// 		for (int i = 0; i < 100000; ++i) {
	// 			numbers.push_back(i);
	// 		}

	// 		mySpan.addNumber(numbers.begin(), numbers.end());

	// 		std::cout << "Shortest Span: " << mySpan.shortestSpan() << std::endl;
	// 		std::cout << "Longest Span: " << mySpan.longestSpan() << std::endl;
	// 	} catch (const std::exception& e) {
	// 		std::cout << "Exception: " << e.what() << std::endl;
	// 	}
	// }
    return 0;
}

// 00000000 00000000 00000000 00000000 01111111 11111111 11111111 11111111 2147483647
// 11111111 11111111 11111111 11111111 10000000 00000000 00000000 00000000 -2147483648
// 00000000 00000000 00000000 00000000 11111111 11111111 11111111 11111111 = n
// n + 1 == 2^32
// 00000000 00000000 00000000 00000000 
// 11111111 11111111 11111111 11110000 
// 00000000 00000000 00000000 00000000
// 01111111 11111111 11111111 11111111 2147483647	in: int
// 10000000 00000000 00000000 00000001 -2147483647	in: int
// 10000000 00000000 00000000 00000001 2147483649	in: unsigned int
// 11111111 11111111 11111111 11111111 
