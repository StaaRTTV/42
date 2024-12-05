/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:35:31 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/05 16:27:11 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	map_check_letters(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '\n' && game->map[y][x] != '1' && game->map[y][x] != '0' && game->map[y][x] != 'C' && game->map[y][x] != 'E' && game->map[y][x] != 'P')
			{
				write(2, "LA BITE A AXEL\n", 15);
				ft_printf("Invalid character '%c' at line %d, column %d\n", game->map[y][x], y, x);
				exit(1);
			}
			x++;
		}
		y++;
	}
}
void	map_validator(t_game *game)
{
	map_check_letters(game);
}
