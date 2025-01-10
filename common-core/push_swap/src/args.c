/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:38:59 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/10 16:17:00 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
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

void	check_mlt_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) < 1 || ft_strisdigit(av[i]) == 1
			|| ft_isonlyspace(av[i]) == 0)
			ft_error("✖ Argument is invalid ✖\n");
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			ft_error("✖ Argument is invalid ✖\n");
		else
			ft_printf("✔ Argument is valid ✔\n");
		i++;
	}
}

char	**single_arg(char *av)
{
	char		**tab;
	int			i;

	i = -1;
	if (ft_strlen(av) < 1 || ft_isonlyspace(av) == 0)
		ft_error("✖ Argument is invalid ✖");
	tab = ft_split(av, ' ');
	if (!tab)
		ft_error("ft_split failed"); 
	while (i++, tab[i] != NULL)
	{
		if (ft_strisdigit(tab[i]) == 1)
		{
			free_tab(tab);
			ft_error("✖ Argument is invalid ✖");
		}
		if (ft_atol(tab[i]) > INT_MAX || ft_atol(tab[i]) < INT_MIN)
		{
			free_tab(tab);
			ft_error("✖ Argument is invalid ✖");
		}
		ft_printf("✔ Argument is valid ✔\n");
	}
	return (tab);
}
