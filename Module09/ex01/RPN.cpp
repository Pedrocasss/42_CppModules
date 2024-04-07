#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &rpn)
{
    *this = rpn;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &rpn)
{
    (void)rpn;
    return (*this);
}

int	checkLine(std::string line)
{
	for (size_t i = 0; i < line.length(); i++)
	{
		if (i % 2 == 0 && (!isdigit(line[i]) && line[i] != '/' && line[i] != '*' && line[i] != '-' && line[i] != '+'))
			return 1;
		if (i % 2 != 0 && line[i] != ' ')
			return 1;
	}
	return 0;
}

int	mul(std::stack<int> &stack)
{
	if (stack.size() < 2)
		return 1;
	int top = stack.top();
	stack.pop();
	int	top2 = stack.top();
	stack.pop();
	top2 *= top;
	stack.push(top2);
	return 0;
}

int	div(std::stack<int> &stack)
{
	if (stack.size() < 2)
		return 1;
	int top = stack.top();
	stack.pop();
	int	top2 = stack.top();
	stack.pop();
	if (top == 0)
		return 1;
	top2 /= top;
	stack.push(top2);
	return 0;
}

int	add(std::stack<int> &stack)
{
	if (stack.size() < 2)
		return 1;
	int top = stack.top();
	stack.pop();
	int	top2 = stack.top();
	stack.pop();
	top2 += top;
	stack.push(top2);
	return 0;
}

int	sub(std::stack<int> &stack)
{
	if (stack.size() < 2)
		return 1;
	int top = stack.top();
	stack.pop();
	int	top2 = stack.top();
	stack.pop();
	top2 -= top;
	stack.push(top2);
	return 0;
}

void	calculate(std::string line)
{
	std::stack<int> stack;

	for (size_t i = 0; i < line.length(); i++)
	{
		if (isdigit(line[i]))
			stack.push(line[i] - '0');
		if (line[i] == '*' && mul(stack))
		{
            error("invalid multiplication");
			return ;
		}
		if (line[i] == '/' && div(stack))
		{
            error("invalid division");
			return ;
		}
		if (line[i] == '+' && add(stack))
		{
            error("invalid addition");
			return ;
		}
		if (line[i] == '-' && sub(stack))
		{
            error("invalid subtraction");
			return ;
		}
	}
	if (stack.size() != 1)
		error("invalid input");
	else
		std::cout << "Result: " << stack.top() << std::endl;
}

void error(std::string message)
{
    std::cerr << "Error: " << message << std::endl;
    return ;
}