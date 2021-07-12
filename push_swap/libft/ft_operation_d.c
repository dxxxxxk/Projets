/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:06:07 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:06:09 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_operation(t_opt *val, int ret, char *str)
{
	if (val->e == ' ' && val->m == '\0' && val->p == '\0' && str[0] != '-'
	&& val->d == '\0' && val->larg <= (int)ft_strlen(str)
	&& val->len == '\0')
	{
		ft_putchar(' ');
		ret++;
	}
	else if (val->e == ' ' && (val->len == 'q' || val->len == 'l'
	|| val->len == 'p'))
	{
		ft_putchar(' ');
		ret++;
	}
	return (ret);
}

static	int		ft_perf_3(t_opt *val, int ret, char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i = 1;
	if (ft_strcmp("0", str) == 0 && val->po == '.' && val->preci <= 0)
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

int				ft_op_d_1(t_opt *val, int ret, char *str, int len)
{
	int		i;

	i = 0;
	ret = ft_operation(val, ret, str);
	if (str[0] == '-')
		len = len - 1;
	if (str[0] == '-')
	{
		ft_putchar('-');
		ret++;
	}
	if (val->p == '+' && str[0] != '-' && val->z == '0')
	{
		ft_putchar('+');
		ret++;
	}
	while (i < val->preci - len)
	{
		ft_putchar('0');
		ret++;
		i++;
	}
	ret = ft_perf_3(val, ret, str);
	return (ret);
}

int				ft_op_d_2(t_opt *val, int ret, char *str)
{
	int		i;

	i = 0;
	ret = ft_operation(val, ret, str);
	if (str[i] == '-')
		i = 1;
	if (ft_strcmp("0", str) == 0 && val->po == '.' && val->preci <= 0
	&& val->larg > 0)
	{
		ft_putchar(' ');
		ret++;
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
