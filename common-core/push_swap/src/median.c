/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:20:46 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 21:05:17 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int  *stack_to_tab(t_stack *stacks, int *tab, t_stack_id which)
{
	int i;

	i = 0;
	if (which == STACK_A)
	{
		while (i < stacks->size_a)
		{
			tab[i] = stacks->stack_a[i];
			i++;
		}
	}
	else
	{
		while (i < stacks->size_b)
		{
			tab[i] = stacks->stack_b[i];
			i++;
		}
	}
	return (tab);
}

static void	sort_int_tab(int *tab, t_stack *stacks)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < stacks->size_a)
	{
		j = i + 1;
		while (j < stacks->size_a)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	calculate_median_a(t_stack *stacks)
{
	int *tab;
	int median;

	tab = malloc(sizeof(int) * stacks->size_a);
	if (!tab)
		ft_error("Malloc failed");
	tab = stack_to_tab(stacks, tab, STACK_A);
	sort_int_tab(tab, stacks);
	median = tab[stacks->size_a / 2];
	ft_printf("La mediane c'est : %d\n", median);
	free(tab);
	return (median);
}

int	calculate_median_b(t_stack *stacks)
{
	int *tab;
	int median;

	tab = malloc(sizeof(int) * stacks->size_b);
	if (!tab)
		ft_error("Malloc failed");
	tab = stack_to_tab(stacks, tab, STACK_B);
	sort_int_tab(tab, stacks);
	median = tab[stacks->size_b / 2];
	ft_printf("La mediane c'est : %d\n", median);
	free(tab);
	return (median);
}
