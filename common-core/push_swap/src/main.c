/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:02 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/07 14:17:40 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	if (ac == 2)
		single_arg(av[1]);
	if (ac > 2)
		multiple_args(ac, av);
	else if (ac == 1)
		ft_error("");
	return (0);
}