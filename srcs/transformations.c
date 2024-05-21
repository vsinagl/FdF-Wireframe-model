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
		matrix[i].x = map->matrix[i].x - map->matrix[i].y + x_offset;
		matrix[i].y = map->matrix[i].x * 0.5 + map->matrix[i].y * 0.5 - (map->matrix[i].z * (map->sidelen/sqrt(2))) + y_offset;
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

t_point	*projection_45_3D(t_map2 *map, int x_offset, int y_offset)
{
	int			i;
	int			matrix_len;
	t_point		*matrix;
	float		angle;

	matrix_len = map->n_cols * map->n_lines;
	matrix = (t_point*)malloc(sizeof(t_point) * matrix_len);
	i = 0;
	angle = 45;
	while (i < matrix_len)
	{
		matrix[i].x = (map->matrix[i].x + x_offset) * cos(deg_to_rad(angle)) - (map->matrix[i].y + y_offset) * sin(deg_to_rad(angle));
		matrix[i].y = (map->matrix[i].y + y_offset) * cos(deg_to_rad(angle)) + (map->matrix[i].x + x_offset) * sin(deg_to_rad(angle)) - map->matrix[i].z * (map->sidelen/sqrt(2));
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
			matrix[y * map->n_cols + x].x = map->matrix[y * map->n_cols + x].x + x_offset;
			matrix[y * map->n_cols + x].y = map->matrix[y * map->n_cols + x].y + y_offset;
			matrix[y * map->n_cols + x].color = map->matrix[y * map->n_cols + x].color;
			x++;
		}
		y++;
	}
	return (matrix);
}
	

