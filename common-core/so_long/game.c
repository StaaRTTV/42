/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:37:50 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/04 09:22:38 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int close_game(t_game *game)
{
    int i = 0;

    while (game->map[i])
        free(game->map[i++]);
    free(game->map);
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}