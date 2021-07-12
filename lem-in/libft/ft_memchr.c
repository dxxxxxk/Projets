/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:04:52 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:04:54 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	ct;
	size_t	i;

	str = (char *)s;
	ct = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ct)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
