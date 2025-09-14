#include "../fdf.h"
#include "colors.h"

#define MIN_Z 2
#define MAX_Z 3

static void	draw_vertical_lines(t_data data, t_map map, int color[2], int grid_data[4])
{
	float	step_x;
	float	step_y;
	int		col;
	int		j;
	int		cd[2];
	int		ncd[2];

	step_x = (float)map.width[PADDED] / (float)(map.width[REAL] - 1);
	step_y = (float)map.height[PADDED] / (float)(grid_data[MAX_Z] - grid_data[MIN_Z]);
	col = 0;
	while (col < map.width[REAL])
	{
		j = 0;
		while (j < map.height[REAL] - 1)
		{
			cd[X] = map.x[MIN] + col * step_x;
			cd[Y] = map.y[MAX] - (map.points[j][col].value - grid_data[MIN_Z]) * step_y;
			j++;
			ncd[X] = map.x[MIN] + col * step_x;
			ncd[Y] = map.y[MAX] - (map.points[j][col].value - grid_data[MIN_Z]) * step_y;
			draw_coordinate_line(data, cd, ncd, color);
		}
		col++;
	}
}

static void	draw_horizontal_lines(t_data data, t_map map, int color[2], int grid_data[4])
{
	float	step_x;
	float	step_y;
	int		i;
	int		row;
	int		cd[2];
	int		ncd[2];

	step_x = (float)map.width[PADDED] / (float)(map.width[REAL] - 1);
	step_y = (float)map.height[PADDED] / (float)(grid_data[MAX_Z] - grid_data[MIN_Z]);
	row = 0;
	while(row < map.height[REAL])
	{
		i = 0;
		while (i < map.width[REAL] - 1)
		{
			cd[X] = map.x[MIN] + i * step_x;
			cd[Y] = map.y[MAX] - (map.points[row][i].value - grid_data[MIN_Z]) * step_y;
			i++;
			ncd[X] = map.x[MIN] + i * step_x;
			ncd[Y] = map.y[MAX] - (map.points[row][i].value - grid_data[MIN_Z]) * step_y;
			draw_coordinate_line(data, cd, ncd, color);
		}
		row++;
	}
}

void	draw_front_view(t_data data, t_map map)
{
	int	grid_data[4];
	int color[2] = {GREEN, GREEN};
	
	get_grid_data(map, grid_data);
	draw_horizontal_lines(data, map, color, grid_data);
	draw_vertical_lines(data, map, color, grid_data);
	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
}

static void	copy_map_values(t_map map, t_map *new_map, t_side side)
{
	if (side == LEFT || side == RIGHT)
	{
		new_map->height[REAL] = map.width[REAL];
		new_map->width[REAL] = map.height[REAL];
	}
	else if (side == FRONT || side == BACK)
	{
		new_map->height[REAL] = map.height[REAL];
		new_map->width[REAL] = map.width[REAL];
	}
	new_map->height[1] = map.height[1];
	new_map->height[2] = map.height[2];
	new_map->width[1] = map.width[1];
	new_map->width[2] = map.width[2];
	new_map->x[0] = map.x[0];
	new_map->x[1] = map.x[1];
	new_map->y[0] = map.y[0];
	new_map->y[1] = map.y[1];
}

static t_point	**alloc_newmap(t_map *map)
{
	t_point	**points;
	int		width;
	int		height;
	int		i;

	height = map->height[REAL];
	width = map->width[REAL];
	points = (t_point **)malloc(height * sizeof(t_point *));
	if (!points)
		return (NULL);
	i = 0;
	while (i < height)
	{
		points[i] = (t_point *)malloc(width * sizeof(t_point));
		if (!points[i])
			return (free_points(points, i), NULL);
		i++;
	}
	return (points);
}

/*

	0 0 0 0 1 1 
	0 0 0 0 1 1 
	0 0 1 1 2 2 
	0 0 1 1 2 2 

*/

static void	replace_points(t_map map, t_map *newmap, t_side side) // pffffff good luck with this one
{
	int	i;
	int	j;
	int	height = map.height[REAL];
	int	width = map.width[REAL];
	
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (side == BACK)
				newmap->points[height - i - 1][width - j - 1] = map.points[i][j];
			if (side == LEFT)
				newmap->points[width - j - 1][i] = map.points[i][j];
			if (side == RIGHT)
				newmap->points[j][height - i - 1] = map.points[i][j];
			j++;	
		}
		i++;
	}
}

void	draw_ortho_view(t_data data, t_side side)
{
	t_map	map;
	t_map	new_map;

	map = *data.map;
	if (side == FRONT)
		draw_front_view(data, map);
	else
	{
		copy_map_values(map, &new_map, side);
		new_map.points = alloc_newmap(&new_map);	
		replace_points(map, &new_map, side);
		print_map(&new_map);
		draw_front_view(data, new_map);
		free_points(new_map.points, new_map.height[REAL]);
	}
}

// void	draw_top_view(t_data data)
// {
// 	(void)data;
// }