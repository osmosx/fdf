#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;

	(void)argc;
	data = malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FdF");
	printf("%d", data->height);
	return (0);
}
