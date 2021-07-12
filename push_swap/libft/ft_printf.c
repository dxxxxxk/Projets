/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:41:11 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:41:13 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nnnnormes(const char *format, int i, t_opt *val)
{
	int		u;
	char	*tmp;

	while (format[i] == '-' || format[i] == '+' || format[i] == '#'
	|| format[i] == '0' || format[i] == ' ')
		i = ft_union5(format, i, val);
	if (ft_isdigit(format[i]) && format[i] != '0')
	{
		u = i;
		while (ft_isdigit(format[i]))
			i++;
		tmp = ft_strsub(format, u, i - u);
		val->larg = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
	return (i);
}

int			ft_nnnnnorm(const char *format, int i, t_opt *val)
{
	int		u;
	char	*tmp;

	if (format[i] == '.')
	{
		val->po = '.';
		u = ++i;
		if (!ft_isdigit(format[i]) || format[i] == '-')
			val->preci = 0;
		else
		{
			while (ft_isdigit(format[i]))
				i++;
			tmp = ft_strsub(format, u, i - u);
			val->preci = ft_atoi(tmp);
			ft_strdel(&tmp);
		}
	}
	return (i);
}

int			ft_analyse(const char *format, int i, t_opt *val)
{
	i++;
	i = ft_nnnnormes(format, i, val);
	i = ft_nnnnnorm(format, i, val);
	if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L')
	{
		i++;
		if (format[i] == 'h')
			val->len = 'q';
		else if (format[i] == 'l')
			val->len = 'p';
		else
		{
			i--;
			val->len = format[i];
		}
		i++;
	}
	if (format[i] != '\0')
	{
		val->type = format[i];
		i++;
	}
	return (i);
}

int			ft_format(int *i, int ret, const char *format)
{
	while (format[*i] != '%' && format[*i])
	{
		ft_putchar(format[*i]);
		ret++;
		*i = *i + 1;
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	args;
	t_opt	val;

	ret = 0;
	i = 0;
	va_start(args, format);
	ft_initialisation(&val);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
			ret = ft_format(&i, ret, format);
		if (format[i] == '%')
		{
			i = ft_analyse(format, i, &val);
			ret = ft_print_all(&val, args, ret);
			ft_initialisation(&val);
		}
	}
	va_end(args);
	return (ret);
}
