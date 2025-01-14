/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:02 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 16:09:44 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void printstack(t_stack *stacks)
{
	int i;

	i = 0;
	ft_printf("size_a = %d\n", stacks->size_a);
	while (i < stacks->size_a)
	{
		ft_printf("stack_a[%d] = %d\n", i, stacks->stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("size_b = %d\n", stacks->size_b);
	while (i < stacks->size_b)
	{
		ft_printf("stack_b[%d] = %d\n", i, stacks->stack_b[i]);
		i++;
	}
	ft_printf("\n");
}
int	main(int ac, char **av)
{
	t_stack	stacks;

	stacks.stack_a = init_stack_a(ac, av, &stacks.size_a);
	stacks.stack_b = init_stack_b(stacks.stack_a, stacks.size_a, &stacks);
	if (stacks.size_a == 2)
	{
		if (stacks.stack_a[0] > stacks.stack_a[1])
			swap(&stacks, STACK_A);
	}
	if (stacks.size_a == 3)
		sort_3_elements(&stacks);
	// printstack(&stacks);
	quicksort(&stacks);
	free(stacks.stack_a);
	free(stacks.stack_b);
	return (0);
}
