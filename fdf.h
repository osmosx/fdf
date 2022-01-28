#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"

# define WIDTH			1920
# define HEIGHT			1080

# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ESC			53
# define ZOOM_UP		24
# define ZOOM_DOWN		27

typedef struct s_dot
{
	float	x;
	float	y;
	int		alt;
	int		color;
}	t_dot;

typedef struct s_fdf {
	int		width;
	int		height;
	int		**matrix;
	t_dot	**points;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fdf;

void	read_file(char *file, t_fdf *data);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	create_line(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);
int		key_hook(int key, t_fdf *data);
void	ft_free(char **arr);
#endif
