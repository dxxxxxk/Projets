/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:19:42 by dieroyer          #+#    #+#             */
/*   Updated: 2018/11/15 23:26:42 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!(s1 || s2) || n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && n-- > 1)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
