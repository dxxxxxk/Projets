/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:59:14 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:59:16 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_union(char *str, char *tmp, char *tmp2, long double len)
{
	int		i;

	i = 0;
	len *= 10000000;
	if (len == 0)
	{
		tmp = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp, "0");
		ft_strdel(&tmp);
	}
	else
	{
		i = (long int)(len);
		tmp = ft_strdup(str);
		tmp2 = ft_itoa(i);
		ft_strdel(&str);
		str = ft_strjoin(tmp, tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	return (str);
}

char	*ft_union2(char *str, long int intpart, char *tmp)
{
	if (intpart == 0)
		str = ft_strjoin("0", ".");
	else
	{
		tmp = ft_itoa(intpart);
		str = ft_strjoin(tmp, ".");
		ft_strdel(&tmp);
	}
	return (str);
}

char	*ft_union3(char *str, char *tmp)
{
	tmp = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strjoin(tmp, "000000");
	ft_strdel(&tmp);
	return (str);
}

int		ft_union4(char *tmp, int ret)
{
	ft_printf("%d", ft_atoi(tmp) + 1);
	ret++;
	return (ret);
}

int		ft_union5(const char *format, int i, t_opt *val)
{
	if (format[i] == '-')
		val->m = format[i];
	else if (format[i] == '+')
		val->p = format[i];
	else if (format[i] == '#')
		val->d = format[i];
	else if (format[i] == ' ')
		val->e = format[i];
	else
		val->z = format[i];
	i++;
	return (i);
}
