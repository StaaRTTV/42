/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:21:24 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/08 15:42:21 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_and_fill(int fd, char *remainder, int *bytes_read)
{
    char *buffer;
    char *temp;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while (!ft_strchr(*remainder, '\n'))
    {
        *bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (*bytes_read <= 0)
            break;
        buffer[*bytes_read] = '\0';
        temp = remainder;
        remainder = ft_strjoin(remainder, buffer);
        free(temp);
        if (!remainder)
        {
            free(buffer);
            return (NULL);
        }
    }
    free(buffer);
    return (*remainder);
}

static char *extract_line(char *remainder)
{
    char *line;
    char *new_remainder;
    int len;

    len = 0;
    while (remainder[len] && remainder[len] != '\n')
    {
        line = ft_strdup(remainder);
    }
}

char *get_next_line(int fd)
{
    int bytes_read;
    char *line;
    static char *remainder;

    remainder = NULL;
    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    bytes_read = 0;
    remainder = read_and_fill(fd, remainder, &bytes_read);
    if (!remainder)
        return (NULL);
    line = extract_line(&remainder);
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