/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:41:56 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:41:57 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_ft_o(t_opt *val, int ret, char *str, int len)
{
	if (val->d == '#' && ft_strcmp("0", str) != 0)
		len++;
	if (val->m != '-' && val->larg > len && val->larg > val->preci)
		ret = ft_opt_d(val, len, ret, str);
	else if (str[0] == '-' && val->z != '0')
	{
		ft_putchar('-');
		ret++;
	}
	if (val->preci > 0)
		ret = ft_op_o_1(val, ret, str, len);
	else
		ret = ft_op_o_2(val, ret, str);
	len = ft_strlen(str);
	if (str[0] != '-' && val->p == '+')
		len++;
	if (val->d == '#' && ft_strcmp("0", str) != 0)
		len++;
	if (val->m == '-' && val->larg > 0)
		ret = ft_opt_d(val, len, ret, str);
	return (ret);
}

int				ft_print_o(t_opt *val, va_list args, int ret)
{
	unsigned long long int	stock;
	char					*str;
	int						i;
	int						len;

	stock = ft_print_conversions(args, val);
	str = ft_itoa_num(stock, 8, 3);
	i = 0;
	len = ft_strlen(str);
	if (val->larg == len + 1 && val->preci == len && str[i] == '-')
		len = val->preci + 1;
	if (val->z == '0' && val->preci == -42 && str[i] == '-')
	{
		ft_putchar('-');
		ret++;
	}
	len = ft_strlen(str);
	ret = ft_ft_o(val, ret, str, len);
	ft_strdel(&str);
	return (ret);
}
