/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:20:51 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/11 15:25:36 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (*str != '\0')
		ft_printf("%s\n", str);
	exit(1);
}

void	dup_check(char **tab, int which)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab[j])
	{
		i = j + 1;
		while (tab[i])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
			{
				if (which == 1)
					free_tab(tab);
				ft_error("ma bite");
			}
			i++;
		}
		j++;
	}
}

int    *tabatoi(char **table, int which, int *size_a)
{
    int    i;
    int    index;
    int    tmp;
    int    *stack_a;

    i = (which == 0);
    tmp = i;
    index = 0;
    *size_a = 0;
    while (table[tmp++])
        (*size_a)++;
    stack_a = malloc((*size_a) * sizeof(int));
    if (!stack_a)
        errorhandler("Malloc failed");
    while (table[i])
        stack_a[index++] = ft_atoi(table[i++]);
    if (which)
        freetable(table);
    return (stack_a);
}
