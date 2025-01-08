/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:02 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/08 15:09:18 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	char	**tab;

	if (ac == 2)
	{
		tab = single_arg(av[1]);
		dup_check(tab, 1);
	}
	if (ac > 2)
	{
		check_mlt_args(ac, av);
		dup_check(av, 2);
	}
	else if (ac == 1)
		ft_error("");
	return (0);
}
