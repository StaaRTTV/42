/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:11:51 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/30 15:36:46 by gpochon          ###   ########.fr       */
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
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	move_character(t_g *game, int x, int y)
{
	if (game->map[game->y_player + y][game->x_player + x] == '0')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		ft_count(game, x, y);
		game->moves++;
	}
	else if (game->map[game->y_player + y][game->x_player + x] == 'C')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		ft_count(game, x, y);
		game->collectibles--;
		game->moves++;
	}
	if (game->map[game->y_player + y][game->x_player + x] == 'E'
		&& game->collectibles == 0)
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		ft_putstr_fd("YOU WIN\nGAME MADE BY GPOCHON\nSPONSORED BY DELHAIZE\n",
			1);
		close_game(game);
	}
	mob_handle(game, x, y);
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

void	put_img(t_g *game, void *img, int x, int y)
{
	if (!img)
	{
		ft_exit("Error: Image not loaded correctly\n");
	}
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}
