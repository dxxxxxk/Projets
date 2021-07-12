/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:11:18 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/12 17:22:24 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sasb(char *str, long long *tab, long long *tab2, int l)
{
	int		swap;

	swap = 0;
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0)
	{
		swap = ht(tab, l);
		if (swap == 0 || swap == 1)
			return ;
		swap = tab[l - swap];
		tab[l - ht(tab, l)] = tab[l - ht(tab, l) + 1];
		tab[l - ht(tab, l) + 1] = swap;
	}
	if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
	{
		swap = ht(tab2, l);
		if (swap == 0 || swap == 1)
			return ;
		swap = tab2[l - swap];
		tab2[l - ht(tab2, l)] = tab2[l - ht(tab2, l) + 1];
		tab2[l - ht(tab2, l) + 1] = swap;
	}
}

void	ft_papb(char *str, long long *tab, long long *tab2, int l)
{
	int		swap;

	swap = 0;
	if (ft_strcmp(str, "pa") == 0)
	{
		swap = ht(tab2, l);
		if (swap == 0)
			return ;
		else
		{
			tab[l - ht(tab, l) - 1] = tab2[l - swap];
			tab2[l - swap] = 9223372036854775;
		}
	}
	else if (ft_strcmp(str, "pb") == 0)
	{
		swap = ht(tab, l);
		if (swap == 0)
			return ;
		else
		{
			tab2[l - ht(tab2, l) - 1] = tab[l - swap];
			tab[l - swap] = 9223372036854775;
		}
	}
}

void	ft_rarra(char *str, long long *tab, long long *tab2, int l)
{
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0 ||
	ft_strcmp(str, "rb") == 0)
	{
		if (ft_strcmp(str, "ra") == 0)
			ft_rr(0, tab, tab2, l);
		if (ft_strcmp(str, "rb") == 0)
			ft_rr(1, tab, tab2, l);
		if (ft_strcmp(str, "rr") == 0)
			ft_rr(2, tab, tab2, l);
	}
	else if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0 ||
	ft_strcmp(str, "rrb") == 0)
	{
		if (ft_strcmp(str, "rra") == 0)
			ft_rrr(0, tab, tab2, l);
		if (ft_strcmp(str, "rrb") == 0)
			ft_rrr(1, tab, tab2, l);
		if (ft_strcmp(str, "rrr") == 0)
			ft_rrr(2, tab, tab2, l);
	}
}

void	ft_rr(int ab, long long *tab, long long *tab2, int l)
{
	int		swap;
	int		i;

	i = 0;
	if ((ab == 0 || ab == 2) && ht(tab, l) > 1)
	{
		swap = tab[l - ht(tab, l)];
		while (i + 1 < ht(tab, l))
		{
			tab[l - ht(tab, l) + i] = tab[l - ht(tab, l) + i + 1];
			i++;
		}
		tab[l - 1] = swap;
	}
	i = 0;
	if ((ab == 1 || ab == 2) && ht(tab2, l) > 1)
	{
		swap = tab2[l - ht(tab2, l)];
		while (i + 1 < ht(tab2, l))
		{
			tab2[l - ht(tab2, l) + i] = tab2[l - ht(tab2, l) + i + 1];
			i++;
		}
		tab2[l - 1] = swap;
	}
}

void	ft_rrr(int ab, long long *tab, long long *tab2, int l)
{
	int	swap;
	int	i;

	i = 0;
	if ((ab == 0 || ab == 2) && ht(tab, l) > 1)
	{
		swap = tab[l - 1];
		while (i + 1 < ht(tab, l))
		{
			tab[l - 1 - i] = tab[l - 2 - i];
			i++;
		}
		tab[l - ht(tab, l)] = swap;
	}
	i = 0;
	if ((ab == 1 || ab == 2) && ht(tab2, l) > 1)
	{
		swap = tab2[l - 1];
		while (i + 1 < ht(tab2, l))
		{
			tab2[l - 1 - i] = tab2[l - 2 - i];
			i++;
		}
		tab2[l - ht(tab2, l)] = swap;
	}
}
