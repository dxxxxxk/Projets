#include "lemin.h"

void	               new_path(t_lem *data, int e)
{
	(void)e;
	(void)data;


	/*int	u;
	int	k;

	u = 0;
	k = 0;
	know(data, e, &k, &u); //connaitre les connus et inc

	print_name(data, e);
	printf("-%d", e);
	printf(" a %d connues et %d inconnues\n", k, u);
	print_tab(data, data->k, k);
	ft_printf("\n");
	print_tab(data, data->u, u);
	ft_printf("\n");
	printf("On crée les chemins: \n");

	c_path(u, k, e, data);
	print_paths(data);
	printf("\n\n");*/
}

/*
void	c_path(int u, int k, int e, t_lem *data)
{
//	int connu;
	int	p;

	//Placer la connu a cote de l'inconnu 
	//avoir une fonction aui trouve la bonne place dans le cas 1-1
	//while (alrdy_se(t_lem *data, int c, int e)) 
	if (u == 1 && k == 1) //ajouter l'inconnu aux chemins ayant la connu
	{
		p = find_place(data, data->k[0]); //c
		if (p == -1) //new chemin
		{
			data->paths[data->path][2] = e;
			data->paths[data->path][0] = data->paths[data->path][0] + 1;
			data->path = data->path + 1;
		}
		else //complete le chemin
		{
			data->paths[p][data->paths[p][0]] = e;
			data->paths[p][0] = data->paths[p][0] + 1;
		}
		return ;
	}
}

int		find_u(t_lem *data, int ) 
int		find_place(t_lem *data, int c)
{
	int	i;

	i = 0;
	while (i < data->path)
	{
		if (data->paths[i][data->paths[i][0] - 1] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	know(t_lem *data, int e, int *k, int *u)
{
	int	i;

	i = 0;
	while (i < data->lrooms[e][1])
	{
		if (alrdy_se(data, data->rooms[e][i + 1], e))
		{
			data->k[*k] = data->rooms[e][i + 1];
			*k = *k + 1;
		}
		else
		{
			data->u[*u] = data->rooms[e][i + 1];
			*u = *u + 1;
		}
		i++;
	}
}*/