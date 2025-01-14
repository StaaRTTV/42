/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:02 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 10:46:25 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stacks;

	stacks.stack_a = init_stack_a(ac, av, &stacks.size_a);
	stacks.stack_b = init_stack_b(stacks.stack_a, stacks.size_a);
	free(stacks.stack_a);
	free(stacks.stack_b);
	return (0);
}
