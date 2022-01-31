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
	int		z;
	int		color;
}	t_dot;

typedef struct s_fdf {
	int		width;
	int		height;
	t_dot	**matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
	int		scr_x;
	int		scr_y;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fdf;

void	read_file(char *file, t_fdf *data);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	create_line(t_dot start, t_dot end, t_fdf *data);
void	draw(t_fdf *data, t_dot **matrix);
int		key_hook(int key, t_fdf *data);
void	ft_free(char **arr);
void	ft_bzero(void *str, size_t n);
int		hex_to_dec(char *hex, long long decimal);
void	set_color(t_dot *matrix, char *z);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	init_img(t_fdf *data);
void	isometric(t_dot *start, t_dot *end, int z, int z1);
void	get_zoom(t_dot *a, t_dot *b, t_fdf *data);
void	get_shift(t_dot *start, t_dot *end, t_fdf *data);
#endif
