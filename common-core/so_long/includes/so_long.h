/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:43:25 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/09 11:06:32 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../includes/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h> 

# define TILE_SIZE 128
# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define sprite_still "sprites/character.xpm"
# define sprite_up "sprites/back_char.xpm"
# define sprite_down "sprites/character_walk.xpm"
# define sprite_left "sprites/left_char.xpm"
# define sprite_right "sprites/right_char.xpm"
# define sprite_wall "sprites/bush.xpm"
# define sprite_floor "sprites/grass.xpm"
# define sprite_collectible "sprites/collectible.xpm"
# define sprite_exit "sprites/portal.xpm"

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

int		handle_movement(int keycode, t_game *game);
int		close_game(t_game *game);
void	load_sprites(t_game *game);
void	render_map(t_game *game);
char	**load_map(const char *filename);
void	free_map(char **map);
void	map_validator(t_game *game);
void	size_of_map(t_game *game);
void	init_player_position(t_game *game);

#endif
