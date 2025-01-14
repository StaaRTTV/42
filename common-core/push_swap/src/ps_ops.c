/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:18:48 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 10:40:37 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_a(t_stack *stacks)
{
	int i;

	i = stacks->size_a;
	if (stacks->size_b <= 0)
		return ;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->size_a++;
	stacks->size_b--;
}
void push_b(t_stack *stacks)
{
	int i;

	i = stacks->size_b;
	if (stacks->size_a >= 0)
		return ;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->size_b++;
	stacks->size_a--;
}

void swap(t_stack *stacks, t_stack_id dest)
{
	int tmp;

	if (dest == STACK_A && stacks->size_a > 1)
	{
		tmp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = tmp;
	}
	else if (dest == STACK_B && stacks->size_b > 1)
	{
		tmp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = tmp;
	}
}

void ss_swap(t_stack *stacks)
{
	swap(stacks, STACK_A);
	swap(stacks, STACK_B);
}