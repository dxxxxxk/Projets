/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_func_fillit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:45:31 by aljigmon          #+#    #+#             */
/*   Updated: 2019/04/03 16:38:59 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_fillit.h"
#include <stdlib.h>
#include "libft.h"

static char	**ft_to_a(char **tab, char a)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				tab[i][j] = a;
			j++;
		}
		i++;
	}
	return (tab);
}

static int	ft_tab_func(int index, char **tab, int i, int j)
{
	int		(*f[19])(char**, int, int);

	f[0] = ft_write_squares;
	f[1] = ft_write_bars;
	f[2] = ft_write_bars_vertical;
	f[3] = ft_write_l;
	f[4] = ft_write_l_2;
	f[5] = ft_write_l_3;
	f[6] = ft_write_l_4;
	f[7] = ft_write_l_5;
	f[8] = ft_write_l_6;
	f[9] = ft_write_l_7;
	f[10] = ft_write_l_8;
	f[11] = ft_write_s;
	f[12] = ft_write_s_2;
	f[13] = ft_write_z;
	f[14] = ft_write_z_2;
	f[15] = ft_write_t;
	f[16] = ft_write_t_2;
	f[17] = ft_write_t_3;
	f[18] = ft_write_t_4;
	return (f[index](tab, i, j));
}

static int	ft_toward(char **tab, int *i, int *j)
{
	if (tab[*i][*j] == '\0')
	{
		(*i)++;
		if (tab[*i] == NULL)
			return (1);
		*j = 0;
	}
	return (0);
}

static char	**ft_solve(t_pieces *elem, char **tab, int i, int j)
{
	while (elem)
	{
		if (ft_toward(tab, &i, &j))
			break ;
		while (tab[i][j])
		{
			if (ft_tab_func(elem->type - 1, tab, i, j))
			{
				if (ft_solve(elem->next, ft_to_a(tab, elem->a), 0, 0) == NULL)
				{
					tab = ft_del(tab, elem->a, &i, &j);
					j++;
					break ;
				}
				return (tab);
			}
			j++;
		}
		if (elem && tab[i + 1] == NULL && tab[i][j] == '\0' && elem->bfr)
			return (NULL);
	}
	return (tab);
}

char		**ft_solver(t_pieces *elem, int size, int i)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(*tab) * size + 1)))
		return (NULL);
	tab[size] = NULL;
	while (i < size)
	{
		if (!(tab[i] = (char*)malloc(sizeof(**tab) * size + 1)))
		{
			if (i == 0)
			{
				free(tab);
				tab = NULL;
				return (tab);
			}
			while (i >= 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		tab[i++][size] = '\0';
	}
	ft_init_tab(tab, '.', size);
	return (ft_solve(elem, tab, 0, 0));
}
