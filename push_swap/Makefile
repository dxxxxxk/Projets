# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 12:30:35 by dieroyer          #+#    #+#              #
#    Updated: 2019/10/18 15:45:35 by rchaigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED =	\033[0;31m
BRED =	\033[1;31m
GREEN =	\033[0;32m
BGREE =	\033[1;32m
YELLOW =\033[0;33m
BLUE =	\033[0;34m
PINK =	\033[0;35m
CYAN =	\033[0;36m
RESET =	\033[0m
WHITE =	\033[1m

NAME = checker
NAME2 = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -fsanitize=address

HEADERS = libft/libft.h

LIBFT = libft/libft.a

SRC = main_checker.c operation.c pushswap.c operation_2.c error.c mid.c mid_2.c sorted.c print.c sorted_2.c operation_3.c pushswap_2.c pushswap_3.c

SRC2 = main_push_swap.c pushswap.c operation.c operation_2.c error.c mid.c mid_2.c sorted.c print.c sorted_2.c operation_3.c pushswap_2.c pushswap_3.c

SRC_LIBFT = libft/ft_atoi.c libft/ft_strcmp.c

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)

NB = $(words $(SRC))
NB3 = $(shell echo $$(( $(NB) + 1)))

I =	0
K = 0
J =	0

all: $(LIBFT) $(NAME) $(NAME2) $(NAME3)

$(NAME): $(LIBFT) $(OBJ)
	 @if [ "$(J)" -eq "0" ]; then printf "%-10s $(WHITE)%-15s$(RESET) %23s\n" "Compiling" $(NAME) "***"; $(eval J = 1) fi
	 @$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	 @printf "$(GREEN)[ 100%% ]   Compiling   $(BGREE)%-16s$(RESET) %10s\n\n$(RESET)" $(NAME) "done ---"
	 @echo "$(BLUE)-------------- [ $(CYAN)EVERYTHING IS OK$(BLUE) ] --------------$(RESET)"

$(NAME2): $(LIBFT) $(OBJ2)
	 @if [ "$(K)" -eq "0" ]; then printf "%-10s $(WHITE)%-15s$(RESET) %23s\n" "Compiling" $(NAME2) "***"; $(eval K = 1) fi
	 @$(CC) $(FLAGS) -o $(NAME2) $(OBJ2) $(LIBFT)
	 @printf "$(GREEN)[ 100%% ]   Compiling   $(BGREE)%-16s$(RESET) %10s\n\n$(RESET)" $(NAME2) "done ---"
	 @echo "$(BLUE)-------------- [ $(CYAN)EVERYTHING IS OK$(BLUE) ] --------------$(RESET)"

$(LIBFT): $(SRC_LIBFT) $(HEADERS)
	 @printf "%-10s $(WHITE)%-15s$(RESET) %23s\n" "Linking" "Libft" "***"
	 @make -C libft

%.o: %.c push_swap.h
	 @if [ "$(J)" -eq "0" ]; then printf "%-10s $(WHITE)%-15s$(RESET) %23s\n" "Compiling" $(NAME) "***"; $(eval J = 1) fi
	 @$(eval PERCENT = $(shell echo $$(($(I) * 100 / $(NB3)))))
	 @$(CC) $(FLAGS) -o $@ -c $< -I $(LIBFT)
	 @if [ "$(I)" -le "8" ]; then printf "$(YELLOW)[ %3d%% ]   %s   %-15s\r$(RESET)" $(PERCENT) $(NAME) $(<F); $(eval J =$(shell echo $$(($(J)+1)))) fi
	 @if [ "$(I)" -gt "8" ]; then printf "$(YELLOW)[ %3d%% ]   %s   %-15s\r$(RESET)" $(PERCENT) $(NAME2) $(<F);  fi
	 @$(eval I = $(shell echo $$(($(I) + 1))))

clean :
	 @rm -f $(OBJ) $(OBJ2)
	 @make -C libft clean

fclean: clean
	 @rm -f $(LIBFT)
	 @rm -f $(NAME) $(NAME2)

re: fclean all
