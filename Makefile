# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/26 00:59:46 by vbaron            #+#    #+#              #
#    Updated: 2016/11/13 05:51:01 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	gnl
FLAGS	=	-Wall -Wextra -Werror
CC		=	clang
SRC		=	get_next_line.c main.c

all:		$(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	$(CC) $(FLAGS) -I libft/includes -o get_next_line.o -c get_next_line.c
	$(CC) $(FLAGS) -I libft/includes -o main.o -c main.c
	$(CC) -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

norminette:
	norminette $(SRC)
	norminette get_next_line.h

clean:
	rm -f main.o
	rm -f get_next_line.o

fclean: clean
	rm -f $(NAME)

re: fclean all
