/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:24:26 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/02 22:38:01 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

int	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	srcl;

	i = 0;
	srcl = 0;
	while (src[srcl] != '\0')
		srcl++;
	if (size == 0)
		return (srcl);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srcl);
}
/*
int	main(void)
{
    char src[] = "J'encule Eliot";
    char dest[6];  

    size_t copied_len = ft_strlcpy(dest, src, sizeof(dest));

	printf("mine : %d\n", ft_strlcpy(dest, src, 0));
	/*printf("real : %zu\n", strlcpy(dest, src, 50));
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	printf("Lenght of source: %zu\n", copied_len);

    return (0);
}
*/
