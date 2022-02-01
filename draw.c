/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:21:13 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/01 13:22:39 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	max_t(float x, float y)
{
	float	max;

	if (x > y)
		max = x;
	else
		max = y;
	return (max);
}

static float	module(float i)
{
	if (i < 0)
		i = -i;
	return (i);
}

void	create_line(t_dot start, t_dot end, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	get_zoom(&start, &end, data);
	isometric(&start, &end, data);
	get_shift(&start, &end, data);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max = max_t(module(x_step), module(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if ((int)start.x < data->scr_x && (int)start.y < data->scr_y
			&& (int)start.x >= 0 && (int)start.y >= 0)
			my_mlx_pixel_put(data, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
}

void	print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, 0x88F403, "How to Use");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Move: <-/->");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Zoom: +/-");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Rotate: 0/9");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Z_Scale: 8/7");
}

void	draw(t_fdf *data, t_dot **matrix)
{
	int	x;
	int	y;

	y = 0;
	ft_bzero(data->addr, data->scr_y * data->scr_x * \
													(data->bits_per_pixel / 8));
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				create_line(matrix[y][x], matrix[y][x + 1], data);
			if (y < data->height - 1)
				create_line(matrix[y][x], matrix[y + 1][x], data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	print_menu(data);
}
