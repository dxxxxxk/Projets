/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func_fillit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:51:07 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/17 14:11:22 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "func_fillit.h"

void	ft_free_list(t_pieces *elem)
{
	t_pieces	*tempo;

	while (elem)
	{
		tempo = elem->next;
		free(elem);
		elem = tempo;
	}
}

void	ft_free_tab(char ***tab)
{
	int		i;

	i = 0;
	if (tab == NULL || *tab == NULL || **tab == NULL)
		return ;
	while ((*tab)[i])
	{
		ft_strdel(&(*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}
