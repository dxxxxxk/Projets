 #include "lemin.h"

int		main(void)
{
	t_lem	data;

	if (init_data(&data))
		return (0);
	ft_read(&data);
	// printf("\n------------------------END OF PARSING------------------------\n");
	if (data.map)
		lemin(&data);			//notre algo
	else
	{
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	return (0);
}

int		ft_read(t_lem *data)
{
	char	*str;
	int		i;

	i = 0;
	while (get_next_line(0, &str) == 1)
	{
		data->map[i] = ft_strdup(str);
		if (str[0] == '\0' || error(i, data))//gestion d'erreur et on en profite pour avoir le max d'infos sur les rooms pour optimiser
		{
			if (str)
				ft_strdel(&str);
			return (1);
		}
		ft_strdel(&str);
		i++;
		data->i = i;
	}
	return (0);
}