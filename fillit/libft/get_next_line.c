/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:13:44 by aljigmon          #+#    #+#             */
/*   Updated: 2019/03/29 18:03:20 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static void		ft_free_elem(t_lst **first, const int fd)
{
	t_lst	*elem;
	t_lst	*tempo;

	elem = *first;
	if (elem->fd == fd)
	{
		*first = (*first)->next;
		free(elem);
		return ;
	}
	while (elem->next != NULL)
	{
		tempo = elem;
		elem = elem->next;
		if (elem->fd == fd)
		{
			tempo->next = elem->next;
			free(elem);
			return ;
		}
	}
}

static t_lst	*ft_new(const int fd)
{
	t_lst	*elem;

	if ((elem = (t_lst*)malloc(sizeof(*elem))) == NULL)
		return (NULL);
	elem->fd = fd;
	elem->tempo = NULL;
	elem->next = NULL;
	return (elem);
}

static t_lst	*good_elem(const int fd, int state)
{
	static t_lst	*first = NULL;
	t_lst			*elem;

	if (fd > 10240)
		return (NULL);
	if (first == NULL)
		if ((first = ft_new(fd)) == NULL)
			return (NULL);
	if ((elem = first) == first && state)
	{
		ft_free_elem(&first, fd);
		return (NULL);
	}
	if (elem->fd == fd)
		return (elem);
	while (elem->next != NULL)
	{
		elem = elem->next;
		if (elem->fd == fd)
			return (elem);
	}
	if (elem->next == NULL)
		if ((elem->next = ft_new(fd)) == NULL)
			return (NULL);
	return (elem->next);
}

static int		ft_line(char *buf, t_lst *elem, char *tempo2, char **line)
{
	int		i;

	i = 0;
	ft_strdel(&buf);
	if (ft_strchr(tempo2, '\n'))
	{
		while (tempo2[i] != '\n')
			i++;
		if ((elem->tempo = ft_strdup(&tempo2[i + 1])) == NULL)
			return (ERROR);
		tempo2[i] = '\0';
		if ((*line = ft_strdup(tempo2)) == NULL)
			return (ERROR);
		ft_strdel(&tempo2);
		return (STILL);
	}
	else if (tempo2[0] != '\0')
	{
		if ((*line = ft_strdup(tempo2)) == NULL)
			return (ERROR);
		ft_strdel(&tempo2);
		return (STILL);
	}
	ft_strdel(&tempo2);
	return ((int)good_elem(elem->fd, 1));
}

int				get_next_line(const int fd, char **line)
{
	char			*buf;
	t_lst			*elem;
	int				nb_c;
	char			*tempo2;

	nb_c = 1;
	if (fd < 0 || !line || BUFF_SIZE < 1 || !(elem = good_elem(fd, 0)))
		return (ERROR);
	if ((buf = ft_strnew(BUFF_SIZE)) == NULL)
		return (ERROR);
	if ((tempo2 = NULL) == NULL && elem->tempo != NULL)
	{
		if ((tempo2 = ft_strdup(elem->tempo)) == NULL)
			return (ERROR);
		ft_strdel(&(elem->tempo));
	}
	while (nb_c && ft_strchr(tempo2, '\n') == NULL)
	{
		if ((nb_c = read(elem->fd, buf, BUFF_SIZE)) == -1)
			return (ERROR);
		buf[nb_c] = '\0';
		if ((tempo2 = ft_strjoin_f(tempo2, buf, 1, 0)) == NULL)
			return (ERROR);
	}
	return (ft_line(buf, elem, tempo2, line));
}
