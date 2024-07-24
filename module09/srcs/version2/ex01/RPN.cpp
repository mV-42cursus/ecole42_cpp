#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <climits>

RPN::RPN() {};
RPN::~RPN() {};

bool RPN::isOperator(const std::string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperation(int a, int b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            throw (std::runtime_error("Division by zero"));
        }
        return (a / b);
    }
    throw (std::runtime_error("Invalid operator"));
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::stack<int> values;

    int value;
    while (iss >> token) {
        if (isOperator(token)) {
            if (values.size() < 2) {
                throw (std::runtime_error("Insufficient operands for operation"));
            }
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            values.push(applyOperation(a, b, token));
        } else {
            std::stringstream ss(token);
            if (!(ss >> value)) {
                throw (std::runtime_error("Could not convert integer."));
            }
            if (value > RPN_MAX) {
                throw(std::runtime_error("Max value breached."));
            }
            values.push(value);
        }
    }
    if (values.size() != 1) {
        throw (std::runtime_error("The expression is malformed"));
    }
    return (values.top());
}
