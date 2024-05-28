#include "../includes/fdf.h"

/*
void	create_menu(t_metadata *meta)
{
	t_color	menucolor;

	menucolor.r = 55;
	menucolor.g = 171;
	menucolor.b = 168;
	menucolor.ovalue = 80;
	//menu_banner(&(meta->img), menucolor);
	meta->pic_42 = mlx_xpm_file_to_image(meta->mlx, "misc/menu2.xpm", &meta->picture_w, &meta->picture_h);
	if (meta->pic_42 == NULL)
		(put_err_fd(MLX_MLX, 2), exit(2));
}
*/
void	black_me_pls(t_metadata *meta)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&meta->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	create_menu(t_metadata *meta)
{
	meta->menu_izo = mlx_xpm_file_to_image(meta->mlx, "misc/menu1.xpm", &meta->picture_w, &meta->picture_h);
	meta->menu_2 = mlx_xpm_file_to_image(meta->mlx, "misc/menu2.xpm", &meta->picture_w, &meta->picture_h);
	meta->menu_3 = mlx_xpm_file_to_image(meta->mlx, "misc/menu3.xpm", &meta->picture_w, &meta->picture_h);
	if (meta->menu_3 == NULL || meta->menu_2 == NULL || meta->menu_izo == NULL)
	{
		free(meta);
		(put_err_fd(MLX_MENU, 2), exit(2));
	}
}


void	*create_img(void* mlx)
{
	void	*img;

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	return(img);
}

void	my_mlx_pixel_put(t_imgdata *img, int x, int y, int color)
{
	int		offset;

	offset = 0;
	if (x >= WIDTH || x <= 0 || y <= 0 || y >= HEIGHT)
		return ;
	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->addr + offset)) = color;
}

void	my_mlx_pixel_put_gradient(t_imgdata *img, int x, int y, int color)
{
	int		offset;

	offset = 0;
	if (x >= WIDTH || x <= 0 || y <= 0 || y >= HEIGHT)
		return ;
	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->addr + offset)) = color;
}
