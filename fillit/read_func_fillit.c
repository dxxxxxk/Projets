/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_func_fillit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:40:19 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/28 14:05:17 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "func_fillit.h"

static int		ft_checker(int (*f[])(char*), char *str)
{
	int		i;

	i = 0;
	while (i < 19)
	{
		if (f[i](str))
			return (i + 1);
		i++;
	}
	return (0);
}

static int		ft_check(char *str)
{
	int		(*f[19])(char*);

	f[0] = ft_check_squares;
	f[1] = ft_check_bars;
	f[2] = ft_check_bars_vertical;
	f[3] = ft_check_l;
	f[4] = ft_check_l_2;
	f[5] = ft_check_l_3;
	f[6] = ft_check_l_4;
	f[7] = ft_check_l_5;
	f[8] = ft_check_l_6;
	f[9] = ft_check_l_7;
	f[10] = ft_check_l_8;
	f[11] = ft_check_s;
	f[12] = ft_check_s_2;
	f[13] = ft_check_z;
	f[14] = ft_check_z_2;
	f[15] = ft_check_t;
	f[16] = ft_check_t_2;
	f[17] = ft_check_t_3;
	f[18] = ft_check_t_4;
	return (ft_checker(f, str));
}

static void		ft_check_rt_read(int rt, char *buf, t_pieces *elem, int *tmp_rt)
{
	if (rt == -1)
		ft_usage(1, elem);
	if (rt == 21)
		buf[rt - 1] = '\0';
	else
		buf[rt] = '\0';
	*tmp_rt = rt;
}

static t_pieces	*ft_create_list(int rt_check, char *a, int *nb_p)
{
	t_pieces	*elem;

	elem = NULL;
	if (!(elem = ft_create_elem_piece(rt_check, *a)))
		return (NULL);
	(*nb_p)++;
	if ((*nb_p) > 26)
		ft_usage(1, elem);
	(*a)++;
	return (elem);
}

t_pieces		*ft_read_file(const int fd, int *nb_p, t_pieces *tempo, char a)
{
	int			rt_read;
	t_pieces	*elem;
	char		buf[21];
	int			rt_check;
	int			tmp_rt_read;

	elem = NULL;
	tmp_rt_read = 0;
	while ((rt_read = read(fd, buf, 21)))
	{
		ft_check_rt_read(rt_read, buf, elem, &tmp_rt_read);
		if ((rt_check = ft_check(buf)))
		{
			if (!(elem = ft_create_list(rt_check, &a, nb_p)))
				ft_usage(2, tempo);
			ft_append_elem_piece(tempo, elem);
			tempo = elem;
		}
		else
			ft_usage(1, elem);
	}
	elem = ft_get_first_elem(elem);
	if (tmp_rt_read == 21)
		ft_usage(1, elem);
	return (elem);
}
