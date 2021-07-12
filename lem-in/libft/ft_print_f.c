/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:42:06 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:42:08 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_power(long double len, int pow, char *str)
{
	long int	i;
	char		*tmp;
	char		*tmp2;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	if (pow == 0)
		str = ft_union(str, tmp, tmp2, len);
	else if (i < pow)
	{
		while (i++ < pow)
			len *= 10;
		if (len == 0)
			while (pow-- != 0)
			{
				tmp = ft_strdup(str);
				ft_strdel(&str);
				str = ft_strjoin(tmp, "0");
				ft_strdel(&tmp);
			}
		else
			str = ft_norm(&i, len, str);
	}
	return (str);
}

static	char	*ft_itoa_float(long double len, t_opt *val)
{
	long int	decipart;
	long int	intpart;
	char		*str;
	char		*tmp;

	tmp = NULL;
	str = NULL;
	decipart = 0;
	intpart = (long int)len;
	str = ft_union2(str, intpart, tmp);
	len -= intpart;
	if (len < 0)
		len *= -1;
	if (val->preci == 6 || val->preci == -42)
	{
		len *= 1000000;
		if (len == 0)
			str = ft_union3(str, tmp);
		else
			str = ft_norm(&decipart, len, str);
	}
	else
		str = ft_power(len, val->preci, str);
	return (str);
}

int				ft_print_preci(t_opt *val, char *str, int ret)
{
	int			i;
	int			retenu;

	retenu = 0;
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (val->po == '.')
		ret = ft_nnorm(str, i, ret, val);
	else
	{
		i = 0;
		if (str[i] == '-')
			i++;
		while (str[i])
			ret = ft_normes(str, ret, &i);
	}
	if (val->preci <= 0 && val->d == '#' && val->po == '.')
	{
		ft_putchar('.');
		ret++;
	}
	return (ret);
}

char			*ft_nnorme(t_opt *val, long double lenn, int *len)
{
	char		*str;

	if (lenn == 05012002)
		str = ft_strdup("inf");
	else if (lenn == 05012000)
		str = ft_strdup("nan");
	else if (lenn == 05012001)
		str = ft_strdup("-inf");
	else
		str = ft_itoa_float(lenn, val);
	*len = ft_strlen(str);
	if (lenn == 05012002 || lenn == 05012000 || lenn == 05012001)
		val->len = 'y';
	if (val->preci <= 0 && val->po == '.' && val->len != 'y')
	{
		*len = 0;
		while (str[*len] != '.')
			*len = *len + 1;
	}
	return (str);
}

int				ft_print_f(t_opt *val, va_list args, int ret)
{
	char		*str;
	long double lenn;
	int			len;

	lenn = ft_print_conv(args, val);
	str = ft_nnorme(val, lenn, &len);
	ret = ft_nnormes(val, str, ret, &len);
	ret = ft_nnnorm(val, str, ret, &len);
	if (val->preci >= 0)
	{
		ret = ft_nnnorme(val, str, ret, &len);
		ret = ft_nnnormes(val, str, ret, &len);
	}
	else
		ret = ft_nnnnorm(val, str, ret);
	len = ft_strlen(str);
	ret = ft_nnnnorme(val, str, &len, ret);
	ft_strdel(&str);
	return (ret);
}
