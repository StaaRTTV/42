/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:58:04 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/04 10:08:33 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        write(2, "Usage: ./map_renderer map_file\n", 31);
        return (1);
    }
    game.map = load_map(argv[1]);
    if (!game.map || !game.map[0])
    {
        write(2, "Error: Failed to load map\n", 26);
        return (1);
    }
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, TILE_SIZE * 14, TILE_SIZE * 5, "Map Renderer");
    game.wall = mlx_xpm_file_to_image(game.mlx, "sprites/bush.xpm", &(int){0}, &(int){0});
    game.floor = mlx_xpm_file_to_image(game.mlx, "sprites/grass.xpm", &(int){0}, &(int){0});
    game.character = mlx_xpm_file_to_image(game.mlx, "sprites/character.xpm", &(int){0}, &(int){0});
	game.collectible = mlx_xpm_file_to_image(game.mlx, "sprites/collectible.xpm", &(int){0}, &(int){0});
	game.exit = mlx_xpm_file_to_image(game.mlx, "sprites/portal.xpm", &(int){0}, &(int){0});
    render_map(&game);
    mlx_hook(game.win, 17, 0, (int (*)(void *))close_game, &game);
    mlx_loop(game.mlx);
    return (0);
}
