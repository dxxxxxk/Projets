#include "lemin.h"

int		find_path(t_lem *data)
{
	int	i;

	i = 0;
	if (data->lrooms[data->start][1] == 0 || data->lrooms[data->end][1] == 0)
		return (0);
	i = explore(data, data->start); // on commence de la fin, pq pas commencer du debut egalement
	return (i);
}

int		explore(t_lem *data, int e) //segfault
{
	int	i;

	i = 0;
	while (i < data->lrooms[e][1])
	{
		if (data->rooms[e][i + 1] == data->end)
			return (1);
		i++;
	}
	fill_seen(data, e);
	i = 0;
	while (i < data->lrooms[e][1])
	{
		if (!alrdy_seen(data, data->rooms[e][i + 1]))
			if (explore(data, data->rooms[e][i + 1]))
				return (1);
		i++;
	}
	return (0);
}

void	fill_seen(t_lem *data, int e)
{
	int		i;

	i = 0;
	if (!(data->seen))
	{
		if (!(data->seen = (int*)malloc((data->nb) * sizeof(int))))
			return ;
		while (i < data->nb)
		{
			data->seen[i] = -1;
			i++;
		}
		data->seen[0] = e;
		data->lseen = data->lseen + 1;
	}
	else
	{
		data->seen[data->lseen] = e;
		data->lseen = data->lseen + 1;	
	}
}

int		alrdy_seen(t_lem *data, int c)
{
	int	i;

	i = 0;
	while (i < data->lseen)
	{
		if (data->seen[i] == c)
			return (1);
		i++;
	}
	return (0);
}