#include "lemin.h"

int		print_final(t_lem *data, int *tab, int r)
{
	int	i;
	int nbf;
	int k;
	int	j;
	int nbc;

	nbc = 0;
	j = 1;
	i = 0;
	nbf = data->f;
	k = 0;
	while (i < data->perfect)
	{
		data->pri[i] = 0;
		i++;
	}
	if (r <= 0)
	{
	//	ft_printf("rien dans rendu, map incomplete\n");
		return (-1);
	}
	i = 0;
	while (i < r)
	{
		data->pri[i] = 0;
		i++;
	}
	i = 0;
	while (nbf > 0)
	{
		while (j < r && data->paths[tab[i]][0] + k >= data->paths[tab[j]][0])
			j++;
		i = 0;
		while (i < j && nbf > 0)
		{
			data->pri[i] = data->pri[i] + 1;
			i++;
			nbf--;
		}
		k++;
		i = 0;
	}
	nbc = data->pri[0] + data->paths[tab[0]][0] - 2;
	i = 1;
	while (i < j)
	{
		if (i < j && data->pri[i] + data->paths[tab[i]][0] - 2 > nbc)
			nbc = data->pri[i] + data->paths[tab[i]][0] - 2;
		i++;
	}
	data->nbp = j;
	// printf("\nnb de fourmis par chemin:\n");
	// print_tab_normal(data->pri, r);
	// printf("\ntab de chemin\n");
	// print_paths(data);
	// printf("\ntab de chemin a utiliser\n");
	// print_tab_normal(data->rendu, data->r);
	// printf("\n\n");
	return (nbc);
}

// int		same_l(int *tab)
// void	actual_ant(int nbf, int path)
void	print_map(char **map, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	print_coor(t_lem *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		ft_printf("\n");
		print_name(data, i);
		ft_printf("\t%d\t", data->x[i]);
		ft_printf("%d\n", data->y[i]);
		i++;
	}
}

void	print_tab(t_lem *data, int *tab, int nb)
{
	int	i;

	i = 0;
	(void)data;
	// while (i < nb)
	// {
	// 	// ft_printf("---tab%d --name\t",tab[i]);
	// 	// print_name(data, tab[i]);
	// 	ft_printf("%d\t", i);
	// 	i++;
	// }
	// ft_printf("\n", i);
	// i = 0;
	while (i < nb)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_tab_normal(int *tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_printf("%d ",tab[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_tab_normal_r(t_lem *data, int **tab, int nb)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < nb)
	{
		while (k < data->lrooms[i][1] + 1)
		{
			ft_printf("%d ", tab[i][k]);
			k++;
		}
		ft_printf("\n");
		k = 0;
		i++;
	}
	ft_printf("\n");
}

void	print_tabbb(t_lem *data, int ***tab, int *xb)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	//k la langueur des chemins, au debut du tableau
	//j la longueur des tableaux, indetermines 1000
	//i la combi maximale, data->perfect
	while (i < data->lrooms[data->end][1])
	{
		while (j < xb[j])
		{
			while (k < tab[i][j][0] + 1)
			{
				if (k == 0)
					ft_printf("%d\t", tab[i][j][k]);
				else
					ft_printf("%d ", tab[i][j][k]);
				k++;
			}
			k = 0;
			ft_printf("\n");
			j++;
		}
		i++;
		if (i < data->lrooms[data->end][1])
			ft_printf("--\n");
		j = 0;
	}
}

void	print_tabb(int **tab, int nb, int n)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < nb)
	{
		// ft_printf("chemin %d\t", i);
		while (k < n)
		{
			ft_printf("%d ",tab[i][k]);
			k++;
		}
		ft_printf("\n");
		i++;
		k = 0;
	}
}

void	print_cb(t_lem *data)
{
	int	i;

	i = 0;
	ft_printf("COMBI BL CB:\n\n");
	while (i < data->nb)
	{
		ft_printf("%d ", data->cb[0][i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < data->lrooms[data->end][1])
	{
		ft_printf("%d ", data->cb[1][i]);
		i++;
	}
}

void	print_tabb_name(t_lem *data, int **tab, int nb, int n)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < nb)
	{
		while (k < n)
		{
			if (k == 0)
			{
				print_name(data, tab[i][k]);
				ft_printf(" - %d ",tab[i][k]);
			}
			else
				ft_printf("-%d ",tab[i][k]);
			k++;
		}
		ft_printf("\n");
		i++;
		k = 0;
	}
}

void	print_paths(t_lem *data)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < data->path)
	{
		//ft_printf("chemin %d\t", i);
		while (k < data->paths[i][0] + 1)
		{
			if (k == 0)
			{
				ft_printf("%d ", data->paths[i][k]); //print_name
				ft_printf("\t");
			}
			else
			{
				ft_printf("%d-", data->paths[i][k]); //print_name
				print_name(data, data->paths[i][k]);
				ft_printf("  ");
			}
			k++;
		}
		ft_printf("\n");
		i++;
		k = 0;
	}
}

void	print_paths_only(t_lem *data)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < data->path)
	{
		if (!ft_rendu(data, i))
		{
			while (k < data->paths[i][0] + 1)
			{
				if (k == 0)
				{
					ft_printf("%d ", data->paths[i][k]); //print_name
					ft_printf("\t");
				}
				else
				{
					print_name(data, data->paths[i][k]);
					ft_printf(" ");
				}
				k++;
			}
			ft_printf("\n");
		}
		i++;
		k = 0;
	}
}

int		ft_rendu(t_lem *data, int i)
{
	int k;

	k = 0;
	while (k < data->r)
	{
		if (data->rendu[k] == i)
			return (0);
		k++;
	}
	return (1);
}

void	print_name(t_lem *data, int nb)
{
	ft_printf(data->names[nb]);
}