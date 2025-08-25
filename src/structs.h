#ifndef STRUCTS_H
# define STRUCTS_H

// make it coordinate[2] (X and Y)) and value (z)
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		*width;
	int		height;
}	t_map;

typedef struct s_img_info
{
	int		bpp;
	int		line_length;
	int		endian;
	char	*addr;
}	t_img_info;

typedef struct s_data
{
	t_map		*map;
	void		*mlx;
	void		*win;
	void		*img;
	t_img_info	*img_info;
}	t_data;

#endif