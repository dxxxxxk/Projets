/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:53:59 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:54:00 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_x(t_push *p, long long *tab)
{
	p->x = 0;
	p->x2 = 0;
	p->x3 = 0;
	p->x4 = 0;
	p->x5 = 0;
	p->x6 = 1;
	if ((p->l <= 100 && ht(tab, p->l) > 22))
	{
		p->x = 0;
		p->x2 = 0;
		p->x3 = 0;
		p->x4 = 0;
		p->x5 = 1;
		p->x6 = 1;
	}
}

int		mn(long long *tab, int l, int min)
{
	long long	*stab;
	int			i;
	int			j;

	if (!(stab = (long long *)malloc(ht(tab, l) * sizeof(long long))))
		return (0);
	i = l - ht(tab, l);
	j = 0;
	while (i < l)
	{
		stab[j] = tab[i];
		i++;
		j++;
	}
	ft_sort_int_tab(stab, ht(tab, l));
	i = 0;
	j = 0;
	while (tab[j] != stab[min - 1])
		j++;
	free(stab);
	return (j);
}

int		mx(long long *tab, int l, int max)
{
	long long	*stab;
	int			i;
	int			j;

	if (!(stab = (long long *)malloc(ht(tab, l) * sizeof(long long))))
		return (0);
	i = l - ht(tab, l);
	j = 0;
	while (i < l)
	{
		stab[j] = tab[i];
		i++;
		j++;
	}
	ft_sort_int_tab(stab, ht(tab, l));
	i = 0;
	j = 0;
	while (tab[j] != stab[ht(tab, l) - max])
		j++;
	free(stab);
	return (j);
}

void	ft_rush_min(long long *tab, long long *tab2, t_push p)
{
	if (p.l - ht(tab, p.l) + 4 < p.l)
		if (tab[p.l - ht(tab, p.l) + 4] < tab2[p.l - ht(tab2, p.l)])
			ft_special_move(tab, tab2, 62, p);
	if (p.l - ht(tab, p.l) + 3 < p.l)
		if (tab[p.l - ht(tab, p.l) + 3] < tab2[p.l - ht(tab2, p.l)])
			ft_special_move(tab, tab2, 52, p);
	if (p.l - ht(tab, p.l) + 2 < p.l)
		if (tab[p.l - ht(tab, p.l) + 2] < tab2[p.l - ht(tab2, p.l)])
			ft_special_move(tab, tab2, 42, p);
	if (p.l - ht(tab, p.l) + 1 < p.l)
		if (tab[p.l - ht(tab, p.l) + 1] < tab2[p.l - ht(tab2, p.l)])
			ft_special_move(tab, tab2, 32, p);
	ft_mvp("pa\n", tab, tab2, p);
	if (p.l - ht(tab, p.l) + 1 < p.l)
		if (tab[p.l - ht(tab, p.l)] > tab[p.l - ht(tab, p.l) + 1])
			ft_mvp("sa\n", tab, tab2, p);
}

void	ft_special_move(long long *tab, long long *tab2, int move, t_push p)
{
	if (move == 31)
		ft_mvp("pa\nsa\npb\nsb\n", tab, tab2, p);
	else if (move == 32)
		ft_mvp("pb\nsb\npa\nsa\n", tab, tab2, p);
	else if (move == 41)
		ft_mvp("pa\nrr\npb\nsb\nrrr\n", tab, tab2, p);
	else if (move == 42)
		ft_mvp("pb\nrr\npa\nsa\nrrr\n", tab, tab2, p);
	else if (move == 51)
		ft_mvp("pa\npa\nrr\nrr\npb\nrrr\nrrr\npb\n", tab, tab2, p);
	else if (move == 52)
		ft_mvp("pb\npb\nrr\nrr\npa\nrrr\nrrr\npa\n", tab, tab2, p);
	else if (move == 61)
		ft_mvp("pa\npa\nrr\nrr\npb\nsb\nrrr\nrrr\npb\n", tab, tab2, p);
	else if (move == 62)
		ft_mvp("pb\npb\nrr\nrr\npa\nsa\nrrr\nrrr\npa\n", tab, tab2, p);
	else if (move == 71)
		ft_mvp("pa\npa\npa\nrr\nrr\nrr\npb\nrrr\nrrr\nrrr\npb\npb\n",
		tab, tab2, p);
	else if (move == 72)
		ft_mvp("pb\npb\npb\nrr\nrr\nrr\npa\nrrr\nrrr\nrrr\npa\npa\n",
		tab, tab2, p);
	else
		return ;
}
