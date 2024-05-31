#include "../includes/fdf.h"
#include <math.h>

void	draw_mesh(t_metadata *meta)
{
	int	x;
	int y;
	
	y = 0;
	while(y < meta->map->n_lines)
	{
		x = 0;
		while(x < meta->map->n_cols)
		{
			if (x < meta->map->n_cols - 1)
				putline_bresemhans(&meta->img,
					meta->p_matrix[y * meta->map->n_cols + x],
					meta->p_matrix[y * meta->map->n_cols + x + 1],
					meta->p_matrix[y * meta->map->n_cols + x].color);
			if (y < meta->map->n_lines - 1)
				putline_bresemhans(&meta->img,
					meta->p_matrix[y * meta->map->n_cols + x],
					meta->p_matrix[(y+1) * meta->map->n_cols + x],
					meta->p_matrix[y * meta->map->n_cols + x].color);
			x++;
		}
		y++;
	}
}	
