/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:07 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 16:09:30 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_elements(t_stack *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap(stacks, STACK_A);
	if (stacks->stack_a[0] > stacks->stack_a[2])
        rot(stacks, STACK_A);
    if (stacks->stack_a[1] > stacks->stack_a[2])
        swap(stacks, STACK_A);
}

void is_sorted(t_stack *stacks)
{
	int i;

	i = 0;
	if (stacks->size_b > 0)
		return;
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] < stacks->stack_a[i + 1])
			i++;
		else
			return;
	}
	// printstack(stacks);
	free(stacks->stack_a);
	free(stacks->stack_b);
	exit(0);
}

void	quicksort_b(t_stack *stacks)
{
	int pivot;
	int i;
	int initial_size;

	i = 0;
	if (stacks->size_b <= 3)
    {
        while (stacks->size_b > 0)
            push_a(stacks);
        sort_3_elements(stacks);
        return;
    }
	initial_size = stacks->size_b;
	pivot = stacks->stack_b[stacks->size_b / 2];
	while (i < initial_size)
	{
		if (stacks->stack_b[0] >= pivot)
            push_a(stacks);
        else
            rot(stacks, STACK_B);
		i++;
	}
	quicksort(stacks);
	quicksort_b(stacks);
}

void quicksort(t_stack *stacks)
{
	int pivot;
	int i;
	int initial_size;

	is_sorted(stacks);
	initial_size = stacks->size_a;
	pivot = stacks->stack_a[stacks->size_a / 2];
	i = 0;
	while (i < initial_size)
	{
		if (stacks->stack_a[0] < pivot)
			push_b(stacks);
		else
			rot(stacks, STACK_A);
		i++;
	}
	quicksort_b(stacks);
	quicksort(stacks);
}


