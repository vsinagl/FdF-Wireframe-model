#ifndef FDF_H
# define FDF_H

# include "../get_next_line/get_next_line_bonus.h"
# include "../mlx_linux/mlx.h"
# include "defines.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <X11/keysym.h>

//old structures, delete this please :)

//mlx_functions
void	*create_img(void* mlx);
t_map2	*create_map(int fd, char **argv);
int		close_program(int keycode, t_metadata *vars);
//graphic functions
void	my_mlx_pixel_put(t_imgdata *data, int x, int y, int color);
void	putline_dda(t_imgdata *data, t_point a, t_point b, int color);
void	putline_bresemhans(t_imgdata *data, t_point a, t_point b, int color);
void	create_menu(t_metadata *meta);
//projection functions
t_point	*just_xy(t_map2 *map, int x_offset, int y_offset);
void	draw_mesh(t_map2 *map, t_point *matrix, t_imgdata *data);
t_point	*rotate_by_angle(t_map2 *map, int x_offset, int y_offset, float angle);
t_point	*izo_base(t_map2 *map, t_point *matrix);
t_point	*izometric(t_map2 *map, int x_offset, int y_offset);
t_point	*izometric3D(t_map2 *map, int x_offset, int y_offset);
t_point	*projection_3D(t_map2 *map, int x_offset, int y_offset, float angle);
void	rotate_map(t_map2 *map, int ax, int ay, int az);
t_map2	*rotate_by_angle2(t_metadata *meta, float angle);
// utils functions
int	get_matrix_width(char *line);
void	print_matrix(t_map2	*map, char member);
int	put_err_fd(char *s, int fd);
void	my_aterror(t_metadata *meta);
int	put_color(t_color color);

#endif
