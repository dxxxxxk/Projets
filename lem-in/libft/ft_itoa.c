/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:58:24 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:58:25 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_num_digit(int n)
{
	long		length;

	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static int		ft_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	long		num;
	long		len;
	char		*str;

	num = n;
	len = ft_num_digit(num);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	if (num < 0)
		num = -num;
	while (len >= 0)
	{
		str	[len] = (num % 10) + '0';
		len--;
		num /= 10;
	}
	if (ft_neg(n))
		str[0] = '-';
	return (str);
}
