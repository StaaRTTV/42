/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:56:29 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/29 09:33:45 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static size_t	count_digit(int digidix)
{
	size_t	count;

	count = 0;
	if (digidix <= 0)
	{
		count = 1;
		if (digidix < 0)
			digidix *= -1;
	}
	while (digidix != 0)
	{
		digidix /= 10;
		count++;
	}
	return (count);
}

static void	define_nb(int i, char *array, int *index)
{
	if (i >= 10)
		define_nb(i / 10, array, index);
	array[(*index)++] = (i % 10) + 48;
}

char	*ft_itoa(int n)
{
	int		j;
	char	*array;

	j = 0;
	array = ft_calloc(1, (count_digit(n) + 1));
	if (!array)
		return (NULL);
	if (n == -2147483648)
	{
		ft_memcpy(array, "-2147483648", 12);
		return (array);
	}
	if (n < 0)
	{
		array[j] = '-';
		j++;
		n *= -1;
	}
	define_nb(n, array, &j);
	array[j] = '\0';
	return (array);
}
