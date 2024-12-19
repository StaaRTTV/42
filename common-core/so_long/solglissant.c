/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solglissant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:26:08 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/19 16:31:59 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"


void	mob_randomizer(t_g *game, int mob_x, int mob_y)
{
	int	dx;
	int	dy;
	int new_x;
	int new_y;
	int direction;

	dx = 0;
	dy = 0;
	direction = rand() % 4;

	if (direction == 0)
		dx = 1;
	else if (direction == 1)
		dx = -1;
	else if (direction == 2)
		dy = 1;
	else if (direction == 3)
		dy = -1;
	new_x = mob_x + dx;
	new_y = mob_y + dy;
	if (game->map[new_y][new_x] == '0')
	{
		game->map[mob_y][mob_x] = '0';
		game->map[new_y][new_x] = 'M';
	}
	game->mob_x = new_x;
	game->mob_y = new_y;
}

void	init_mob_position(t_g *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'M')
			{
				game->mob_x = x;
				game->mob_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
