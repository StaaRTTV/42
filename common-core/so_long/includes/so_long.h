/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:43:25 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/19 16:29:54 by gpochon          ###   ########.fr       */
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
# include <stdlib.h>

# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define SPRITE_STILL "sprites/character.xpm"
# define SPRITE_UP "sprites/back_char.xpm"
# define SPRITE_DOWN "sprites/character_walk.xpm"
# define SPRITE_LEFT "sprites/left_char.xpm"
# define SPRITE_RIGHT "sprites/right_char.xpm"
# define SPRITE_WALL "sprites/bush.xpm"
# define SPRITE_FLOOR "sprites/grass.xpm"
# define SPRITE_MOB "sprites/solglissant.xpm"

# define SPRITE_EXIT "sprites/frame1.xpm"
# define SPRITE_EXIT2 "sprites/frame2.xpm"
# define SPRITE_EXIT3 "sprites/frame3.xpm"
# define SPRITE_EXIT4 "sprites/frame4.xpm"
# define SPRITE_EXIT5 "sprites/frame5.xpm"
# define SPRITE_EXIT6 "sprites/frame6.xpm"

# define SPRITE_COLLECTIBLE "sprites/gem1.xpm"
# define SPRITE_COLLECTIBLE2 "sprites/gem2.xpm"
# define SPRITE_COLLECTIBLE3 "sprites/gem3.xpm"
# define SPRITE_COLLECTIBLE4 "sprites/gem4.xpm"
# define SPRITE_COLLECTIBLE5 "sprites/gem5.xpm"
# define SPRITE_COLLECTIBLE6 "sprites/gem6.xpm"

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
	void	*mob;
	void	*exit[6];
	void	*chr;
	int		x_player;
	int		y_player;
	int		moves;
	int		mob_x;
	int		mob_y;
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
void		mob_randomizer(t_g *game, int mob_x, int mob_y);
int			close_game(t_g *game);
void		render_map(t_g *game);
char		**load_map(const char *filename, t_g *game);
void		free_map(char **map);
void		init_mob_position(t_g *game);
void		map_validator(t_g *game);
void		move_mob(t_g *game);
void		init_player_position(t_g *game);
void		free_textures(t_g *game);
void		size_of(t_g *game);
void		put_img(t_g *game, void *img, int x, int y);
void		if_touch_mob(t_g *game, int x, int y);

#endif
