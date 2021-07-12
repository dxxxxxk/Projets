/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:42:22 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:42:23 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int				ft_print_conversion(va_list args, t_opt *val)
{
	long long int			len;

	if (val->len == 'h')
		len = (short int)va_arg(args, int);
	else if (val->len == 'q')
		len = (signed char)va_arg(args, int);
	else if (val->len == 'l' || val->len == 'p')
	{
		if (val->len == 'l')
			len = (long int)va_arg(args, long int);
		if (val->len == 'p')
			len = (long long int)va_arg(args, long long int);
		if (len == -9223372036854775807 - 1)
		{
			ft_putstr("-9223372036854775808");
			return (05012000);
		}
	}
	else
		len = (int)va_arg(args, int);
	return (len);
}

unsigned long long int		ft_print_conversions(va_list args, t_opt *val)
{
	unsigned long long int	len;

	if (val->len == 'h')
		len = (unsigned short int)va_arg(args, unsigned int);
	else if (val->len == 'q')
		len = (unsigned char)va_arg(args, unsigned int);
	else if (val->len == 'l')
		len = (unsigned long int)va_arg(args, unsigned long int);
	else if (val->len == 'p')
		len = (unsigned long long int)va_arg(args, unsigned long long int);
	else
		len = (unsigned int)va_arg(args, unsigned int);
	return (len);
}

long double					ft_print_conv(va_list args, t_opt *val)
{
	long double				len;

	if (val->len == 'l')
		len = (long int)va_arg(args, long int);
	else if (val->len == 'L')
		len = (long double)va_arg(args, long double);
	else
		len = (double)va_arg(args, double);
	if (len == 1.0 / 0.0 + 0)
		len = 05012002;
	if (len == -1.0 / 0.0 + 0)
		len = 05012001;
	if (len != len)
		len = 05012000;
	return (len);
}
