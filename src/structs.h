#ifndef STRUCTS_H
# define STRUCTS_H

# define X 0
# define Y 1

# define MIN 0
# define MAX 1

# define REAL 0
# define PIXEL 1
# define PADDED 2

# define HIGH 0
# define GROUND 1
# define LOW 2

typedef struct s_point
{
	int				coordinate[2];
	int				value;
	unsigned int	color;
}	t_point;

// 	maybe i dont need color[3] in map becuse every point is filled with a color
typedef struct s_map
{
	t_point			**points;
	unsigned int	color[3]; // high, ground, low
	int				width[3]; // real, pixel
	int				height[3]; // real, pixel
	int				x[2];
	int				y[2];
}	t_map;

typedef struct s_img_info
{
	int		bpp;
	int		line_length;
	int		endian;
	char	*addr;
}	t_img_info;

typedef struct s_mlxt
{
	void	*mlx;
	void	*win;
	void	*img;
	t_img_info	*img_info;
}	t_mlxt;

typedef struct s_data
{
	t_map		*map;
	t_mlxt		mlxt;
}	t_data;

typedef enum s_side
{
	FRONT,
	LEFT,
	BACK,
	RIGHT,
	TOP
}	t_side;

#endif