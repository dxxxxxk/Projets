# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 17:36:20 by dieroyer          #+#    #+#              #
#    Updated: 2019/01/18 14:48:32 by dieroyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_lstdel.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_strstr.c \
	ft_lstdelone.c \
	ft_memset.c \
	ft_strclr.c \
	ft_strmap.c \
	ft_strsub.c \
	ft_atoi.c \
	ft_lstiter.c \
	ft_putchar.c \
	ft_strcmp.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_bzero.c \
	ft_lstmap.c \
	ft_putchar_fd.c \
	ft_strcpy.c \
	ft_strncat.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_lstnew.c \
	ft_putendl.c \
	ft_strdel.c \
	ft_strncmp.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_memalloc.c \
	ft_putendl_fd.c \
	ft_strdup.c \
	ft_strncpy.c \
	ft_isascii.c \
	ft_memccpy.c \
	ft_putnbr.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_isdigit.c \
	ft_memchr.c \
	ft_putnbr_fd.c \
	ft_striter.c \
	ft_strnew.c \
	ft_isprint.c \
	ft_memcmp.c \
	ft_putstr.c \
	ft_striteri.c \
	ft_strnstr.c \
	ft_itoa.c \
	ft_memcpy.c \
	ft_putstr_fd.c \
	ft_strjoin.c \
	ft_strrchr.c \
	ft_lstadd.c \
	ft_memdel.c \
	ft_strcat.c \
	ft_strlcat.c \
	ft_strsplit.c \
	ft_printf.c \
	ft_printf_f.c \
	ft_printf_f2.c \
	ft_putnbr_base.c \
	ft_printf_s.c \
	ft_getconv.c \
	ft_get.c \
	ft_set.c \
	ft_error.c \
	ft_getarg.c \
	ft_initialize.c \
	ft_nbrlen.c \
	ft_printnbr.c \
	ft_putspace.c \
	ft_printnbr_lh.c \
	ft_printnbr_hh.c \
	ft_utils.c \
	ft_power.c \
	ft_power2.c \
	get_next_line.c \
	ft_putlstr.c \
	ft_putstrw.c \
	ft_wstrlen.c 

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror ##-fsanitize=address #-g #-Ofast #-fsanitize=address

HEADER = libft.h ft_printf.h

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC) $(HEADER)	
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
