#include "fdf.h"

void	first_init(t_fdf *data)
{
	data->zoom = 42;
	data->shift_y = 250;
	data->shift_x = 900;
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	(void)argc;
	data = malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fdf");
	first_init(data);
	draw(data);
	mlx_hook(data->win_ptr, 2, 0, key_hook, data);
	mlx_loop(data->mlx_ptr);
	free(data);
	return (0);
}
