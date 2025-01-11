/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:17:23 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/11 15:29:07 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int   *init_stack_a(int ac, char **av, int *size_a)
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
		check_mlt_args(ac, av);
		dup_check(av, 2);
	}
	else if (ac == 1)
		ft_error("");
}

int  *init_stack_b(int *stack_a, int size_a)
{
	int	*stack_b;

	stack_b = malloc(sizeof(int) * size_a);
	if (!stack_b)
    {
        free(stack_a);
        errorhandler("Stack B malloc failed");
    }
	return (stack_b);
}
