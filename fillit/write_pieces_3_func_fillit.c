/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pieces_3_func_fillit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:53:05 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/17 18:03:07 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_write_l_7(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.' && tab[i + 1]
			&& tab[i + 1][j] == '.' && tab[i][j + 1] && tab[i][j + 2]
			&& tab[i + 1][j + 1] == '.'
			&& tab[i + 1][j + 2] == '.')
	{
		tab[i][j] = '#';
		tab[i + 1][j] = '#';
		tab[i + 1][j + 1] = '#';
		tab[i + 1][j + 2] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_l_8(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.' && tab[i + 1]
			&& tab[i + 1][j] == '.'
			&& tab[i][j + 1] && tab[i][j + 2] && tab[i][j + 1] == '.'
			&& tab[i][j + 2] == '.')
	{
		tab[i][j] = '#';
		tab[i + 1][j] = '#';
		tab[i][j + 1] = '#';
		tab[i][j + 2] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_s(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.' && tab[i][j + 1]
			&& tab[i][j + 1] == '.'
			&& tab[i + 1] && tab[i + 1][j] == '.'
			&& j - 1 >= 0 && tab[i + 1][j - 1] == '.')
	{
		tab[i][j] = '#';
		tab[i][j + 1] = '#';
		tab[i + 1][j] = '#';
		tab[i + 1][j - 1] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_s_2(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.' && tab[i + 1]
			&& tab[i + 2] && tab[i + 1][j] == '.'
			&& tab[i][j + 1] && tab[i + 1][j + 1] == '.'
			&& tab[i + 2][j + 1] == '.')
	{
		tab[i][j] = '#';
		tab[i + 1][j] = '#';
		tab[i + 1][j + 1] = '#';
		tab[i + 2][j + 1] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_z(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.'
			&& tab[i][j + 1] && tab[i][j + 2]
			&& tab[i][j + 1] == '.' && tab[i + 1]
			&& tab[i + 1][j + 1] == '.'
			&& tab[i + 1][j + 2] == '.')
	{
		tab[i][j] = '#';
		tab[i][j + 1] = '#';
		tab[i + 1][j + 1] = '#';
		tab[i + 1][j + 2] = '#';
		return (1);
	}
	return (0);
}
