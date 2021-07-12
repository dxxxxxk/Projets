/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces_2_func_fillit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:54:18 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/17 13:54:23 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_s(char *str)
{
	if (!ft_strcmp(str, ".##.\n##..\n....\n....\n")
			|| !ft_strcmp(str, "..##\n.##.\n....\n....\n")
			|| !ft_strcmp(str, "....\n.##.\n##..\n....\n")
			|| !ft_strcmp(str, "....\n..##\n.##.\n....\n")
			|| !ft_strcmp(str, "....\n....\n.##.\n##..\n")
			|| !ft_strcmp(str, "....\n....\n..##\n.##.\n"))
		return (1);
	return (0);
}

int		ft_check_z(char *str)
{
	if (!ft_strcmp(str, "##..\n.##.\n....\n....\n")
			|| !ft_strcmp(str, ".##.\n..##\n....\n....\n")
			|| !ft_strcmp(str, "....\n##..\n.##.\n....\n")
			|| !ft_strcmp(str, "....\n.##.\n..##\n....\n")
			|| !ft_strcmp(str, "....\n....\n##..\n.##.\n")
			|| !ft_strcmp(str, "....\n....\n.##.\n..##\n"))
		return (1);
	return (0);
}

int		ft_check_t(char *str)
{
	if (!ft_strcmp(str, "###.\n.#..\n....\n....\n")
			|| !ft_strcmp(str, ".###\n..#.\n....\n....\n")
			|| !ft_strcmp(str, "....\n###.\n.#..\n....\n")
			|| !ft_strcmp(str, "....\n.###\n..#.\n....\n")
			|| !ft_strcmp(str, "....\n....\n###.\n.#..\n")
			|| !ft_strcmp(str, "....\n....\n.###\n..#.\n"))
		return (1);
	return (0);
}

int		ft_check_t_2(char *str)
{
	if (!ft_strcmp(str, ".#..\n###.\n....\n....\n")
			|| !ft_strcmp(str, "..#.\n.###\n....\n....\n")
			|| !ft_strcmp(str, "....\n.#..\n###.\n....\n")
			|| !ft_strcmp(str, "....\n..#.\n.###\n....\n")
			|| !ft_strcmp(str, "....\n....\n.#..\n###.\n")
			|| !ft_strcmp(str, "....\n....\n..#.\n.###\n"))
		return (1);
	return (0);
}
