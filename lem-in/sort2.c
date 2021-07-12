#include "lemin.h"

int		unblock(t_lem *data)
{
	int	valide;
	int	i;
	int	shortest;
	int	k;

	k = 0;
	i = 0;
	valide = 0;
	shortest = -1;
	while (i < data->path)
	{
		if (data->paths[i][data->paths[i][0]] == data->start)
		{
			if (shortest == -1)
				shortest = i;
			else
			{
				if (data->paths[i][0] < data->paths[shortest][0])
					shortest = i;
			}
			while (k < data->paths[i][0] + 1)
			{
				// ft_printf("dksakdkas%d %d %d\n", i, k, data->perfect);
				data->pt[i][0][k] = data->paths[i][k];
				k++;
			}
			k = 0;
			valide++;
		}
		i++;
	}
	// printf("\n\nOn a %d chemins valides\n", valide);
	if (valide == 0)
	{
		ft_putstr_fd("ERROR\n", 2);
		// printf("\nzero chemin dnc finis\n");
		return (0);
	}
	data->rendu[0] = shortest;
	data->r = 1;
	if (valide == 1)
		return (0);
	combinaison(data, 0);
	return (0);
}

int		*sort_path(t_lem *data, int *rendu, int nbrendu)
{
	int i;
	int tmp;

	i = 0;
	while (i < nbrendu - 1)
	{
		if (data->paths[rendu[i]][0] > data->paths[rendu[i + 1]][0])
		{
			tmp = rendu[i];
			rendu[i] = rendu[i + 1];
			rendu[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (rendu);
}

int		cmp_shot(t_lem *data)
{
	int nbc;
	int	nbcr;

	data->tmprendu = sort_path(data, data->tmprendu, data->tmpr);
	data->rendu = sort_path(data, data->rendu, data->r);
	nbc = print_final(data, data->rendu, data->r);
	nbcr = print_final(data, data->tmprendu, data->tmpr);
	if (nbc > nbcr && nbcr != -1) //data->tmpr >= data->r
	{
		copy_rendu(data);
		data->tmpr = 0;
		return (1);
	}
	else
	{
		data->tmpr = 0;
		return (0);
	}
	// printf("nbcr TMPRENUU = %d\n", data->max);
	// printf("nbc RENDU = %d\n", nbc);
	// printf("next\n\n");
	// printf("\n\nrendu:\n");
	// print_tab_normal(data->rendu, data->r);
	// printf("tmp:\n");
	// print_tab_normal(data->tmprendu, data->tmpr);
}

int		copy_rendu(t_lem *data)
{
	int	i;

	i = 0;
	while (i < data->tmpr)
	{
		data->rendu[i] = data->tmprendu[i];
		i++;
	}
	data->r = data->tmpr;
	data->tmpr = 0;
	return (0);
}

int		combinaison(t_lem *data, int e)
{
	int v1;

	v1 = search_valide(data, e);
	if (v1 == -1)
	{
		// printf("\nRENDU: \n");
		// printf("\n\n\n return 0AAAA in sort2.c combi On a le meilleur rendu: \n");
		// print_tab_normal(data->rendu, data->r);
		return (0);
	}
	if (compare(data, v1)) //on rempli combi  //il utilise v1 + 1
		fill_tmpr(data, v1); //om rempli tmpr et rendu a l'aide de combi
	// if (data->r == data->perfect ||	data->nbp < data->r)
	// {
	// 	printf("\n IN SORT2.C: \n");
	// 	printf("\n\n-return 0 in best combi On a le meilleur rendu ou NBP: \n");
	// 	printf("\n\n-return 0 perfect: %d rendu lenght: %d \n", data->perfect, data->r);
	// 	return (0);
	// }
	combinaison(data, v1 + 1);
	data->tmpr = 0;
	return (0);
}

int		fill_tmpr(t_lem *data, int v1)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (data->c <= 1)
	{
		data->tmprendu[0] = v1;
		data->tmpr = 1;
		if (data->c == 1)
		{
			data->tmprendu[1] = data->combi[0];
			data->tmpr = 2;
		}
		cmp_shot(data);
		data->tmpr = 0;
	}
	else
	{
		while (i < data->c)
		{
			if (!nocompatible(data, data->combi[i], v1) && data->combi[i] != v1)
			{
				data->tmprendu[0] = v1;
				data->tmpr = 1;
				data->tmprendu[data->tmpr] = data->combi[i];
				data->tmpr = 2;
				j = i;
				while (j < data->c)
				{
				//	cmp_shot(data);
					if (!nocompatible(data, data->combi[j], v1) && compatible(data, data->combi[j]))
					{
						data->tmprendu[data->tmpr] = data->combi[j];   //a refaire
						data->tmpr = data->tmpr + 1;
						// cor(v1, j, data);
						// // printf("\n\n");
						// cmp_shot(data);
						// data->tmpr = 2;
					}
					j++;
				}
				if (data->tmpr > 0)
				{
					cmp_shot(data);
					// if (data->nbp < data->r || data->r == data->perfect)
						// return (0);
				}
				j = 0;
				data->tmpr = 0;
			}
			i++;
		}
		data->tmpr = 0;
	}
	return (0);
}

int		cor(int v1, int j, t_lem *data)
{
	int	k;
	int	var;

	k = j;
	// printf("data->tmpr = %d && k = %d\n", data->tmpr, k);
	// printf("111111111tmpr= %d perfect= %d -------- k == %d   data->c == %d \n", data->tmpr, data->perfect, k, data->c);
	while (k < data->c && data->tmpr < data->perfect)
	{
		if (!nocompatible(data, data->combi[k], v1) && compatible(data, data->combi[k]))
		{
			data->tmprendu[data->tmpr] = data->combi[k];   //a refaire
			data->tmpr = data->tmpr + 1;
			// printf("data->tmpr = %d && k = %d +++ %d +++++++++ %d \n", data->tmpr, k,data->tmprendu[data->tmpr], data->combi[k]);
			// printf("tmpr= %d perfect= %d -------- k == %d   data->c == %d \n", data->tmpr, data->perfect, k, data->c);
			cor(v1, j, data);
			// printf("111111111tmpr= %d perfect= %d -------- k == %d   data->c == %d \n", data->tmpr, data->perfect, k, data->c);
			data->tmpr = data->tmpr - 1;
			// printf("111111111tmpr= %d perfect= %d -------- k == %d   data->c == %d \n", data->tmpr, data->perfect, k, data->c);
		}
		k++;
	}
	var = data->tmpr;
	// printf("111111111tmpr= %d perfect= %d -------- k == %d   data->c == %d \n", data->tmpr, data->perfect, k, data->c);
	cmp_shot(data);
	data->tmpr = var;
	return (0);
}

int		compatible(t_lem *data, int e)
{
	int	i;

	i = 1;
	while (i < data->tmpr)
	{
		if (nocompatible(data, data->tmprendu[i], e))
			return (0);
		i++;
	}
	return (1);
}

int		compare(t_lem *data, int v1)
{
	int		i;

	i = search_valide(data, v1 + 1);
	if (i == -1)
		i = search_valide(data, 0);
	if (i == -1)
		return (0);
	data->c = 0;
	while (i < data->path)
	{
		// printf("%d\n", data->r);
		if (i != v1 && data->paths[i][data->paths[i][0]] == data->start)
		{
			if (!nocompatible(data, i, v1))
			{
				data->combi[data->c] = i;
				data->c = data->c + 1;
			}
		}
		i++;
	}
	if (data->c)
		return (1);
	return (0);
}

int		nocompatible(t_lem *data, int i, int v1)
{
	int		j;

	j = 2;
	while (j < data->paths[v1][0])
	{
		if (data->block[i][data->paths[v1][j]])
			return (j);
		j++;
	}
	return (0);
}

// int		nocompatible(t_lem *data, int i, int v1)
// {
// 	int		j;
// 	int		k;

// 	j = 2;
// 	k = 2;
// 	while (j < data->paths[v1][0])
// 	{
// 		while (k < data->paths[i][0])
// 		{
// 			if (data->paths[v1][j] == data->paths[i][k])
// 				return (j);
// 			k++;
// 		}
// 		k = 2;
// 		j++;
// 	}
// 	return (0);
// }

int		search_valide(t_lem *data, int v1)
{
	while (v1 < data->path)
	{
		if (data->paths[v1][data->paths[v1][0]] == data->start)
			return (v1);
		v1++;
	}
	return (-1);
}