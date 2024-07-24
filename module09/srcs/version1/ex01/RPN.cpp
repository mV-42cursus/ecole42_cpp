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

bool isNumeric(const std::string& token) {
    if (token.empty()) return (false);

    // Check if the first character is a digit or a minus/plus sign
    if (!std::isdigit(token[0]) && token[0] != '-' && token[0] != '+') {
        return (false);
    }

    // Check remaining characters to ensure they are all digits
    for (size_t i = 1; i < token.length(); i++) {
        if (!std::isdigit(token[i])) {
            return (false);
        }
    }
    return (true);
}

bool isOverValue(const std::string& token) {
    // -2147483648x
    // +2147483647x
    // 2147483647x
    if (token.length() >= 12) {
        return true;
    }

    long temp = atol(token.c_str());
    if (temp > RPN_MAX) {
        return true;
    } else if (temp > INT_MAX) {
        return true;
    } else if (temp < INT_MIN) {
        return true;
    }
    return false;
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::stack<int> values;

    while (iss >> token) {
        if (isOperator(token)) {
            if (values.size() < 2) {
                throw (std::runtime_error("Insufficient operands for operation"));
            }
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            values.push(applyOperation(a, b, token));
        } else {
            if (!isNumeric(token)) {
                throw (std::runtime_error("Invalid token: " + token));
            } else if (isOverValue(token)) {
                throw(std::runtime_error("Invalid token(out of range): " + token));
            }
            values.push(std::atoi(token.c_str()));
        }
    }
    if (values.size() != 1) {
        throw (std::runtime_error("The expression is malformed"));
    }
    return (values.top());
}
