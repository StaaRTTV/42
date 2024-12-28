/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_e.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:33:11 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/28 14:50:47 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dfs_e.c
 *
 * @brief Depth First Search algorithm
 * Contains the implementation of my Depth First Search algorithm
 * Necessary for the checking of the map (exit)
 *
 */

#include "includes/so_long.h"

static void	dfs_check_e(char **map, int x, int y, t_g *game)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
		game->exit_found = 1;
	map[y][x] = 'V';
	dfs_check_e(map, x + 1, y, game);
	dfs_check_e(map, x - 1, y, game);
	dfs_check_e(map, x, y + 1, game);
	dfs_check_e(map, x, y - 1, game);
}

static char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	if_not_accessible_e(t_g *game)
{
	if (!game->exit_found)
	{
		ft_printf("Error\n");
		ft_printf("The exit isn't acessible !\n");
		exit(1);
	}
}

int	verify_exit(t_g *game)
{
	int		x;
	int		y;
	char	**map_copy;

	game->exit_found = 0;
	map_copy = copy_map(game->map);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'P')
			{
				game->exit_found = 0;
				dfs_check_e(map_copy, x, y, game);
				break ;
			}
			x++;
		}
		y++;
	}
	free_map(map_copy);
	if_not_accessible_e(game);
	return (game->exit_found);
}
