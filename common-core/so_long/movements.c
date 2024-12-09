/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:11:51 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/09 11:07:23 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	change_sprite(t_game *game, char *sprite)
{
	int		img_width;
	int		img_height;

	game->character = mlx_xpm_file_to_image(game->mlx, sprite, &img_width, &img_height);
	if (game->character == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}
static void	move_character(t_game *game, int x, int y)
{
	if (game->map[game->y_player + y][game->x_player + x] == '0')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		game->y_player += y;
		game->x_player += x;
	}
	else if (game->map[game->y_player + y][game->x_player + x] == 'C')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		game->y_player += y;
		game->x_player += x;
	}
	else if (game->map[game->y_player + y][game->x_player + x] == 'E' && game->collectible == 0)
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		ft_putstr_fd("You won!\n", 1);
		exit(EXIT_SUCCESS);
	}
	render_map(game);
}
void	init_player_position(t_game *game)
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
				game->y_player= y;
				return;
			}
			x++;
		}
		y++;
	}
}

int	handle_movement(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
		close_game(game);
	else if (keycode == W)
	{
		move_character(game, 0, -1);
		change_sprite(game, sprite_up);
	}
	else if (keycode == A)
	{
		move_character(game, -1, 0);
		change_sprite(game, sprite_left);
	}
	else if (keycode == S)
	{
		move_character(game, 0, 1);
		change_sprite(game, sprite_down);
	}
	else if (keycode == D)
	{
		move_character(game, 1, 0);
		change_sprite(game, sprite_right);
	}
	render_map(game);
	return (0);
}
