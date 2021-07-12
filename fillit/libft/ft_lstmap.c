/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:09:10 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/29 18:06:59 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	ft_liberation(t_list *first)
{
	t_list		*tempo;

	while (first != NULL)
	{
		tempo = first->next;
		free(first);
		first = tempo;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*first;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((new = f(lst)) == NULL)
		return (NULL);
	first = new;
	lst = lst->next;
	while (lst != NULL)
	{
		new->next = f(lst);
		if (new == NULL)
		{
			ft_liberation(first);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (first);
}
