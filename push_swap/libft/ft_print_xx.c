/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:40:53 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:40:55 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_perf_2(t_opt *val, int ret, char *str, int len)
{
	if (val->d == '#' && val->type != 'o' && ft_strcmp(str, "0") != 0
	&& val->m == '-')
	{
		ft_putchar('0');
		ft_putchar(val->type);
		ret = ret + 2;
	}
	len = ft_strlen(str);
	if (str[0] != '-' && val->p == '+' && val->z != '0')
	{
		ft_putchar('+');
		ret++;
	}
	else if (str[0] == '-' && val->z != '0' && val->preci < 0)
	{
		ft_putchar('-');
		ret++;
	}
	return (ret);
}

static	int		ft_perf(t_opt *val, int ret, char *str, int len)
{
	if (val->larg == len + 1 && val->preci == len && str[0] == '-')
		len = val->preci + 1;
	if (val->z == '0' && val->preci == -42 && str[0] == '-')
	{
		ft_putchar('-');
		ret++;
	}
	else if (str[0] == '-' && val->z == '0' && val->larg <= len
	&& val->preci < 0)
	{
		ft_putchar('-');
		ret++;
	}
	if (str[0] != '-' && val->p == '+' && val->z == '0' && val->preci == -42)
	{
		ft_putchar('+');
		ret++;
	}
	if (val->e == ' ' && (val->len == 'p' || val->len == 'l'
	|| val->len == 'q'))
		len++;
	if (val->m != '-' && val->larg > len && val->larg > val->preci)
		ret = ft_opt_d(val, len, ret, str);
	ret = ft_perf_2(val, ret, str, len);
	return (ret);
}

int				ft_print_xx(t_opt *val, va_list args, int ret)
{
	unsigned long long int	stock;
	char					*str;
	int						i;
	int						len;

	stock = ft_print_conversions(args, val);
	str = ft_itoa_num(stock, 16, 1);
	i = 0;
	len = ft_strlen(str);
	ret = ft_perf(val, ret, str, len);
	if (val->preci >= 0)
		ret = ft_op_xx_1(val, ret, str, len);
	else
		ret = ft_op_xx_2(val, ret, str);
	len = ft_strlen(str);
	if (str[i] != '-' && val->p == '+')
		len = len + 1;
	if (val->m == '-' && val->larg > 0)
		ret = ft_opt_d(val, len, ret, str);
	ft_strdel(&str);
	return (ret);
}
