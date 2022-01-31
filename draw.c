#include "fdf.h"

static int	max_t(int x, int y)
{
	float	max;

	if (x > y)
		max = x;
	else
		max = y;
	return (max);
}

static float	module(int i)
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
	isometric(&start, &end, start.z, end.z);
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

void	draw(t_fdf *data, t_dot **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				create_line(matrix[y][x], matrix[y][x + 1], data);
			if (y < data->height - 1)
				create_line(matrix[y][x], matrix[y + 1][x], data);
			if (y < data->height - 1 && x < data->width - 1)
				create_line(matrix[y][x], matrix[y + 1][x + 1], data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
