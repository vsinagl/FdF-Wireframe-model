#include "../includes/fdf.h"

int	step_calculation(int dx, int dy)
{
	int	step;

	if (dx == 0 && dy == 0)
		step = 0;
	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	return(step);
}
 
void	putline_dda(t_imgdata *data, t_point a, t_point b, int color)
{
	int	dx;
	int	dy;
	int	step;
	double	x1;
	double	y1;
	int	i;

	dx = b.x - a.x;
	dy = b.y - a.y;
	i = 0;
	x1 = a.x;
	y1 = a.y;
	step = step_calculation(dx, dy);
	if (step == 0)
		my_mlx_pixel_put(data,x1, y1, color);
	while (i <= step)
	{
		my_mlx_pixel_put(data, round(x1), round(y1), color);
		x1 += ((double)dx / step);
		y1 += ((double)dy / step);
		i++;
	}
}
