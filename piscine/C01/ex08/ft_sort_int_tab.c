/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:35:42 by gpochon           #+#    #+#             */
/*   Updated: 2024/09/11 15:11:57 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	e;
	int	temp;

	i = 0;
	e = 0;
	temp = 0;
	while (i < size)
	{
		while (e < size - 1)
		{
			if (tab[e + 1] < tab[e])
			{
				temp = tab[e + 1];
				tab[e + 1] = tab[e];
				tab[e] = temp;
				e = 0;
			}
			else
				e++;
		}
		i++;
	}
}
