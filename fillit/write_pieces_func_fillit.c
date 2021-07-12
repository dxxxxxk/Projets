/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pieces_func_fillit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 12:00:21 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/17 17:54:33 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_write_squares(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.'
			&& tab[i][j + 1] && tab[i][j + 1] == '.'
			&& tab[i + 1] && tab[i + 1][j] == '.'
			&& tab[i + 1][j + 1] == '.')
	{
		tab[i][j] = '#';
		tab[i][j + 1] = '#';
		tab[i + 1][j] = '#';
		tab[i + 1][j + 1] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_bars(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j + 1]
			&& tab[i][j + 2] && tab[i][j + 3]
			&& tab[i][j] == '.' && tab[i][j + 1] == '.'
			&& tab[i][j + 2] == '.'
			&& tab[i][j + 3] == '.')
	{
		tab[i][j] = '#';
		tab[i][j + 1] = '#';
		tab[i][j + 2] = '#';
		tab[i][j + 3] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_bars_vertical(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i + 1] && tab[i + 2] && tab[i + 3]
			&& tab[i][j] == '.'
			&& tab[i + 1][j] == '.'
			&& tab[i + 2][j] == '.'
			&& tab[i + 3][j] == '.')
	{
		tab[i][j] = '#';
		tab[i + 1][j] = '#';
		tab[i + 2][j] = '#';
		tab[i + 3][j] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_l(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j + 1] && tab[i + 1] && tab[i + 2]
			&& tab[i][j] == '.'
			&& tab[i + 1][j] == '.'
			&& tab[i + 2][j] == '.'
			&& tab[i + 2][j + 1] == '.')
	{
		tab[i][j] = '#';
		tab[i + 1][j] = '#';
		tab[i + 2][j] = '#';
		tab[i + 2][j + 1] = '#';
		return (1);
	}
	return (0);
}
