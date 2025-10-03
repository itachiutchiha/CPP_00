/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaitlhaj <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-02 18:24:54 by oaitlhaj          #+#    #+#             */
/*   Updated: 2025-10-02 18:24:54 by oaitlhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	isFull = 0;
}

int	PhoneBook::getFullVar()
{
	return (isFull);
}

void	PhoneBook::setFullVar(int newIsFull)
{
	isFull = newIsFull;
}

int	PhoneBook::getIndex()
{
	return (index);
}

void	PhoneBook::setIndex(int newIndex)
{
	index = newIndex;
}
void	PhoneBook::incrementIndex()
{
	index++;
}
void	PhoneBook::add()
{
	this->contacts[this->getIndex()].setFirstName(getUserInfo("Enter Your First Name: "));
	this->contacts[this->getIndex()].setLastName(getUserInfo("Enter Your Last Name: "));
	this->contacts[this->getIndex()].setNickName(getUserInfo("Enter Your Nick Name: "));
	this->contacts[this->getIndex()].setPhoneNumber(getUserInfo("Enter Your  Phone Number: "));
	this->contacts[this->getIndex()].setSecret(getUserInfo("Enter Your Secret: "));
	this->incrementIndex();
	
	if (this->getIndex() == 8)
	{
		this->setFullVar(1);
		this->setIndex(0);
	}
}
void	PhoneBook::exit()
{
	std::cout << "EXIT\n";
	std::exit(0);
}
void	PhoneBook::search()
{
		std::string input;
		if (this->getIndex() == 0 && this->getFullVar() == 0)
			std::cout << "THE PHONEBOOK IS EMPTY\n";
		else
		{
			std::cout << " ----- | --------------- | --------------- | --------------- | --------------- | --------------- |\n";
			std::cout << " index | first name      | last name       | nick name       | phone number    | scret           |\n";
			if (this->getFullVar())
			{
				for (int i = 0; i < 8; i++)
				{
					std::cout << " ----- | --------------- | --------------- | --------------- | --------------- | --------------- |\n";
					std::cout << "   " << i+1 << "   ";
					print_user_info(this->contacts[i].getFirstName());
					print_user_info(this->contacts[i].getLastName());
					print_user_info(this->contacts[i].getNickName());
					print_user_info(this->contacts[i].getPhoneNumber());
					print_user_info(this->contacts[i].getSecret());
					std::cout << "|\n";
				}
			}
			else
			{
				for (int i = 0; i < this->getIndex(); i++)
				{
					std::cout << " ----- | --------------- | --------------- | --------------- | --------------- | --------------- |\n";
					std::cout << "   " << i+1 << "   ";
					print_user_info(this->contacts[i].getFirstName());
					print_user_info(this->contacts[i].getLastName());
					print_user_info(this->contacts[i].getNickName());
					print_user_info(this->contacts[i].getPhoneNumber());
					print_user_info(this->contacts[i].getSecret());
					std::cout << "|\n";
				}
			}
			int j;
			int stop = 0;
			do{
				std::cout << "ENTER AN INDEX BETWEEN";
				if (this->getFullVar() == 1)
					std::cout << "(1 -> 8), IF YOU WANT TO GO BACK PRESS (EXIT): ";
				else
					std ::cout << "(1 -> " << this->getIndex()<< "), IF YOU WANT TO GO BACK PRESS (EXIT): ";
				if (!std::getline(std::cin, input))
				{
					std::cout << "\n";
					std::exit(0);
				}
				if (input == "EXIT")
					break ;
				if (input.length() != 1)
					std::cout << "INVALID INDEX\n";
				else
				{
					j = input[0] - 48;
					if (j <= 0 || (j > this->getIndex() && this->getFullVar() == 0) || (this->getFullVar() == 1 && j > 8))
						std::cout << "INVALID INDEX\n";
					else
						stop = 1;
				}
			}while(!stop);
			if (stop == 1)
			{
				std::cout << " ----- | --------------- | --------------- | --------------- | --------------- | --------------- |\n";
				std::cout << " index | first name      | last name       | nick name       | phone number    | scret           |\n";
				std::cout << "   " << j << "   ";
				print_user_info(this->contacts[j-1].getFirstName());
				print_user_info(this->contacts[j-1].getLastName());
				print_user_info(this->contacts[j-1].getNickName());
				print_user_info(this->contacts[j-1].getPhoneNumber());
				print_user_info(this->contacts[j-1].getSecret());
				std::cout << "|\n";
			}
		}
}
