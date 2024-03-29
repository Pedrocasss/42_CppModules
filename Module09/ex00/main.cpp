#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./btc <file.txt>" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange xChange(av[1]);
	} catch (BitcoinExchange::badCsvFile &e) {
		std::cerr << e.what() << std::endl;
	} catch (BitcoinExchange::badInputFile &e) {
		std::cerr << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}