/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:06 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:54:08 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_raorrrab(long long *tab, long long *tab2, t_push *p, int max)
{
	if (mx(tab2, p->l, max) <= ft_mid(tab2, *p))
		while (tab2[p->l - ht(tab2, p->l)] != tab2[mx(tab2, p->l, max)])
			ft_mvp("rb\n", tab, tab2, *p);
	else
		while (tab2[p->l - ht(tab2, p->l)] != tab2[mx(tab2, p->l, max)])
			ft_mvp("rrb\n", tab, tab2, *p);
	if (max == 1)
		p->x++;
	else if (max == 2)
		p->x2++;
	else if (max == 3)
		p->x3++;
	else if (max == 4)
		p->x4++;
	else if (max == 5)
		p->x5++;
	else if (max == 6)
		p->x6++;
	else
		return ;
}

void	ft_raorrraa(long long *tab, long long *tab2, t_push *p, int min)
{
	if (mn(tab, p->l, min) <= ft_mid(tab, *p))
		while (tab[p->l - ht(tab, p->l)] != tab[mn(tab, p->l, min)])
			ft_mvp("ra\n", tab, tab2, *p);
	else
		while (tab[p->l - ht(tab, p->l)] != tab[mn(tab, p->l, min)])
			ft_mvp("rra\n", tab, tab2, *p);
	if (min == 1)
		p->x++;
	else if (min == 2)
		p->x2++;
	else if (min == 3)
		p->x3++;
	else if (min == 4)
		p->x4++;
	else if (min == 5)
		p->x5++;
	else if (min == 6)
		p->x6++;
	else
		return ;
}

int		ft_conditions(long long *tab, t_push p, int nb)
{
	if (nb == 1 && ht(tab, p.l) > 9 &&
	p.x6 < 1 - (p.x4 + p.x3 + p.x2 + p.x + p.x5) &&
	dm(tab, p, mn(tab, p.l, 6)) > dm(tab, p, mn(tab, p.l, 1)) &&
	dm(tab, p, mn(tab, p.l, 6)) > dm(tab, p, mn(tab, p.l, 2)) &&
	dm(tab, p, mn(tab, p.l, 6)) > dm(tab, p, mn(tab, p.l, 3)) &&
	dm(tab, p, mn(tab, p.l, 6)) > dm(tab, p, mn(tab, p.l, 4)) &&
	dm(tab, p, mn(tab, p.l, 6)) > dm(tab, p, mn(tab, p.l, 5)))
		return (1);
	else if ((nb == 2 && ht(tab, p.l) > 8 &&
	p.x5 < 2 - (p.x4 + p.x3 + p.x2 + p.x + p.x6) &&
	dm(tab, p, mn(tab, p.l, 5)) > dm(tab, p, mn(tab, p.l, 1)) &&
	dm(tab, p, mn(tab, p.l, 5)) > dm(tab, p, mn(tab, p.l, 2)) &&
	dm(tab, p, mn(tab, p.l, 5)) > dm(tab, p, mn(tab, p.l, 3)) &&
	dm(tab, p, mn(tab, p.l, 5)) > dm(tab, p, mn(tab, p.l, 4))) ||
	((nb == 3 && ht(tab, p.l) > 7 &&
	p.x4 < 3 - (p.x5 + p.x3 + p.x2 + p.x + p.x6) &&
	dm(tab, p, mn(tab, p.l, 4)) > dm(tab, p, mn(tab, p.l, 1)) &&
	dm(tab, p, mn(tab, p.l, 4)) > dm(tab, p, mn(tab, p.l, 2)) &&
	dm(tab, p, mn(tab, p.l, 4)) > dm(tab, p, mn(tab, p.l, 3)))) ||
	(nb == 4 && ht(tab, p.l) > 6 &&
	dm(tab, p, mn(tab, p.l, 3)) > dm(tab, p, mn(tab, p.l, 1)) &&
	p.x3 < 4 - (p.x4 + p.x2 + p.x + p.x5 + p.x6) &&
	dm(tab, p, mn(tab, p.l, 3)) > dm(tab, p, mn(tab, p.l, 2))))
		return (1);
	return (0);
}

