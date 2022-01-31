#include "fdf.h"

void	set_color(t_dot *matrix, char *z)
{
	matrix->z = ft_atoi(z);
	if (matrix->z <= -9)
		matrix->color = 0xe5c9ff;
	if (matrix->z > -9)
		matrix->color = 0xc9d2ff;
	if (matrix->z > -7)
		matrix->color = 0xc9e9ff;
	if (matrix->z > -5)
		matrix->color = 0xc9f8ff;
	if (matrix->z > -3)
		matrix->color = 0xc9ffe0;
	if (matrix->z > -1)
		matrix->color = 0xdbffc9;
	if (matrix->z == 0)
		matrix->color = 0xe80c0c;
	if (matrix->z > 1)
		matrix->color = 0xfff9c9;
	if (matrix->z > 3)
		matrix->color = 0xffe2b0;
	if (matrix->z > 5)
		matrix->color = 0xffd4b0;
	if (matrix->z > 7)
		matrix->color = 0xffbdb0;
	if (matrix->z > 9)
		matrix->color = 0xffb0b0;
}

int	hex_to_dec(char *hex, long long decimal)
{
	long long	base;
	int			i;

	base = 1;
	i = ft_strlen(hex);
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base *= 16;
		}
		i--;
	}
	return (decimal);
}

void	isometric(t_dot *start, t_dot *end, int z, int z1)
{
	start->x = (start->x - start->y) * cos(1.0);
	start->y = (start->x + start->y) * sin(1.2) - z;
	end->x = (end->x - end->y) * cos(1.0);
	end->y = (end->x + end->y) * sin(1.2) - z1;
}

void	get_zoom(t_dot *a, t_dot *b, t_fdf *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	a->z *= (data->zoom / 10);
	b->x *= data->zoom;
	b->y *= data->zoom;
	b->z *= (data->zoom / 10);
}

void	get_shift(t_dot *start, t_dot *end, t_fdf *data)
{
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
}