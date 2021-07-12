/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:05:12 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:05:13 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*s;

	dest = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dest == s)
		return (dst);
	if (dest > s)
	{
		i = len;
		while (i--)
			dest[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = s[i];
			i++;
		}
	}
	return (dst);
}
