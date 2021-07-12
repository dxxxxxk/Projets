/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:06:00 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:06:01 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_operation(t_opt *val, int ret, char *str)
{
	if (val->e == ' ' && val->m == '\0' && val->p == '\0' && str[0] != '-'
	&& val->d == '\0' && val->larg <= (int)ft_strlen(str)
	&& val->len == '\0')
	{
		ft_putchar(' ');
		ret++;
	}
	else if (val->e == ' ' && (val->len == 'q' || val->len == 'l'
	|| val->len == 'p'))
	{
		ft_putchar(' ');
		ret++;
	}
	return (ret);
}
