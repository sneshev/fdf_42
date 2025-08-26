#ifndef STRUCTS_H
# define STRUCTS_H

#define X 0
#define Y 1

typedef struct s_point
{
	int	coordinate[2];
	int	value;
	int	color;
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

#endif