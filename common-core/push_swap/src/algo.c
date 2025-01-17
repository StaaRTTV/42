/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:07 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/17 12:47:08 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_sorted(t_stack *stacks)
{
	int i;

	i = 0;
	if (stacks->size_b != 0)
		return (1);
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void quicksort_b(t_stack *stacks)
{
	int pivot;
	int pushed;
	int initialsize;

	initialsize = stacks->size_b;
	if (stacks->size_b <= 3)
	{
		if (stacks->size_b == 2)
			swap(stacks, STACK_B);
		else if (stacks->size_b == 3)
			sort_3_elements_b(stacks);
	}
	pivot = calculate_median_b(stacks);
	pushed = 0;
	while (initialsize > 0)
	{
		if (stacks->stack_b[0] >= pivot)
		{
			push_a(stacks);
			pushed++;
		}
		else
			rot(stacks, STACK_B);
		initialsize--;
	}
	while (pushed > 0)
	{
		rot(stacks, STACK_B);
		pushed--;
	}
	if (stacks->size_b > 0)
		quicksort_b(stacks);
	quicksort(stacks);
}

void quicksort(t_stack *stacks)
{
	int pivot;
	int pushed;
	int initialsize;

	initialsize = stacks->size_a;
	if (is_sorted(stacks) == 0 && stacks->size_b == 0)
		exit(0);
	pivot = calculate_median_a(stacks);
	pushed = 0;
	while (initialsize > 0)
	{
		if (stacks->stack_a[0] <= pivot)
		{
			push_b(stacks);
			pushed++;
		}
		else
			rot(stacks, STACK_A);
		initialsize--;
	}
	while (pushed > 0)
	{
		rot(stacks, STACK_A);
		pushed--;
	}
	if (is_sorted(stacks) == 1)
		quicksort(stacks);
	if (stacks->size_b > 0)
		quicksort_b(stacks);
}
/*
void	ft_cleanquicksort(void)
{
	#END OF RECURSIVE
	#SPLIT CURRENT SIZE
	#CALL RECURSIVE
	#MERGE BOTH RECURSIONS
}
*/