#include "../includes/fdf.h"
#include <string.h>

void	print_point_matrix(t_map2	*map,t_point *matrix, char member)
{
	int	x;
	int	y;

	y = 0;
	if (member != 'x' && member != 'y')
	{
		printf("wrong coordinate\n");
		return ;
	}
	while(y < map->n_lines)
	{
		x = 0;
		while(x < map->n_cols)
		{
			if (member == 'x')
				printf("%i, ",matrix[y * map->n_cols + x].x);
			if (member == 'y')
				printf("%i, ",matrix[y * map->n_cols + x].y);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
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
				printf("%f, ",map->matrix[y * map->n_cols + x].x);
			if (member == 'y')
				printf("%f, ",map->matrix[y * map->n_cols + x].y);
			if (member == 'z')
				printf("%f, ",map->matrix[y * map->n_cols + x].z);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

//TOTO NAD PUJDE DO JINEHO HRNICKU

int	get_matrix_width(char *line)
{
	int	count;

	count = 0;
	while(1)
	{
//		if (*line != ' ' && *line != ',' && *line != '\n' && *line != '\0' && !ft_isdigit(*line))
//			return(-1);
		while(*line == ' ' || *line == '-' || *line == '+')
			line++;
		//printf("line point %c\t", *line);
		if (ft_isdigit(*line))
			count++;
		while(ft_isdigit(*line))
			line++;
		if (*line == ',')
		{
			line++;
			while(ft_isalpha(*line) || ft_isdigit(*line))
				line++;
			while(*line == ' ')
				line++;
		}
		if (*line == '\n' || *line == '\0')
			break;
		//if (!ft_isdigit(*line) && *line != '+' && *line != '-')
			//return(-1);
	}
	return(count);
}


int	get_color(char *line)
{
	char str_dup[11];
	int	i;

	i = 0;
	while(line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
	{
		if (i > 8)
			break;
		str_dup[i] = ft_toupper(line[i]);
		i++;
		//printf("get_color, i: %i\n", i);
	}
	str_dup[i] = '\0';
	int number = (ft_atoi_base("0123456789ABCDEF", &str_dup[2])); // << 8 | 0xFF);
	return(number);
}
