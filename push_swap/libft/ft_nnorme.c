/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nnorme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:42:37 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:42:38 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nnormes(t_opt *val, char *str, int ret, int *len)
{
	if (val->larg == *len + 1 && val->preci == *len && str[0] == '-')
		*len = val->preci + 1;
	if (val->e == ' ' && val->z == '0' && str[0] != '-')
	{
		ft_putchar(' ');
		ret++;
		*len = *len + 1;
	}
	if (val->z == '0' && val->preci == -42 && str[0] == '-')
	{
		ft_putchar('-');
		ret++;
	}
	if (val->d == '#')
		*len = *len + 1;
	if (str[0] != '-' && val->p == '+' && val->z == '0' && val->preci <= 0)
	{
		ft_putchar('+');
		ret++;
	}
	if (val->m != '-' && val->larg > *len && val->larg > val->preci)
		ret = ft_opt_d(val, *len, ret, str);
	return (ret);
}

int		ft_nnnorm(t_opt *val, char *str, int ret, int *len)
{
	if (val->m != '-' && val->larg > *len && val->len == 'y' && val->preci > 0)
		ret = ft_opt_d(val, *len, ret, str);
	if (val->len != 'y')
		*len = ft_strlen(str);
	if (val->preci <= 0 && val->po == '.')
	{
		*len = 0;
		while (str[*len] != '.')
			*len = *len + 1;
	}
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

int		ft_nnnorme(t_opt *val, char *str, int ret, int *len)
{
	if (val->e == ' ' && val->z != '0' && str[0] != '-')
	{
		ft_putchar(' ');
		ret++;
	}
	else if (val->e == ' ' && (val->len == 'p' || val->len == 'l'
				|| val->len == 'q'))
	{
		ft_putchar(' ');
		ret++;
	}
	if (str[0] == '-')
		*len = *len - 1;
	if (str[0] == '-')
	{
		ft_putchar('-');
		ret++;
	}
	if (val->p == '+' && str[0] != '-' && val->z == '0' && val->preci > 0)
	{
		ft_putchar('+');
		ret++;
	}
	return (ret);
}

int		ft_nnnormes(t_opt *val, char *str, int ret, int *len)
{
	int	i;

	i = 0;
	while (i < val->preci - *len && val->len != 'y')
	{
		ft_putchar('0');
		ret++;
		i++;
	}
	if (ft_strcmp("0", str) == 0 && val->po == '.' && val->preci <= 0
			&& val->larg > 0)
	{
		ft_putchar(' ');
		ret++;
	}
	else
		ret = ft_print_preci(val, str, ret);
	return (ret);
}

int		ft_nnnnorm(t_opt *val, char *str, int ret)
{
	if (val->e == ' ' && val->z != '0' && str[0] != '-')
	{
		ft_putchar(' ');
		ret++;
	}
	if (ft_strcmp("0", str) == 0 && val->po == '.' && val->preci <= 0
			&& val->larg > 0)
	{
		ft_putchar(' ');
		ret++;
	}
	else
		ret = ft_print_preci(val, str, ret);
	return (ret);
}
