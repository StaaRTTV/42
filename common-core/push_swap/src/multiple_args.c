/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:38:59 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/03 16:23:08 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_mlt_args(char **av)
{
	int	i;
	i = 1;
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 0)
		{
			ft_printf("Multiple arguments ca a pas marche, c'etait le char %s\n", av[i]);
			ft_error("Invalid argument, either choose a single argument or multiple arguments or the arguments are not digits");
		}	
		i++;
	}

}

void	multiple_args(int ac, char **av)
{
	tps_list	*stack_a;
	tps_list	*stack_b;
	int			i;

	i = 1;
	check_mlt_args(av);
	ft_printf("Multiple arguments ca a marche\n");
	exit (0);
}
