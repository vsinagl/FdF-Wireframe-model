#include "../includes/fdf.h"
#include <unistd.h>

int	window_init(t_metadata *meta)
{
	meta->mlx = mlx_init();
	if (meta->mlx == NULL)
	{
		my_free(meta);
		(put_err_fd(MLX_MLX, 2), exit(2));
	}
	meta->win = mlx_new_window(meta->mlx, WIDTH, HEIGHT, "Good grade plz :)");
	if (meta->win == NULL)
	{
		my_free(meta);
		(put_err_fd(MLX_WIN, 2), exit(2));
	}
	meta->img.img = create_img(meta->mlx);
	if (meta->img.img == NULL)
	{
		my_free(meta);
		mlx_destroy_window(meta->mlx, meta->win);
		(put_err_fd(MLX_IMG, 2), exit(2));
	}
	meta->img.addr = mlx_get_data_addr(meta->img.img,
								&meta->img.bits_per_pixel,
								&meta->img.line_length,
								&meta->img.endian);
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
	meta->map = create_map(fd, meta, argv);
	if (meta->map == NULL)
		(put_err_fd(ERR_MAP, 2), exit(1));
	meta->matrix_len = meta->map->n_cols * meta->map->n_lines;
	meta->p_matrix = (t_point*)malloc(sizeof(t_point) * meta->matrix_len);
	return(0);
}

/*
int	init_metadata(t_metadata *meta)
{
	create_menu(meta);
	//create_menu(meta, &meta->menu_img2, "misc/menu_dimetric.xpm");
	return(0);
}

void	create_menu(t_metadata *meta)
{
	meta->menu_izo = mlx_xpm_file_to_image(meta->mlx, "misc/menu_izo", &meta->picture_w, &meta->picture_h);
	if (meta->menu_izo == NULL)
		(put_err_fd(MLX_MENU, 2), exit(2));
	meta->menu_izo = mlx_xpm_file_to_image(meta->mlx, "misc/menu_izo", &meta->picture_w, &meta->picture_h);
}
*/


//hooking strategy:
/*
 * > map can be updated, so i will call update functions.
 * > > check that init function initialize all the needed structures and matrix. There will be one matrix containg 2D draw coordinates for basic view(e.g izometric, dimetric) and second one with updated values.
 * > > update function update the map-> matrix on based parametrs(angles,at first run  it will upate map based on default value in metadata.
 *			THIS FUNCTION SHOUDL BE THEN CALLED IN MLX_HOOK
 *	
	then the function for drawing is called also in mlx_hhok
 *
 * > after key pressed, the parametrs(angle, zoom, sidelen etc.) is updated, then map drawn (for angle) then matrix computed and then matrix drawn!.
 STEPS:
 3D coordinates transformation --> transform to 2D coordinates(create 2D view of 3D object) --> draw mesh on screen
 * >  free and clear actual image
 * > create new image
 * > draw image
 *

 *
 */
int	drawing(void *param)
{
	t_metadata *meta;

	meta = param;
	
	//printf("drawing f started\n");
	black_me_pls(meta);
	draw_mesh2(meta);
//	printf("mesh drawed\n");
	if (meta->projection == 1)
		mlx_put_image_to_window(meta->mlx, meta->win, meta->menu_izo, 50, 50);
	else if (meta->projection == 2)
		mlx_put_image_to_window(meta->mlx, meta->win, meta->menu_2, 50, 50);
	else if(meta->projection == 3)
		mlx_put_image_to_window(meta->mlx, meta->win, meta->menu_3, 50, 50);
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img.img, MENUWIDTH + 60, 0);
	if (meta == NULL)
		printf("what the hack\n");
	return(0);
}

//meta->projection 1: izometric
//meta->projection 2: parallel
//meta->projection 3: oblique
int	run_program(t_metadata *meta)
{
	izometric3D_2(meta->map, meta->p_matrix, meta->map->x_offset, meta->map->y_offset);
	mlx_hook(meta->win, 33, 1L << 17, &close_program, meta);
	mlx_key_hook(meta->win, &key_control, meta);
	mlx_loop_hook(meta->mlx, &drawing, meta);
	mlx_loop(meta->mlx);
	printf("session succesfully ended\n");
	mlx_destroy_display(meta->mlx);
	return(0);
}

int main(int argc, char **argv)
{
	t_metadata	meta;

	process_args(argc, argv, &meta);
	meta.projection = 1;
	meta.camera_angle = 0.45;
	window_init(&meta);
	create_menu(&meta);
	//handle_erros(err);
	run_program(&meta);
	return(0);
}
