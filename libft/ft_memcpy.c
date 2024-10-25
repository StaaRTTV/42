/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:52:14 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/21 11:35:52 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == src || len == 0)
		return (dest);
	while (i < len)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}
/*
int    main(void)
{
    char str[50] = "je";
    char str2[10];

    printf("avant: %s\n",str);
    ft_memcpy(str, str2, 7 * (sizeof(char)));
    printf("apres: %s\n",str);
    return (0);
}
*/
