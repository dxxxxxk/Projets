/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:56:48 by dieroyer          #+#    #+#             */
/*   Updated: 2019/03/21 15:33:38 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newstrjoin(char *s1, char *s2)
{
	char	*s;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	s = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (s);
}

char	ft_check(char **s, int fd)
{
	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!*s)
	{
		if (!(*s = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
	}
	return (0);
}

char	*ft_read_line(char **s, int fd)
{
	char	*buf;
	int		ret;

	buf = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*s = ft_newstrjoin(*s, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (*s);
}

void	ft_fline(char **s, int i, int fd, char *tmp)
{
	tmp = ft_strsub(s[fd], i + 1, ft_strlen(s[fd]) - (i + 1));
	ft_strdel(&s[fd]);
	s[fd] = tmp;
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[OPEN_MAX];
	int			i;
	char		*tmp;

	tmp = NULL;
	if (ft_check(&s[fd], fd) == -1 || !line)
		return (-1);
	ft_read_line(&s[fd], fd);
	i = 0;
	if (s[fd][i] != '\0')
	{
		while (s[fd][i] != '\0' && s[fd][i] != '\n')
			i++;
		*line = ft_strsub(s[fd], 0, i);
		if (s[fd][i] == '\n')
			ft_fline(s, i, fd, tmp);
		else
			ft_strclr(s[fd]);
		return (1);
	}
	return (0);
}
