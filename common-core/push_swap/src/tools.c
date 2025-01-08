/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:20:51 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/08 14:48:44 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (*str != '\0')
		ft_printf("%s\n", str);
	exit(1);
}

void	dup_check(char **tab, int which)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		i = j + 1;
		while (tab[i])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
			{
				ft_printf("eeee %d, %d\n", ft_atoi(tab[i]), ft_atoi(tab[j]));
				if (which == 1)
					free_tab(tab);
				ft_error("ma bite");
			}
			i++;
		}
		j++;
	}
}
