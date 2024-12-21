/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solglissant2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:32:20 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/21 12:34:31 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	count_mob(t_g *game)
{
	int	x;
	int	y;

	y = 0;
	game->mob_count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'M')
				game->mob_count++;
			x++;
		}
		y++;
	}
}

void	mob_handle(t_g *game, int x, int y)
{
	if (game->mob_count == 1)
	{
		char_touch_mob(game, x, y);
		make_mob_move(game);
	}
}