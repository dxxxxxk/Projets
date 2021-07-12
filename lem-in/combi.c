#include "lemin.h"
//b fonctionne pas comme il faut, voir le probleme
int		best_combi(t_lem *data, int e, int on)
{
	int	i;
	int	v1;
	int nb;

	i = 0;
	nb = 0;
	(void)on;
	//printf("\n%d %d\n", data->path, data->perfect);
	v1 = search_valide(data, e);
	if (v1 == -1)
	{
		if (data->path < 300 && on == 1) //appeller qu'une fois de plus best_combi
			best_combi(data, 0, 0);
		//printf("\n ##################################on a tt parcouru: %d - %d - %d - %d %d\n", data->nbp, data->r, data->path, v1, data->perfect);
		return (0);
	}
	if (data->r == data->perfect  && data->path > 250) /*&& e >= data->p*/
	{
		data->endalgo = data->endalgo + 1;
		// printf("\n #######IN BEST COMBI.C: %d - %d\n", data->nbp, data->r);
		return (1);
		if (data->endalgo > 30)
			return (1);
	}
	while (i < data->path)
	{
		if (data->paths[i][data->paths[i][0]] == data->start && v1 != i)
		{
			if (/*data->paths[i][2] != data->paths[v1][2] && */nocompatible(data, i, v1))
			{
		//		printf("on va creeer une alternative aux chemins: %d et %d\n", i, v1);
				nb = change(data, v1, i) + nb;
			}
			// if (i > data->perfect + data->path / 2)
			// {
			// 	printf("\n #################IN BEST COMBI.C: %d - %d - %d\n", i, data->perfect, data->path);
			// 	best_combi(data, v1 + 1, on);
			// 	return (0);
			// }
			if (nb)
				best_combi(data, 0, on);
		}
		i++;
	}
//	if (data->path < 200)//dasdlalsdlsaldlasl dlsaldla lactuel
	best_combi(data, v1 + 1, on);
	return (3);
}

int		change(t_lem *data, int v1, int i)
{
	int	j;
	int nb;

	nb = 0;
	j = 0;
	//printf(" TEST TEST %d - %d --- %d \n", i, v1, data->path);
	if (data->paths[i][0] >= data->paths[v1][0])
	{
//		printf("Deveroulliage du chemin long:\n\n");
		j = nocompatible(data, v1, i);
		nb = creat_a(data, i, j, v1);
		// printf("Deveroulliage du chemin court:\n\n");
		j = nocompatible(data, i, v1);
		nb = creat_a(data, v1, j, i) + nb;
	}
	else
	{
		j = nocompatible(data, i, v1);
		nb = creat_a(data, v1, j, i);
		j = nocompatible(data, v1, i);
		nb = creat_a(data, i, j, v1) + nb;
	}
	return (nb);
}

