#include "../includes/fdf.h"
/*
void	matrix_xyvalues(t_map2 *map, int x, int y)
{
		map->matrix[y * map->n_cols + x].x = (float)x;
		map->matrix[y * map->n_cols + x].y = (float)y;
}
*/

void	fill_matrix(t_map2 *map, char *line,int y, int len)
{
	int			x;

	x = 0;
	while(x < len)
	{	
		map->matrix[y * map->n_cols + x].x = (float)(-map->n_cols / 2 + x);
		map->matrix[y * map->n_cols + x].y = (float)(-map->n_lines / 2 + y);
		if (*line == '0' && ft_toupper(*(line + 1)) == 'X')
		{
			map->matrix[y * len + x].color = get_color(line);
			while(ft_isalpha(*line) || ft_isdigit(*line))
				line++;
			while(*line == ' ')
				line++;
		}
		else
			map->matrix[y * len + x].color = DEFAULTCOLOR;
		map->matrix[y * len + x].z = (float)ft_atoi(line);
		while(ft_isdigit(*line) || *line == '+' || *line == '-')
			line++;
		while(*line == ' ' || *line == ',')
			line++;
		if (*line == '\n' || '\0')
			break;
		x++;
	}
}

void	map_default_values(t_map2 *map)
{
	int	sidelen;

	if (((WIDTH - MENUWIDTH) / map->n_cols) > (HEIGHT / map->n_lines))
		sidelen = ((WIDTH - MENUWIDTH) / map->n_cols);
	else
		sidelen = (HEIGHT / map->n_lines);
	if (sidelen > 5)
		map->sidelen = sidelen / 3;
	else
		map->sidelen = 5;
	//map->sidelen = DEFAULTSIDELEN;
	map->x_offset = ((WIDTH - MENUWIDTH) / 2);
	map->y_offset = (HEIGHT / 2);
	map->az = 0;
}

void	*map_init(char **argv)
{
	char	*line;
	int		fd;
	t_map2	*map;

	fd = open(argv[1],O_RDONLY);
	line = get_next_line(fd);
	printf("map init1\n");
	map = (t_map2*)malloc(sizeof(t_map2));
	if (line == NULL || *line == '\0' || map == NULL || get_matrix_width(line) < 0)
		return NULL;
	printf("map init2\n");
	map->n_cols = get_matrix_width(line);
	map->n_lines = 0;
	printf("map init3\n");
	while(line != NULL)
	{
		if (map->n_lines > 0 && map->n_cols != get_matrix_width(line))
		{
			printf("error on line: %i\n", map->n_lines);
			return (NULL);
		}
		line = get_next_line(fd);
		map->n_lines++;
	}
	close(fd);
	map->matrix = (t_element*)malloc(sizeof(t_element) * map->n_lines * map->n_cols);
	return map;
}

t_map2	*create_map(int fd, char **argv)
{
	t_map2	*map;
	char	*line;
	int		i;

	printf("map jedeme ?\n");
	map = map_init(argv);
	if (map == NULL)
	{
		//my_aterror;
		(put_err_fd(ERR_MAP, 2), exit(1));
	}
	printf("map init test:\nmap->n_lines = %i\t map->n_cols = %i\n",
			map->n_lines, map->n_cols);
	line = get_next_line(fd);
	i = 0;
	while(line != NULL)
	{
		fill_matrix(map, line, i, map->n_cols);
		line = get_next_line(fd);
		i++;
	}
	map_default_values(map);
	return(map);
}
