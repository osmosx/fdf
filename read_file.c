/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:26:03 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/01 13:26:05 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_heigth(char *file)
{
	char	*line;
	int		fd;
	int		heigth;

	heigth = 0;
	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		error("File read error!");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		heigth++;
	}
	close(fd);
	return (heigth);
}

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;
	char	**arr;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("File read error!");
	width = 0;
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		arr = ft_split(line, ' ');
		while (arr[width])
			width++;
		free(line);
		ft_free(arr);
	}
	close(fd);
	return (width);
}

void	mem_alloc(t_fdf *data)
{
	int		i;

	data->matrix = (t_dot **)malloc(sizeof(t_dot *) * (data->height + 1));
	if (data->matrix == NULL)
		error("Memory not allocated");
	i = 0;
	while (i <= data->height)
	{
		data->matrix[i] = (t_dot *)malloc(sizeof(t_dot) * (data->width + 1));
		if (data->matrix[i] == NULL)
			error("Memory not allocated");
		i++;
	}
}

void	fill_matrix(t_dot *matrix, char *line, int y)
{
	int			x;
	long long	i;
	char		**dots;
	char		**color;

	dots = ft_split(line, ' ');
	x = 0;
	i = 0;
	while (dots[x])
	{
		if (ft_strlen(dots[x]) < 5)
			set_color(&matrix[x], dots[x]);
		else
		{
			color = ft_split(dots[x], ',');
			matrix[x].z = ft_atoi(color[0]);
			matrix[x].color = hex_to_dec(color[1], i);
			ft_free(color);
		}
		matrix[x].y = y;
		matrix[x].x = x;
		x++;
	}
	ft_free(dots);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	int		y;
	int		fd;
	char	*line;

	data->height = get_heigth(file_name);
	data->width = get_width(file_name);
	mem_alloc(data);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error("File read error!");
	i = 0;
	y = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->matrix[i++], line, y++);
		free(line);
	}
	close(fd);
}
