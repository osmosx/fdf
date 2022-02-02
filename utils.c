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

void	isometric(t_dot *start, t_dot *end, t_fdf *data)
{
	start->x = (start->x - start->y) * cos(data->angle_cos);
	start->y = (start->x + start->y) * sin(data->angle_sin) - start->z;
	end->x = (end->x - end->y) * cos(data->angle_cos);
	end->y = (end->x + end->y) * sin(data->angle_sin) - end->z;
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

void	set_color(t_dot *matrix, char *z)
{
	matrix->z = ft_atoi(z);
	if (matrix->z > -9)
		matrix->color = 0x00FF00;
	if (matrix->z > -7)
		matrix->color = 0xCAFFCA;
	if (matrix->z > -5)
		matrix->color = 0xACFFAC;
	if (matrix->z > -3)
		matrix->color = 0x97FF97;
	if (matrix->z > -1)
		matrix->color = 0x5CFF5C;
	if (matrix->z == 0)
		matrix->color = 0x00CC00;
	if (matrix->z > 1)
		matrix->color = 0x00A300;
	if (matrix->z > 3)
		matrix->color = 0x008200;
	if (matrix->z > 5)
		matrix->color = 0x006800;
	if (matrix->z > 7)
		matrix->color = 0xA30000;
	if (matrix->z > 9)
		matrix->color = 0xCC0000;
}
