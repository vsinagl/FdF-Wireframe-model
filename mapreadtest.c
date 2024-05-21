
#include "includes/fdf.h"
//budu cist mapu radek po radku
//pri prvnim cteni urcim pocet bodu v mape
//	pokud nebude pocet bodu na radku odpovidat poctu pri prvnim cteni --> Error

// body ulozim, budu trackovat souradnice
// kdyz eof, vratim nactenou mapu

//LIBFT FUNCTIONS!!
int	ft_isdigit(char str)
{
	if (str < '0' || str > '9')
		return (0);
	return (1);
}
// END OF THE LIBFT FUNCTIONS!!

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
		if (*line == ' ')
			line++;
		else if (*line == '\n' || *line == '\0')
			break;
		else
			return (-1);
	}
	return(count);
}

void	matrix_xyvalues(t_map2 *map, int x, int y)
{
	if (x == 0 || map->sidelen == 0)
		map->matrix[y * map->n_cols + x].x = x;
	else
		map->matrix[y * map->n_cols + x].x = x + x*(map->sidelen - 1);
	if (y == 0 || map->sidelen == 0)
		map->matrix[y * map->n_cols + x].y = y;
	else
		map->matrix[y * map->n_cols + x].y = y + y*(map->sidelen - 1);
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
		if(*line == ' ')
			line++;
		else if (*line == '\n' || '\0')
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
			return (NULL);
		line = get_next_line(fd);
		map->n_lines++;
	}
	map->matrix = (t_element*)malloc(sizeof(t_element) * map->n_lines * map->n_cols);
	map->sidelen = 50;
	close(fd);
	return map;
}

t_map2	*create_map2(int fd, char **argv)
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


/* OLD VERSION
-in this version i create linked list of all points
- for better navigation and performance I switch for generating 2d array of point(matrix). Indexing can be used for easily navigating in horizontal and vertical direction
*/

void	load_map(char *line, t_map *map)
{
	t_mappoint	*point;
	int			x;
	static int	y;

	printf("load_map f started\n");
	if (line == NULL)
		return ;
	if (*line == '\n' || '\0')
				return ;
	x = 0;
	while(1)
	{	
		point = (t_mappoint*)malloc(sizeof(t_mappoint));
		if (point == NULL)
			return; //zde asi nejaka funkce pro error handling
		point->x = x++;
		point->y = y;
		point->z = atoi(line);
		point->color = COLORRED;
		point->next = NULL;
		if (map->start == NULL)
		{
			map->start = point;
			map->end = point;
		}
		else
		{
			map->end->next = point;
			map->end = map->end->next;
		}
		while(ft_isdigit(*line))
			line++;
		if(*line == ' ')
			line++;
		else if (*line == '\n' || '\0')
			break;
	}
	map->n_lines = y + 1;
	y++;
}

t_map	*create_map(int fd)
{
	char	*line;
	int		point_number;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	line = get_next_line(fd);
	point_number = get_matrix_width(line);
	if (point_number <= 0)
		return(NULL); //Error
	while(line != NULL)
	{
		if (point_number != get_matrix_width(line))
		{
			//problem pokud je newlajna na konci fajlu, spadne to do erroru
			printf("Error\n");
			return(NULL);
		}
		load_map(line, map);
		map->n_rows = point_number;
		line = get_next_line(fd);
	}
	return(map);
}

void	print_map(t_map *map)
{
	t_mappoint	*map_i;

	printf("\nMAP READED_____\n");
	printf("map.n_lines: %i\tmap.n_rows: %i\n",map->n_lines, map->n_rows);
	map_i = map->start;
	printf("map elements: \n");
	while(map_i != NULL)
	{
		printf("x:%i\ty:%i\tz:%i\n", map_i->x, map_i->y, map_i->z);
		map_i = map_i->next;
	}
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

int	run_program(t_map2 *map)
{
	t_metadata	vars;
	t_imgdata	img;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return(1);
	vars.win = mlx_new_window(vars.mlx, 800, 800, "Necum na me ty kokos!");
	if (vars.win == NULL)
		return (1);
	img.img = create_img(vars.mlx);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	//sandbox:
	//t_point	*matrix  = rotate_by_angle(map, 300, 10, 30);	
	//t_point	*matrix2  = izometric(map, 400, 0);	
	//t_point	*matrix3  = izometric3D(map, 400, 0);	
	t_point	*matrix4  = projection_45_3D(map, 400, 0);	
	//draw_mesh(map, matrix, &img);
	draw_mesh(map, matrix4, &img);

	
	//window put, hook and looping
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
	printf("session succesfully ended\n");
	return(0);
}

int main(int argc, char **argv)
{
	int	fd;
	t_map2 *map;

	if (argc != 2)
	{
		printf("wrong argument input. Fdf program takes only one argument, which is name of the map\nPlease, run program like this:\n\t./fdf <name_of_the_map>.fdf\n");
		return (1);	
	}
	fd = open(argv[1],O_RDONLY);
	if (fd < 0)
	{
		printf("file: %s can't be read\n", argv[1]);
		return(1);
	}
	map = create_map2(fd, argv);
	if (map == NULL)
	{
		printf("Error in map reading\n");
		return(1);
	}
	printf("map created\n");
	print_matrix(map, 'x');
	print_matrix(map, 'y');
	print_matrix(map, 'z');
	run_program(map);
	return(0);
}

