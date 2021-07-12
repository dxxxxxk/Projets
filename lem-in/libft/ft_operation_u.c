/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:06:43 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:06:44 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_part_op(t_opt *val, int ret, char *str)
{
	int			i;

	i = 0;
	if (ft_strlen(str) == 1 && str[0] == '0' && val->po == '.'
	&& val->preci <= 0)
	{
		if (val->larg > 0)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i++]);
			ret++;
		}
	}
	return (ret);
}

int				ft_op_u_1(t_opt *val, int ret, char *str, int len)
{
	int			i;

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
	ret = ft_part_op(val, ret, str);
	return (ret);
}

int				ft_op_u_2(t_opt *val, int ret, char *str)
{
	int			i;

	i = 0;
	if (str[i] == '-')
		i = 1;
	if (ft_strlen(str) == 1 && str[0] == '0' && val->po == '.'
	&& val->preci <= 0)
	{
		if (val->larg > 0)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i++]);
			ret++;
		}
	}
	return (ret);
}
