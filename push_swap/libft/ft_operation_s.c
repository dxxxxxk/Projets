/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:06:36 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:06:37 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_p(t_opt *val, int ret, int stock, int len)
{
	if (len <= val->preci || val->preci == -42)
		stock = len;
	else
		stock = val->preci;
	if (val->m != '-' && val->larg > 0)
		ret = ft_opt(val, stock, ret);
	return (ret);
}

static	int		ft_m(t_opt *val, int ret, int stock, int len)
{
	if (len <= val->preci || val->preci == -42)
		stock = len;
	else
		stock = val->preci;
	if (val->m == '-' && val->larg > 0)
		ret = ft_opt(val, stock, ret);
	return (ret);
}

int				ft_op_s_1(t_opt *val, int ret, char *str, int len)
{
	int		i;
	int		stock;

	i = 0;
	stock = 0;
	ret = ft_p(val, ret, stock, len);
	if (val->preci >= 0)
	{
		while (i < val->preci && str[i])
		{
			ft_putchar(str[i++]);
			ret++;
		}
	}
	else
	{
		ft_putstr(str);
		ret = ret + len;
	}
	ret = ft_m(val, ret, stock, len);
	return (ret);
}
