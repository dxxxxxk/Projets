/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_piece_func_fillit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:34:05 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/29 16:43:08 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_del(char **tab, char a, int *ip, int *jp)
{
	int		i;
	int		j;
	int		first;

	i = 0;
	first = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (first && tab[i][j] == a)
			{
				first = 0;
				*ip = i;
				*jp = j;
			}
			if (tab[i][j] == a)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}
