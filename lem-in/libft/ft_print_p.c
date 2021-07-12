/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:41:47 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:41:49 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_preci_2(t_opt *val, int ret, char *str, int len)
{
	if (val->z == '0' && val->preci == -42 && str[0] == '-')
	{
		ft_putchar('-');
		ret++;
	}
	len = ft_strlen(str);
	if (str[0] != '-' && val->p == '+' && val->z == '0' && val->preci == -42)
	{
		ft_putchar('+');
		ret++;
	}
	return (ret);
}

static	int	ft_preci(t_opt *val, int ret, char *str, int len)
{
	ret = ft_preci_2(val, ret, str, len);
	if (val->m != '-' && val->larg > len && val->larg > val->preci)
		ret = ft_opt_d(val, len, ret, str);
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

int			ft_print_p(t_opt *val, va_list args, int ret)
{
	char	*str;
	long	len;
	char	*tmp;

	len = (long)va_arg(args, void *);
	str = ft_itoa_num(len, 16, 0);
	tmp = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strjoin("0x", tmp);
	ft_strdel(&tmp);
	len = ft_strlen(str);
	if (val->larg == len + 1 && val->preci == len && str[0] == '-')
		len = val->preci + 1;
	ret = ft_preci(val, ret, str, len);
	if (val->preci >= 0)
		ret = ft_op_p_1(val, ret, str, len);
	else
		ret = ft_op_p_2(val, ret, str);
	len = ft_strlen(str);
	if (str[0] != '-' && val->p == '+')
		len = len + 1;
	if (val->m == '-' && val->larg > 0)
		ret = ft_opt_d(val, len, ret, str);
	ft_strdel(&str);
	return (ret);
}
