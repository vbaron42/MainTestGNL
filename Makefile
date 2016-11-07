# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/26 00:59:46 by vbaron            #+#    #+#              #
#    Updated: 2016/10/28 08:17:28 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	gnl
FLAGS	=	-Wall -Wextra -Werror
CC		=	gcc
SRC		=	get_next_line.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	cd libft/ && $(MAKE)
	$(CC) $(FLAGS) $(SRC) -L ./libft -lft -o $(NAME)
	cd libft/ && $(MAKE) fclean

%.o: %.c
	$(cc) $(FLAGS) -c $^ -o $@

norminette:
	norminette $(SRC)
	norminette get_next_line.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
