#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"

# define WIDTH			1960.0
# define HEIGHT			1280.0

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf {
	int		width;
	int		height;
	int		**matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

void	read_file(char *file, t_fdf *data);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
#endif
