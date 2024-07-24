#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

#define RPN_MAX 9

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define DEF_COLOR "\033[0;39m"
#define LF "\e[1K\r"

class RPN
{
private:
    bool    isOperator(const std::string& token);
    int     applyOperation(int a, int b, const std::string& op);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
public:
    RPN();
    ~RPN();
    int     evaluate(const std::string& expression);
};

#endif
