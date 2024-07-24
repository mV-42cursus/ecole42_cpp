#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat Max("Amy", 150);
        std::cout << "Bureaucrat: " << Max.getName() << ", Grade: " << Max.getGrade() << std::endl;
        Max.incrementGrade();
        std::cout << "After incrementing grade: " << Max.getName() << ", Grade: " << Max.getGrade() << std::endl;
    }   catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
	try {
        Bureaucrat Min("Bob", 1);
        std::cout << "Bureaucrat: " << Min.getName() << ", Grade: " << Min.getGrade() << std::endl;
		Min.decrementGrade();
        std::cout << "After decrementing grade: " << Min.getName() << ", Grade: " << Min.getGrade() << std::endl;
    }   catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
	return 0;
}
