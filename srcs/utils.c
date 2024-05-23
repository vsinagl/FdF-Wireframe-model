#include "../includes/fdf.h"

int	put_err_fd(char *s, int fd)
{
	int	i;

	if (s == NULL || fd < 0)
		return -1;
	i = 0;
	while(s[i] != '\0')
	{
		write(fd,&s[i], 1);
		i++;
	}
	return(i);
}

int	close_program(int keycode, t_metadata *vars)
{
	if (keycode == 'q')
	{
		mlx_destroy_window(vars->mlx, vars->win);
		//POZOR !! je treba mit sturkturu data, kde budou vsechny metadata vcetne vars a img.
		//protoze pokud tady ukoncim process, stale budu mit alokovany img.!!!
		//valgrind erros 3:)
	}
	else
		printf("you press %c key\n", keycode);
	return (0);
}

int put_color(t_color color)
{
    return ((color.ovalue & 0xFF) << 24) | ((color.r & 0xFF) << 16) | ((color.g & 0xFF) << 8) | (color.b & 0xFF);
}

int put_color_test(int r, int g, int b, int ovalue)
{
	return (ovalue << 24 | r << 16 | g << 8 | b);
}
