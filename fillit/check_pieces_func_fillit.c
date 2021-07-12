/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces_func_fillit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:46:46 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/17 12:16:08 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_squares(char *str)
{
	if (!ft_strcmp(str, "##..\n##..\n....\n....\n")
			|| !ft_strcmp(str, ".##.\n.##.\n....\n....\n")
			|| !ft_strcmp(str, "..##\n..##\n....\n....\n")
			|| !ft_strcmp(str, "....\n##..\n##..\n....\n")
			|| !ft_strcmp(str, "....\n.##.\n.##.\n....\n")
			|| !ft_strcmp(str, "....\n..##\n..##\n....\n")
			|| !ft_strcmp(str, "....\n....\n##..\n##..\n")
			|| !ft_strcmp(str, "....\n....\n.##.\n.##.\n")
			|| !ft_strcmp(str, "....\n....\n..##\n..##\n"))
		return (1);
	return (0);
}

int		ft_check_bars(char *str)
{
	if (!ft_strcmp(str, "####\n....\n....\n....\n")
			|| !ft_strcmp(str, "....\n####\n....\n....\n")
			|| !ft_strcmp(str, "....\n....\n####\n....\n")
			|| !ft_strcmp(str, "....\n....\n....\n####\n"))
		return (1);
	return (0);
}

int		ft_check_l(char *str)
{
	if (!ft_strcmp(str, "#...\n#...\n##..\n....\n")
			|| !ft_strcmp(str, ".#..\n.#..\n.##.\n....\n")
			|| !ft_strcmp(str, "..#.\n..#.\n..##\n....\n")
			|| !ft_strcmp(str, "....\n#...\n#...\n##..\n")
			|| !ft_strcmp(str, "....\n.#..\n.#..\n.##.\n")
			|| !ft_strcmp(str, "....\n..#.\n..#.\n..##\n"))
		return (1);
	return (0);
}

int		ft_check_l_2(char *str)
{
	if (!ft_strcmp(str, "##..\n#...\n#...\n....\n")
			|| !ft_strcmp(str, ".##.\n.#..\n.#..\n....\n")
			|| !ft_strcmp(str, "..##\n..#.\n..#.\n....\n")
			|| !ft_strcmp(str, "....\n##..\n#...\n#...\n")
			|| !ft_strcmp(str, "....\n.##.\n.#..\n.#..\n")
			|| !ft_strcmp(str, "....\n..##\n..#.\n..#.\n"))
		return (1);
	return (0);
}

int		ft_check_l_3(char *str)
{
	if (!ft_strcmp(str, ".###\n...#\n....\n....\n")
			|| !ft_strcmp(str, "....\n.###\n...#\n....\n")
			|| !ft_strcmp(str, "....\n....\n.###\n...#\n")
			|| !ft_strcmp(str, "###.\n..#.\n....\n....\n")
			|| !ft_strcmp(str, "....\n###.\n..#.\n....\n")
			|| !ft_strcmp(str, "....\n....\n###.\n..#.\n"))
		return (1);
	return (0);
}
