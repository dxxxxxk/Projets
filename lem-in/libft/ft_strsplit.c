/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:55:18 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:55:22 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int			ft_str_len(char const *s, char c)
{
	int	len;
	int i;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**output;

	if (!s || !(output = (char**)malloc(sizeof(char*) * (
						ft_count_words(s, c) + 1))))
		return (0);
	i = 0;
	k = 0;
	while (i < ft_count_words(s, c))
	{
		j = 0;
		if (!(output[i] = ft_strnew(ft_str_len(&s[k], c) + 1)))
			output[i] = NULL;
		while (s[k] == c)
			k++;
		while (s[k] && s[k] != c)
			output[i][j++] = s[k++];
		output[i++][j] = '\0';
	}
	output[i] = 0;
	return (output);
}
