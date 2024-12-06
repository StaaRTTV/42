/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:11:51 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/06 21:19:47 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_up(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				if (game->map[y - 1][x] == '0')
				{
					game->map[y][x] = '0';
					game->map[y - 1][x] = 'P';
				}
				else if (game->map[y - 1][x] == 'C')
				{
					game->map[y][x] = '0';
					game->map[y - 1][x] = 'P';
					game->collectible--;
				}
				else if (game->map[y - 1][x] == 'E' && game->collectible == 0)
				{
					game->map[y][x] = '0';
					game->map[y - 1][x] = 'P';
					ft_putstr_fd("You won!\n", 1);
					exit(EXIT_SUCCESS);
				}
			}
			x++;
		}
		y++;
	}
}