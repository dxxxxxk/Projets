# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 15:54:49 by rchaigno          #+#    #+#              #
#    Updated: 2019/10/15 15:54:52 by rchaigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED =		\033[0;31m
BRED =		\033[1;31m
GREEN =		\033[0;32m
BGREE =		\033[1;32m
YELLOW =	\033[0;33m
BLUE =		\033[0;34m
PINK =		\033[0;35m
CYAN =		\033[0;36m
RESET =		\033[0m
WHITE =		\033[1m

NAME      = libft.a

CC        = gcc

C_FLAGS   = -Wall -Wextra -Werror

HEADER    = libft.h

FILES = ft_atoi.c		\
		ft_atol.c		\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strdup.c		\
		ft_strndup.c	\
		ft_strlen.c		\
		ft_swap.c		\
		ft_swap_str.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_isprint.c	\
		ft_isascii.c	\
		ft_isalpha.c	\
		ft_isalnum.c	\
		ft_isdigit.c	\
		ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_putchar.c	\
		ft_putstr.c		\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		get_next_line.c \
		ft_printf.c				\
		ft_check.c				\
		ft_opt.c				\
		ft_print_c.c			\
		ft_print_f.c			\
		ft_print_s.c			\
		ft_print_conv.c			\
		ft_opt_s.c				\
		ft_print_p.c			\
		ft_print_d.c			\
		ft_print_o.c			\
		ft_print_u.c			\
		ft_print_xx.c			\
		ft_print_all.c			\
		ft_print_x.c			\
		ft_operation_d.c	 	\
		ft_operation_p.c	 	\
		ft_operation_s.c	 	\
		ft_operation_u.c	 	\
		ft_operation_o.c	 	\
		ft_operation_x.c	 	\
		ft_operation_xx.c	 	\
		ft_norme.c				\
		ft_nnorme.c				\
		ft_union.c				\
		ft_itoa_num.c

OBJ = $(patsubst %.c, %.o, $(notdir $(FILES)))

NB = $(words $(FILES))

I = 0
J = 0

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)[ 100%% ]   Compiling   $(BGREE)%-16s$(RESET) %10s\n\n$(RESET)" $(NAME) "done ---"
	@echo "$(BLUE)-------------- [ $(CYAN)EVERYTHING IS OK$(BLUE) ] --------------$(RESET)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@if [ "$(J)" -eq "0" ]; then printf "%-10s $(WHITE)%-15s$(RESET) %23s\n" "Compiling" $(NAME) "***"; $(eval J = 1) fi
	@$(eval PERCENT = $(shell echo $$(($(I) * 100 / $(NB)))))
	@gcc -c -o $@ $< $(C_FLAGS)
	@printf "$(YELLOW)[ %3d%% ]   %s   %-15s\r$(RESET)" $(PERCENT) $(NAME) $(<F)
	@$(eval I = $(shell echo $$(($(I) + 1))))

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
