#include "fdf.h"

static int	max_t(float x, float y)
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

static void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	create_line(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->matrix[(int)y][(int)x];
	z1 = data->matrix[(int)y1][(int)x1];
//	--------------zoom------------
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	//---------------color------------
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	//----------------3d------------------
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	//--------------shift--------------
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = max_t(module(x_step), module(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
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
				create_line(x, y, x + 1, y, data);
			if (y < data->height - 1)
				create_line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
