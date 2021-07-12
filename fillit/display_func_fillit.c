/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_fillit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:56:40 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/26 12:09:19 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "func_fillit.h"

void	ft_usage(int state, t_pieces *elem)
{
	if (elem != NULL)
	{
		while (elem->bfr)
			elem = elem->bfr;
		ft_free_list(elem);
	}
	if (state == 0)
	{
		ft_putstr("usage: The program takes only one argument\n");
		ft_putstr("Example: ./fillit source_file\n");
	}
	else if (state == 1)
		ft_putendl("error");
	exit(EXIT_FAILURE);
}

void	ft_display_2d(char **tab)
{
	int		i;
	int		j;

	if (*tab == NULL || tab == NULL)
		return ;
	i = 0;
	while (tab[i] && tab[i][0] != '1')
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != '1')
			ft_putchar(tab[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
