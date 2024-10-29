/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:07:01 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/09 16:22:09 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	srcl;
	unsigned int	destl;

	i = 0;
	srcl = ft_strlen(src);
	destl = ft_strlen(dest);
	if (size == 0)
		return (srcl);
	if (size <= destl)
		return (size + srcl);
	while (src[i] && (destl + i) < (size - 1))
	{
		dest[destl + i] = src[i];
		i++;
	}
	dest[i + destl] = '\0';
	return (destl + srcl);
}
/*
int main(void)
{
    char dest[20] = "Simon ";
    const char src[] = "Gay";

    size_t total_len = ft_strlcat(dest, src, sizeof(dest));

    printf("Destination après concaténation : %s\n", dest);
    printf("Longueur totale (dest + src) : %zu\n", total_len);

    return (0);
}
*/
