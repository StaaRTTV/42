/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:11:51 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/09 15:22:43 by gpochon          ###   ########.fr       */
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
void	ft_print_moves(t_game *game)
{
	char	*text;
	text = ft_itoa(game->moves);
	if (!text)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "moves :");
	mlx_string_put(game->mlx, game->win, 40, 10, 0x00FFFFFF, text);
}
static void	move_character(t_game *game, int x, int y)
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
	else if (game->map[game->y_player + y][game->x_player + x] == 'E' && game->collectibles == 0)
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		ft_putstr_fd("TIA GAGNE LE SANNNGGGG\n", 1);
		close_game(game);
	}
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
	else if (keycode == W || keycode == 65362)
	{
		move_character(game, 0, -1);
		change_sprite(game, sprite_up);
	}
	else if (keycode == A || keycode == 65361)
	{
		move_character(game, -1, 0);
		change_sprite(game, sprite_left);
	}
	else if (keycode == S || keycode == 65364)
	{
		move_character(game, 0, 1);
		change_sprite(game, sprite_down);
	}
	else if (keycode == D || keycode == 65363)
	{
		move_character(game, 1, 0);
		change_sprite(game, sprite_right);
	}
	render_map(game);
	ft_print_moves(game);
	return (0);
}
