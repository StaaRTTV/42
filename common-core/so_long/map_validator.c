/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:35:31 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/06 21:48:52 by gpochon          ###   ########.fr       */
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

static void check_walls(char **map, int height, int width)
{
    int x;
    int y;

    x = 0;
    while (x < width)
    {
        if (map[0][x] != '1')
			exit(1);
        x++;
    }
    y = 1;
    while (y < height - 1)
    {
        if (map[y][0] != '1' || map[y][width - 1] != '1')
            exit(1);
        y++;
    }
    x = 0;
    while (x < width)
    {
        if (map[height - 1][x] != '1')
            exit(1);
        x++;
    }
}
static void	check_other(t_game *game, char to_check)
{
	int		x;
	int		y;
	int		check;

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
	if (check == 0 || check > 1)
	{
		ft_printf("probleme de %c mon garssssss\n", to_check);
		exit(1);
	}
}

static void	check_gem(t_game *game, char to_check)
{
	int		x;
	int		y;
	int		check;

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
	if (check == 0)
	{
		ft_printf("probleme de %c mon garssssss\n", to_check);
		exit(1);
	}
}

void	map_validator(t_game *game)
{
	map_check_letters(game);
	check_walls(game->map, game->height, game->width);
	check_other(game, 'P');
	check_other(game, 'E');
	check_gem(game, 'C');
}
