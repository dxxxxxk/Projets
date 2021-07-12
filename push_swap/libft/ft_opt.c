/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:42:53 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:42:54 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_opt_d(t_opt *val, int len, int ret, char *str)
{
	int	i;
	int	diff;

	i = 0;
	if (len < 0)
		len = 0;
	if (val->m != '-')
	{
		if (val->preci > len)
			diff = val->preci;
		else
			diff = len;
		diff = ft_diff(str, val, diff, len);
		if (val->d == '#' && val->type != 'o' && val->type != 'f'
		&& ft_strcmp(str, "0") != 0 && val->preci == -42 && val->z == '0')
			ret = ft_putox(val, ret);
		if (i < val->larg - diff)
			ret = ft_ps(val, ret, diff);
		if (val->d == '#' && val->type != 'o' && val->type != 'f'
		&& ft_strcmp(str, "0") != 0 && (val->preci != -42 || val->z != '0'))
			ret = ft_putox(val, ret);
	}
	if (val->m == '-')
		ret = ft_opt_m(val, len, ret, str);
	return (ret);
}

int		ft_putox(t_opt *val, int ret)
{
	ft_putchar('0');
	ft_putchar(val->type);
	ret = ret + 2;
	return (ret);
}

int		ft_diff(char *str, t_opt *val, int diff, int len)
{
	if (ft_strcmp(str, "nan") == 0 || ft_strcmp(str, "inf") == 0
	|| ft_strcmp(str, "-inf") == 0)
		diff = ft_strlen(str);
	if (str[0] != '-' && val->p == '+')
		diff++;
	if (str[0] == '-' && val->preci == len)
		diff++;
	if (val->d == '#' && val->type != 'o' && val->type != 'f'
	&& ft_strcmp(str, "0") != 0)
		diff = diff + 2;
	return (diff);
}

int		ft_ps(t_opt *val, int ret, int diff)
{
	int	i;

	i = 0;
	while (i < val->larg - diff)
	{
		if (val->po == '.' && val->preci <= 0 && val->z == '0'
		&& val->type == 'f')
			ft_putchar('0');
		else if (val->preci == -42 && val->z == '0' && val->type != 'f')
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
		ret++;
	}
	return (ret);
}

int		ft_opt_m(t_opt *val, int len, int ret, char *str)
{
	int	i;
	int	diff;

	i = 0;
	if (val->preci > len)
		diff = val->preci;
	else
		diff = len;
	if (str[i] != '-' && val->p == '+' && val->preci != -42)
		diff++;
	if (str[i] == '-' && val->preci == len)
		diff++;
	if (val->d == '#' && val->type != 'o' && val->type != 'f')
		diff = diff + 2;
	if (val->d == '#' && (val->type == 'x' || val->type == 'X')
	&& ft_strcmp(str, "0") == 0 && val->preci == 0 && val->po == '.')
		diff -= 2;
	while (i < val->larg - diff)
	{
		ft_putchar(' ');
		i++;
		ret++;
	}
	return (ret);
}
