/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:41:39 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:41:40 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_ret(t_opt *val, int ret)
{
	if (val->preci == 0)
		return (ret);
	else
	{
		ft_putstr("(null)");
		ret = ret + 6;
	}
	return (ret);
}

int				ft_print_s(t_opt *val, va_list args, int ret)
{
	char	*str;
	int		stock;
	int		len;

	stock = 0;
	str = (char *)(va_arg(args, char *));
	if (!str)
	{
		len = 6;
		if (len <= val->preci || val->preci == -42)
			stock = len;
		else
			stock = val->preci;
		if (val->m != '-' && val->larg > 0)
			ret = ft_opt(val, stock, ret);
		ret = ft_ret(val, ret);
		if (val->m == '-' && val->larg > 0)
			ret = ft_opt(val, stock, ret);
		return (ret);
	}
	len = ft_strlen(str);
	ret = ft_op_s_1(val, ret, str, len);
	return (ret);
}
