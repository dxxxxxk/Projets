/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_xx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:06:58 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:06:59 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_little(t_opt *val, int ret)
{
	if (val->larg > 0)
	{
		ft_putchar(' ');
		ret++;
	}
	return (ret);
}

static	int		ft_op(t_opt *val, int ret, char *str, int len)
{
	int			i;

	i = 0;
	if (val->d == '#' && val->m != '-' && ft_strcmp("0", str) != 0
	&& val->larg <= (int)ft_strlen(str))
	{
		ft_putstr("0X");
		ret = ret + 2;
	}
	while (i < val->preci - len)
	{
		ft_putchar('0');
		ret++;
		i++;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i++]);
		ret++;
	}
	return (ret);
}

int				ft_op_xx_1(t_opt *val, int ret, char *str, int len)
{
	int			i;

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
	i = 0;
	if (str[i] == '-')
		i = 1;
	if (ft_strcmp("0", str) == 0 && val->po == '.' && val->preci <= 0)
		ret = ft_little(val, ret);
	else
		ret = ft_op(val, ret, str, len);
	return (ret);
}

static	int		ft_little_loop(t_opt *val, int ret, char *str)
{
	int			i;

	if (val->d == '#' && ft_strcmp(str, "0") != 0 && val->m != '-'
			&& val->larg <= (int)ft_strlen(str))
	{
		ft_putstr("0X");
		ret = ret + 2;
	}
	i = 0;
	while (str[i] && val->po != '.')
	{
		ft_putchar(str[i++]);
		ret++;
	}
	return (ret);
}

int				ft_op_xx_2(t_opt *val, int ret, char *str)
{
	int			i;

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
		ret = ft_little_loop(val, ret, str);
	return (ret);
}
