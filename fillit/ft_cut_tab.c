/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:46:53 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/16 15:23:39 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_lines(char **tab, int size)
{
	int		tempo;
	int		j;

	tempo = size;
	j = 0;
	while (tab[j])
	{
		if (tab[j][size] != '.')
			return (0);
		j++;
	}
	size = tempo;
	j = 0;
	while (tab[size][j])
	{
		if (tab[size][j] != '.')
			return (0);
		j++;
	}
	return (1);
}

char			**ft_cut_tab(char **tab)
{
	int		size;
	int		i;

	if (tab == NULL || *tab == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(tab[0]) - 1;
	while (ft_check_lines(tab, size))
		size--;
	size++;
	if (tab[0][size] != '.')
		return (tab);
	tab[size][0] = '1';
	while (tab[i])
	{
		tab[i][size] = '1';
		i++;
	}
	return (tab);
}
