#include "lemin.h"

int		solve(t_lem *data, int end)
{
	int r;
	int j;
	int	k;

	// r = end;
	k = 0;
	// data->block[data->path][data->end] = 1;
	while (k < data->lrooms[data->end][1])
	{
		r = end;
		while (r != data->start)
		{
			j = r;
			r = end_cmp(data, r);
			if (r >= 0 && j != r)
			{
				data->paths[data->path][0] = data->paths[data->path][0] + 1;
				data->paths[data->path][data->paths[data->path][0]] = r;
				data->block[data->path][r] = 1;
				data->pass[r][1] = data->pass[r][1] + 1;
				if (r == data->start)
					data->path = data->path + 1;
			}
			else
			{
				data->path = data->path + 1;
				delete_path(data);
				r = data->start;
			}
		}
		k++;
	}
	return (0);
	// while (data->path != data->lrooms[data->end][1])
	// {
	// 	//print_name(data, r);
	// 	j = r;
	// 	r = end_cmp(data, r);
	// 	if (j == r)
	// 	{
	// 		data->path = data->path + 1;
	// 		solve(data, data->end);
	// 		return (0);
	// 	}
	// 	//data->paths[data->path][data->paths[data->path][0] + 1] = r; //data->paths[data->path][0] + 1
	// 	else if (r >= 0 && r != data->start)			//j
	// 	{
	// 		data->paths[data->path][i] = r;
	// 		data->block[data->path][r] = 1;
	// 		data->pass[r][1] = 1;
	// 		data->paths[data->path][0] = data->paths[data->path][0] + 1;
	// 		i++;
	// 	}
	// 	//if (r == data->start || r == -1) // && ts chemins trouve ou alors on peut envoyer les fourmis
	// 	else
	// 	{
	// 		if (r != -1)
	// 		{
	// 			data->block[data->path][r] = 1;
	// 			data->paths[data->path][data->paths[data->path][0] + 1] = r;
	// 			data->paths[data->path][0] = data->paths[data->path][0] + 1; //pareil qu'en haut, on ajoute la room au chemin
	// 		}
	// 		data->path = data->path + 1;					//on incremente data path
	// 		solve(data, data->end);
	// 		return (0);											//on cherche un autre chemin
	// 	}
	// }
}

int		end_cmp(t_lem *data, int e)
{
	int i;
	int r;

	i = 1;
	r = -1;
	while (i < data->lrooms[e][1] + 1 && r == -1)
	{
		if (!blocked(data, data->rooms[e][i]) && !block_self(data, data->rooms[e][i]))
			r = data->rooms[e][i];
		i++;
	}
	i = 1;
	if (r == -1)
		return (-1);
	while (i < data->lrooms[e][1] + 1)
	{
		if (data->range[data->rooms[e][i]][1] <= data->range[r][1] && !blocked(data, data->rooms[e][i]) && !block_self(data, data->rooms[e][i]))
			r = data->rooms[e][i];
		i++;
	}
	return (r);
}

int		blocked(t_lem *data, int e)
{
	// if (data->pass[e][1])
		// return (1);
	int	i;

	i = 0;
	while (i < data->path)
	{
		if (data->paths[i][2] == e)
			return (1);
		i++;
	}
	return (0);
}

int		block_self(t_lem *data, int e)
{
	if (data->block[data->path][e]) 
		return (1);
	// int i;

	// i = 1;
	// while (i < data->paths[data->path][0])
	// {
	// 	if (e == data->paths[data->path][i])
	// 		return (1);
	// 	i++;
	// }
	return (0);
}