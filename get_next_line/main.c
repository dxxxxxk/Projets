/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:23:25 by dieroyer          #+#    #+#             */
/*   Updated: 2019/02/06 16:47:48 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		ret;
	char	*line;
	line = NULL;
	(void)ac;
	
	fd = open(av[1], O_RDONLY);	
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%d: %s\n", ret, line);
		free(line);
		line = NULL;
		while ((ret = get_next_line(fd3, &line)) == 1)
		{
			printf("%d: %s\n", ret, line);
			free(line);
			line = NULL;
		}
	}
	while ((ret = get_next_line(fd2, &line)) == 1)
	{	
		printf("%d: %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("%d\n", ret);
	free(line);
	line = NULL;
}
