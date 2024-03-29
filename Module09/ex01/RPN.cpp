#include "RPN.hpp"

RPN::RPN()
{
    std::cout << "RPN constructor created" << std::endl;
}

RPN::~RPN()
{
    std::cout << "RPN destructor destroyed" << std::endl;
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return (*this);
}

int	checkLine(std::string line)
{
	for (size_t i = 0; i < line.length(); i++)
	{
		if (i % 2 == 0 && (!isdigit(line[i]) && line[i] != '/' && line[i] != '*' && line[i] != '-' && line[i] != '+'))
			return (1);
		if (i % 2 != 0 && line[i] != ' ')
			return (1);
	}
	return (0);
}

void error()
{
    std::cout << "Error." << std::endl;
    return ;
}

void calculate(std::string line)
{
    std::stack<int> stack;
    std::string token;
    std::string::size_type start = 0, end = 0;

    while ((end = line.find(' ', start)) != std::string::npos)
    {
        token = line.substr(start, end - start);
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
            stack.push(atoi(token.c_str()));
        else
        {
            if (stack.size() <= 1)
            {
                error();
                return ;
            }
            int top = stack.top();
            stack.pop();
            int top2 = stack.top();
            stack.pop();
            if (token == "*")
                top2 *= top;
            else if (token == "/")
            {
                if (top == 0)
                {
                    error();
                    return ;
                }
                top2 /= top;
            }
            else if (token == "+")
                top2 += top;
            else if (token == "-")
                top2 -= top;
            stack.push(top2);
        }
        start = end + 1;
    }

    token = line.substr(start);
    if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
        stack.push(atoi(token.c_str()));
    else
    {
        if (stack.size() <= 1)
            error();
        int top = stack.top();
        stack.pop();
        int top2 = stack.top();
        stack.pop();
        if (token == "*")
            top2 *= top;
        else if (token == "/")
        {
            if (top == 0)
            {
                error();
                return ;
            }
            top2 /= top;
        }
        else if (token == "+")
            top2 += top;
        else if (token == "-")
            top2 -= top;
        stack.push(top2);
    }

    if (stack.size() != 1)
        error();
    else
        std::cout << stack.top() << std::endl;
}