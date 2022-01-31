#include "fdf.h"

int	move(int key, t_fdf *data)
{
	if (key == UP)
		data->shift_y -= 20;
	if (key == DOWN)
		data->shift_y += 20;
	if (key == LEFT)
		data->shift_x -= 20;
	if (key == RIGHT)
		data->shift_x += 20;
	return (0);
}

int	zoom(int key, t_fdf *data)
{
	if (key == ZOOM_UP)
		data->zoom += 5;
	if (key == ZOOM_DOWN)
		data->zoom -= 5;
	return (0);
}

int	key_hook(int key, t_fdf *data)
{
	printf("%d\n", key);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(key, data);
	if (key == ZOOM_UP || key == ZOOM_DOWN)
		zoom(key, data);
	if (key == ESC)
		exit(0);
//	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->addr, data->scr_y * data->scr_x *
						(data->bits_per_pixel / 8));
	draw(data, data->matrix);

	return (0);
}

