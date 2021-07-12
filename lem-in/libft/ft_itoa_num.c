/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:04:13 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:04:16 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_sign(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static	char	*ft_tab(int num)
{
	char	*tab;

	if (num == 0)
		tab = "0123456789abcdef";
	else if (num == 1)
		tab = "0123456789ABCDEF";
	else if (num == 2)
		tab = "0123456789";
	else
		tab = "01234567";
	return (tab);
}

char			*ft_itoa_num(unsigned long long int val, int base, int num)
{
	char					*str;
	char					*tab;
	unsigned long long int	size;
	unsigned long long int	tmp;

	tab = ft_tab(num);
	tmp = val;
	size = 0;
	while (tmp /= base)
		size++;
	size += 1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_sign(val % base)];
		size--;
		val /= base;
	}
	return (str);
}
