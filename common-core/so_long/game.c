/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:37:50 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/25 17:47:15 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	close_game(t_g *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	free_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	exit(0);
	return (0);
}

void	count_collectibles(t_g *game)
{
	int	x;
	int	y;

	y = 0;
	game->collectibles = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			x++;
		}
		y++;
	}
}

void	free_textures(t_g *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->chr);
	mlx_destroy_image(game->mlx, game->exit[0]);
	mlx_destroy_image(game->mlx, game->exit[1]);
	mlx_destroy_image(game->mlx, game->exit[2]);
	mlx_destroy_image(game->mlx, game->exit[3]);
	mlx_destroy_image(game->mlx, game->exit[4]);
	mlx_destroy_image(game->mlx, game->exit[5]);
	mlx_destroy_image(game->mlx, game->collectible[0]);
	mlx_destroy_image(game->mlx, game->collectible[1]);
	mlx_destroy_image(game->mlx, game->collectible[2]);
	mlx_destroy_image(game->mlx, game->collectible[3]);
	mlx_destroy_image(game->mlx, game->collectible[4]);
	mlx_destroy_image(game->mlx, game->collectible[5]);
	mlx_destroy_image(game->mlx, game->mob);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}
