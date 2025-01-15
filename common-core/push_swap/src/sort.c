/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:49:15 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/15 14:51:16 by gpochon          ###   ########.fr       */
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
