/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:42:58 by gpochon           #+#    #+#             */
/*   Updated: 2024/09/26 14:21:24 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		src_len;

	src_len = ft_strlen(src);
	dest = malloc(sizeof(*dest) * (src_len) + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_strcpy(dest, src);
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			pos;

	pos = 0;
	res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	while (pos < ac)
	{
		res[pos].size = ft_strlen(av[pos]);
		res[pos].str = av[pos];
		res[pos].copy = ft_strdup(res[pos].str);
		pos++;
	}
	res[pos].str = 0;
	return (res);
}
/*
int main(void)
{
	char *strings[] = {"Hello", "42", "World", "LibGPO"};
	int ac = 4;

	struct s_stock_str *tab = ft_strs_to_tab(ac, strings);
	if (tab == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return 1;
	}
	for (int i = 0; i < ac; i++)
	{
		printf("Original String: %s\n", tab[i].str);
		printf("Copied String: %s\n", tab[i].copy);
		printf("String Length: %d\n\n", tab[i].size);
	}
	for (int i = 0; i < ac; i++)
	{
		free(tab[i].copy);
	}
	free(tab);
	return 0;
}
*/
