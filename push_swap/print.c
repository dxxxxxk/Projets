/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:53:47 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:53:50 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push			ft_init(int l, int fd)
{
	t_push		p;

	p.fd = fd;
	p.l = l;
	return (p);
}

int				ft_print_ok(long long *tab, int l)
{
	int		i;

	i = 0;
	while (i + 1 < l)
	{
		if (tab[i + 1] > tab[i])
			i++;
		else
		{
			ft_printf("KO\n");
			return (0);
		}
	}
	ft_printf("OK\n");
	return (0);
}

void			ft_print_tab(long long *tab, long long *tab2, int l)
{
	int		i;

	i = 0;
	while (i < l)
	{
		ft_printf("%lld", tab[i]);
		ft_printf("\t|\t");
		ft_printf("%lld\n", tab2[i]);
		i++;
	}
	ft_printf("\n");
}

void			ft_mvp(char *str, long long *tab, long long *tab2, t_push p)
{
	char		**str2;
	int			i;
	char		*str3;

	i = 0;
	str2 = ft_strsplit(str, '\n');
	while (str2[i])
	{
		ft_move_compare(str2[i], tab, tab2, p.l);
		str3 = ft_strjoin(str2[i], "\n");
		ft_putstr_fd(str3, p.fd);
		ft_printf("%s", str3);
		ft_strdel(&str2[i]);
		i++;
		ft_strdel(&str3);
	}
	free(str2);
}

void			push_swap(int ac, char **av)
{
	long long	*tab;
	long long	*tab2;
	t_push		tmp;

	tmp.fd = open("push_file", O_WRONLY | O_TRUNC | O_CREAT
	| O_APPEND, S_IRUSR | S_IWUSR);
	if (tmp.fd == -1 || ac == 1)
		return ;
	if (!(tab = fill_tab(ac, av, &tmp)))
	{
		if (tab)
			free(tab);
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	if (!(tab2 = (long long*)malloc(tmp.l * sizeof(long long))))
		return ;
	ft_fill_b(tab2, tmp.l);
	ft_resolution(tab, tab2, tmp.l, tmp.fd);
	if (close(tmp.fd) == -1)
		return ;
	free(tab);
	free(tab2);
}
