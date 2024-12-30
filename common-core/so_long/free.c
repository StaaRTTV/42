/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:05:14 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/30 15:35:13 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_mlx_resources(t_g *game)
{
	free_textures(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}

void	free_game(t_g *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	free_mlx_resources(game);
}

void	free_textures(t_g *game)
{
	if (!game || !game->mlx)
		return ;
	free_textures_2(game);
}

void	error_exit(t_g *game, char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}
