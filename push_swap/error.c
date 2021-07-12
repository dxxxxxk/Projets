/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:51:32 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 15:51:34 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		dgt(char **str, int i, int *x)
{
	if (str[i][*x] == '-')
		*x = *x + 1;
	while (str[i][*x])
	{
		if (!(ft_isdigit(str[i][*x])))
			return (1);
		*x = *x + 1;
	}
	*x = 0;
	return (0);
}

int		dgt2(char **av, int i, int *x)
{
	if (av[i][*x] == '-')
		*x = *x + 1;
	while (av[i][*x])
	{
		if (!(ft_isdigit(av[i][*x])))
			return (1);
		*x = *x + 1;
	}
	*x = 0;
	return (0);
}

int		check_doublon(int ac, char **av, int x)
{
	int		i;
	int		k;

	i = 1;
	k = 2;
	while (i < ac && k < ac)
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
			return (1);
		if (ft_atol(av[k]) > 2147483647 || ft_atol(av[k]) < -2147483648)
			return (1);
		if (ft_strcmp(av[i], av[k]) == 0)
			return (1);
		k++;
		if (k == ac)
		{
			if (dgt2(av, i, &x))
				return (1);
			i++;
			k = i + 1;
			if (dgt2(av, i, &x) && av[i] && k == ac)
				return (1);
		}
	}
	return (0);
}

int		doublon(char **str, int i, int x, int k)
{
	if (ft_atol(str[i]) > 2147483647 || ft_atol(str[i]) < -2147483648)
		return (1);
	if (dgt(str, i, &x) && !str[k])
		return (1);
	while (str[i] != NULL && str[k] != NULL)
	{
		if (ft_atol(str[i]) > 2147483647 || ft_atol(str[i]) < -2147483648)
			return (1);
		if (ft_atol(str[k]) > 2147483647 || ft_atol(str[k]) < -2147483648)
			return (1);
		if (ft_strcmp(str[i], str[k]) == 0)
			return (1);
		k++;
		if (str[k] == NULL)
		{
			if (dgt(str, i, &x))
				return (1);
			i++;
			k = i + 1;
			if (dgt(str, i, &x) && str[i] && str[k] == NULL)
				return (1);
		}
	}
	return (0);
}

int		ft_error_tab(int ac, char **av, char **str)
{
	int		i;
	int		k;
	int		x;

	i = 0;
	k = 1;
	x = 0;
	if (ac == 2)
	{
		if (doublon(str, i, x, k))
			return (1);
	}
	else
	{
		if (check_doublon(ac, av, x))
			return (1);
	}
	return (0);
}
