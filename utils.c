/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:26:22 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/01 13:26:26 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_dot *matrix, char *z)
{
	matrix->z = ft_atoi(z);
	if (matrix->z > -9)
		matrix->color = 0xCC0000;
	if (matrix->z > -7)
		matrix->color = 0x00FFFF;
	if (matrix->z > -5)
		matrix->color = 0xFF0000;
	if (matrix->z > -3)
		matrix->color = 0x00FF00;
	if (matrix->z > -1)
		matrix->color = 0x0000FF;
	if (matrix->z == 0)
		matrix->color = 0x00FF00;
	if (matrix->z > 1)
		matrix->color = 0x0000FF;
	if (matrix->z > 3)
		matrix->color = 0x00FF00;
	if (matrix->z > 5)
		matrix->color = 0xFF0000;
	if (matrix->z > 7)
		matrix->color = 0x00FFFF;
	if (matrix->z > 9)
		matrix->color = 0xCC0000;
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

void	isometric(t_dot *start, t_dot *end, t_fdf *data)
{
	start->x = (start->x - start->y) * cos(data->angle);
	start->y = (start->x + start->y) * sin(data->angle) - start->z;
	end->x = (end->x - end->y) * cos(data->angle);
	end->y = (end->x + end->y) * sin(data->angle) - end->z;
}

void	get_zoom(t_dot *a, t_dot *b, t_fdf *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	a->z *= (data->z_scale);
	b->x *= data->zoom;
	b->y *= data->zoom;
	b->z *= data->z_scale;
}

void	get_shift(t_dot *start, t_dot *end, t_fdf *data)
{
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
}
