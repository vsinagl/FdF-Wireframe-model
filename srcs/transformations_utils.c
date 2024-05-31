#include "../includes/fdf.h"

float	deg_to_rad(float deg)
{
	return (deg * M_PI)/180.0;
}

void	rotate_matrix(float *x, float *y, float angle)
{
	float	x_tmp;
	float	y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = x_tmp * cos(deg_to_rad(angle)) - y_tmp * sin(deg_to_rad(angle));
	*y = x_tmp * sin(deg_to_rad(angle)) + y_tmp * cos(deg_to_rad(angle));
}

void	rotate_map(t_map2 *map, int ax, int ay, int az)
{
	int	i;
	int	matrix_len;

	i = 0;
	matrix_len = map->n_cols * map->n_lines;
	map->az += az;
	while (i < matrix_len)
	{
		rotate_matrix(&map->matrix[i].x, &map->matrix[i].y, az);
		rotate_matrix(&map->matrix[i].y, &map->matrix[i].z, ax);
		rotate_matrix(&map->matrix[i].x, &map->matrix[i].z, ay);
		i++;
	}
}

void	offset_matrix(t_metadata *meta, int x_offset, int y_offset)
{
	int	i;
	t_point	*matrix;

	i = 0;
	matrix = meta->p_matrix;
	meta->map->x_offset += x_offset;
	meta->map->y_offset += y_offset;
	while (i < meta->matrix_len)
	{
		matrix[i].x += x_offset;
		matrix[i].y += y_offset;
		i++;
	}
}
