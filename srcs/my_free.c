
#include "../includes/fdf.h"

void	clear_matrix(t_metadata *meta)
{
	free(meta->p_matrix);
	meta->p_matrix = NULL;
}

void	clear_map(t_metadata *meta)
{

	if (meta->map->matrix != NULL)
		free(meta->map->matrix);
	meta->map->matrix = NULL;
	free(meta->map);
	meta->map = NULL;
}

void	my_free(t_metadata *meta)
{
	printf("free function activated\n");
	if (meta->img.img != NULL)
	{
		mlx_destroy_image(meta->mlx, meta->img.img);
		meta->img.img = NULL;
	}
	if (meta->menu_izo != NULL)
	{
		mlx_destroy_image(meta->mlx, meta->menu_izo);
		meta->menu_izo = NULL;
		printf("menu izo cleared\n");
	}
	if (meta->menu_2 != NULL)
	{
		mlx_destroy_image(meta->mlx, meta->menu_2);
		meta->menu_2 = NULL;
		printf("menu 2 cleared\n");
	}
	if (meta->menu_3 != NULL)
	{
		mlx_destroy_image(meta->mlx, meta->menu_3);
		meta->menu_3 = NULL;
		printf("menu 3 cleared\n");
	}
	if (meta->p_matrix != NULL)
		clear_matrix(meta);
	if (meta->map != NULL)
		clear_map(meta);
	mlx_clear_window(meta->mlx, meta->win);
	mlx_destroy_window(meta->mlx, meta->win);
//	mlx_destroy_display(meta->mlx);
	printf("all sucesfully free\n");
	return;
}

