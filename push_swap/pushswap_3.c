/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:17 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:54:19 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_cond(long long *tab, long long *tab2, t_push p, int nb)
{
	if ((nb == 2) && (((p.x + p.x2 + p.x3 + p.x4 + p.x5 + p.x6) == 6) ||
	(p.x == 1 && (p.x2 + p.x3 + p.x4 + p.x5 + p.x6) == 0) ||
	(p.x == 1 && p.x2 == 1 && (p.x3 + p.x4 + p.x5 + p.x6) == 0)))
		return (1);
	if ((nb == 2) && (p.l - ht(tab, p.l) + 5 < p.l))
	{
		if ((tab[p.l - ht(tab, p.l) + 5] == tab[p.l - ht(tab, p.l) + 4] + 1 &&
		tab[p.l - ht(tab, p.l) + 4] == tab[p.l - ht(tab, p.l) + 3] + 1 &&
		tab[p.l - ht(tab, p.l) + 3] == tab[p.l - ht(tab, p.l) + 2] + 1 &&
		tab[p.l - ht(tab, p.l) + 2] == tab[p.l - ht(tab, p.l) + 1] + 1 &&
		tab[p.l - ht(tab, p.l) + 1] == tab[p.l - ht(tab, p.l)] + 1))
			return (1);
	}
	if ((nb != 2) && ((p.x + p.x2 + p.x3 + p.x4 + p.x5 + p.x6 == 6) ||
	(p.x == 1 && p.x2 + p.x3 + p.x4 + p.x5 + p.x6 == 0) ||
	(p.x == 1 && p.x2 == 1 && p.x3 + p.x4 + p.x5 + p.x6 == 0) || (
	(tab2[p.l - ht(tab2, p.l) + 5] + 1 ==
	tab2[p.l - ht(tab2, p.l) + 4] && tab2[p.l - ht(tab2, p.l) + 4] + 1 ==
	tab2[p.l - ht(tab2, p.l) + 3] && tab2[p.l - ht(tab2, p.l) + 3] + 1 ==
	tab2[p.l - ht(tab2, p.l) + 2] && tab2[p.l - ht(tab2, p.l) + 2] + 1 ==
	tab2[p.l - ht(tab2, p.l) + 1] && tab2[p.l - ht(tab2, p.l) + 1] + 1 ==
	tab2[p.l - ht(tab2, p.l)] + 1 && p.l - ht(tab2, p.l) + 5 < p.l))))
		return (1);
	return (0);
}

void	ft_sorta_2(long long *tab, long long *tab2, t_push p, int *nb)
{
	while (ht(tab, p.l) > 4 && p.k == 0)
	{
		if (ft_cond(tab, tab2, p, 1))
			init_x(&p, tab);
		if (ft_conditions(tab, p, 1))
			ft_raorrraa(tab, tab2, &p, 6);
		else if (ft_conditions(tab, p, 2))
			ft_raorrraa(tab, tab2, &p, 5);
		else if (ft_conditions(tab, p, 3))
			ft_raorrraa(tab, tab2, &p, 4);
		else if (ft_conditions(tab, p, 4))
			ft_raorrraa(tab, tab2, &p, 3);
		else if (ht(tab, p.l) > 5 && dm(tab, p, mn(tab, p.l, 2)) >
		dm(tab, p, mn(tab, p.l, 1)) &&
		p.x2 < 5 - (p.x3 + p.x4 + p.x + p.x5 + p.x6))
			ft_raorrraa(tab, tab2, &p, 2);
		else
			ft_raorrraa(tab, tab2, &p, 1);
		ft_conditions2(tab, tab2, p);
		*nb = *nb + 1;
		if (ft_sorted(tab, p.l) == 1 && p.x4 == 0 && p.x3 == 0 && p.x2 == 0
		&& p.x5 == 0 && p.x6 == 0)
			p.k = 1;
	}
}

void	ft_sorta(long long *tab, long long *tab2, t_push p)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	init_x(&p, tab);
	if (ft_sorted(tab, p.l))
		return ;
	p.k = 0;
	ft_sorta_2(tab, tab2, p, &nb);
	if (ht(tab, p.l) == 3)
		ft_sort3(tab, tab2, p.l - ht(tab, p.l), p);
	else
		ft_sort4(tab, tab2, p);
	while (i < nb)
	{
		ft_mvp("pa\n", tab, tab2, p);
		if (tab[p.l - ht(tab, p.l) + 1] < tab[p.l - ht(tab, p.l)])
			ft_mvp("sa\n", tab, tab2, p);
		i++;
	}
}

void	ft_sortb(long long *tab, long long *tab2, t_push p)
{
	init_x(&p, tab);
	while (ht(tab2, p.l) > 2)
	{
		if (ft_cond(tab, tab2, p, 2))
			init_x(&p, tab);
		if (ft_conditionsb(tab2, p, 1) || ft_conditionsb(tab2, p, 2))
			ft_raorrrab(tab, tab2, &p, 5);
		else if (ft_conditionsb(tab2, p, 3))
			ft_raorrrab(tab, tab2, &p, 4);
		else if (ft_conditionsb(tab2, p, 4))
			ft_raorrrab(tab, tab2, &p, 3);
		else if (ht(tab2, p.l) > 3 &&
		dm(tab2, p, mx(tab2, p.l, 2)) > dm(tab2, p, mx(tab2, p.l, 1)) &&
		p.x2 < 5 - (p.x3 + p.x4 + p.x + p.x5 + p.x6))
			ft_raorrrab(tab, tab2, &p, 2);
		else
			ft_raorrrab(tab, tab2, &p, 1);
		ft_rush_min(tab, tab2, p);
	}
	if (tab2[mx(tab2, p.l, 1)] != tab2[p.l - ht(tab2, p.l)])
		ft_mvp("sb\n", tab, tab2, p);
	while (0 < ht(tab2, p.l))
		ft_mvp("pa\n", tab, tab2, p);
}