int		creat_a(t_lem *data, int i, int j, int v1)
{
	int nb;
	int	aim;
	//j c'est la position de la node qui bloque, a tester avec la fin du chemin
	nb = 0;
	// j = data->paths[i][0] - 2;
	aim = j;
	j = 2;
	while (j < aim)//j >= 2)
	{
		if (data->lrooms[data->paths[i][j]][1] > 2)
		{
		//	printf("\n\nLa node a deveroullier qui a plus de deux liaisons: %d, elle a %d liaisons\n", data->paths[i][j], data->lrooms[data->paths[i][j]][1]);
			nb = creat_alt(data, data->paths[i][j], i, v1) + nb;
		}
		// j--;
		j++;
	}
	return (nb);
}
//chemin uperieur au nombre de fourmis
int		creat_alt(t_lem *data, int s, int i, int v1)
{
	int	c;
	int	r;
	int	d;
	int	k;
	int	number;

	number = 0;
	k = 0;
	d = -1;
	r = -1;
	c = 1;
	// print_tabb(data->block, data->path + 2, data->nb);
	while (c < data->lrooms[s][1] + 1)
	{
		// printf("\ndsa\n");
		// if (number == 15)
		// 	return (1);
		if (!bself(data, i, data->rooms[s][c], s) && data->pass[data->rooms[s][c]][1] == 0) // si la node fait pas parti du chemin, a reutiliser avec v1
		{
			d = r;
			if (r == -1)
				r = c;
			else
			{
				// if (data->range[data->rooms[s][r]][1] >= data->range[data->rooms[s][c]][1] && data->range[data->rooms[s][c]][1] < data->f && data->rooms[s][c] != data->end)
					// r = c;
				///////// if (!blocked(data, data->rooms[s][c]) && data->pass[data->rooms[s][r]][1] >= data->pass[data->rooms[s][c]][1] && data->range[data->rooms[s][c]][1] < data->f && data->rooms[s][c] != data->end)
					// r = c;
				// if (data->pass[data->rooms[s][r]][1] + 1 >= data->pass[data->rooms[s][c]][1])
				if (/*!blocked(data, data->rooms[s][c]) && */data->rooms[s][c] != data->end)
					r = c;
			}
			if (d != r)
			{
				// printf("newwwwwwwwwwwww----DATA v %d -- i %d OFF---%d crea: %d sol:%d\n", v1, i, data->off, data->rooms[s][r], s);
		//		printf("On cree un chenin alternatif a %d qui etait bloque par le chemin %d sur la node %d, la node qui permet ca est la %d\n", i, v1, s, data->rooms[s][c]);
				// data->block[data->path][data->rooms[s][r]] = 1;
				k = 1;
				while (data->paths[i][k] != s && k < data->paths[i][0])
				{
					data->paths[data->path][k] = data->paths[i][k];
					data->block[data->path][data->paths[i][k]] = 1;
					k++;
				}
				data->block[data->path][s] = 1;
				data->paths[data->path][k] = s;
				data->block[data->path][data->rooms[s][r]] = 1;
				data->paths[data->path][k + 1] = data->rooms[s][r];
				data->paths[data->path][0] = k + 1;
				data->pass[data->rooms[s][r]][1] = data->pass[data->rooms[s][r]][1] + 1;
				// data->path = data->path + 1;
				// print_paths(data);
				// printf("\n%d ---- %d\n\n", data->paths[data->path - 1][0], c);
				// printf("\n\n\n");
				create_alternative(data, data->rooms[s][r], i, v1);
					// printf("newwwwwwwwwwwww----DATA v %d -- i %d OFF---%d crea: %d sol:%d\n", v1, i, data->off, data->rooms[s][r], s);
					// printf("\nNEW COMBI\n");
				if (data->paths[data->path - 1][data->paths[data->path - 1][0]] == data->start && valid_path(data)/* && data->paths[data->path - 1][0] < data->f*/)
				{
					combinaison(data, data->path - 1); //il a trouve une nouvelle combi
				//	printf("CHEMIN+++\n");
					// print_paths(data);
					if (data->tmpr > 0)
					{
						number++;
						// printf("\ncompi\n");
						cmp_shot(data);
						// if (data->nbp < data->r || data->perfect == data->r) // if (data->nbp < data->r)
							// return (0);				//elle est meilleure du coup il l'a garde et elle est meme peut etre optimal
							// 	return (1);
					}//arreter si optimal
				}
				else
				{
					// data->pass[data->rooms[s][r]][1] = data->pass[data->rooms[s][r]][1] + 3;
					// data->pass[data->paths[data->path - 1][data->paths[data->path - 1][0] - 1]][1] = data->pass[data->paths[data->path - 1][data->paths[data->path - 1][0] - 1]][1] + 3;
					delete_path(data);
				}
			} //creat altttttt
		}
		c++;
	}
	return (number);
}

int		delete_path(t_lem *data)
{
	int i;

	i = 2;
	while (i < data->paths[data->path - 1][0])
	{
	// 	data->block[data->path - 1][data->paths[data->path - 1][i]] = 0;
		data->pass[data->paths[data->path - 1][i]][1] = data->pass[data->paths[data->path - 1][i]][1] + 3;
		data->block[data->path - 1][data->paths[data->path - 1][i]] = 0;
		i++;
	}
	// i = 0;
	// while (i < data->nb)
	// {
	// 	data->block[data->path - 1][i] = 0;
	// 	i++;
	// }
	data->paths[data->path - 1][0] = 1;
	// data->paths[data->path - 1][1] = data->end;
	data->path = data->path - 1;
	return (1);
}

int		valid_path(t_lem *data)
{
	int	i;

	i = 0;
	while (i < data->path - 1)
	{
		if (same_path(data, i, data->path - 1))
			return (0);
		i++;
	}
	return (1);
}

