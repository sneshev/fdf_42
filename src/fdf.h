#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>
#include <limits.h>
#include "../libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"

#define WIDTH 500
#define HEIGHT 500

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

t_map *get_map(char *file_name);

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