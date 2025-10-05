# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: oaitlhaj <marvin@42.fr>                    #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-10-05 13:48:48 by oaitlhaj          #+#    #+#             #
#   Updated: 2025-10-05 13:48:48 by oaitlhaj         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=Account

SRC=tests.cpp Account.cpp 
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Account.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
