#include "fdf.h"

int	get_heigth(char *file)
{
	char	*line;
	int		fd;
	int		heigth;

	heigth = 0;
	fd = open(file, O_RDONLY, 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		heigth++;
		free(line);
	}
	free(line);
	close(fd);
	return (heigth);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;
	char	**arr;

	width = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	arr = ft_split(line, ' ');
	while (arr[width] && *arr[width] != '\n')
	{
		free(arr[width]);
		width++;
	}
	free(line);
	free(arr);
	close(fd);
	return (width);
}

void	fill_matrix(int *z, char *line)
{
	int		i;
	char	**nums;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	data->height = get_heigth(file_name);
	data->width = get_width(file_name);
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 2));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		fill_matrix(data->matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	// Кажется тут что-то течет...
}
