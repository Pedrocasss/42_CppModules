/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:24:41 by psoares-          #+#    #+#             */
/*   Updated: 2023/11/19 18:24:42 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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