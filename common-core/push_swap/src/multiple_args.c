/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:38:59 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/06 09:31:03 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int    ft_strisdigit(char *str)
{
    int    i;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
            || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+')
	{
        i++;
		if (str[i] == '\0')
			return (1);
	}
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}

void	check_mlt_args(char **av, int ac)
{
    int    i;
    
    i = 1;
    while (i < ac)
    {
        if(ft_strlen(av[i]) < 1 || ft_strisdigit(av[i]) == 1)
            ft_printf("✖ Argument [%d] is invalid ✖\n", i);
        else
            ft_printf("✔ Argument [%d] is valid ✔\n", i);
        i++;
    }
}

void	multiple_args(int ac, char **av)
{
	tps_list	*stack_a;
	tps_list	*stack_b;
	int			i;

	i = 1;
	check_mlt_args(av, ac);
	exit (0);
}
