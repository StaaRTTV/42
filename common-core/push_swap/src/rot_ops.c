/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:18:11 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 16:01:03 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rot(t_stack *stacks, t_stack_id which)
{
	int	tmp;
	int	i;

	i = -1;
	if (which == STACK_A && stacks->size_a > 1)
	{
		ft_printf("ra\n");
		tmp = stacks->stack_a[0];
		while (i++, i < stacks->size_a - 1)
			stacks->stack_a[i] = stacks->stack_a[i + 1];
		stacks->stack_a[stacks->size_a - 1] = tmp;
	}
	else if (which == STACK_B && stacks->size_b > 1)
	{
		ft_printf("rb\n");
		tmp = stacks->stack_b[0];
		while (i++, i < stacks->size_b - 1)
			stacks->stack_b[i] = stacks->stack_b[i + 1];
		stacks->stack_b[stacks->size_b - 1] = tmp;
	}
}

void	rrot(t_stack *stacks, t_stack_id which)
{
	int	tmp;
	int	i;

	if (which == STACK_A)
	{
		ft_printf("rra\n");
		i = stacks->size_a;
		tmp = stacks->stack_a[stacks->size_a - 1];
		while (i--, i > 0)
			stacks->stack_a[i] = stacks->stack_a[i - 1];
		stacks->stack_a[0] = tmp;
	}
	else if (which == STACK_B)
	{
		ft_printf("rrb\n");
		i = stacks->size_b;
		tmp = stacks->stack_b[stacks->size_b - 1];
		while (i--, i > 0)
			stacks->stack_b[i] = stacks->stack_b[i - 1];
		stacks->stack_b[0] = tmp;
	}
}

void	rr(t_stack *stacks)
{
	ft_printf("rr\n");
	rot(stacks, STACK_A);
	rot(stacks, STACK_B);
}

void	rrr(t_stack *stacks)
{
	ft_printf("rrr\n");
	rrot(stacks, STACK_A);
	rrot(stacks, STACK_B);
}
