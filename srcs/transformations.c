#include "../includes/fdf.h"
#include <math.h>

typedef struct s_matrix
{
	t_point	matrix;
}	p_matrix;

float	deg_to_rad(float deg)
{
	return (deg * M_PI)/180.0;
}

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

t_point	*izometric3D(t_map2 *map, int x_offset, int y_offset)
{
	int			i;
	int			matrix_len;
	t_point		*matrix;

	matrix_len = map->n_cols * map->n_lines;
	matrix = (t_point*)malloc(sizeof(t_point) * matrix_len);
	i = 0;
	while (i < matrix_len)
	{
		matrix[i].x = map->matrix[i].x * map->sidelen - map->matrix[i].y * map->sidelen + x_offset;
		matrix[i].y = map->matrix[i].x * 0.5 * map->sidelen + map->matrix[i].y * 0.5 * map->sidelen - (map->matrix[i].z * (map->sidelen/sqrt(2))) + y_offset;
		matrix[i].color = map->matrix[i].color;
		i++;
	}
	printf("projection matrix created\n");
	return (matrix);
}

t_point	*izometric(t_map2 *map, int x_offset, int y_offset)
{
	int			i;
	int			matrix_len;
	t_point		*matrix;

	matrix_len = map->n_cols * map->n_lines;
	matrix = (t_point*)malloc(sizeof(t_point) * matrix_len);
	i = 0;
	while (i < matrix_len)
	{
		matrix[i].x = (map->matrix[i].x) - (map->matrix[i].y) + x_offset;
		matrix[i].y = map->matrix[i].x * 0.5 + map->matrix[i].y * 0.5 + y_offset;
		matrix[i].color = map->matrix[i].color;
		i++;
	}
	printf("matrix created\n");
	return (matrix);
}

/*
t_point	*rotate_by_angle(t_map2 *map, int x_offset, int y_offset, float angle)
{
	int			i;
	int			matrix_len;
	t_point		*matrix;

	matrix_len = map->n_cols * map->n_lines;
	matrix = (t_point*)malloc(sizeof(t_point) * matrix_len);
	i = 0;
	while (i < matrix_len)
	{
		matrix[i].x = (map->matrix[i].x + x_offset) * cos(deg_to_rad(angle)) - (map->matrix[i].y + y_offset) * sin(deg_to_rad(angle));
		matrix[i].y = (map->matrix[i].y + y_offset) * cos(deg_to_rad(angle)) + (map->matrix[i].x + x_offset) * sin(deg_to_rad(angle));
		matrix[i].color = map->matrix[i].color;
		i++;
	}
	printf("matrix created\n");
	return (matrix);
}
*/

/*
- old function, not working properly and definitly is not an right izometric view, should delete it later but still keeping for inspiration or some other tries on functions projections
*/

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
		matrix[i].x = (map->matrix[i].x) * cos(deg_to_rad(angle)) - (map->matrix[i].y) * sin(deg_to_rad(angle)) + x_offset;
		matrix[i].y = (map->matrix[i].y) * cos(deg_to_rad(angle)) + (map->matrix[i].x) * sin(deg_to_rad(angle)) - map->matrix[i].z * (map->sidelen/sqrt(2)) + y_offset;
		matrix[i].color = map->matrix[i].color;
		i++;
	}
	return (matrix);
}

void	rotate_matrix(int *x, int *y, float angle)
{
	int	x_tmp;
	int	y_tmp;

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
	matrix_len = map->n_lines * map->n_lines;
	while (i < matrix_len)
	{
		rotate_matrix(&map->matrix[i].x, &map->matrix[i].y, az);
		rotate_matrix(&map->matrix[i].y, &map->matrix[i].z, ax);
		rotate_matrix(&map->matrix[i].x, &map->matrix[i].z, ay);
		i++;
	}
}

/*
t_point	*rotation_projection(t_map2 *map, int x_offset, int y_offset)
{
	int		i;
	int		matrix_len;
	t_point	*matrix;

	matrix_len = map->n_cols * map->n_lines;
	matrix = (t_point*)malloc(sizeof(t_point)*matrix_len);	
	//algorthimg here :)
	return(matrix);
}
*/

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
			matrix[y * map->n_cols + x].x = map->matrix[y * map->n_cols + x].x + x_offset;
			matrix[y * map->n_cols + x].y = map->matrix[y * map->n_cols + x].y + y_offset;
			matrix[y * map->n_cols + x].color = map->matrix[y * map->n_cols + x].color;
			x++;
		}
		y++;
	}
	return (matrix);
}
	

