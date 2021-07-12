/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pieces_4_func_fillit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:53:16 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/17 18:09:08 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_write_z_2(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.' && tab[i + 1] && tab[i + 2]
			&& tab[i + 1][j] == '.' && j - 1 >= 0
			&& tab[i + 1][j - 1] == '.'
			&& tab[i + 2][j - 1] == '.')
	{
		tab[i][j] = '#';
		tab[i + 1][j] = '#';
		tab[i + 1][j - 1] = '#';
		tab[i + 2][j - 1] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_t(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.'
			&& tab[i][j + 1] && tab[i][j + 2]
			&& tab[i][j + 1] == '.'
			&& tab[i][j + 2] == '.' && tab[i + 1]
			&& tab[i + 1][j + 1] == '.')
	{
		tab[i][j] = '#';
		tab[i][j + 1] = '#';
		tab[i][j + 2] = '#';
		tab[i + 1][j + 1] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_t_2(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.'
			&& tab[i + 1] && j - 1 >= 0 && tab[i][j + 1]
			&& tab[i + 1][j] == '.'
			&& tab[i + 1][j - 1] == '.'
			&& tab[i + 1][j + 1] == '.')
	{
		tab[i][j] = '#';
		tab[i + 1][j] = '#';
		tab[i + 1][j - 1] = '#';
		tab[i + 1][j + 1] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_t_3(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.'
			&& tab[i + 1] && tab[i + 2] && tab[i][j + 1]
			&& tab[i + 1][j] == '.'
			&& tab[i + 1][j + 1] == '.'
			&& tab[i + 2][j] == '.')
	{
		tab[i][j] = '#';
		tab[i + 1][j] = '#';
		tab[i + 1][j + 1] = '#';
		tab[i + 2][j] = '#';
		return (1);
	}
	return (0);
}

int	ft_write_t_4(char **tab, int i, int j)
{
	if (tab[i] && tab[i][j] && tab[i][j] == '.'
			&& tab[i + 1] && tab[i + 2] && j - 1 >= 0
			&& tab[i + 1][j] == '.'
			&& tab[i + 2][j] == '.'
			&& tab[i + 1][j - 1] == '.')
	{
		tab[i][j] = '#';
		tab[i + 1][j] = '#';
		tab[i + 2][j] = '#';
		tab[i + 1][j - 1] = '#';
		return (1);
	}
	return (0);
}
