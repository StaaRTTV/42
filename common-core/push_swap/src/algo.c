/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:07 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/15 15:46:34 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	sort_3_elements_a(t_stack *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_a[0];
	b = stacks->stack_a[1];
	c = stacks->stack_a[2];
	if (a > b && b > c)
	{
		swap(stacks, STACK_A);
		rrot(stacks, STACK_A);
	}
	else if (a > c && c > b)
		rot(stacks, STACK_A);
	else if (b > a && a > c)
		rrot(stacks, STACK_A);
	else if (b > c && c > a)
		swap(stacks, STACK_A);
	else if (c > a && a > b)
	{
		swap(stacks, STACK_A);
		rot(stacks, STACK_A);
	}
}
void	sort_3_elements_b(t_stack *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_b[0];
	b = stacks->stack_b[1];
	c = stacks->stack_b[2];
	if (a > b && b > c)
	{
		swap(stacks, STACK_B);
		rrot(stacks, STACK_B);
	}
	else if (a > c && c > b)
		rot(stacks, STACK_B);
	else if (b > a && a > c)
		rrot(stacks, STACK_B);
	else if (b > c && c > a)
		swap(stacks, STACK_B);
	else if (c > a && a > b)
	{
		swap(stacks, STACK_B);
		rot(stacks, STACK_B);
	}
}
int is_sorted(t_stack *stacks)
{
	int i;

	i = 0;
	if (stacks->size_b > 0)
		return (1);
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (1);
		i++;
	}
	// printstack(stacks);
	return (0);
}

void	quicksort_b(t_stack *stacks)
{
	int pivot;
	int i;
	int initial_size;

	i = 0;
	if (stacks->size_b <= 3)
    {
		if (stacks->size_b == 2)
			swap(stacks, STACK_B);
		else if (stacks->size_b == 3)
			sort_3_elements(stacks);
        return;
    }
	initial_size = stacks->size_b;
	pivot = calculate_median_b(stacks);
	while (i < initial_size)
	{
		if (stacks->stack_b[0] >= pivot)
            push_a(stacks);
        else
            rot(stacks, STACK_B);
		i++;
	}
	quicksort_b(stacks);
}

void quicksort(t_stack *stacks)
{
	int pivot;
	int i;
	int initial_size;

	is_sorted(stacks);
	pivot = calculate_median_a(stacks);
	initial_size = stacks->size_a;
	i = 0;
	while (i < initial_size)
	{
		if (stacks->stack_a[0] <= pivot)
			push_b(stacks);
		else
			rot(stacks, STACK_A);
		i++;
	}
	quicksort(stacks);
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