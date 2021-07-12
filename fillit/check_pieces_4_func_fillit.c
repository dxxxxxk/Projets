/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces_4_func_fillit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:55:19 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/17 13:55:24 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_l_8(char *str)
{
	if (!ft_strcmp(str, "###.\n#...\n....\n....\n")
			|| !ft_strcmp(str, "....\n###.\n#...\n....\n")
			|| !ft_strcmp(str, "....\n....\n###.\n#...\n")
			|| !ft_strcmp(str, ".###\n.#..\n....\n....\n")
			|| !ft_strcmp(str, "....\n.###\n.#..\n....\n")
			|| !ft_strcmp(str, "....\n....\n.###\n.#..\n"))
		return (1);
	return (0);
}

int		ft_check_s_2(char *str)
{
	if (!ft_strcmp(str, "#...\n##..\n.#..\n....\n")
			|| !ft_strcmp(str, ".#..\n.##.\n..#.\n....\n")
			|| !ft_strcmp(str, "..#.\n..##\n...#\n....\n")
			|| !ft_strcmp(str, "....\n#...\n##..\n.#..\n")
			|| !ft_strcmp(str, "....\n.#..\n.##.\n..#.\n")
			|| !ft_strcmp(str, "....\n..#.\n..##\n...#\n"))
		return (1);
	return (0);
}

int		ft_check_z_2(char *str)
{
	if (!ft_strcmp(str, "...#\n..##\n..#.\n....\n")
			|| !ft_strcmp(str, "..#.\n.##.\n.#..\n....\n")
			|| !ft_strcmp(str, ".#..\n##..\n#...\n....\n")
			|| !ft_strcmp(str, "....\n...#\n..##\n..#.\n")
			|| !ft_strcmp(str, "....\n..#.\n.##.\n.#..\n")
			|| !ft_strcmp(str, "....\n.#..\n##..\n#...\n"))
		return (1);
	return (0);
}

int		ft_check_t_3(char *str)
{
	if (!ft_strcmp(str, "#...\n##..\n#...\n....\n")
			|| !ft_strcmp(str, ".#..\n.##.\n.#..\n....\n")
			|| !ft_strcmp(str, "..#.\n..##\n..#.\n....\n")
			|| !ft_strcmp(str, "....\n#...\n##..\n#...\n")
			|| !ft_strcmp(str, "....\n.#..\n.##.\n.#..\n")
			|| !ft_strcmp(str, "....\n..#.\n..##\n..#.\n"))
		return (1);
	return (0);
}

int		ft_check_t_4(char *str)
{
	if (!ft_strcmp(str, ".#..\n##..\n.#..\n....\n")
			|| !ft_strcmp(str, "..#.\n.##.\n..#.\n....\n")
			|| !ft_strcmp(str, "...#\n..##\n...#\n....\n")
			|| !ft_strcmp(str, "....\n.#..\n##..\n.#..\n")
			|| !ft_strcmp(str, "....\n..#.\n.##.\n..#.\n")
			|| !ft_strcmp(str, "....\n...#\n..##\n...#\n"))
		return (1);
	return (0);
}
