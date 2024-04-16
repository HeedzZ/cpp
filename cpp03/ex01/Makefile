# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 15:17:50 by ymostows          #+#    #+#              #
#    Updated: 2024/04/04 15:17:50 by ymostows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= scavtrap
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR = .objFiles

FILES		= main ClapTrap ScavTrap

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= ClapTrap.hpp ScavTrap.hpp

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(OPTS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all