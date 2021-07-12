#include "lemin.h"

void lemin(t_lem *data)
{
	int	k;
	int	ret;

	ret = 0;
	k = 0;
	// char **names;

	// print_map(map, data->i);
	if (data->f <= 0 || data->nb < 2 || !use(data))
	{
		ft_putstr_fd("ERROR\n", 2);
		while (k < data->nb)
		{
			free(data->names[k]);
			k++;
		}
		k = 0;
		while (k < data->i)
		{
			free(data->map[k]);
			k++;
		}
		return ;
	}
	// if (data->nb)
	// {
	// 	ft_printf("\nnumber of rooms: %d\n", data->nb);
	// 	ft_printf("\nnames of rooms:");
	// 	names = ft_strsplit(data->names, '\n');
	// 	print_map(names, data->nb);
	// 	ft_printf("\ncoordonnees:");
	// 	print_coor(data);
	// 	free_map(names);
	// }
	// if (data->tubes)
	// {
	// 	ft_printf("\nnumber of tubes: %d\n", data->tubes);
	// 	ft_printf("Lien entre les salles\n");
	// 	print_tabb(data->rooms, data->nb, data->nb);
	// 	ft_printf("Nombre de lien qu'a la salle:\n");
	// 	print_tabb(data->lrooms, data->nb, 2);
	// }
	// if (data->f)
	// 	ft_printf("\nnumber of ants: %d\n", data->f);
	// if (data->lrooms[data->start][1] == 1 || data->lrooms[data->end][1] == 1)
	// {
	// 	ft_printf("Les salles par lesquels je suis passe pour trouver le chemin:\n");
	// 	print_tab(data, data->seen, data->lseen);
	// }
	// printf("\n\tALGO:\n");
	if (!algo(data)) //trouver les premiers chemins, trouver la meilleur comb
		return ;
	data->p = data->path;
//	printf("\n\n NB COUPS: %d  \nNB CHEMINS CHERCHES: %d\t NB CHEMINS COMBI: %d\t NB CHEMINS utilise: %d\n\n\n", print_final(data, data->rendu, data->r), data->path, data->r, data->nbp);
	// ret = best_combi(data, 0, 1);
	// ret = best_combi(data, 0, 1);
	// ret = best_combi(data, 0, 1);
	// ret = best_combi(data, 0, 1);
	// if (data->path < 120 && data->r != data->perfect && data->nbp == data->r)
	// 	best_combi(data, data->rendu[0]);
	// best_combi(data, 0);
	// best_combi(data, 0);
	// best_combi(data, 0);
	// best_combi(data, 0);
	// best_combi(data, 0);
	// printf("\n\n\n\n\tRESULT RENDU:\n\n");
	// print_tab_normal(data->rendu, data->r);
//	printf("\n\n\n");
//	printf("\n\tRESULT RENDU LONGUEUR(s) de(s) chemin(s) utilisé(s):\n\n");
//	printf("\n\n\n");
	print_map(data->map, data->i);
	printf("\n");
	data->rendu = sort_path(data, data->rendu, data->r); // toujours mettre sort_path avant print_final (data->rendu trier)
	print_final(data, sort_path(data, data->rendu, data->r), data->r); //toujours mettre print_final avant print_ants (data->pri modifier)
	print_ants(data);
	// printf("\n");
	// print_paths(data);
	// printf("NB coups = %d\n", print_final(data, data->rendu, data->r));
	// printf("\n");
	// print_tabb(data->block, data->path, data->nb);
	printf("\n\n NB COUPS: %d  \nNB CHEMINS CHERCHES: %d\t NB CHEMINS COMBI: %d\t NB CHEMINS utilise: %d\n\n\n", print_final(data, data->rendu, data->r), data->path, data->r, data->nbp);
	// if (ret == 0)
	// 	printf("algo a teste tt les bloquage, donc le debloquage a refaire\n");
	// else if (ret == 1)
	// 	printf("algo a quitte quand = perfect\n");
	// else if (ret == 3)
	// 	printf("algo a finis, debloquage a paufiner\n");
	// printf("---\n");
	print_tab_normal(data->rendu, data->r);
	// print_paths_only(data);
	// // printf("\n");
	// print_tabb(data->lrooms, data->nb, 2);
	// printf("\n");
	// print_tab_normal_r(data, data->rooms, data->nb);
	// printf("\n");
	// printf("\n");
	// printf("\n");
	print_tabbb(data, data->pt, data->xb);
	printf("\n");
	print_paths(data);
	printf("\n");
	// print_tabb(data->pass, data->nb, 2);
	// print_tab(data, data->xb, data->lrooms[data->end][1]);
	printf("\n");
	print_cb(data);
	printf("\n");
	// print(data, data->cb, data->nb);
	// print_tabb(data->block, data->path + 2, data->nb);
}

int use(t_lem *data) //si la str est utilisable avec ce qu'n a deja return 1
{
	if (data->start < 0 || data->end < 0)
		return (0);
	if (data->lrooms[data->start][1] == 0 || data->lrooms[data->end][1] == 0)
		return (0);
	//algo() a appeller
	return (1);
}

int init_data(t_lem *data)
{
	if (!(data->names = (char**)malloc(100000 * sizeof(char*))))
		return (0);
	if (!(data->map = (char**)malloc(100000 * sizeof(char*))))
		return (0);
	data->onoff = 0;
	data->max = 0;
	data->lseen = 0;
	data->lseeen = 0;
	data->on = 0;
	data->start = -1;
	data->startt = -1;
	data->end = -1;
	data->endd = -1;
	data->i = 0;
	data->nb = 0;
	data->f = 0;
	data->tubes = 0;
	data->path = 0;
	data->r = 0;
	data->tmpr = 0;
	data->c = 0;
	data->perfect = 0;
	data->p = -1;
	data->nbp = 1000000;
	data->endalgo = 0;
	return (0);
}