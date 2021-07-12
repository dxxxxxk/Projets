/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:52:51 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:52:53 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_mid(long long *tab, t_push p)
{
	int		mid;

	mid = p.l - ht(tab, p.l) + (ht(tab, p.l) / 2);
	return (mid);
}

int		dm(long long *tab, t_push p, int pos_min1234)
{
	int		diff;

	diff = valeur_abs(ft_mid(tab, p) - pos_min1234);
	return (diff);
}

int		valeur_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}
