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
}

void	print_user_info(std::string str)
{
	if (str.length() <= 10)
	{
		std::cout <<  "|";
		print_spaces(10 - str.length());
		std::cout <<  str;
	}
	else
		std::cout << "|" << str.substr(0, 9) << ".";
}

bool	isOnlySpaces(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isspace(str[i]))
			return (false);
	}
	return (true);
}
bool	isNonPrintavle(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 32 && str[i] < 127)
			return (false);
	}
	return (true);
}

bool	isNumber(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (false);
	}
	return (true);
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
		else if (userData.empty())
	        std::cout << "INVALID: EMPTY DATA\n";
		else if (isOnlySpaces(userData))
	        std::cout << "INVALID: CONTAIN ONLY SPACES\n";
		else if (isNonPrintavle(userData))
	        std::cout << "INVALID: NON PRINTABLE CHARACTERE\n";
		else if (msg == "Enter Your  Phone Number: " && !isNumber(userData))
	        std::cout << "INVALID: PHONE NUMBER CAN CONTAIN ONLY DIGITS\n";
	} while (userData.empty() || isOnlySpaces(userData) || isNonPrintavle(userData) || (msg == "Enter Your  Phone Number: " && !isNumber(userData)));

return userData;

}

void	printUserData(Contact contact, int index)
{
	std::cout << "|         " << index;
	print_user_info(contact.getFirstName());
	print_user_info(contact.getLastName());
	print_user_info(contact.getNickName());
	print_user_info(contact.getPhoneNumber());
	print_user_info(contact.getSecret());
	std::cout << "|\n";
}

void	printTableHeader()
{
	std::cout << "|----------|----------|----------|----------|----------|----------|\n";
	std::cout << "|   index  |first name|last name | nick name|  number  |   scret  |\n";
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
