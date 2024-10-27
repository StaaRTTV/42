/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:41:33 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/21 11:39:13 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (!src)
		return (NULL);
	if (dest > src)
	{
		i = count;
		while (i > 0)
		{
			i--;
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		}
	}
	else
	{
		i = 0;
		while (i < count)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}
/*
int    main(void)
{
    char src[] = "la mamie elle appelle à 22h30 normal!";
    char dest[35];

    printf("input: %s\n", src);
    ft_memmove(dest,src,strlen(src) + 1);
    printf("output: %s\n", dest);

    ft_memmove(src + 6, src, 5);
    printf("test: %s\n", src);
    return (0);
}
*/
