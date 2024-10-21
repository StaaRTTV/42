/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:28:27 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/18 14:37:45 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	aff(char *filename)
{
	int		fd;
	int		ret;
	char	buffer[4096];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 18);
	}
	else
	{
		ret = read(fd, buffer, 4096);
		write(1, buffer, ret);
		close(fd);
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (ac > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	else
	{
		aff(av[1]);
		return (0);
	}
}
