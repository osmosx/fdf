#include "fdf.h"



void	first_init(t_fdf *data)
{
	data->zoom = 42;
	data->shift_y = 250;
	data->shift_x = 900;
	data->scr_x = WIDTH;
	data->scr_y = HEIGHT;
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	(void)argc;
	data = malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	first_init(data);
	init_img(data);
	draw(data, data->matrix);
	mlx_hook(data->win_ptr, 2, 0, key_hook, data);
	mlx_loop(data->mlx_ptr);
	free(data);
	return (0);
}
