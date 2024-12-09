/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:58:04 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/09 15:14:57 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    size_of(t_game *game)
{
    while (game->map[game->height])
        game->height++;
    game->width = (ft_strlen(game->map[0]) - 1);
    if (game->width < 15 || game->height < 8)
        game->tile_size = 128;
    else if (game->width < 30 || game->height < 16)
        game->tile_size = 64;
    else if (game->width < 60 || game->height < 33)
        game->tile_size = 32;
    else
        game->tile_size = 24;
}
int main(int argc, char **argv)
{
    t_game game;

    game.moves = 0;
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
    size_of(&game);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.tile_size * game.width, game.tile_size * game.height, "SO FUCKING LONG");
    load_sprites(&game);
    render_map(&game);
    map_validator(&game);
    count_collectibles(&game);
    init_player_position(&game);
    mlx_hook(game.win, 2, 1L << 0, handle_movement, &game);
    mlx_loop(game.mlx);
    return (0);
}
