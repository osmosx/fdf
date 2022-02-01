/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:25:11 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/01 13:25:20 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_init(t_fdf *data)
{
	data->zoom = 20;
	data->z_scale = 1;
	data->shift_y = 250;
	data->shift_x = 900;
	data->scr_x = WIDTH;
	data->scr_y = HEIGHT;
	data->angle = 0.8;
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		data = malloc(sizeof(t_fdf));
		if (!data)
			error("Memory not allocated");
		read_file(argv[1], data);
		first_init(data);
		init_img(data);
		draw(data, data->matrix);
		mlx_hook(data->win_ptr, 2, 0, key_hook, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	else
		error("Wrong number of arguments!");
	return (0);
}
