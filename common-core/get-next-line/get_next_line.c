/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:21:24 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/07 19:38:34 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buffer(int fd, t_list *last_c, int alr_read)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	while (ft_strchr(last_c, '\n'))
	{
		*alr_read = read(fd, buffer, BUFFER_SIZE);
		if (*alr_read <= 0)
			break ;
		buffer[alr_read] = NULL;
	}
	return (*last_c);
}

static char	*set_line(char *line_buff)
{
}

char	*get_next_line(int fd)
{
	int				alr_read;
	char			*line;
	static t_list	*last_c;

	last_c = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, 0, 0) < 0)
		return (-1);
	alr_read = 0;
	last_c = fill_buffer(fd, &last_c, &alr_read);
	if (last_c)
		line = set_line(last_c);
	return (line);
}
/*
#include <stdio.h>

int	main()
{
	int	fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);
	}
	return (0);
}
*/