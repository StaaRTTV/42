/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:58:04 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/18 13:23:29 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	update_game(t_g *game)
{
	render_map(game);
	ft_print_moves(game);
	return (0);
}

void	size_of(t_g *game)
{
	while (game->map[game->height])
		game->height++;
	game->width = (ft_strlen(game->map[0]) - 1);
	game->tile_size = 32;
}

int	main(int argc, char **argv)
{
	t_g	game;

	game.moves = 0;
	if (argc != 2)
		return (write(2, "Usage: ./map_renderer map_file\n", 31));
	game.map = load_map(argv[1], &game);
	if (!game.map || !game.map[0])
		return (write(2, "Error: Failed to load map\n", 26));
	game.mlx = mlx_init();
	load_sprites(&game);
	map_validator(&game);
	count_collectibles(&game);
	init_player_position(&game);
	game.win = mlx_new_window(game.mlx, game.tile_size * game.width,
			game.tile_size * game.height, "SO FUCKING LONG");
	mlx_hook(game.win, 17, 0L, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_movement, &game);
	mlx_loop_hook(game.mlx, *update_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
