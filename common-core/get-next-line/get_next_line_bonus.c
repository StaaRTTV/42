/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:21:24 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/13 09:51:37 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static char	*read_and_fill(int fd, char *remainder, int *bytes_read)
{
	char	*buffer;
	char	*temp;

	if (!remainder)
		remainder = ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr((const char *)remainder, '\n'))
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read <= 0)
			break ;
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
	return (remainder);
}

static char	*extract_line(char **remainder)
{
	char	*line;
	char	*new_remainder;
	int		len;

	len = 0;
	if (!*remainder || !**remainder)
		return (NULL);
	while ((*remainder)[len] && (*remainder)[len] != '\n')
		len++;
	if ((*remainder)[len] == '\n')
		len++;
	line = ft_substr(*remainder, 0, len);
	if (!line)
		return (NULL);
	new_remainder = ft_strdup(*remainder + len);
	free (*remainder);
	*remainder = new_remainder;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	int			bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (remainder[fd])
		{
			free(remainder[fd]);
			remainder[fd] = NULL;
		}
		return (NULL);
	}
	bytes_read = 0;
	remainder[fd] = read_and_fill(fd, remainder[fd], &bytes_read);
	if (!remainder[fd])
		return (NULL);
	line = extract_line(&remainder[fd]);
	if (bytes_read == 0 && !line)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
	}
	return (line);
}
/*
int main(void)
{
	int fd;
	char *line;
	int	i = 710;
	int k = 0;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur d'ouverture du fichier");
		return (1);
	}
	while (k < i)
	{
		line = get_next_line(fd);
		printf("%s", line);
		k++;
	}
	close(fd);
	return (0);
}
*/
