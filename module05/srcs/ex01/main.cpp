#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat Jack("Jack", 101);
        Form document("Tax Form", 100, 50);
        std::cout << Jack << std::endl;
        std::cout << document << std::endl;
        Jack.signForm(document);
    }   catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
