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
		if (*line != ' ' && *line != ',' && *line != '\n' && *line != '\0')
			return(-1);
		while(*line == ' ' || *line == ',')
			line++;
		if (*line == '\n' || *line == '\0')
			break;
		printf("line point %c\t", *line);
		count++;
		if (*line == '0' && ft_toupper(*(line + 1)) == 'X')
		{
			printf("I'am here\n");
			while(ft_isalpha(*line) || ft_isdigit(*line))
				line++;
			while(*line == ' ')
				line++;
			printf("fuck you point %c\t", *line);
		}
		//if (!ft_isdigit(*line) && *line != '+' && *line != '-')
			//return(-1);
		printf("count: %i\n", count);
		while(ft_isdigit(*line) || *line == '+' || *line == '-')
			line++;
	}
	printf("final count: %i\n", count);
	return(count);
}


int	get_color(char *line)
{
	char str_dup[10];
	int	i;

	i = 0;
	printf("line = %s\n", line);
	while(line[i] != ' ')
	{
		if (i > 10)
			break;
		str_dup[i] = ft_toupper(line[i]);
		i++;
	}
	str_dup[i] = '\0';
	
	printf("str_dup = %s\n", &str_dup[2]);

	int number = (ft_atoi_base("0123456789ABCDEF", &str_dup[2])); // << 8 | 0xFF);
	printf("\n number is: %i\n", number);
	int red = (number >> 16) & 0xff; // Extracts the red component
    int green = (number >> 8) & 0xff; // Extracts the green component
    int blue = number & 0xff; // Extracts the blue component

    printf("Red: %d, Green: %d, Blue: %d\n", red, green, blue);
	return(number);
}