void	ft_conditions2(long long *tab, long long *tab2, t_push p)
{
	if (p.l - ht(tab2, p.l) + 4 < p.l)
		if (tab2[p.l - ht(tab2, p.l) + 4] > tab[p.l - ht(tab, p.l)] &&
		tab2[p.l - ht(tab2, p.l) + 4] != 9223372036854775)
			ft_special_move(tab, tab2, 61, p);
	if (p.l - ht(tab2, p.l) + 3 < p.l)
		if (tab2[p.l - ht(tab2, p.l) + 3] > tab[p.l - ht(tab, p.l)] &&
		tab2[p.l - ht(tab2, p.l) + 3] != 9223372036854775)
			ft_special_move(tab, tab2, 51, p);
	if (p.l - ht(tab2, p.l) + 2 < p.l)
		if (tab2[p.l - ht(tab2, p.l) + 2] > tab[p.l - ht(tab, p.l)] &&
		tab2[p.l - ht(tab2, p.l) + 2] != 9223372036854775)
			ft_special_move(tab, tab2, 41, p);
	if (p.l - ht(tab2, p.l) + 1 < p.l)
		if (tab2[p.l - ht(tab2, p.l) + 1] > tab[p.l - ht(tab, p.l)] &&
		tab2[p.l - ht(tab2, p.l) + 1] != 9223372036854775)
			ft_special_move(tab, tab2, 31, p);
	ft_mvp("pb\n", tab, tab2, p);
	if (p.l - ht(tab2, p.l) + 1 < p.l)
		if (tab2[p.l - ht(tab2, p.l)] < tab2[p.l - ht(tab2, p.l) + 1])
			ft_mvp("sb\n", tab, tab2, p);
}

int		ft_conditionsb(long long *tab2, t_push p, int nb)
{
	if ((nb == 1 && ht(tab2, p.l) > 7 &&
	p.x6 < 1 - (p.x4 + p.x3 + p.x2 + p.x + p.x5) &&
	dm(tab2, p, mx(tab2, p.l, 6)) > dm(tab2, p, mx(tab2, p.l, 1)) &&
	dm(tab2, p, mx(tab2, p.l, 6)) > dm(tab2, p, mx(tab2, p.l, 2)) &&
	dm(tab2, p, mx(tab2, p.l, 6)) > dm(tab2, p, mx(tab2, p.l, 3)) &&
	dm(tab2, p, mx(tab2, p.l, 6)) > dm(tab2, p, mx(tab2, p.l, 4)) &&
	dm(tab2, p, mx(tab2, p.l, 6)) > dm(tab2, p, mx(tab2, p.l, 5))) ||
	(nb == 2 && ht(tab2, p.l) > 6 &&
	p.x5 < 2 - (p.x4 + p.x3 + p.x2 + p.x + p.x6) &&
	dm(tab2, p, mx(tab2, p.l, 5)) > dm(tab2, p, mx(tab2, p.l, 1)) &&
	dm(tab2, p, mx(tab2, p.l, 5)) > dm(tab2, p, mx(tab2, p.l, 2)) &&
	dm(tab2, p, mx(tab2, p.l, 5)) > dm(tab2, p, mx(tab2, p.l, 3)) &&
	dm(tab2, p, mx(tab2, p.l, 5)) > dm(tab2, p, mx(tab2, p.l, 4))) ||
	((nb == 3 && ht(tab2, p.l) > 5 &&
	p.x4 < 3 - (p.x5 + p.x3 + p.x2 + p.x + p.x6) &&
	dm(tab2, p, mx(tab2, p.l, 4)) > dm(tab2, p, mx(tab2, p.l, 1)) &&
	dm(tab2, p, mx(tab2, p.l, 4)) > dm(tab2, p, mx(tab2, p.l, 2)) &&
	dm(tab2, p, mx(tab2, p.l, 4)) > dm(tab2, p, mx(tab2, p.l, 3)))) ||
	((nb == 4 && ht(tab2, p.l) > 4 &&
	dm(tab2, p, mx(tab2, p.l, 3)) > dm(tab2, p, mx(tab2, p.l, 1)) &&
	p.x3 < 4 - (p.x4 + p.x2 + p.x + p.x5 + p.x6) &&
	dm(tab2, p, mx(tab2, p.l, 3)) > dm(tab2, p, mx(tab2, p.l, 2)))))
		return (1);
	return (0);
}
