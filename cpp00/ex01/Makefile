# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 12:45:08 by marvin            #+#    #+#              #
#    Updated: 2024/01/24 12:45:08 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook

CC			=	c++

FLAG		=	 -Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			Contact.cpp \
			PhoneBook.cpp

OBJ			=	$(SRC:.cpp=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm  $(NAME)

re: fclean all

.PHONY: all clean fclean re