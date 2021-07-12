#include "lemin.h"

int		algo(t_lem *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(data->range = (int**)malloc((data->nb) * sizeof(int*))))
		return (0);
	// if (!(data->range2 = (int**)malloc((data->nb) * sizeof(int*))))
		// return (0);
	if (!(data->paths = (int**)malloc(100 * sizeof(int*))))
		return (0);
	if (!(data->corr = (int**)malloc(2 * sizeof(int*))))
		return (0);
	if (!(data->uftrace = (int*)malloc(data->nb * sizeof(int))))
		return (0);
	if (!(data->seeen = (int*)malloc(data->nb * sizeof(int))))
		return (0);
	if (!(data->fo = (int**)malloc(data->f * sizeof(int*))))
		return (0);
	if (!(data->pass = (int**)malloc(data->nb * sizeof(int*))))
		return (0);
	if (!(data->cb = (int**)malloc(2 * sizeof(int*))))
		return (0);
	if (!(data->combi = (int*)malloc(150 * sizeof(int))))
		return (0);
	if (!(data->block = (int**)malloc(100 * sizeof(int*))))
		return (0);
	// if (!(data->block = (int**)malloc(200000 * sizeof(int*))))
		// return (0);
	if (!(data->cb[0] = (int*)malloc(data->nb * sizeof(int))))
		return (0);
	if (!(data->cb[1] = (int*)malloc(data->lrooms[data->end][1] * sizeof(int))))
		return (0);
	if (!(data->corr[0] = (int*)malloc((100) * sizeof(int))))
		return (0);
	if (!(data->corr[1] = (int*)malloc((100) * sizeof(int))))
		return (0);
	if (data->f >= data->nb && data->f >= 100)
	{
		while (i < data->f)
		{
			if (i < 100)
			{
				if (!(data->paths[i] = (int*)malloc((data->nb + 1) * sizeof(int))))
					return (0);
				if (!(data->block[i] = (int*)malloc((data->nb) * sizeof(int))))
					return (0);
				while (j < data->nb)
				{
					data->block[i][j] = 0;
					j++;
				}
				j = 0;
				data->paths[i][0] = 1;
				data->paths[i][1] = data->end;
				data->block[i][data->end] = 1;
			}
			if (i < data->nb)
			{
				if (!(data->range[i] = (int*)malloc((2) * sizeof(int))))
					return (0);
				// if (!(data->range2[i] = (int*)malloc((2) * sizeof(int))))
				// return (0);
				data->range[i][0] = i;
				// data->range2[i][0] = i;
				data->range[i][1] = -1;
				// data->range2[i][1] = -1;
				if (!(data->pass[i] = (int*)malloc((2) * sizeof(int))))
					return (0);
				data->pass[i][0] = i;
				data->pass[i][1] = 0;
				data->uftrace[i] = 0;
			}
			if (!(data->fo[i] = (int*)malloc(3 * sizeof(int))))
				return (0);
			i++;
		}

	}
	else if (data->nb >= data->f && data->nb >= 100)
	{
		while (i < data->nb)
		{
			if (i < 100)
			{
				if (!(data->paths[i] = (int*)malloc((data->nb + 1) * sizeof(int))))
					return (0);
				if (!(data->block[i] = (int*)malloc((data->nb) * sizeof(int))))
					return (0);
				while (j < data->nb)
				{
					data->block[i][j] = 0;
					j++;
				}
				j = 0;
				data->paths[i][0] = 1;
				data->paths[i][1] = data->end;
				data->block[i][data->end] = 1;
			}
			if (i < data->f)
			{
				if (!(data->fo[i] = (int*)malloc(3 * sizeof(int))))
					return (0);
			}
			if (!(data->range[i] = (int*)malloc((2) * sizeof(int))))
				return (0);
			// if (!(data->range2[i] = (int*)malloc((2) * sizeof(int))))
			// return (0);
			data->range[i][0] = i;
			// data->range2[i][0] = i;
			data->range[i][1] = -1;
			// data->range2[i][1] = -1;
			if (!(data->pass[i] = (int*)malloc((2) * sizeof(int))))
				return (0);
			data->pass[i][0] = i;
			data->pass[i][1] = 0;
			data->uftrace[i] = 0;
			i++;
		}
	}
	else //300 > data->f et datanb
	{
		while (i < 100)
		{
			if (!(data->paths[i] = (int*)malloc((data->nb + 1) * sizeof(int))))
			return (0);
			if (!(data->block[i] = (int*)malloc((data->nb) * sizeof(int))))
				return (0);
			while (j < data->nb)
			{
				data->block[i][j] = 0;
				j++;
			}
			j = 0;
			data->paths[i][0] = 1;
			data->paths[i][1] = data->end;
			data->block[i][data->end] = 1;
			if (i < data->f)
			{
				if (!(data->fo[i] = (int*)malloc(3 * sizeof(int))))
					return (0);
			}
			if (i < data->nb)
			{
				if (!(data->range[i] = (int*)malloc((2) * sizeof(int))))
					return (0);
				// if (!(data->range2[i] = (int*)malloc((2) * sizeof(int))))
				// return (0);
				data->range[i][0] = i;
				// data->range2[i][0] = i;
				data->range[i][1] = -1;
				// data->range2[i][1] = -1;
				if (!(data->pass[i] = (int*)malloc((2) * sizeof(int))))
					return (0);
				data->pass[i][0] = i;
				data->pass[i][1] = 0;
				data->uftrace[i] = 0;
			}
			i++;
		}
	}

	// while (i < 300)
	// {

	// 	if (!(data->paths[i] = (int*)malloc((data->nb + 1) * sizeof(int))))
	// 		return (0);
	// 	if (!(data->block[i] = (int*)malloc((data->nb) * sizeof(int))))
	// 		return (0);
	// 	while (j < data->nb)
	// 	{
	// 		data->block[i][j] = 0;
	// 		j++;
	// 	}
	// 	j = 0;
	// 	data->paths[i][0] = 1;
	// 	data->paths[i][1] = data->end;
	// 	data->block[i][data->end] = 1;
	// 	i++;
	// }
	// i = 0;
	// while (i < data->f)
	// {
	// 	if (!(data->fo[i] = (int*)malloc(3 * sizeof(int))))
	// 		return (0);
	// 	i++;
	// }
	// i = 0;
	// while (i < data->nb)
	// {
	// 	if (!(data->range[i] = (int*)malloc((2) * sizeof(int))))
	// 		return (0);
	// 	// if (!(data->range2[i] = (int*)malloc((2) * sizeof(int))))
	// 		// return (0);
	// 	data->range[i][0] = i;
	// 	// data->range2[i][0] = i;
	// 	data->range[i][1] = -1;
	// 	// data->range2[i][1] = -1;
	// 	if (!(data->pass[i] = (int*)malloc((2) * sizeof(int))))
	// 		return (0);
	// 	data->pass[i][0] = i;
	// 	data->pass[i][1] = 0;
	// 	data->uftrace[i] = 0;
	// 	i++;
	// }

	// printf("\n\n----OOOOO------\n");
	reset_cb(data);
	// printf("\n\n----AAAAAA------\n");
	i = bfs(data, data->start);
	// i = bfs2(data, data->end);
	if (data->range[data->end][1] == -1)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	solve(data, data->end);
	//printf("\n\n----after solve------\n");
	//print_paths(data);
	pt(data);
	unblock(data);
	fill_cb(data);
	//printf("----------\n");
	//printf("DEBLOQUAGE APRES LES PREMIERS CHEMINS TROUVES\n");
