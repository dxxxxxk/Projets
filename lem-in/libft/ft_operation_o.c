/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:06:17 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:06:18 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_o(t_opt *val, int ret, char *str)
{
	int			i;

	i = 0;
	if (val->d == '#' && ft_strcmp("0", str) != 0)
	{
		ft_putchar('0');
		ret++;
	}
	while (str[i])
	{
		ft_putchar(str[i++]);
		ret++;
	}
	return (ret);
}

int				ft_op_o_1(t_opt *val, int ret, char *str, int len)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		len = len - 1;
	while (i < val->preci - len)
	{
		ft_putchar('0');
		ret++;
		i++;
	}
	i = 0;
	if (str[i] == '-')
		i = 1;
	if (ft_strcmp("0", str) != 0 && val->po == '.' && val->preci <= 0)
	{
		if (val->larg > 0)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	else
		ret = ft_o(val, ret, str);
	return (ret);
}

static	int		ft_o2(t_opt *val, int ret, char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i = 1;
	if (val->larg > 0 && val->d != '#')
	{
		ft_putchar(' ');
		ret++;
	}
	while (str[i] && val->d == '#')
	{
		ft_putchar(str[i++]);
		ret++;
	}
	return (ret);
}

int				ft_op_o_2(t_opt *val, int ret, char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i = 1;
	if (ft_strcmp("0", str) == 0 && val->po == '.' && val->preci <= 0)
		ret = ft_o2(val, ret, str);
	else
	{
		if (val->d == '#' && ft_strcmp("0", str) != 0)
		{
			ft_putchar('0');
			ret++;
		}
		while (str[i])
		{
			ft_putchar(str[i++]);
			ret++;
		}
	}
	return (ret);
}
