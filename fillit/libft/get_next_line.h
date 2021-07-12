/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:14:24 by aljigmon          #+#    #+#             */
/*   Updated: 2019/02/25 11:20:22 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define ERROR -1
# define STILL 1

typedef struct					s_lst
{
	int				fd;
	char			*tempo;
	struct s_lst	*next;
}								t_lst;

int								get_next_line(const int fd, char **line);

#endif
