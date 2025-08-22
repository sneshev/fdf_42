#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>
#include "../libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"


char **get_map(char *file_name);

// utils
bool	is_space(char c);
void	free_arr(char **arr);

// helpers
void	print_map(char **map);


#endif