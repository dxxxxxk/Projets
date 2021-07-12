/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:21:03 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/12 10:14:48 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_strlen_n(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n')
		i++;
	return (i);
}

static int	fill_line(char **str, char **line, char **buff)
{
	int		len;
	char	*tmp;

	len = ft_strlen_n(*str);
	tmp = *str;
	*line = ft_strndup(*str, len);
	*str = ft_strdup(&tmp[len + 1]);
	ft_strdel(&tmp);
	ft_strdel(&(*buff));
	return (1);
}

static int	ft_check(char **str, char **buff, char **tmp, char **line)
{
	*tmp = ft_strdup(*str);
	ft_strdel(&(*str));
	if (!(*str = ft_strjoin(*tmp, *buff)))
		return (-1);
	ft_strdel(&(*tmp));
	if (ft_strchr(*str, '\n') != NULL)
	{
		fill_line(str, line, buff);
		return (1);
	}
	return (0);
}

static int	ft_read(int fd, char **line, char **str)
{
	char	*tmp;
	int		ret;
	char	*buff;
	int		test;

	if (!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (ft_strchr(*str, '\n') != NULL)
	{
		fill_line(&(*str), line, &buff);
		return (1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		test = ft_check(str, &buff, &tmp, line);
		if (test == 1 || test == -1)
			return (test);
	}
	ft_strdel(&(buff));
	if (ft_isprint(*str[0]))
		return (2);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			r;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFF_SIZE < 1)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	r = ft_read(fd, line, &(str[fd]));
	if (r == 0)
	{
		if (str[fd])
			ft_strdel(&str[fd]);
	}
	else if (r == 2)
	{
		if (ft_strchr(str[fd], '\n') != NULL)
			*line = ft_strndup(str[fd], ft_strlen_n(str[fd]));
		else
			*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		return (1);
	}
	return (r);
}
