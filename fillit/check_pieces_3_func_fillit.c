/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces_3_func_fillit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:54:48 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/17 13:54:51 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_bars_vertical(char *str)
{
	if (!ft_strcmp(str, "#...\n#...\n#...\n#...\n")
			|| !ft_strcmp(str, ".#..\n.#..\n.#..\n.#..\n")
			|| !ft_strcmp(str, "..#.\n..#.\n..#.\n..#.\n")
			|| !ft_strcmp(str, "...#\n...#\n...#\n...#\n"))
		return (1);
	return (0);
}

int		ft_check_l_4(char *str)
{
	if (!ft_strcmp(str, "...#\n...#\n..##\n....\n")
			|| !ft_strcmp(str, "..#.\n..#.\n.##.\n....\n")
			|| !ft_strcmp(str, ".#..\n.#..\n##..\n....\n")
			|| !ft_strcmp(str, "....\n...#\n...#\n..##\n")
			|| !ft_strcmp(str, "....\n..#.\n..#.\n.##.\n")
			|| !ft_strcmp(str, "....\n.#..\n.#..\n##..\n"))
		return (1);
	return (0);
}

int		ft_check_l_5(char *str)
{
	if (!ft_strcmp(str, "..##\n...#\n...#\n....\n")
			|| !ft_strcmp(str, ".##.\n..#.\n..#.\n....\n")
			|| !ft_strcmp(str, "##..\n.#..\n.#..\n....\n")
			|| !ft_strcmp(str, "....\n..##\n...#\n...#\n")
			|| !ft_strcmp(str, "....\n.##.\n..#.\n..#.\n")
			|| !ft_strcmp(str, "....\n##..\n.#..\n.#..\n"))
		return (1);
	return (0);
}

int		ft_check_l_6(char *str)
{
	if (!ft_strcmp(str, "...#\n.###\n....\n....\n")
			|| !ft_strcmp(str, "....\n...#\n.###\n....\n")
			|| !ft_strcmp(str, "....\n....\n...#\n.###\n")
			|| !ft_strcmp(str, "..#.\n###.\n....\n....\n")
			|| !ft_strcmp(str, "....\n..#.\n###.\n....\n")
			|| !ft_strcmp(str, "....\n....\n..#.\n###.\n"))
		return (1);
	return (0);
}

int		ft_check_l_7(char *str)
{
	if (!ft_strcmp(str, "#...\n###.\n....\n....\n")
			|| !ft_strcmp(str, "....\n#...\n###.\n....\n")
			|| !ft_strcmp(str, "....\n....\n#...\n###.\n")
			|| !ft_strcmp(str, ".#..\n.###\n....\n....\n")
			|| !ft_strcmp(str, "....\n.#..\n.###\n....\n")
			|| !ft_strcmp(str, "....\n....\n.#..\n.###\n"))
		return (1);
	return (0);
}
