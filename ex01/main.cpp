/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaitlhaj <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-02 18:25:04 by oaitlhaj          #+#    #+#             */
/*   Updated: 2025-10-02 18:25:04 by oaitlhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	print_spaces(int len)
{
	for (int i = 0; i < len; i++)
		std::cout << " ";
	std::cout << " ";
}

void	print_user_info(std::string str)
{
	if (str.length() <= 15)
	{
		std::cout << "| " << str;
		print_spaces(15 - str.length());
	}
	else
		std::cout << "| " << str.substr(0, 12) << "... ";
}

std::string	getUserInfo(std::string msg)
{
	std::string userData;
	do 
	{
	    std::cout << msg;
	    if (!std::getline(std::cin, userData)) 
	    {
	        std::cout << "\n";
	        exit(1);
	    }
	    if (userData.empty())
	        std::cout << "INVALID: EMPTY DATA\n";

	} while (userData.empty());

return userData;

}

int main()
{
	PhoneBook phonebook;
	std::string input;
	std::cout << "CHOOSE -> (ADD, PRINT, SEARCH, EXIT): ";
	while (1)
	{
		if (!std::getline(std::cin, input))
		{
			std::cout << "\n";
			exit(1);
		}
		if (input == "EXIT")
			phonebook.exit();
		else if (input == "ADD")
			phonebook.add();

		else if (input == "SEARCH")
			phonebook.search();
		else
			std::cout << "YOUR INPUT IS INVALID\n";
		std::cout << "CHOOSE -> (ADD, PRINT, SEARCH, EXIT): ";
	}

}
