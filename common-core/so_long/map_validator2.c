/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:21:05 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/30 15:59:06 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	check_mob(t_g *game, char to_check)
{
	int	x;
	int	y;
	int	check;

	y = 0;
	check = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == to_check)
				check++;
			x++;
		}
		y++;
	}
	if (check > 1)
	{
		error_exit(game, "There is too much mobs\n");
	}
}

void	map_check_rectangle(t_g *game)
{
	int	x;
	int	y;
	int	width;

	if (!game->map || !game->map[0])
		ft_putstr_fd("Error\n", 1);
	y = 0;
	width = ft_strlen2emedunom(game->map[0]);
	while (game->map[y])
	{
		x = ft_strlen2emedunom(game->map[y]);
		if (x != width)
		{
			error_exit(game, "There is an issue with the length\n");
		}
		if (x == 0)
		{
			error_exit(game, "Empty row detected in map\n");
		}
		y++;
	}
}

void	is_ber(char *str, t_g *game)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
		|| str[i - 4] != '.')
	{
		error_exit(game, "Map file must be a .ber file\n");
	}
}
