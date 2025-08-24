#ifndef FDF_H
#define FDF_H

#include "../libft/libft.h"
#include "ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
#include "gnl/get_next_line.h"
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
t_map *get_map(char *file_name);

// data
int		init_data(t_data *data, t_map **map);


// utils
bool	is_space(char c);
bool	is_number(char *str);
bool	is_positive_int(char *str);
int		ft_error(char *str);

// helpers
void	print_map(t_map *map);

// freeing
void	free_arr(char **arr);
void	free_map(t_map **map);
void	free_points(t_point **points, int height);

#endif