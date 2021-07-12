/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:04:33 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:04:34 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*s;

	dest = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		*dest = *s;
		if (*s == (unsigned char)c)
			return (dest + 1);
		dest++;
		s++;
	}
	return (NULL);
}
