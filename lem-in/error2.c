#include "lemin.h"

//room return 1 si la room est formatee et l'ajoute a la liste des rooms
//tubes return 1 si la ligne tube est formate correctement
//comm return 1 si la ligne est formatee correctement

int		room(char **strr, t_lem *data, int on)   // ?? coordonnes negatives test sur un lem
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (strr[i])
		i++;
	if (i != 3)
		return (0);
	if (strr[0][0] == 'L' || strr[0][0] == '#')
		return (0);
	while (strr[0][k])
	{
		if (!ft_isascii(strr[0][k]) || strr[0][0] == 'L' || strr[0][0] == '#')
			return (0);
		k++;
	}
	k = 0;
	while (strr[1][k])
	{
		if (!ft_isdigit(strr[1][k]))
			return (0);
		k++;
	}
	k = 0;
	while (strr[2][k])
	{
		if (!ft_isdigit(strr[2][k]))
			return (0);
		k++;
	}
	data->on = on;
 	if (on == 1)
	{
		if (add_room(strr[0], data, ft_atoi(strr[1]), ft_atoi(strr[2]))) //if nom de salle pas dans notre liste de noms && ajouter le nouveau nom a notre liste
			return (0);
		if (data->startt >= 0 && data->start < 0)
		{
			data->start = data->nb;
			data->startt = -1;
		}
		if (data->endd >= 0 && data->end < 0)
		{
			data->end = data->nb;
			data->endd = -1;
		}
		data->nb = data->nb + 1;
	/* 	fill_name_rooms(data); */
	}
	return (1);
}

int		add_room(char *newname, t_lem *data, int x, int y) //si elles ont les memes coordonnes
{
	int		i;

	i = 0;
	if (data->nb)
	{
		while ((i < data->nb) && (ft_strcmp(data->names[i], newname) != 0))
			i++;
		if (i >= data->nb)
		{
			if (check_xy(x, y, data)) //on verifie que les coordonnes son valides et on remplie
			{
				if (data->on == 1)
					data->names[i] = ft_strdup(newname);
			}
			else
				return (1);
		}
	}
	else
	{
		// if (!(data->x = (int *)malloc(1 * sizeof(int))))
		// 	return (1);
		// if (!(data->y = (int *)malloc(1 * sizeof(int))))
		// 	return (1);
		if (!(data->x = (int *)malloc(100000 * sizeof(int))))
			return (1);
		if (!(data->y = (int *)malloc(100000 * sizeof(int))))
			return (1);
 		if (data->on == 1)
		{
			data->x[data->nb] = x;
			data->y[data->nb] = y;
			data->names[i] = ft_strdup(newname);
		}
	}
	return (0);
}

/* void	fill_name_rooms(t_lem *data)
{
	int	*tmp;
	int	i;

	i = 0;
	if (!data->rooms)
	{
		if (!(data->rooms = (int**)malloc((1) * sizeof(int*))))
			return ;
		data->rooms[0] = data->nb;
		return ;
	}
	if (!(tmp = (int*)malloc((data->nb - 1) * sizeof(int))))
		return ;
	while (i < data->nb - 1)
	{
		tmp[i] = data->rooms[i];
		i++;
	}
	free(data->rooms);
	if (!(data->rooms = (int**)malloc((data->nb) * sizeof(int*))))
		return ;
	i = 0;
	while (i < data->nb)
	{
		data->rooms[i] = tmp[i];
		i++;
	}
	free(tmp);
	data->rooms[i] = data->nb;
	return (0);
} */

int		check_xy(int x, int y, t_lem *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		if (data->x[i] == x && data->y[i] == y)
			return (0);
		i++;
	}
 	if (data->on == 1)
		fill_xy(x, y, data);
	return (1);
}

void	fill_xy(int x, int y, t_lem *data)
{
	// int	*tmp;
	// int	*tmp2;

	// if (!(tmp = (int*)malloc((data->nb) * sizeof(int))))
	// 	return ;
	// if (!(tmp2 = (int*)malloc((data->nb) * sizeof(int))))
	// 	return ;
	// fill_empty_tab(tmp, data->x, data->nb);
	// fill_empty_tab(tmp2, data->y, data->nb);
	// free(data->x);
	// free(data->y);
	// if (!(data->x = (int*)malloc((data->nb + 1) * sizeof(int))))
	// 	return ;
	// if (!(data->y = (int*)malloc((data->nb + 1) * sizeof(int))))
	// 	return ;
	// fill_empty_tab(data->x, tmp, data->nb);
	// fill_empty_tab(data->y, tmp2, data->nb);
	data->x[data->nb] = x;
	data->y[data->nb] = y;
	// free(tmp);
	// free(tmp2);
}

