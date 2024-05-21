#ifndef DEFINES_H
# define	DEFINES_H

# define COLORRED	0xc1272d;
# define SIDELEN	30;

//error messages
# define ERR_ARG	"Error: wrong number of arguments\n"
# define MLX_ADD	"Error : mlx_get_data_addr error\n"
# define ERR_OPEN	"Error : Error opening the file\n"
# define ERR_READ	"Error : Error reading the file\n"
# define MLX_MLX	"Error : mlx_connection\n"
# define MLX_WIN	"Error : mlx_new_window error\n"
# define MLX_IMG	"Error : mlx_new_image error\n"
# define ERR_MAL	"Error : malloc error\n"
# define ERR_MAP	"Error : map creation\n"

# define WIDTH		1920
# define HEIGHT		1080
# define MENUWIDTH	400

# define ESC		53
# define UP			126
# define DOWN		125
# define RIGHT		124
# define LEFT		123

typedef struct s_color{
	int r;
	int	g;
	int b;
	int ovalue;
}	t_color;

typedef struct s_point {
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct	s_imgdata {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imgdata;
	
typedef struct s_element {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_element;

typedef struct s_map2 {
	t_element	*matrix;
	int			n_lines;
	int			n_cols;
	int			sidelen;
} t_map2;

typedef struct	s_metadata {
	void		*mlx;
	void		*win;
	t_imgdata	img;
	t_map2		*map;
	t_point		*izo_matrix;
	void		*pic_42;
	int			picture_w;
	int			picture_h;
}				t_metadata;

typedef struct s_mappoint {
	int	x;
	int	y;
	int	z;
	int	color;
	struct s_mappoint	*next;
}	t_mappoint;

typedef struct s_diff{
	int	x;
	int	y;
}	t_diff;

#endif

