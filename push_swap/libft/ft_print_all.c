/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:43:09 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:43:11 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_all(t_opt *val, va_list args, int ret)
{
	if (val->type == 'c' || val->type == '%')
		ret = ft_print_c(val, args, ret);
	else if (val->type == 's')
		ret = ft_print_s(val, args, ret);
	else if (val->type == 'p')
		ret = ft_print_p(val, args, ret);
	else if (val->type == 'd' || val->type == 'i')
		ret = ft_print_d(val, args, ret);
	else if (val->type == 'o')
		ret = ft_print_o(val, args, ret);
	else if (val->type == 'u')
		ret = ft_print_u(val, args, ret);
	else if (val->type == 'x')
		ret = ft_print_x(val, args, ret);
	else if (val->type == 'X')
		ret = ft_print_xx(val, args, ret);
	else if (val->type == 'f')
		ret = ft_print_f(val, args, ret);
	else if (val->type != '\0')
	{
		ft_putchar(val->type);
		ret++;
	}
	return (ret);
}
