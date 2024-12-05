/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:43:25 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/05 12:35:02 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../includes/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define TILE_SIZE 128

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int 	width;
	int 	height;
	char	**map;
	void	*wall;
	void	*floor;
	void 	*collectible;
	void	*exit;
	void	*character;
	int		x_player;
	int		y_player;
}	t_game;

int		close_game(t_game *game);
void	load_sprites(t_game *game);
void	render_map(t_game *game);
char	**load_map(const char *filename);
void	free_map(char **map);
void	map_validator(t_game *game);
void	size_of_map(t_game *game);

#endif
