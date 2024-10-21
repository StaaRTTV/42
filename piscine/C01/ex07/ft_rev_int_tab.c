/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:02:20 by gpochon           #+#    #+#             */
/*   Updated: 2024/09/11 11:15:46 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	lettre;

	i = 0;
	while (i < size / 2)
	{
		lettre = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = lettre;
		i++;
	}
}
