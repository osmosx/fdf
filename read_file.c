#include "fdf.h"

static int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

void	read_file(char *file, t_fdf *data)
{
	int		i;
	char	*line;

	line = NULL;
	data->height = get_height(file);
}

