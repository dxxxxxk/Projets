#include "lemin.h"

int		error(int i, t_lem *data)
{
	char **str;

	if (!data->map[i])
		return (1);
	str = ft_strsplit(data->map[data->i], ' ');
	if (i == 0)
	{
		if(!fourmis(str, data))
			return (1);
		else
		{
			// ft_printf("one more fourmis++\n");
			return (0);
		}
	}
	if (data->onoff == 0)
	{
		if ((data->startt >= 0) || (data->endd >= 0))
		{
			// printf("special start - end\n");
			if (!room(str, data, 0))
			{
				// printf("special start - end\n");
				return (1);
			}
		}
	}
	if (data->start >= 0 && data->end >= 0)
		data->onoff = 1;
	//if (room(str, data, 1) || tubes(str, i, data, 1) || comm(str, i) || comment(str, i, data))
	if (data->tubes == 0 && room(str, data, 1))
	{
		// ft_printf("one more room++\n");
		return (0);
	}
	if (data->nb > 0 && data->start >= 0 && data->end >= 0 && tubes(data->map, data, 1))
	{
		// ft_printf("one more tubes++\n");
		return (0);
	}
	if (comment(data))
	{
		// ft_printf("one more comment++\n");
		return (0);
	}
	if (commande(str, data))
	{
		// ft_printf("one more commande++\n");
		return (0);
	}
	// ft_printf("pas entre\n");
	return (1);
}

int	check_name(t_lem *data, int name)
{
	if (!data->names[name])
		return (0);
	return (1);
}

int	check_names(t_lem *data, char *name)
{
	int		i;

	i = 0;
	while (i < data->nb)
	{
		if (ft_strcmp(name, data->names[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ret_names(t_lem *data, char *name)
{
	int		i;

	i = 0;
	while (i < data->nb)
	{
		if (ft_strcmp(name, data->names[i]) == 0)
			return (i);
		i++;
	}
	return (0);
}