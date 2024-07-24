#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <expression>" << std::endl;
        return (1);
    }

    RPN rpn;
    std::string expression(argv[1]);

    try {
        int result = rpn.evaluate(expression);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}
