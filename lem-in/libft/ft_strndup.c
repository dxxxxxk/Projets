/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:01:27 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:01:28 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		cmp;
	size_t	i;
	char	*dest;

	cmp = 0;
	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (s1[cmp] && i < n)
	{
		dest[cmp] = s1[cmp];
		cmp++;
		i++;
	}
	dest[cmp] = '\0';
	return (dest);
}
