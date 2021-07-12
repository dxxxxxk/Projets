/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:43:00 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:43:01 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_opt(t_opt *val, int len, int ret)
{
	int i;

	i = 0;
	if (len < 0)
		len = 0;
	while (i < val->larg - len)
	{
		if (val->z == '0' && val->m != '-')
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
		ret++;
	}
	return (ret);
}
