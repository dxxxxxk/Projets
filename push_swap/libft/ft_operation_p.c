/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:06:23 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:06:25 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_op(t_opt *val, int ret, char *str)
{
	int		i;

	i = 0;
	if (val->e == ' ' && val->m == '\0' && val->p == '\0'
			&& val->po == '\0' && val->d == '\0' && val->larg == 0
			&& val->len == '\0')
	{
		ft_putchar(' ');
		ret++;
	}
	while (str[i])
	{
		ft_putchar(str[i++]);
		ret++;
	}
	return (ret);
}

static	int		ft_op_1(t_opt *val, int ret, char *str)
{
	int			i;

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
		ret = ft_op(val, ret, str);
	return (ret);
}

int				ft_op_p_1(t_opt *val, int ret, char *str, int len)
{
	int			i;

	i = 0;
	if (str[i] == '-')
		len = len - 1;
	if (str[i] == '-')
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
	ret = ft_op_1(val, ret, str);
	return (ret);
}

static	int		ft_op_3(t_opt *val, int ret, char *str)
{
	int		i;

	i = 0;
	if (val->e == ' ' && val->m == '\0' && val->p == '\0'
			&& val->po == '\0' && val->d == '\0' && val->larg == 0
			&& val->preci == -42 && val->len == '\0' && str[0] != '-')
	{
		ft_putchar(' ');
		ret++;
	}
	while (str[i])
	{
		ft_putchar(str[i++]);
		ret++;
	}
	return (ret);
}

int				ft_op_p_2(t_opt *val, int ret, char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i = 1;
	if (ft_strcmp("0", str) == 0 && val->po == '.' && val->preci <= 0
			&& val->larg > 0)
	{
		ft_putchar(' ');
		ret++;
	}
	else
		ret = ft_op_3(val, ret, str);
	return (ret);
}
