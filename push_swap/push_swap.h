/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:56:03 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/16 14:46:21 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include <fcntl.h>

typedef struct	s_push
{
	int		l;
	int		fd;
	int		i;
	int		mediane;
	int		x;
	int		k;
	int		x2;
	int		x3;
	int		x4;
	int		x5;
	int		x6;
}				t_push;

int				ft_space(char **av, t_push *p);
void			ft_domed(long long *tab, long long *stab, t_push *p);
int				ft_med(long long *tab, long long *stab, t_push *p, int i);
int				ft_strrlen(char **str);
long long		*ft_clean(char **str);
void			ft_50(int *tab, int *tab2, t_push p);
t_push			ft_init(int l, int fd);
void			push_swap(int ac, char **av);
int				ft_print_ok(long long *tab, int l);
void			ft_print_tab(long long *tab, long long *tab2, int l);
void			ft_mvp(char *str, long long *tab, long long *tab2, t_push p);
void			ft_rush_min(long long *tab, long long *tab2, t_push p);
int				ft_conditionsb(long long *tab2, t_push p, int nb);
int				ft_cond(long long *tab, long long *tab2, t_push p, int nb);
int				ft_conditions(long long *tab, t_push p, int nb);
void			ft_condtions2(long long *tab, long long *tab2, t_push p);
void			check(int ac, char **av, int *l, long long *tab);
void			check2(char **str, long long *tab, int *l);
void			ft_papb(char *str, long long *tab, long long *tab2, int l);
int				mn(long long *tab, int l, int min);
int				mx(long long *tab, int l, int max);
void			ft_print_fd(long long *tab, long long *tab2, t_push tmp);
void			ft_fill_b(long long *tab2, int l);
long long		*fill_tab(int ac, char **av, t_push *p);
int				ht(long long *tab, int l);
int				ft_error_tab(int ac, char **av, char **str);
int				ft_move_compare(char *str, long long *tab, long long *tab2,
				int l);
void			ft_rarrra(char *str, long long *tab, long long *tab2,
				unsigned long l);
void			ft_rr(int ab, long long *tab, long long *tab2, int l);
void			ft_rrr(int ab, long long *tab, long long *tab2, int l);
int				ft_double(int l, long long *tab);
int				ft_sorted(long long *tab, int l);
void			ft_sort3(long long *tab, long long *tab2, int i, t_push p);
void			ft_sort4(long long *tab, long long *tab2, t_push p);
void			ft_sort5(long long *tab, long long *tab2, t_push p);
void			ft_sort_5(long long *tab, long long *tab2, t_push p);
long long		*ft_sort_int_tab(long long *tab, int l);
void			ft_sort_50(long long *tab, long long *tab2, t_push p);
void			ft_500(long long *tab, long long *tab2, t_push p);
void			ft_sorta(long long *tab, long long *tab2, t_push p);
void			ft_sortb(long long *tab, long long *tab2, t_push p);
void			ft_special_move(long long *tab, long long *tab2, int move,
				t_push p);
void			ft_raorrraa(long long *tab, long long *tab2, t_push *p,
				int min);
void			init_x(t_push *p, long long *tab);
void			ft_mediane(long long *tab, t_push *p);
int				ft_mid(long long *tab, t_push p);
int				dm(long long *tab, t_push p, int pos_min1234);
void			ft_pushonb_mediane(long long *tab, long long *tab2, t_push p);
int				valeur_abs(int nb);
int				ft_resolution(long long *tab, long long *tab2, int l, int fd);
void			call(long long *tab, long long *tab2, t_push p);
void			call2(long long *tab, long long *tab2, t_push p);
void			ft_rarra(char *str, long long *tab, long long *tab2, int l);
void			ft_papb(char *str, long long *tab, long long *tab2, int l);
void			ft_sasb(char *str, long long *tab, long long *tab2, int l);
void			ft_conditions2(long long *tab, long long *tab2, t_push p);
void			ft_raorrrab(long long *tab, long long *tab2, t_push *p,
				int max);

#endif
