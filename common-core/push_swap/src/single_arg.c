/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:17:31 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/07 16:18:44 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	single_arg(char *av)
{
	char		**tab;
	int			i;

	i = -1;
	if (ft_strlen(av) < 1 || ft_isonlyspace(av) == 0)
		ft_error("✖ Argument is invalid ✖");
	tab = ft_split(av, ' ');
	if (!tab)
		ft_error("ft_split failed"); 
	while (i++, tab[i] != NULL)
	{
		if (ft_strisdigit(tab[i]) == 1)
		{
			free_tab(tab);
			ft_error("✖ Argument is invalid ✖");
		}
		if (ft_atol(tab[i]) > INT_MAX || ft_atol(tab[i]) < INT_MIN)
		{
			free_tab(tab);
			ft_error("✖ Argument is invalid ✖");
		}
		ft_printf("✔ Argument is valid ✔\n");
	}
}