//	print_paths(data);
	return (1);
}

void	pt(t_lem *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->path <= data->lrooms[data->start][1] && data->path <= data->lrooms[data->end][1])
		data->perfect = data->path;
	else if (data->lrooms[data->start][1] <= data->lrooms[data->end][1])
		data->perfect = data->lrooms[data->start][1];
	else
		data->perfect = data->lrooms[data->end][1];
	if (!(data->pri = (int*)malloc(data->perfect * sizeof(int))))
		return ;
	if (!(data->pri2 = (int*)malloc(data->perfect * sizeof(int))))
		return ;
	if (!(data->rendu = (int*)malloc(data->perfect * sizeof(int))))
		return ;
	if (!(data->tmprendu = (int*)malloc(data->perfect * sizeof(int))))
		return ;
	if (!(data->pt = (int***)malloc(data->lrooms[data->end][1] * sizeof(int**))))
		return ;
	if (!(data->xb = (int*)malloc(data->lrooms[data->end][1] * sizeof(int))))
		return ;
	while (i < data->lrooms[data->end][1])
	{
		data->xb[i] = 1;
		if (!(data->pt[i] = (int**)malloc(50 * sizeof(int*))))
			return ;
		data->corr[0][i] = i;
		data->corr[1][i] = 0;
		while (j < 50)
		{
			if (!(data->pt[i][j] = (int*)malloc(data->nb * sizeof(int))))
				return ;
			data->pt[i][j][0] = 1;
			data->pt[i][j][1] = data->end;
			j++;
		}
		j = 0;
		i++;
	}
}

int		bfs(t_lem *data, int e)
{
	int	i;
	int	k;
	int	ra;
	int	j;
	int	h;

	ra = 0;
	i = 0;
	h = 0;
	k = 0;
	j = 0;
	data->seeen[0] = e;
	data->uftrace[data->start] = 1;
	data->lseeen = data->lseeen + 1;
	while (data->lseeen > i)
	{
		data->range[data->seeen[i]][1] = ra;
		k = k + fill_seeen(data, data->seeen[i]);
		if (h >= j)
		{
			j = k;
			k = 0;
			ra++;
			h = 0;
		}
		h++;
	//	print_tabb_name(data, data->range, data->nb, 2);
	//	print_tab(data, data->seeen, data->lseeen);
	//	printf("\n");
		i++;
		/*if (i < data->nb)
		{
			printf("e = ");
			print_name(data, data->seeen[i]);
			printf("- ra = %d\n", ra);*/

		/*}*/
	}
	//printf("\n");
	return(0);
}

int		fill_seeen(t_lem *data, int e)
{
	int	n;
	int	k;

	n = 0;
	k = 0;
	// printf("dsadash----------\n");
	// print_tab_normal(data->uftrace, data->nb);
	while (n < data->lrooms[e][1])
	{
		if (data->uftrace[data->rooms[e][n + 1]] == 0)
		{
			data->seeen[data->lseeen] = data->rooms[e][n + 1];
			data->lseeen = data->lseeen + 1;
			data->uftrace[data->rooms[e][n + 1]] = 1;
			k++;
		}
		n++;
	}
	return (k);
}
