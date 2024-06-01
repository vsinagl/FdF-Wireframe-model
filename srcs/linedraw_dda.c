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

int interpolate_color(int color1, int color2, int steps, int i) 
{
    unsigned char	r;
    unsigned char	g;
    unsigned char	b;
    unsigned char	r1;
    unsigned char	g1;
    unsigned char	b1;
    unsigned char	r2;
    unsigned char	g2;
    unsigned char	b2;
	float			ratio;

    r1 = (color1 >> 16) & 0xFF;
    g1 = (color1 >> 8) & 0xFF;
    b1 = color1 & 0xFF;
    r2 = (color2 >> 16) & 0xFF;
    g2 = (color2 >> 8) & 0xFF;
    b2 = color2 & 0xFF;
    ratio = (float)i / (float)steps;
    r = (unsigned char)((1 - ratio) * r1 + ratio * r2);
    g = (unsigned char)((1 - ratio) * g1 + ratio * g2);
    b = (unsigned char)((1 - ratio) * b1 + ratio * b2);
    return ((r << 16) | (g << 8) | b);
}
 
void	putline_dda(t_imgdata *data, t_point a, t_point b)
{
	t_diff	diff;
	double	x1;
	double	y1;
	int		color;
	int		i;

	diff.x = b.x - a.x;
	diff.y = b.y - a.y;
	i = 0;
	x1 = a.x;
	y1 = a.y;
	diff.step = step_calculation(diff.x, diff.y);
	if (diff.step == 0)
		my_mlx_pixel_put(data,x1, y1, a.color);
	while (i <= diff.step)
	{
		color = interpolate_color(a.color, b.color, diff.step, i);
		my_mlx_pixel_put(data, round(x1), round(y1), color);
		x1 += ((double)diff.x / diff.step);
		y1 += ((double)diff.y / diff.step);
		i++;
	}
}
