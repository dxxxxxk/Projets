/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:35:51 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/29 18:08:03 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstappend(t_list **first, t_list *elem)
{
	t_list	*tmp;

	if (first == NULL || elem == NULL || *first == NULL)
		return ;
	tmp = *first;
	while (tmp->next)
	{
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
	{
		tmp->next = elem;
		elem->next = NULL;
	}
}
