#include "../includes/fdf.h"
#include <math.h>

void	print_point(char *s, t_point *matrix, int index)
{
	int x;
	int y;
	
	x = matrix[index].x;
	y = matrix[index].y;
	printf("%s index: %i x: %i, y: %i\n",s, index, x, y);
	return;
}

void	draw_mesh(t_map2 *map, t_point *matrix, t_imgdata *data)
{
	int	x;
	int y;
	
	y = 0;
	while(y < map->n_lines)
	{
		x = 0;
		while(x < map->n_cols)
		{
			printf("x: %i, y: %i, color %i:\n",matrix[y * map->n_cols + x].x,matrix[y * map->n_cols + x].y,matrix[y * map->n_cols + x].color);
//			printf("index: %i\n", y * map->n_cols + x);
			print_point("pointer point:", matrix, y * map->n_cols + x);
			if (x < map->n_cols - 1)
			{

				putline_bresemhans(data,
					matrix[y * map->n_cols + x],
					matrix[y * map->n_cols + x + 1],
					matrix[y * map->n_cols + x].color);
				print_point("left point", matrix, y * map->n_cols + x + 1);
			}
			if (y < map->n_lines - 1)
			{
				putline_bresemhans(data,
					matrix[y * map->n_cols + x],
					matrix[(y+1) * map->n_cols + x],
					matrix[y * map->n_cols + x].color);
				print_point("right point:", matrix, (y+1) * map->n_cols + x);
			}
			x++;
		}
		y++;
	}
}	



