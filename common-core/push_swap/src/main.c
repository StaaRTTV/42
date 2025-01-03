/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:02 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/03 16:06:03 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (*str != '\0')
		ft_printf("%s\n", str);
	exit(1);
}

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
