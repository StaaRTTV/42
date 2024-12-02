/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:58:04 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/02 16:02:58 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_rectangle(t_data *img, int x, int y, int height, int width, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "sprites/grass.xpm";
	int		img_width;
	int		img_height;
	int		win_width = 1792;
	int		win_height = 640;
	int		x;
	int		y;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (mlx == NULL)
		return (1);
	mlx_win = mlx_new_window(mlx, win_width, win_height, "Le jeu");
	if (mlx_win == NULL)
		return (1);

	y = 0;
	while (y < win_height)
	{
		x = 0;
		while (x < win_width)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x += img_width;
		}
		y += img_height;
	}

	mlx_loop(mlx);
	return (0);
}
