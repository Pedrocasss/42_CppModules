#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
};

int checkLine(std::string line);
void calculate(std::string line);
int mul(std::stack <int> &stack);
int div(std::stack <int> &stack);
int add(std::stack <int> &stack);
int sub(std::stack <int> &stack);
void error(std::string message);

#endif