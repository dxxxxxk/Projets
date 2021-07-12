/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:32:13 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/29 18:05:33 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int		count_words(const char *s, char c)
{
	int		i;
	int		count;

	if (s == NULL)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char		**insert_them(char **tab, const char *s, char c, int size)
{
	int		i;
	int		a;
	int		j;

	j = 0;
	a = 0;
	i = 0;
	if (tab == NULL || s == NULL)
		return (NULL);
	while (a < size)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			tab[a][j] = s[i];
			i++;
			j++;
		}
		tab[a][j] = '\0';
		j = 0;
		a++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		size;

	if (s == NULL)
		return (NULL);
	size = count_words(s, c);
	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * size + 1)) == NULL)
		return (NULL);
	tab[size] = 0;
	while (i < size)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		{
			i--;
			while (i > -1)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	return (insert_them(tab, s, c, size));
}
