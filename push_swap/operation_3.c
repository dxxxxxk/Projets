/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:53:34 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/18 15:43:15 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_fill_b(long long *tab2, int l)
{
	int		i;

	i = 0;
	while (i < l)
	{
		tab2[i] = 9223372036854775;
		i++;
	}
}

long long	*fill_tab(int ac, char **av, t_push *p)
{
	char		**str;
	long long	*tab;

	if (ft_space(av, p))
		return (0);
	str = ft_strsplit(av[1], ' ');
	if (ft_error_tab(ac, av, str) == 1)
		return ((long long *)ft_clean(str));
	if (ac == 2)
	{
		if (!(tab = (long long*)malloc(ft_strrlen(str) * sizeof(long long))))
			return ((long long *)ft_clean(str));
		check2(str, tab, &(p->l));
	}
	else
	{
		if (!(tab = (long long*)malloc((ac - 1) * sizeof(long long))))
			return ((long long *)ft_clean(str));
		check(ac, av, &(p->l), tab);
	}
	ft_clean(str);
	if (ft_double(p->l, tab))
		return (0);
	return (tab);
}

int			ft_double(int l, long long *tab)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (j + 1 < l)
	{
		while (i < l)
		{
			if (tab[j] == tab[i])
				return (1);
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}

int			ft_move_compare(char *str, long long *tab, long long *tab2, int l)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0 ||
	ft_strcmp(str, "sb") == 0)
		ft_sasb(str, tab, tab2, l);
	else if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0)
		ft_papb(str, tab, tab2, l);
	else if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rb") == 0 ||
	ft_strcmp(str, "rr") == 0 || ft_strcmp(str, "rra") == 0 ||
	ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0)
		ft_rarra(str, tab, tab2, l);
	else
		return (1);
	return (0);
}

int			ft_resolution(long long *tab, long long *tab2, int l, int fd)
{
	t_push	p;

	p = ft_init(l, fd);
	if (ft_sorted(tab, l))
		return (0);
	if (l <= 5)
		ft_sort_5(tab, tab2, p);
	else
		ft_sort_50(tab, tab2, p);
	return (0);
}
