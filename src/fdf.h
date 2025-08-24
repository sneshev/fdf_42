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

typedef struct s_map
{
	int **map;
	int width;
	int height;
}	t_map;

t_map *get_map(char *file_name);

// utils
bool	is_space(char c);
void	free_arr(char **arr);
void	free_irr(int **arr, int height);
bool	is_number(char *str);
bool	is_positive_int(char *str);

// helpers
void	print_map(t_map *map);
void	free_map(t_map **map);

#endif