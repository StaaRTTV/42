/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:25:08 by gpochon           #+#    #+#             */
/*   Updated: 2024/09/23 10:12:18 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	diff;
	int	*array;
	int	i;

	diff = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	array = malloc(diff * sizeof(int));
	*range = array;
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (diff);
}
