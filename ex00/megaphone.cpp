/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaitlhaj <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 14:54:19 by oaitlhaj          #+#    #+#             */
/*   Updated: 2025-08-09 14:54:19 by oaitlhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; av[i] != NULL; i++)
		{
			std::string str = av[i];
			for (int j = 0; str[j] != '\0'; j++)
				std::cout << (char)std::toupper(str[j]);
		}
		std::cout << "\n";
	}
	else
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE\n";
	return (0);
}
