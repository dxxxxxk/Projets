/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:41:31 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:41:33 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_perf(t_opt *val, int ret, char *str, int len)
{
	if (val->larg == len + 1 && val->preci == len && str[0] == '-')
		len = val->preci + 1;
	if (val->z == '0' && val->preci == -42 && str[0] == '-')
	{
		ft_putchar('-');
		ret++;
	}
	len = ft_strlen(str);
	if (val->m != '-' && val->larg > len && val->larg > val->preci)
		ret = ft_opt_d(val, len, ret, str);
	else if (str[0] == '-' && val->z != '0')
	{
		ft_putchar('-');
		ret++;
	}
	return (ret);
}

int				ft_print_u(t_opt *val, va_list args, int ret)
{
	unsigned long long int	stock;
	char					*str;
	int						i;
	int						len;

	stock = ft_print_conversions(args, val);
	str = ft_itoa_num(stock, 10, 2);
	i = 0;
	len = ft_strlen(str);
	ret = ft_perf(val, ret, str, len);
	if (val->preci >= 0)
		ret = ft_op_u_1(val, ret, str, len);
	else
		ret = ft_op_u_2(val, ret, str);
	len = ft_strlen(str);
	if (str[i] != '-' && val->p == '+')
		len = len + 1;
	if (val->m == '-' && val->larg > 0)
		ret = ft_opt_d(val, len, ret, str);
	ft_strdel(&str);
	return (ret);
}
