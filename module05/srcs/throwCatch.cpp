#include <iostream>

void processNumber(int num) {
    try {
        if (num == 0) {
            throw "Number is zero";
        } else if (num < 0) {
            throw std::string("Number is negative");
        }
        std::cout << "Number is valid: " << num << std::endl;
    } catch (const char* msg) {
        std::cerr << "Caught exception: " << msg << std::endl;
    } catch (const std::string& msg) {
        std::cerr << "Caught exception: " << msg << std::endl;
    }
}

int main() {
    processNumber(10); // Number is valid: 10
    processNumber(-5); // Caught exception: Number is negative
    processNumber(0);  // Caught exception: Number is zero
    return 0;
}