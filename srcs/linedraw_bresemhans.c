#include "../includes/fdf.h"

void	draw_simple_line(t_imgdata *data, t_point a, t_point b, int color)
{
	int	step;

	step = 0;
	if ((b.x - a.x) == 0)
	{
		while(step < abs(b.y - a.y))
		{
			if ((b.y - a.y) > 0)
				my_mlx_pixel_put(data, a.x, a.y + step, color);
			else
				my_mlx_pixel_put(data, a.x, a.y - step, color);
			step++;
		}
	}
	else
	{
		while(step < abs(b.x - a.x))
		{
			if ((b.x - a.x) > 0)
				my_mlx_pixel_put(data, a.x + step, a.y, color);
			else
				my_mlx_pixel_put(data, a.x - step, a.y, color);
			step++;
		}
	}
}

void	drawline_under45(t_imgdata *data, t_point start, t_point end, int color)
{
	t_diff	diff;
	int			inc;
	int			po;
	int			x;
	int			y;

	diff.x = end.x - start.x;
	diff.y = end.y - start.y;
	x = start.x;
	y = start.y;
	if (diff.y > 0)
		inc = 1;
	else
		inc = -1;
	po = 2 * abs(diff.y) - diff.x;
	while (x <= end.x)
	{
		my_mlx_pixel_put(data, x++, y, color);
		if (po < 0)
			po = po + 2 * abs(diff.y);
		else
		{
			po = po + abs(2 * diff.y) - 2 * diff.x;
			y += inc;
		}
	}
}

void	drawline_above45(t_imgdata *data, t_point start, t_point end, int color)
{
	t_diff	diff;
	int		inc;
	int		po;
	int		x;
	int		y;
	int		step;

	diff.x = end.x - start.x;
	diff.y = end.y - start.y;
	x = start.x;
	y = start.y;
	if (diff.y > 0)
		inc = 1;
	else
		inc = -1;
	po = 2 * diff.x - abs(diff.y);
	step = abs(diff.y);
	while (step-- >= 0)
	{
		my_mlx_pixel_put(data, x, y, color);
		if (po < 0)
			po = po + 2 * diff.x;
		else
		{
			po = po - abs(2 * diff.y) + 2 * diff.x;
			x += 1;
		}
		y += inc;
	}            	
}                	
                 	
void	putline_bresemhans(t_imgdata *data, t_point a, t_point b, int color)
{
	int	dx;
	int	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dx == 0 && dy == 0)
		my_mlx_pixel_put(data,a.x, a.y, color);
	else if (dy == 0 || dx == 0)
		draw_simple_line(data, a, b, color);
	else
	{
		if (dx > 0)
		{
			if (abs(dx) >= abs(dy))
				drawline_under45(data, a, b, color);
			else
				drawline_above45(data, a, b, color);
		}
		else
		{
			if (abs(dx) >= abs(dy))
				drawline_under45(data, b, a, color);
			else
				drawline_above45(data, b, a, color);
		}
	} 
}
