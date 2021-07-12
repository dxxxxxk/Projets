/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_bigger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:11:38 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/17 17:12:58 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_fillit.h"

int				ft_make_bigger(t_pieces *elem, char **tab)
{
	int		size;
	char	*alphabet;
	int		i;
	int		j;

	size = 0;
	i = 0;
	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (elem)
	{
		elem = elem->next;
		size++;
	}
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == alphabet[size - 1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
