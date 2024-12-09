/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:58:04 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/09 11:06:56 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    size_of_map(t_game *game)
{
    while (game->map[game->height])
        game->height++;
    game->width = (ft_strlen(game->map[0]) - 1);
}

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
    size_of_map(&game);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, TILE_SIZE * game.width, TILE_SIZE * game.height, "Map Renderer");
    load_sprites(&game);
    render_map(&game);
    map_validator(&game);
    init_player_position(&game);
    mlx_hook(game.win, 2, 1L << 0, handle_movement, &game);
    mlx_loop(game.mlx);
    return (0);
}
