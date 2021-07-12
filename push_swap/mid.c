/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:51:44 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/16 14:43:59 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_mediane(long long *tab, t_push *p)
{
	long long	*stab;
	int			i;
	int			j;

	j = 0;
	i = p->l - ht(tab, p->l);
	if (!(stab = (long long*)malloc(ht(tab, p->l) * sizeof(long long))))
		return ;
	while (i < p->l)
	{
		stab[j] = tab[i];
		i++;
		j++;
	}
	ft_sort_int_tab(stab, ht(tab, p->l));
	ft_domed(tab, stab, p);
	free(stab);
}

void			ft_domed(long long *tab, long long *stab, t_push *p)
{
	if (ht(tab, p->l) >= 250)
		p->mediane = ft_med(tab, stab, p, 6);
	else if (ht(tab, p->l) >= 200)
		p->mediane = ft_med(tab, stab, p, 5);
	else if (ht(tab, p->l) > 100)
		p->mediane = ft_med(tab, stab, p, 4);
	else if (ht(tab, p->l) > 40)
		p->mediane = ft_med(tab, stab, p, 3);
	else
		p->mediane = ft_med(tab, stab, p, 2);
	if (p->l == 100)
	{
		if (ht(tab, p->l) > 40)
			p->mediane = ft_med(tab, stab, p, 3);
		else
			p->mediane = ft_med(tab, stab, p, 2);
	}
}

int				ft_med(long long *tab, long long *stab, t_push *p, int i)
{
	int		ret;

	ret = stab[mn(stab, ht(tab, p->l), (ht(tab, p->l) / i) + 1)];
	return (ret);
}

void			ft_pushonb_mediane(long long *tab, long long *tab2, t_push p)
{
	int		i;
	int		j;

	i = p.l - ht(tab, p.l);
	j = p.l - ht(tab, p.l);
	ft_mediane(tab, &p);
	while (j < p.l && tab[mn(tab, p.l, 1)] != p.mediane)
	{
		if (tab[i] >= p.mediane && !ft_sorted(tab, p.l))
			ft_mvp("ra\n", tab, tab2, p);
		else if (tab[i] < p.mediane)
		{
			ft_mvp("pb\n", tab, tab2, p);
			i++;
		}
		j++;
	}
}

int				ft_space(char **av, t_push *p)
{
	int		i;

	i = 0;
	p->l = 0;
	while (av[1][p->l])
	{
		if (!ft_isdigit(av[1][i]))
			i++;
		p->l = p->l + 1;
	}
	if (ft_strlen(av[1]) == (size_t)i)
		return (1);
	p->l = 0;
	return (0);
}
