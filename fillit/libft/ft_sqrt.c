/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:35:52 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/29 18:07:12 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		i;

	i = 1;
	while (i <= nb)
	{
		if (ft_power(i, 2) == nb)
			return (i);
		i++;
	}
	return (0);
}
