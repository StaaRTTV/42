/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:18:26 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/22 13:31:36 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
        {
            if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
            {
                return ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
            }
            i++;
        }
        return 0;
}
/*
int    main(void)
{
    char    str1[] = "hellp";
    char    str2[] = "hello";
    
    printf("%d\n", ft_memcmp(str1, str2, 6));
    return (0);
}
*/
