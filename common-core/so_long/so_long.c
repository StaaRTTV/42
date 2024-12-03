/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:58:04 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/03 14:55:23 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		map_width;
	int		map_height;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map_file>\n", 2);
		return (EXIT_FAILURE);
	}
	game.map = load_map(argv[1]);
	if (game.map == NULL)
	{
		ft_putstr_fd("Error: Could not load map\n", 2);
		return (EXIT_FAILURE);
	}
	map_width = 0;
	map_height = 0;
	while (game.map[0][map_width])
		map_width++;
	while (game.map[map_height])
		map_height++;
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		ft_putstr_fd("Error: Could not initialize mlx\n", 2);
		free_map(game.map);
		return (EXIT_FAILURE);
	}
	game.win = mlx_new_window(game.mlx, map_width * 128, map_height * 128, "so_long");
	if (game.win == NULL)
	{
		ft_putstr_fd("Error: Could not create window\n", 2);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		free_map(game.map);
		return (EXIT_FAILURE);
	}
	int img_width;
	int img_height;

	game.wall = mlx_xpm_file_to_image(game.mlx, "sprites/bush.xpm", &img_width, &img_height);
	if (game.wall == NULL)
	{
		ft_putstr_fd("Error: Could not load wall image\n", 2);
		mlx_destroy_window(game.mlx, game.win);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		free_map(game.map);
		return (EXIT_FAILURE);
	}
	mlx_hook(game.win, 17, 0, close_game, &game);
	game.collectible = mlx_xpm_file_to_image(game.mlx, "sprites/collectible.xpm", &img_width, &img_height);
	if (game.collectible == NULL)
	{
		ft_putstr_fd("Error: Could not load collectible image\n", 2);
		mlx_destroy_image(game.mlx, game.wall);
		mlx_destroy_window(game.mlx, game.win);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		free_map(game.map);
		return (EXIT_FAILURE);
	}
	render_map(&game);
	mlx_hook(game.win, 17, 0, (int (*)(void *))close_game, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (EXIT_SUCCESS);
}