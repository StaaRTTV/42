/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:13:05 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/04 10:24:34 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

size_t	count_lines(const char *filename)
{
	int		fd;
	size_t	line_count = 0;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		free(line);
	}
	close(fd);
	return (line_count);
}

char	**load_map(const char *filename)
{
	int		fd;
	char	*line;
	char	**map;
	size_t	line_count;
	int		i;

	line_count = count_lines(filename);
	if (line_count == 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		if (map[i] == NULL)
		{
			free_map(map);
			close(fd);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	load_sprites(t_game *game)
{
	int		img_width;
	int		img_height;
	
	game->wall = mlx_xpm_file_to_image(game->mlx, "bush.xpm", &img_width, &img_height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "grass.xpm", &img_width, &img_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "collectible.xpm", &img_width, &img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "portal.xpm", &img_width, &img_height);
	game->character = mlx_xpm_file_to_image(game->mlx, "character.xpm", &img_width, &img_height);

	if (game->wall == NULL || game->floor == NULL || game->collectible == NULL || game->exit == NULL || game->character == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][y] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 128, y * 128);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, x * 128, y * 128);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible, x * 128, y * 128);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 128, y * 128);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->character, x * 128, y * 128);
			x++;
		}
		y++;
	}
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
