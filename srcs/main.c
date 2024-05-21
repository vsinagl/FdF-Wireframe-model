#include "../includes/fdf.h"

int	window_init(t_metadata *meta)
{
	meta->mlx = mlx_init();
	if (meta->mlx == NULL)
	{
		my_aterror(meta);
		(put_err_fd(MLX_MLX, 2), exit(2));
	}
	meta->win = mlx_new_window(meta->mlx, WIDTH, HEIGHT, "Good grade plz :)");
	if (meta->win == NULL)
	{
		my_aterror(meta);
		(put_err_fd(MLX_WIN, 2), exit(2));
	}
	meta->img.img = create_img(meta->mlx);
	if (meta->img.img == NULL)
	{
		my_aterror(meta);
		mlx_destroy_window(meta->mlx, meta->win);
		(put_err_fd(MLX_IMG, 2), exit(2));
	}
	meta->img.addr = mlx_get_data_addr(meta->img.img,
								&meta->img.bits_per_pixel,
								&meta->img.line_length,
								&meta->img.endian);
	printf("window initialized\n");
	return(0);
}

int	process_args(int argc, char **argv, t_metadata *meta)
{
	int	fd;

	if (argc != 2)
		(put_err_fd(ERR_ARG, 2), exit(1));
	fd = open(argv[1],O_RDONLY);
	if (fd < 0)
		(put_err_fd(ERR_READ, 2), exit(1));
	meta->map = create_map(fd, argv);
	if (meta->map == NULL)
		(put_err_fd(ERR_MAP, 2), exit(1));
	print_matrix(meta->map, 'x');
	print_matrix(meta->map, 'y');
	print_matrix(meta->map, 'z');
	return(0);
}

int	run_program(t_metadata *meta)
{
	meta->izo_matrix  = izometric3D(meta->map, (MENUWIDTH + 500), 500);	
	//t_point *matrix;
	//matrix = just_xy(meta->map, 500, 500);
	draw_mesh(meta->map, meta->izo_matrix, &(meta->img));
	create_menu(meta);
	//draw_mesh(meta->map, matrix, &(meta->img));
	//window put, hook and looping
	//mlx_put_image_to_window(meta->mlx, meta->win, meta->img.img, 0, 0);
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img.img, 0, 0);
	mlx_put_image_to_window(meta->mlx, meta->win, meta->pic_42, 0, 0);
	mlx_key_hook(meta->win, close_program, &meta);
	mlx_loop(meta->mlx);
	printf("session succesfully ended\n");
	return(0);
}

int main(int argc, char **argv)
{
	t_metadata	meta;

	process_args(argc, argv, &meta);
	window_init(&meta);
	//handle_erros(err);
	run_program(&meta);
	return(0);

}
