/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:53:11 by dieroyer          #+#    #+#             */
/*   Updated: 2019/10/16 14:42:08 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	long long	*tab2;
	long long	*tab;
	t_push		tmp;

	if (ac == 1)
		return (0);
	else
	{
		if (!(tab = fill_tab(ac, av, &tmp)))
		{
			if (tab)
				free(tab);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	if ((!(tab2 = (long long*)malloc(tmp.l * sizeof(long long))))
	|| tmp.fd == -1)
		return (0);
	ft_print_fd(tab, tab2, tmp);
	return (0);
}

void	ft_print_fd(long long *tab, long long *tab2, t_push tmp)
{
	char *str;

	ft_fill_b(tab2, tmp.l);
	while (get_next_line(0, &str) == 1)
	{
		if (ft_move_compare(str, tab, tab2, tmp.l))
		{
			ft_putstr_fd("Error\n", 2);
			ft_strdel(&str);
			return ;
		}
		ft_strdel(&str);
	}
	ft_print_ok(tab, tmp.l);
	free(tab);
	free(tab2);
}
