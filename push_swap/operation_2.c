/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:53:25 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:53:27 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ht(long long *tab, int l)
{
	long long	i;
	int			haut;

	i = l - 1;
	haut = 0;
	while (i >= 0 && tab[i] != 9223372036854775)
	{
		i--;
		haut++;
	}
	return (haut);
}

void		check(int ac, char **av, int *l, long long *tab)
{
	int		i;

	i = 0;
	while (i + 1 < ac)
	{
		tab[i] = ft_atol(av[i + 1]);
		*l = *l + 1;
		i++;
	}
}

int			ft_strrlen(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i = i + 1;
	return (i);
}

void		check2(char **str, long long *tab, int *l)
{
	int		i;

	i = 0;
	while (str[i])
	{
		tab[i] = ft_atol(str[i]);
		*l = *l + 1;
		i++;
	}
}

long long	*ft_clean(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	return (0);
}
