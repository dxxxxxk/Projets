# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:45:28 by dieroyer          #+#    #+#              #
#    Updated: 2018/11/08 18:46:01 by dieroyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	srcs/ft_putchar.c	\
		srcs/ft_putstr.c	\
		srcs/ft_strcmp.c	\
		srcs/ft_strlen.c	\
		srcs/ft_swap.c		\

OBJ =	ft_putchar.o		\
		ft_putstr.o			\
		ft_strcmp.o			\
		ft_strlen.o			\
		ft_swap.o			\

INCLUDE = includes/

FLAG = -Wall -Wextra -Werror -Iincludes

all:
	@gcc $(FLAG) -c $(SRC)
	@ar rc libft.a $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
