#include "fdf.h"
#include "mlx_linux/mlx.h"
#include <math.h>
#include <X11/keysym.h>

void	create_square(t_data *data, int x, int y, int length, int color)
{
	int	end_x;
	int	end_y;
	int	start_y;

	end_x = x + length;
	end_y = y + length;
	start_y = y;
	while(x < end_x)
	{
		y = start_y;
		while(y < end_y)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

void	hratky(t_data *data, t_point a, t_point b, int thkns, int color)
{
	for (int i = 0; i < thkns; i++)
	{
		a.y++;
		b.y++;
		putline_bresemhans(data, a, b, color);
	}
}

void	test_draw1(t_data *data, void (*drawline)(t_data*, t_point, t_point, int), t_point origin, int r, int color)
{
	t_point	a;

	for (int i = 0; i <= 360; i++)
	{
		a.y = origin.y - r * sin(i);
		a.x = origin.x + r * cos(i);
		drawline(data, origin, a, color);
	}
}

int weird_function(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 'q')
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		//POZOR !! je treba mit sturkturu data, kde budou vsechny metadata vcetne vars a img.
		//protoze pokud tady ukoncim process, stale budu mit alokovany img.!!!
		//valgrind erros 3:)
		exit(0);
	}
	else
		printf("you press %c key\n", keycode);
	return (0);
}

int	main()
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return(1);
	vars.win = mlx_new_window(vars.mlx, 800, 800, "Necum na me ty kokos!");
	if (vars.win == NULL)
		return (1);
	//mlx_hook(vars.win,2, 1l<<0, close, &vars);

	img.img = create_img(vars.mlx);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//create_square(&img, 100, 100, 100, 0xFF0000);
	/*
	t_point a;
	t_point b;
	a.x = 1;
	a.y = 1;
	b.x = 300;
	b.y = 300;
	t_point c;
	c.x = 360;
	c.y = 0;
	t_point d;
	d.x = 720;
	d.y = 0;
	putline_bresemhans(&img, a, b, 0xFF00FF);
	//putline_dda(&img, a, b, 0xFF0000);
	putline_bresemhans(&img, b, c, 0xFF00FF);
	putline_bresemhans(&img, c, a, 0xFF00FF);
	putline_bresemhans(&img, c, d, 0x00FFFF);
	putline_dda(&img, b, c, 0xFF0000);
	putline_bresemhans(&img, d, b, 0xFF00FF);
*/
	int colortest = weird_function(210, 74, 74);
	printf("result of color test: %i\n", colortest);
	t_point origin;
	origin.x = 210;
	origin.y = 400;
	test_draw1(&img, &putline_dda, origin,  200, colortest);
	t_point origin2;
	origin2.x = 620;
	origin2.y = 400;
	test_draw1(&img, &putline_bresemhans, origin2,  200, 0xBB88AA);
	//hratky(&img, c, a, 2, 0xFFAF08);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
	printf("session succesfully ended\n");
	return(0);
}
