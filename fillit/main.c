/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:48:03 by aljigmon          #+#    #+#             */
/*   Updated: 2019/04/04 13:32:57 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_fillit.h"
#include <fcntl.h>
#include <unistd.h>

static void		ft_start(int *nb_p, int ac)
{
	*nb_p = 0;
	if (ac - 1 != 1)
		ft_usage(0, NULL);
}

static void		ft_finish(const int fd, char **tab, t_pieces *elem)
{
	tab = ft_cut_tab(tab);
	ft_display_2d(tab);
	ft_free_list(elem);
	ft_free_tab(&tab);
	close(fd);
}

int				main(int ac, char **av)
{
	int			fd;
	t_pieces	*elem;
	char		**tab;
	int			nb_pieces;

	ft_start(&nb_pieces, ac);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_usage(1, NULL);
	if ((elem = ft_read_file(fd, &nb_pieces, NULL, 'A')) == NULL)
		ft_usage(1, NULL);
	if (nb_pieces > 12)
		nb_pieces = ft_sqrt_fillit(nb_pieces) * 2;
	else
		nb_pieces = ft_sqrt_fillit(nb_pieces);
	if (!(tab = ft_solver(elem, nb_pieces, 0)))
		ft_usage(2, elem);
	while (ft_make_bigger(elem, tab))
	{
		ft_free_tab(&tab);
		nb_pieces++;
		if (!(tab = ft_solver(elem, nb_pieces, 0)))
			ft_usage(2, elem);
	}
	ft_finish(fd, tab, elem);
	return (0);
}
