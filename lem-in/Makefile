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

NAME = lem-in

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address

HEADERS = libft/libft.h

LIBFT = libft/libft.a

SRC = main.c error.c error2.c print.c lemin.c tools.c algo.c bfs.c paths.c sort.c sort2.c combi.c print2.c algo2.c

OBJ = $(SRC:.c=.o)

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

$(LIBFT): $(HEADERS)
	 @printf "%-10s $(WHITE)%-15s$(RESET) %23s\n" "Linking" "Libft" "***"
	 @make -C libft

%.o: %.c
	 @if [ "$(J)" -eq "0" ]; then printf "%-10s $(WHITE)%-15s$(RESET) %23s\n" "Compiling" $(NAME) "***"; $(eval J = 1) fi
	 @$(eval PERCENT = $(shell echo $$(($(I) * 100 / $(NB3)))))
	 @$(CC) $(FLAGS) -o $@ -c $< -I $(LIBFT)
	 @if [ "$(I)" -le "8" ]; then printf "$(YELLOW)[ %3d%% ]   %s   %-15s\r$(RESET)" $(PERCENT) $(NAME) $(<F); $(eval J =$(shell echo $$(($(J)+1)))) fi
	 @if [ "$(I)" -gt "8" ]; then printf "$(YELLOW)[ %3d%% ]   %s   %-15s\r$(RESET)" $(PERCENT) $(NAME2) $(<F);  fi
	 @$(eval I = $(shell echo $$(($(I) + 1))))

clean :
	 @rm -f $(OBJ)
	 @make -C libft clean

fclean: clean
	 @rm -f $(LIBFT)
	 @rm -f $(NAME) $(NAME2)

re: fclean all