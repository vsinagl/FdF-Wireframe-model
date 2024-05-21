
#include "../includes/fdf.h"

void	clear_matrix(t_point *p_matrix)
{
	t_point	*tmp;

	while(p_matrix != NULL)
	{
		tmp = p_matrix;
		p_matrix++;
		free(tmp);
	}
}

void	clear_map(t_metadata *meta)
{
	t_element	*tmp;
	t_element	*iterator;

	iterator = meta->map->matrix;
	while (iterator != NULL)
	{
		tmp = iterator;
		iterator++;
		free(tmp);
	}
	free(meta->map);
}

void	my_aterror(t_metadata *meta)
{
	if (meta->img.img != NULL)
		mlx_destroy_image(meta->mlx, meta->img.img);
	if (meta->izo_matrix != NULL)
		clear_matrix(meta->izo_matrix);
	if (meta->map != NULL)
		clear_map(meta);
	return;
}

