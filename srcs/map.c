#include "../includes/fdf.h"

void	matrix_xyvalues(t_map2 *map, int x, int y)
{
	if (x == 0 || map->sidelen == 0)
		map->matrix[y * map->n_cols + x].x = x;
	else
		map->matrix[y * map->n_cols + x].x = x; //x*(map->sidelen);
	if (y == 0 || map->sidelen == 0)
		map->matrix[y * map->n_cols + x].y = y;
	else
		map->matrix[y * map->n_cols + x].y = y; //y*(map->sidelen);
}

void	fill_matrix(t_map2 *map, char *line,int y, int len)
{
	int			x;

	x = 0;
	while(x < len)
	{	
		matrix_xyvalues(map, x, y);
		map->matrix[y * len + x].z = atoi(line);
		map->matrix[y * len + x].color = 0xFFFFFF;
		x++;
		while(ft_isdigit(*line))
			line++;
		while(*line == ' ')
			line++;
		if (*line == '\n' || '\0')
			break;
	}
}

void	*map_init(char **argv)
{
	char	*line;
	int		fd;
	t_map2	*map;

	fd = open(argv[1],O_RDONLY);
	line = get_next_line(fd);
	map = (t_map2*)malloc(sizeof(t_map2));
	if (line == NULL || *line == '\0' || map == NULL)
		return NULL;
	map->n_cols = get_matrix_width(line);
	map->n_lines = 0;
	while(line != NULL)
	{
		if (map->n_lines > 0 && map->n_cols != get_matrix_width(line))
		{
			//my_aterror --> freee everything and exit with put_err_fd
			return (NULL);
		}
		line = get_next_line(fd);
		map->n_lines++;
	}
	map->matrix = (t_element*)malloc(sizeof(t_element) * map->n_lines * map->n_cols);
	map->sidelen = SIDELEN;
	close(fd);
	return map;
}

t_map2	*create_map(int fd, char **argv)
{
	t_map2	*map;
	char	*line;
	int		i;

	map = map_init(argv);
	if (map == NULL)
		return(NULL);
	printf("map init test:\nmap->n_lines = %i\t map->n_cols = %i\n",
			map->n_lines, map->n_cols);
	line = get_next_line(fd);
	i = 0;
	while(line != NULL)
	{
		fill_matrix(map, line, i, map->n_cols);
		line = get_next_line(fd);
		;
		i++;
	}
	return(map);
}
