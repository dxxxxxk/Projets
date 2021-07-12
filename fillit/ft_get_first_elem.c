/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_first_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:04:50 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/28 14:07:16 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_fillit.h"
#include <stdlib.h>

t_pieces	*ft_get_first_elem(t_pieces *elem)
{
	if (elem != NULL)
		while (elem->bfr)
			elem = elem->bfr;
	return (elem);
}
