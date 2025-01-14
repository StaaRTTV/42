/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:17:23 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 10:56:12 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*init_stack_a(int ac, char **av, int *size_a)
{
	char	**tab;
	int		*stack_a;

	if (ac == 2)
	{
		tab = single_arg(av);
		dup_check(tab, 1);
		stack_a = tabatoi(tab, 1, size_a);
	}
	if (ac > 2)
	{
		tab = av;
		check_mlt_args(ac, av);
		dup_check(av, 0);
		stack_a = tabatoi(av, 0, size_a);
	}
	else if (ac == 1)
		ft_error("");
	return (stack_a);
}

int	*init_stack_b(int *stack_a, int size_a, t_stack *stacks)
{
	int	*stack_b;

	stacks->size_b = 0;
	stack_b = malloc(sizeof(int) * size_a);
	if (!stack_b)
	{
		free(stack_a);
		ft_error("Stack B malloc failed");
	}
	return (stack_b);
}