int		tubes(char **str, t_lem *data, int on)
{
	int		k;
	char	**tmp2;

	k = 0;
	tmp2 = ft_strsplit(str[data->i], '-');
	while (tmp2[k])
		k++;
	if (k != 2)
		return (0);
	k = 0;
	if (tmp2[0][0] == '#' || tmp2[0][0] == 'L')
		return (0);
	while (tmp2[0][k]) 
	{
		if (!ft_isascii(tmp2[0][k]))
			return (0);
		k++;
	}
	k = 0;
	while (tmp2[1][k]) 
	{
		if (!ft_isascii(tmp2[1][k]))
			return (0);
		k++;
	}
	if (ft_strcmp(tmp2[0], tmp2[1]) == 0)
		return (0);
	if (!check_names(data, tmp2[0]))
		return (0);
	if (!check_names(data, tmp2[1]))
	{
		ft_printf("err\n");
		return (0);
	}
	if (on == 1)
	{
		if (!fill_rooms(data, ret_names(data, tmp2[0]), ret_names(data, tmp2[1])))
			return (0);
		data->tubes = data->tubes + 1;
	}
	return (1);
}

int		fill_rooms(t_lem *data, int a, int b)
{
	int		i;
	int		l;

	i = 0;
	l = 1;
	if (data->tubes == 0)
	{
		if (!(data->rooms = (int**)malloc((data->nb) * sizeof(int*))))
			return (0);
		if (!(data->lrooms = (int**)malloc((data->nb) * sizeof(int*))))
			return (0);
		while (i < data->nb)
		{
			if (!(data->lrooms[i] = (int*)malloc((2) * sizeof(int))))
				return (0);
			if (!(data->rooms[i] = (int*)malloc((data->nb + 1) * sizeof(int))))
				return (0);
			data->lrooms[i][0] = i;
			data->rooms[i][0] = i;
			data->lrooms[i][1] = 0;
			while (l < data->nb + 1)
			{
				data->rooms[i][l] = -1;
				l++;
			}
			l = 1;
			i++;
		}
		data->rooms[a][1] = b;
		data->lrooms[a][1] = 1;
		data->rooms[b][1] = a; 
		data->lrooms[b][1] = 1;
	}
	else
	{
		if (find_l(data, a, b))
			return (0);
		data->rooms[a][data->lrooms[a][1] + 1] = b;
		data->rooms[b][data->lrooms[b][1] + 1] = a;
		data->lrooms[b][1] = data->lrooms[b][1] + 1;
		data->lrooms[a][1] = data->lrooms[a][1] + 1;
	}
	return (1);
}

int		find_l(t_lem *data, int a, int b)
{
	int	i;

	i = 0;
	while (i < data->lrooms[a][1])
	{
		if (data->rooms[a][i + 1] == b)
			return (1);
		else
			i++;
	}
	return (0);
}

int		comment(t_lem *data)
{
	if (data->map[data->i][0] != '#')
		return (0);
	if (data->map[data->i][0] == '#' && !data->map[data->i][1])
		return (1);
	if (data->map[data->i][0] == '#' && data->map[data->i][1] != '#')
		return (1);
	if (data->map[data->i][0] == '#' && data->map[data->i][1] == '#' && !data->map[data->i][2])
		return (0);
	if (data->map[data->i][0] == '#' && data->map[data->i][1] == '#' && data->map[data->i][2] == '#')
		return (1);
	return (0);
}

int		commande(char **strr, t_lem *data)
{
	int		k;

	k = 0;
	if (ft_strcmp(data->map[data->i], "##start") == 0)
	{
		if (data->start < 0)
		{
			data->startt = data->nb;
			//printf("special comm start\n");
			return (2);
		}
		else
			return (0);
	}
	if (ft_strcmp(data->map[data->i], "##end") == 0)
	{
		if (data->end < 0)
		{
			data->endd = data->nb;
			//printf("special comm end\n");
			return (3);
		}
		else
			return (0);
	}
	if (strr[0][0] == '#' && !strr[0][1])
		return (0);
	if (strr[0][0] != '#' || strr[0][1] != '#')
		return (0);
	if (strr[0][0] == '#' && strr[0][1] == '#' && !strr[0][2])
		return (1);
	if (strr[0][0] == '#' && strr[0][1] == '#' && strr[0][2] == '#')
		return (0);
	return (1);
}

int		fourmis(char **strr, t_lem *data)
{
	int		k;

	k = 0;
	while (strr[k])
		k++;
	if (k != 1)
		return (0);
	else
	{
		k = 0;
		while (strr[0][k])
		{
			if (!ft_isdigit(strr[0][k]))
				return (0);
			k++;
		}
	}
	data->f = atoi(strr[0]);
	if (!data->f)
		return (0);
	return (1);
}