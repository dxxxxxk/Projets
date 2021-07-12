/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func_fillit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:00:59 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/26 12:15:47 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_fillit.h"
#include <stdlib.h>

t_pieces	*ft_create_elem_piece(int tp, char a)
{
	t_pieces	*elem;

	if ((elem = (t_pieces*)malloc(sizeof(*elem))) == NULL)
		return (NULL);
	elem->a = a;
	elem->type = tp;
	elem->bfr = NULL;
	elem->next = NULL;
	return (elem);
}

void		ft_append_elem_piece(t_pieces *first, t_pieces *elem)
{
	if (first == NULL)
		return ;
	while (first->next)
		first = first->next;
	elem->bfr = first;
	first->next = elem;
}
