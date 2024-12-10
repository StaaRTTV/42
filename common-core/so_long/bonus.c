/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:22:46 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/10 15:28:01 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_print_moves(t_g *game)
{
	char	*text;

	text = ft_itoa(game->moves);
	if (!text)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "moves :");
	mlx_string_put(game->mlx, game->win, 40, 10, 0x00FFFFFF, text);
}

void	load_portal(t_g *game)
{
	int	img_width;
	int	img_height;

	img_height = game->tile_size;
	img_width = game->tile_size;
	game->exit[0] = mlx_xpm_file_to_image(game->mlx, SPRITE_EXIT, &img_width,
			&img_height);
	game->exit[1] = mlx_xpm_file_to_image(game->mlx, SPRITE_EXIT2, &img_width,
			&img_height);
	game->exit[2] = mlx_xpm_file_to_image(game->mlx, SPRITE_EXIT3, &img_width,
			&img_height);
	game->exit[3] = mlx_xpm_file_to_image(game->mlx, SPRITE_EXIT4, &img_width,
			&img_height);
	game->exit[4] = mlx_xpm_file_to_image(game->mlx, SPRITE_EXIT5, &img_width,
			&img_height);
	game->exit[5] = mlx_xpm_file_to_image(game->mlx, SPRITE_EXIT6, &img_width,
			&img_height);
}

void	animate_portal(t_g *game, int x, int y)
{
	static int	frame = 0;
	static int	animation_step = 0;

	mlx_put_image_to_window(game->mlx, game->win, game->exit[animation_step], x,
		y);
	if (frame % 100 == 0)
	{
		animation_step++;
		if (animation_step == 6)
			animation_step = 0;
	}
	frame++;
}

void	load_gem(t_g *game)
{
	int	img_width;
	int	img_height;

	img_height = game->tile_size;
	img_width = game->tile_size;
	game->collectible[0] = mlx_xpm_file_to_image(game->mlx, SPRITE_COLLECTIBLE,
			&img_width, &img_height);
	game->collectible[1] = mlx_xpm_file_to_image(game->mlx, SPRITE_COLLECTIBLE2,
			&img_width, &img_height);
	game->collectible[2] = mlx_xpm_file_to_image(game->mlx, SPRITE_COLLECTIBLE3,
			&img_width, &img_height);
	game->collectible[3] = mlx_xpm_file_to_image(game->mlx, SPRITE_COLLECTIBLE4,
			&img_width, &img_height);
	game->collectible[4] = mlx_xpm_file_to_image(game->mlx, SPRITE_COLLECTIBLE5,
			&img_width, &img_height);
	game->collectible[5] = mlx_xpm_file_to_image(game->mlx, SPRITE_COLLECTIBLE6,
			&img_width, &img_height);
}

void	animate_gem(t_g *game, int x, int y)
{
	static int	frame = 0;
	static int	animation_step = 0;

	mlx_put_image_to_window(game->mlx, game->win,
		game->collectible[animation_step], x, y);
	if (frame % 800 == 0)
	{
		animation_step++;
		if (animation_step == 6)
			animation_step = 0;
	}
	frame++;
}
