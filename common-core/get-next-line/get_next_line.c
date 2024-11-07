/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:13:03 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/07 15:47:37 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_buffer(int fd, char *left_char, char *buffer)
{
	
}

char	*set_line(char *line_buff)
{
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	static char		*last_c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
}
