/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:43:25 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/16 11:44:39 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>

# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define SPRITE_STILL "sprites2/character.xpm"
# define SPRITE_UP "sprites2/back_char.xpm"
# define SPRITE_DOWN "sprites2/character_walk.xpm"
# define SPRITE_LEFT "sprites2/left_char.xpm"
# define SPRITE_RIGHT "sprites2/right_char.xpm"
# define SPRITE_WALL "sprites2/bush.xpm"
# define SPRITE_FLOOR "sprites2/grass.xpm"

# define SPRITE_EXIT "sprites2/frame1.xpm"
# define SPRITE_EXIT2 "sprites2/frame2.xpm"
# define SPRITE_EXIT3 "sprites2/frame3.xpm"
# define SPRITE_EXIT4 "sprites2/frame4.xpm"
# define SPRITE_EXIT5 "sprites2/frame5.xpm"
# define SPRITE_EXIT6 "sprites2/frame6.xpm"

# define SPRITE_COLLECTIBLE "sprites2/gem1.xpm"
# define SPRITE_COLLECTIBLE2 "sprites2/gem2.xpm"
# define SPRITE_COLLECTIBLE3 "sprites2/gem3.xpm"
# define SPRITE_COLLECTIBLE4 "sprites2/gem4.xpm"
# define SPRITE_COLLECTIBLE5 "sprites2/gem5.xpm"
# define SPRITE_COLLECTIBLE6 "sprites2/gem6.xpm"

typedef struct s_g
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		collectibles;
	char	**map;
	void	*wall;
	void	*floor;
	void	*collectible[6];
	void	*exit[6];
	void	*chr;
	int		x_player;
	int		y_player;
	int		moves;
	int		frame;
	int		tile_size;
	clock_t	last_time;

}			t_g;

void		animate_gem(t_g *game, int x, int y);
void		load_gem(t_g *game);
void		animate_portal(t_g *game, int x, int y);
void		load_portal(t_g *game);
void		ft_print_moves(t_g *game);
void		load_sprites(t_g *game);
void		count_collectibles(t_g *game);
int			handle_movement(int keycode, t_g *game);
int			close_game(t_g *game);
void		render_map(t_g *game);
char		**load_map(const char *filename, t_g *game);
void		free_map(char **map);
void		map_validator(t_g *game);
void		init_player_position(t_g *game);
void		free_textures(t_g *game);
void		size_of(t_g *game);
void		put_img(t_g *game, void *img, int x, int y);

#endif
