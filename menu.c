/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:25:11 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/01 13:25:20 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	draw_background(t_fdf *data)
//{
//	int	*image;
//	int	i;
//
//	ft_bzero(data->addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
//	image = (int *)(data->addr);
//	i = 0;
//	while (i < HEIGHT * WIDTH)
//	{
//		if ((i % WIDTH) < 250)
//			image[i] = 0x2A5300;
//		else
//			image[i] = 0x000000;
//		i++;
//	}
//}

void	print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Move: <- / ->");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Zoom: + / -");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Scale: Q / W");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Rotate: 0/9");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "ISO ON/OFF: 1 / 2");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Reset: TAB");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Exit: ESC");
}
