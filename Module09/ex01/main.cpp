#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Example of usage : ./RPN '1 2 3 + *''" << std::endl;
		return 0;
	}
	if (checkLine(argv[1]))
		error("Invalid input");
	calculate(argv[1]);
}