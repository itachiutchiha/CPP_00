/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaitlhaj <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-30 02:30:53 by oaitlhaj          #+#    #+#             */
/*   Updated: 2025-09-30 02:30:53 by oaitlhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
	
}

std::string	Contact::getFirstName()
{
	return (firstName);
}
void	Contact::setFirstName(std::string newFirstName)
{
	firstName = newFirstName;
}



std::string	Contact::getLastName()
{
	return (lastName);
}
void	Contact::setLastName(std::string newLastName)
{
	lastName = newLastName;
}



std::string	Contact::getNickName()
{
	return (nickName);
}
void	Contact::setNickName(std::string newNickName)
{
	nickName = newNickName;
}



std::string	Contact::getPhoneNumber()
{
	return (phoneNumber);
}
void	Contact::setPhoneNumber(std::string newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
}



std::string	Contact::getSecret()
{
	return (secret);
}
void	Contact::setSecret(std::string newSecret)
{
	secret = newSecret;
}
