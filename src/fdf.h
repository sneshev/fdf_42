#ifndef FDF_H
#define FDF_H

#include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
#include "utils/ft_printf/ft_printf.h"
#include "utils/gnl/get_next_line.h"
#include "structs.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>
#include <limits.h>

#define WIDTH 500
#define HEIGHT 500

// map
t_map	*get_map(char *file_name);
void	get_grid_data(t_map *map, int *grid_data);

// data
int		init_mlx_data(t_data *data);
void	mlx_event_handle(t_data *data);

// draw
void	draw_isometric_projection(t_data data);
void	draw_line(t_data data, t_point p1, t_point p2);
// void	draw_coordinate_line(t_data data, t_point p1, t_point p2);
void	put_image_pixel(t_data data, int x, int y, int color);


// utils
bool	is_space(char c);
bool	is_number(char *str);
bool	is_positive_int(char *str);
int		ft_error(char *str);



// freeing
void	free_arr(char **arr);
void	free_map(t_map **map);
void	free_points(t_point **points, int height);
void	free_data_exit(t_data *data);

// helpers
void	print_map(t_map *map);


#endif