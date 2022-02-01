/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:23:57 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/01 13:24:47 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	move(int key, t_fdf *data)
{
	if (key == UP)
		data->shift_y -= 35;
	if (key == DOWN)
		data->shift_y += 35;
	if (key == LEFT)
		data->shift_x -= 35;
	if (key == RIGHT)
		data->shift_x += 35;
	return (0);
}

int	zoom(int key, t_fdf *data)
{
	if (key == ZOOM_UP)
		data->zoom += 5;
	if (key == ZOOM_DOWN)
		data->zoom -= 5;
	return (0);
}

int	angle(int key, t_fdf *data)
{
	if (key == 25)
		data->angle += 0.05;
	if (key == 29)
		data->angle -= 0.05;
	return (0);
}

int	key_hook(int key, t_fdf *data)
{
	printf("%d\n", key);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(key, data);
	if (key == ZOOM_UP || key == ZOOM_DOWN)
		zoom(key, data);
	if (key == ANGLE_DOWN || key == ANGLE_UP)
		angle(key, data);
	if (key == ESC)
		exit(0);
	draw(data, data->matrix);
	return (0);
}
