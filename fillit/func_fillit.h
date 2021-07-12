/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_fillit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:50:38 by aljigmon          #+#    #+#             */
/*   Updated: 2019/04/23 18:17:57 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_FILLIT_H
# define FUNC_FILLIT_H

typedef struct	s_pieces
{
	int						type;
	char					a;
	struct s_pieces			*bfr;
	struct s_pieces			*next;
}				t_pieces;

void			ft_usage(int state, t_pieces *elem);
int				ft_check_squares(char *str);
int				ft_check_bars(char *str);
int				ft_check_bars_vertical(char *str);
int				ft_check_l(char *str);
int				ft_check_l_2(char *str);
int				ft_check_l_3(char *str);
int				ft_check_l_4(char *str);
int				ft_check_l_5(char *str);
int				ft_check_l_6(char *str);
int				ft_check_l_7(char *str);
int				ft_check_l_8(char *str);
int				ft_check_s(char *str);
int				ft_check_s_2(char *str);
int				ft_check_z(char *str);
int				ft_check_z_2(char *str);
int				ft_check_t(char *str);
int				ft_check_t_2(char *str);
int				ft_check_t_3(char *str);
int				ft_check_t_4(char *str);
int				ft_write_squares(char **tab, int i, int j);
int				ft_write_bars(char **tab, int i, int j);
int				ft_write_bars_vertical(char **tab, int i, int j);
int				ft_write_l(char **tab, int i, int j);
int				ft_write_l_2(char **tab, int i, int j);
int				ft_write_l_3(char **tab, int i, int j);
int				ft_write_l_4(char **tab, int i, int j);
int				ft_write_l_5(char **tab, int i, int j);
int				ft_write_l_6(char **tab, int i, int j);
int				ft_write_l_7(char **tab, int i, int j);
int				ft_write_l_8(char **tab, int i, int j);
int				ft_write_s(char **tab, int i, int j);
int				ft_write_s_2(char **tab, int i, int j);
int				ft_write_z(char **tab, int i, int j);
int				ft_write_z_2(char **tab, int i, int j);
int				ft_write_t(char **tab, int i, int j);
int				ft_write_t_2(char **tab, int i, int j);
int				ft_write_t_3(char **tab, int i, int j);
int				ft_write_t_4(char **tab, int i, int j);
void			ft_display_2d(char **tab);
t_pieces		*ft_create_elem_piece(int tp, char a);
void			ft_append_elem_piece(t_pieces *first, t_pieces *elem);
void			ft_free_list(t_pieces *elem);
char			**ft_solver(t_pieces *elem, int size, int i);
char			**ft_del(char **tab, char a, int *ip, int *jp);
void			ft_init_tab(char **tab, char c, int size);
void			ft_free_tab(char ***tab);
int				ft_sqrt_fillit(int nb);
char			**ft_cut_tab(char **tab);
int				ft_make_bigger(t_pieces *elem, char **tab);
t_pieces		*ft_read_file(const int fd, int *nb_p, t_pieces *tempo, char a);
t_pieces		*ft_get_first_elem(t_pieces *elem);

#endif
