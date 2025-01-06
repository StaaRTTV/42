/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:17:31 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/06 13:20:30 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	single_arg(char *av)
{
	tps_list	*stack_a;
	tps_list	*stack_b;
	char		**tab;
	int			i;

	i = 0;
	if (ft_strlen(av) < 1 || ft_isonlyspace(av) == 0)
		ft_error("✖ Argument is invalid ✖");
	tab = ft_split(av, ' ');
	while (tab[i] != NULL)
	{
		if (ft_strisdigit(tab[i]) == 1)
		{
			ft_error("✖ Argument is invalid ✖");
		}
		else
		{
			tab[i] = ft_atoi(tab[i]);
		}
		i++;
	}
}
