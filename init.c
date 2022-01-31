#include "fdf.h"

void	init_img(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->scr_x, \
															data->scr_y, "fdf");
	data->img = mlx_new_image(data->mlx_ptr, data->scr_x, data->scr_y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
										&data->line_length, &data->endian);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
