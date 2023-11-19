#include "Phonebook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;

	system("clear");
	while (1)
	{
		std::cout << "Write a valid command(ADD, SEARCH or EXIT)" << std::endl;
		getline(std::cin, input);
		if (input == "ADD")
			phonebook.addAll();
		if (input == "SEARCH")
			phonebook.printTable();
		if (input == "EXIT")
			break ;
		std::cin.clear();
	}
}