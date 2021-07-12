/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:43:56 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/12 18:44:01 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		call(long long *tab, long long *tab2, t_push p)
{
	ft_mvp("pb\n", tab, tab2, p);
	ft_sort3(tab, tab2, p.l - ht(tab, p.l), p);
	ft_mvp("pa\n", tab, tab2, p);
}

void		call2(long long *tab, long long *tab2, t_push p)
{
	if (ft_sorted(tab, p.l))
		return ;
	ft_mvp("pb\n", tab, tab2, p);
	ft_sort4(tab, tab2, p);
	ft_mvp("pa\n", tab, tab2, p);
}

int			ft_sorted(long long *tab, int l)
{
	int	i;

	i = 0;
	while (i + 1 < ht(tab, l))
	{
		if (tab[i + 1 + l - ht(tab, l)] > tab[i + l - ht(tab, l)])
			i++;
		else
			return (0);
	}
	return (1);
}

long long	*ft_sort_int_tab(long long *tab, int l)
{
	int	i;
	int	swap;

	i = 0;
	while (i + 1 < l)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

void		ft_500(long long *tab, long long *tab2, t_push p)
{
	ft_pushonb_mediane(tab, tab2, p);
	ft_pushonb_mediane(tab, tab2, p);
	ft_pushonb_mediane(tab, tab2, p);
	ft_pushonb_mediane(tab, tab2, p);
	if (p.l >= 400 && p.l < 600)
	{
		ft_pushonb_mediane(tab, tab2, p);
		ft_pushonb_mediane(tab, tab2, p);
		ft_pushonb_mediane(tab, tab2, p);
		ft_pushonb_mediane(tab, tab2, p);
		ft_pushonb_mediane(tab, tab2, p);
		ft_pushonb_mediane(tab, tab2, p);
		ft_pushonb_mediane(tab, tab2, p);
		ft_pushonb_mediane(tab, tab2, p);
		ft_pushonb_mediane(tab, tab2, p);
	}
}
