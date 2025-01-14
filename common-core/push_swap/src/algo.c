/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:07 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 14:46:45 by gpochon          ###   ########.fr       */
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

void	quicksort_b(t_stack *stacks)
{
	int pivot;
	int i;

	i = 0;
	if (stacks->size_b == 0)
		return;
	if (stacks->size_b <= 3)
    {
        while (stacks->size_b > 0)
            push_a(stacks);
        sort_3_elements(stacks);
        return;
    }
	pivot = stacks->stack_b[stacks->size_b / 2];
	while (i < stacks->size_b)
	{
		if (stacks->stack_b[0] >= pivot)
        {
            push_a(stacks);
			i++;
        }
        else
            rot(stacks, STACK_B);
	}
	quicksort(stacks);
	quicksort_b(stacks);
}

void quicksort(t_stack *stacks)
{
	int pivot;
	int i;

	i = 0;
	if (stacks->size_a <= 3)
    {
        sort_3_elements(stacks);
        return;
    }
	pivot = stacks->stack_a[stacks->size_a / 2];
	while (i < stacks->size_a)
	{
		while (i < stacks->size_a)
		{
			if (stacks->stack_a[0] < pivot)
        {
            push_b(stacks);
            i++;
        }
        else
            rot(stacks, STACK_A);
		}
	}
	quicksort_b(stacks);
	quicksort(stacks);
}


