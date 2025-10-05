# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: oaitlhaj <marvin@42.fr>                    #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-10-03 10:52:09 by oaitlhaj          #+#    #+#             #
#   Updated: 2025-10-03 10:52:09 by oaitlhaj         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=phonebook

SRC=main.cpp PhoneBook.cpp Contact.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp PhoneBook.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
