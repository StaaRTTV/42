/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:18:11 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 10:45:43 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rot(t_stack *stacks, t_stack_id which)
{
	int	tmp;
	int	i;

	i = 0;
	if (which == STACK_A && stacks->size_a > 1)
	{
		tmp = stacks->stack_a[0];
		while (i < stacks->size_a - 1)
		{
			stacks->stack_a[i] = stacks->stack_a[i + 1];
			i++;
		}
		stacks->stack_a[stacks->size_a - 1] = tmp;
	}
	else if (which == STACK_B && stacks->size_b > 1)
	{
		tmp = stacks->stack_b[0];
		while (i < stacks->size_b - 1)
		{
			stacks->stack_b[i] = stacks->stack_b[i + 1];
			i++;
		}
		stacks->stack_b[stacks->size_b - 1] = tmp;
	}
}

void	rrot(t_stack *stacks, t_stack_id which)
{
	int	tmp;
	int	i;

	if (which == STACK_A)
	{
		i = stacks->size_a - 1;
		tmp = stacks->stack_a[stacks->size_a - 1];
		while (i > 0)
		{
			stacks->stack_a[i] = stacks->stack_a[i - 1];
			i--;
		}
		stacks->stack_a[0] = tmp;
	}
	else if (which == STACK_B)
	{
		i = stacks->size_b - 1;
		tmp = stacks->stack_b[stacks->size_b - 1];
		while (i > 0)
		{
			stacks->stack_b[i] = stacks->stack_b[i - 1];
			i--;
		}
		stacks->stack_b[0] = tmp;
	}
}

void	rr(t_stack *stacks)
{
	rot(stacks, STACK_A);
	rot(stacks, STACK_B);
}

void	rrr(t_stack *stacks)
{
	rrot(stacks, STACK_A);
	rrot(stacks, STACK_B);
}
