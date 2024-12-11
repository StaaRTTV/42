/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:11:51 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/11 13:42:45 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	change_sprite(t_g *game, char *sprite)
{
	int	img_width;
	int	img_height;

	mlx_destroy_image(game->mlx, game->chr);
	game->chr = mlx_xpm_file_to_image(game->mlx, sprite, &img_width,
			&img_height);
	if (game->chr == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void	move_character(t_g *game, int x, int y)
{
	if (game->map[game->y_player + y][game->x_player + x] == '0')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		game->y_player += y;
		game->x_player += x;
		game->moves++;
	}
	else if (game->map[game->y_player + y][game->x_player + x] == 'C')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		game->y_player += y;
		game->x_player += x;
		game->collectibles--;
		game->moves++;
	}
	else if (game->map[game->y_player + y][game->x_player + x] == 'E'
		&& game->collectibles == 0)
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		ft_putstr_fd("TIA GAGNE LE SANNNGGGG\n", 1);
		close_game(game);
	}
}

void	init_player_position(t_g *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->x_player = x;
				game->y_player = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	handle_movement(int keycode, t_g *game)
{
	if (keycode == ESCAPE)
		close_game(game);
	else if (keycode == W || keycode == 65362)
	{
		move_character(game, 0, -1);
		change_sprite(game, SPRITE_UP);
	}
	else if (keycode == A || keycode == 65361)
	{
		move_character(game, -1, 0);
		change_sprite(game, SPRITE_LEFT);
	}
	else if (keycode == S || keycode == 65364)
	{
		move_character(game, 0, 1);
		change_sprite(game, SPRITE_DOWN);
	}
	else if (keycode == D || keycode == 65363)
	{
		move_character(game, 1, 0);
		change_sprite(game, SPRITE_RIGHT);
	}
	return (0);
}
