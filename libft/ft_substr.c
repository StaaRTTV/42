/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:52:27 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/24 10:43:25 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*result;

	i = 0;
	result = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s[start] && i < len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	char	test[] = "wesh les amigos";

	printf("%s", ft_substr(test, 5, 3));
	return (0);
}
*/
