/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:43:18 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:43:19 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_opt *val, va_list args, int ret)
{
	int		i;

	i = 0;
	if (val->m != '-' && val->larg > 0)
		ret = ft_opt(val, 1, ret);
	if (val->type == '%')
		ft_putchar('%');
	else
		ft_putchar((unsigned char)va_arg(args, int));
	ret++;
	if (val->m == '-' && val->larg > 0)
		ret = ft_opt(val, 1, ret);
	return (ret);
}
