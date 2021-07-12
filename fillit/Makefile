NAME = fillit
 
CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADERS = libft/libft.h

LIBFT = libft/libft.a

SRC = check_pieces_2_func_fillit.c \
	  check_pieces_3_func_fillit.c \
	  check_pieces_4_func_fillit.c \
	  check_pieces_func_fillit.c \
	  display_func_fillit.c \
	  free_func_fillit.c \
	  ft_cut_tab.c \
	  ft_init_tab.c \
	  ft_make_bigger.c \
	  ft_sqrt_fillit.c \
	  list_func_fillit.c \
	  main.c \
	  remove_piece_func_fillit.c \
	  solver_func_fillit.c \
	  write_pieces_2_func_fillit.c \
	  write_pieces_3_func_fillit.c \
	  write_pieces_4_func_fillit.c \
	  write_pieces_func_fillit.c \
	  read_func_fillit.c \
	  ft_get_first_elem.c

SRC_LIBFT = libft/ft_strcmp.c \
			libft/ft_putstr.c \
			libft/ft_putendl.c \
			libft/ft_putchar.c \
			libft/ft_strdel.c \
			libft/ft_strlen.c \
			libft/ft_memset.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): $(SRC_LIBFT) $(HEADERS)
	make -C libft

%.o: %.c func_fillit.h
	$(CC) $(CFLAGS) -o $@ -c $< -Ilibft/

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re:	fclean all
