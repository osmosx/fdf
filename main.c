#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	data;
	int		i;

	(void)argc;
	(void) argv;
	i = 0x810202;
	printf("%d", mlx_get_color_value(data.mlx_ptr, i));
	return (0);
}

