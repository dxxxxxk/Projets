/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:25 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:54:27 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_50(long long *tab, long long *tab2, t_push p)
{
	if (p.l <= 50 && p.l > 7)
		ft_pushonb_mediane(tab, tab2, p);
	else if (p.l == 6 || p.l == 7)
	{
		if (p.l == 7)
		{
			ft_raorrraa(tab, tab2, &p, 1);
			ft_mvp("pb\n", tab, tab2, p);
		}
		ft_raorrraa(tab, tab2, &p, 1);
		ft_mvp("pb\n", tab, tab2, p);
		ft_sort5(tab, tab2, p);
		ft_mvp("pa\n", tab, tab2, p);
		if (p.l == 7)
			ft_mvp("pa\n", tab, tab2, p);
		return ;
	}
	else
		ft_500(tab, tab2, p);
	ft_sorta(tab, tab2, p);
	ft_sortb(tab, tab2, p);
}

void	ft_sort3(long long *tab, long long *tab2, int i, t_push p)
{
	if (tab[i] < tab[i + 1] && tab[i] < tab[i + 2])
		ft_mvp("sa\nra\n", tab, tab2, p);
	else if (tab[i] > tab[i + 1] && tab[i] < tab[i + 2])
		ft_mvp("sa\n", tab, tab2, p);
	else if (tab[i] < tab[i + 1] && tab[i] > tab[i + 2])
		ft_mvp("rra\n", tab, tab2, p);
	else if (tab[i] > tab[i + 1] && tab[i] > tab[i + 2]
	&& tab[i + 1] < tab[i + 2])
		ft_mvp("ra\n", tab, tab2, p);
	else
		ft_mvp("sa\nrra\n", tab, tab2, p);
}

void	ft_sort4(long long *tab, long long *tab2, t_push p)
{
	if (ft_sorted(tab, p.l))
		return ;
	if (mn(tab, p.l, 1) == 0 + p.l - ht(tab, p.l))
	{
		call(tab, tab2, p);
		return ;
	}
	else if (mn(tab, p.l, 1) == 1 + p.l - ht(tab, p.l))
	{
		ft_mvp("sa\n", tab, tab2, p);
		if (ft_sorted(tab, p.l))
			return ;
		call(tab, tab2, p);
	}
	else
	{
		if (mn(tab, p.l, 1) == 2 + p.l - ht(tab, p.l))
			ft_mvp("rra\n", tab, tab2, p);
		ft_mvp("rra\n", tab, tab2, p);
		if (ft_sorted(tab, p.l))
			return ;
		call(tab, tab2, p);
	}
}

void	ft_sort5(long long *tab, long long *tab2, t_push p)
{
	int		x;
	int		i;

	i = 0;
	x = tab[mn(tab, p.l, 1)];
	if (ft_sorted(tab, p.l))
		return ;
	while (tab[p.l - ht(tab, p.l)] != x)
	{
		if (tab[1] == tab[mn(tab, p.l, 1)])
			ft_mvp("ra\n", tab, tab2, p);
		else if (tab[2] == tab[mn(tab, p.l, 1)])
			ft_mvp("ra\nra\n", tab, tab2, p);
		else if (tab[3] == tab[mn(tab, p.l, 1)])
			ft_mvp("rra\nrra\n", tab, tab2, p);
		else
			ft_mvp("rra\n", tab, tab2, p);
		i++;
	}
	call2(tab, tab2, p);
}

void	ft_sort_5(long long *tab, long long *tab2, t_push p)
{
	if (p.l == 2)
		ft_mvp("ra\n", tab, tab2, p);
	else if (p.l == 3)
		ft_sort3(tab, tab2, 0, p);
	else if (p.l == 4)
		ft_sort4(tab, tab2, p);
	else
		ft_sort5(tab, tab2, p);
}
