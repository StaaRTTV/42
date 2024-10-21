/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:36:25 by gpochon           #+#    #+#             */
/*   Updated: 2024/09/23 12:24:30 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	strtotal(int size, char **strs, char *sep)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += ft_strlen(sep) * (size - 1);
	return (total);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*finito;

	i = 0;
	if (size == 0)
	{
		finito = malloc(sizeof(char));
		finito[0] = '\0';
		return (finito);
	}
	finito = malloc(sizeof(char) * (strtotal(size, strs, sep) + 1));
	if (finito == NULL)
		return (NULL);
	finito[0] = '\0';
	while (i < size)
	{
		ft_strcat(finito, strs[i]);
		if (i < size - 1)
			ft_strcat(finito, sep);
		i++;
	}
	return (finito);
}
/*
int main(void)
{
    char *strs[4] = {"Hello", "World", "!", "!"};
    char *sep = " - ";
    char *ret;

    ret = ft_strjoin(4, strs, sep);
    printf("%s\n", ret);
    free(ret);
    return (0);
}
*/	
