/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:38:34 by dieroyer          #+#    #+#             */
/*   Updated: 2018/11/30 17:21:23 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 4096

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (ac != 2)
	{
		if (ac < 2)
			write(1, "File name missing.\n", 19);
		if (ac > 2)
			write(1, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	ret = read(fd, &buf, BUF_SIZE);
	printf("BUFF_SIZE = ""%d\n", BUF_SIZE);
	printf("ret = ""%d\n", ret);
	printf("buffer = ""%s\n", buf);
	buf[ret] = '\0';
	ft_putstr(buf);
	return (0);
}
