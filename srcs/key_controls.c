#include "../includes/fdf.h"
#include <ctype.h>

int	close_program(t_metadata *vars)
{
	my_free(vars);
	exit(0);
}

void	zoom(int keycode, t_metadata *meta)
{
	int zoom;

	printf("zoom keycode: %c\n", keycode);
	if (meta->map->sidelen < 10)
		zoom = 1;
	else if (meta->map->sidelen < 30)
		zoom = 3;
	else if (meta->map->sidelen < 70)
		zoom = 5;
	if (keycode == 'z' )
	{
		meta->map->sidelen += zoom;
		izometric3D_2(meta->map, meta->p_matrix, meta->map->x_offset, meta->map->y_offset); 
	}
	if (keycode == 'x')
	{
		meta->map->sidelen -= zoom;
		izometric3D_2(meta->map, meta->p_matrix, meta->map->x_offset, meta->map->y_offset); 
	}
}

int	key_control(int keycode , void *param)
{
	t_metadata *meta;
	int			move;
	int			rot;

	meta = param;
	move = DEF_MOVE;
	rot = DEF_ROT;
	printf("you press: %c\n", keycode);
	if (keycode == ESC)
		close_program(meta);
	else if (keycode == UP || tolower(keycode) == 'w')
		offset_matrix(meta, 0, -move);
	else if (keycode == DOWN || tolower(keycode) == 's')
		offset_matrix(meta, 0, move);
	else if (keycode == LEFT || tolower(keycode) == 'a')
		offset_matrix(meta, -move, 0);
	else if (keycode == RIGHT || tolower(keycode) == 'd')
		offset_matrix(meta, move, 0);
	else if (tolower(keycode) == 'q')
	{
		rotate_map(meta->map, 0, 0, rot);
		izometric3D_2(meta->map, meta->p_matrix, meta->map->x_offset, meta->map->y_offset); 
	}
	if (tolower(keycode) == 'e')
	{
		rotate_map(meta->map, 0, 0, -rot);
		izometric3D_2(meta->map, meta->p_matrix, meta->map->x_offset, meta->map->y_offset); 
	}
	else 
		zoom(keycode, meta);

	return(0);

}

