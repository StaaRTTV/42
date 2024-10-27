/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:52:42 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/21 14:17:09 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
    char str[] = "Hello, world!";  
    char *dup1 = ft_strdup(str);
    char *dup2 = strdup(str);

    if (dup1 == NULL || dup2 == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }
    printf("Original: %s\n", str);
    printf("ft_strdup: %s\n", dup1);
    printf("strdup: %s\n", dup2);

    if (strcmp(dup1, dup2) == 0)
        printf("Test réussi !\n");
    else
        printf("Test échoué.\n");
    free(dup1);
    free(dup2);
    return 0;
}
*/
