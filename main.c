#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	(void)argc;
	data = malloc(sizeof(t_fdf));
	read_file(argv[1], data);
//	data->mlx_ptr = mlx_init();
//	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FdF");
//	mlx_loop(data->mlx_ptr);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free(data);
	return (0);
}
