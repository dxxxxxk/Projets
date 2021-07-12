/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:36:03 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/29 18:07:36 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strreplace(char *str, char c, char r)
{
	char	*s;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	if ((s = (char*)malloc(sizeof(*s) * ft_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			s[i++] = r;
		else
		{
			s[i] = str[i];
			i++;
		}
	}
	s[i] = '\0';
	return (s);
}
