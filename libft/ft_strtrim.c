/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:18:23 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/24 12:01:26 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dest, const char *src, size_t size)
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

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (str)
		ft_strlcpy(str, (char *)(s1 + start), end - start + 1);
	return (str);
}

/*int	main()
{
	const char	str[] = "ooooo[jesuisfionnnnbeau]oooo";
	const char	rjer[] = "o";
	
	printf("%s", ft_strtrim(str, rjer));
	return (0);
}*/
