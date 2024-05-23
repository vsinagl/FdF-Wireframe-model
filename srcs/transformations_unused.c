#include "../includes/fdf.h"

float	calculate_r(int x, int y, int x_offset, int y_offset, int option)
{
	int	x2;
	int	y2;

	x2 = (x - x_offset);
	y2 = (y + y_offset);
	if (option == 1)
		return(x2);
	if (option ==2)
		return(y2);
	return 0;
}

t_point	*izo_base(t_map2 *map, t_point *matrix)
{
	int			i;
	int			y;
	int			x;

	y = 0;
	while (y < map->n_lines)
	{
		x = 0;
		while (x < map->n_cols)
		{
			i = y * map->n_lines + x;
		//	printf("matrix[i].y = %i\t", matrix[i].y);
			matrix[i].y -= (map->sidelen / sqrt(2))* (y);
			//matrix[i].x -= (map->sidelen/2)* (y + 1);
		//	printf("matrix[i].y = %i\n", matrix[i].y);
			x++;
		}
		y++;
	}
	return matrix;
	
}

t_map2	*rotate_by_angle2(t_metadata *meta, float angle)
{
	int				i;
	int				matrix_len;
	t_element		*matrix;
	t_map2			*tmp_map;

	tmp_map = (t_map2*)malloc(sizeof(t_map2));
	tmp_map->n_cols = meta->map->n_cols;
	tmp_map->n_lines = meta->map->n_lines;
	tmp_map->sidelen = meta->map->sidelen;
	matrix_len = meta->map->n_cols * meta->map->n_lines;
	matrix = (t_element*)malloc(sizeof(t_element) * matrix_len);
	i = 0;
	printf("tmp_map initialized\n");
	while (i < matrix_len)
	{
		matrix[i].x = (meta->map->matrix[i].x) * cos(deg_to_rad(angle)) - (meta->map->matrix[i].y) * sin(deg_to_rad(angle));
		matrix[i].y = (meta->map->matrix[i].y) * cos(deg_to_rad(angle)) + (meta->map->matrix[i].x) * sin(deg_to_rad(angle));
		matrix[i].z = meta->map->matrix[i].z;
		matrix[i].color = meta->map->matrix[i].color;
		i++;
	}
	tmp_map->matrix = matrix;
	printf("matrix2 created\n");
	return(tmp_map);
}

t_point	*projection_3D(t_map2 *map, int x_offset, int y_offset, float angle)
{
	int			i;
	int			matrix_len;
	t_point		*matrix;

	matrix_len = map->n_cols * map->n_lines;
	matrix = (t_point*)malloc(sizeof(t_point) * matrix_len);
	i = 0;
	while (i < matrix_len)
	{
		matrix[i].x = (int)round((map->matrix[i].x) * cos(deg_to_rad(angle)) - (map->matrix[i].y) * sin(deg_to_rad(angle)) + x_offset);
		matrix[i].y = (int)round((map->matrix[i].y) * cos(deg_to_rad(angle)) + (map->matrix[i].x) * sin(deg_to_rad(angle)) - map->matrix[i].z * (map->sidelen/sqrt(2)) + y_offset);
		matrix[i].color = map->matrix[i].color;
		i++;
	}
	return (matrix);
}

t_point	*just_xy(t_map2 *map, int x_offset, int y_offset)
{
	int			x;
	int			y;
	t_point		*matrix;

	y = 0;
	matrix = (t_point*)malloc(sizeof(t_point) * map->n_lines * map->n_cols);
	while(y < map->n_lines)
	{
		x = 0;
		while(x < map->n_cols)
		{
			matrix[y * map->n_cols + x].x = map->matrix[y * map->n_cols + x].x * map->sidelen + x_offset;
			matrix[y * map->n_cols + x].y = map->matrix[y * map->n_cols + x].y * map->sidelen + y_offset;
			matrix[y * map->n_cols + x].color = map->matrix[y * map->n_cols + x].color;
			x++;
		}
		y++;
	}
	return (matrix);
}
