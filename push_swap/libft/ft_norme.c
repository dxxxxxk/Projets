/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:42:44 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:42:45 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_norm(long int *part, long double len, char *str)
{
	*part = (long int)(len + 0.5);
	str = ft_strjoin(str, ft_itoa(*part));
	return (str);
}

int			ft_normes(char *str, int ret, int *i)
{
	ft_putchar(str[*i]);
	*i = *i + 1;
	ret++;
	return (ret);
}

int			ft_nnorm(char *str, int i, int ret, t_opt *val)
{
	int		n;

	n = 0;
	if (val->preci <= 0)
		ret = ft_norme(str, i, ret);
	else
	{
		if (str[0] == '-')
			n++;
		while (str[n] != '.' && str[n])
			ret = ft_normes(str, ret, &n);
		i = 0;
		while (str[n] && i <= val->preci)
		{
			ret = ft_normes(str, ret, &n);
			i++;
		}
	}
	return (ret);
}

int			ft_nnnnorme(t_opt *val, char *str, int *len, int ret)
{
	if (val->preci <= 0 && val->po == '.' && val->len != 'y')
	{
		*len = 0;
		while (str[*len] != '.')
			*len = *len + 1;
	}
	if (val->e == ' ')
		*len = *len + 1;
	if (val->d == '#' && ft_strcmp("0", str) != 0)
		*len = *len + 1;
	if (val->m == '-' && val->larg > 0)
		ret = ft_opt_d(val, *len, ret, str);
	return (ret);
}

int			ft_norme(char *str, int i, int ret)
{
	char	*strr;
	char	*tmp;
	int		n;

	n = i++;
	while (str[i] == '5')
		i++;
	strr = ft_strsub(str, i, 1);
	i = n;
	n = 0;
	if (str[0] == '-')
		n++;
	if (ft_atoi(strr) > 5)
	{
		while (n < i - 1 && str[n])
			ret = ft_normes(str, ret, &n);
		tmp = ft_strsub(str, i - 1, 1);
		ret = ft_union4(tmp, ret);
		ft_strdel(&tmp);
	}
	else
		while (n < i && str[n])
			ret = ft_normes(str, ret, &n);
	ft_strdel(&strr);
	return (ret);
}
