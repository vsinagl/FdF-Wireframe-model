#include "../includes/fdf.h"

int	get_matrix_width(char *line)
{
	int	count;

	count = 0;
	while(1)
	{
		count++;
		while(ft_isdigit(*line))
		{
			line++;
		}
		while(*line == ' ')
			line++;
		if (*line == '\n' || *line == '\0')
			break;
	}
	return(count);
}

void	print_matrix(t_map2	*map, char member)
{
	int	x;
	int	y;

	y = 0;
	while(y < map->n_lines)
	{
		x = 0;
		while(x < map->n_cols)
		{
			if (member == 'x')
				printf("%i, ",map->matrix[y * map->n_cols + x].x);
			if (member == 'y')
				printf("%i, ",map->matrix[y * map->n_cols + x].y);
			if (member == 'z')
				printf("%i, ",map->matrix[y * map->n_cols + x].z);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
