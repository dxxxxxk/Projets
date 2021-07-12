#include "lemin.h"

void	fill_empty_tab(int *tab, int *tab2, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		tab[i] = tab2[i];
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_strdel(&map[i]);
		i++;
	}
}