int		same_path(t_lem *data, int x, int y)
{
	int	i;

	i = 0;
	if (data->paths[x][0] == data->paths[y][0])
	{
		while (i < data->paths[x][0] && i < data->paths[y][0])
		{
			if (data->paths[x][i] != data->paths[y][i])
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int		better(t_lem *data, int i, int c, int s)
{
	(void)s;
	if (!b(data, i, c))
		return (1);
	return (0);
}

int		b(t_lem *data, int i, int c) //chemin en cours
{
	// if (data->block[i][c])
		// return (1);
	// int	k;
	int	k;

	k = 1;
	while (k < data->paths[i][0])
	{
		if (data->paths[i][k] == c)
			return (1);
		k++;
	}
	return (0);
}

int		bself(t_lem *data, int i, int c, int self) //chemin en cours self pr quitter car chemin pas finis
{
	// if (data->block[i][c])
		// return (1);
	// int	k;
	int	k;

	k = 1;
	while (k < data->paths[i][0])
	{
		if (data->paths[i][k] == self)
			return (0);
		if (data->paths[i][k] == c)
			return (1);
		k++;
	}
	return (0);
}

int		create_alternative(t_lem *data, int r, int k, int v1)
{
	///////////////////////k chemin de r
	////r position dans room de ij node a ecrire et passer concerne, i chemin concerne 
	int	i;
	int	j;

	i = data->paths[data->path][0] + 1;
	while (r != data->start && r != -1)
	{
		//print_name(data, r);
		j = r;
		r = end_c(data, r, k, v1);
		if (j == r || r == -1)
		{
			data->path = data->path + 1;
			return (0);
		}
		//data->paths[data->path][data->paths[data->path][0] + 1] = r; //data->paths[data->path][0] + 1
		else if (r >= 0 && r != data->start)			//j
		{
			data->paths[data->path][i] = r;
			// data->block[data->path][r] = 1;
			data->block[data->path][r] = 1;
			data->pass[r][1] = data->pass[r][1] + 1;
			data->paths[data->path][0] = data->paths[data->path][0] + 1;
			i++;
		}
		//if (r == data->start || r == -1) // && ts chemins trouve ou alors on peut envoyer les fourmis
		else
		{
			data->paths[data->path][data->paths[data->path][0] + 1] = r;
			if (r != -1)
			{
				data->block[data->path][r] = 1;
				data->paths[data->path][0] = data->paths[data->path][0] + 1; //pareil qu'en haut, on ajoute la room au chemin
				data->path = data->path + 1;
				return (1);
			}													//on incremente data path
			data->path = data->path + 1;						//on incremente data path
			return (0);											//on cherche un autre chemin
		}
	}
	return (0);
}

int		end_c(t_lem *data, int e, int k, int v1)
{
	int i;
	int r;

	i = 1;
	r = -1;
	(void)k;
//	ft_printf("r = %d\n", r);
	while (i < data->lrooms[e][1] + 1 && r == -1)
	{
		if (!block_self(data, data->rooms[e][i]) && data->pass[data->rooms[e][i]][1] == 0) /*&& data->range[data->rooms[e][i]][1] < data->f*/ //&& !bo(data, k, data->rooms[e][i]))
			r = data->rooms[e][i];
		i++;
	}
//	ft_printf("  rrrrrr = %d, %d\n", r, v1);
	i = 1;
	if (r == -1)
		return (-1);
	while (i < data->lrooms[e][1] + 1)
	{
		if (!block_self(data, data->rooms[e][i]) && !b(data, v1, data->rooms[e][i]) && data->pass[data->rooms[e][i]][1] == 0) /*&& data->range[data->rooms[e][i]][1] < data->f && data->pass[data->rooms[e][i]][1] <= data->pass[r][1]*/// && !blocked(data, data->rooms[e][i])) //&& !b(data, k, data->rooms[e][i]))
		{
			if (data->pass[data->rooms[e][i]][1] < data->pass[r][1] && data->range[data->rooms[e][i]][1] <= data->range[r][1])
				r = data->rooms[e][i];
			else if (data->pass[data->rooms[e][i]][1] < data->pass[r][1] || data->range[data->rooms[e][i]][1] < data->range[r][1])
				r = data->rooms[e][i];
			//else if (data->range[data->rooms[e][i]][1] < data->range[r][1])
		//		r = data->rooms[e][i];
			// else if (data->pass[data->rooms[e][i]][1] + 4 < data->pass[r][1]/* && data->range[data->rooms[e][i]][1] < data->range[r][1]*/)
				// r = data->rooms[e][i];
		}
		i++;
	}
//	ft_printf("  fin = %d\n\n", r);
	return (r);
}