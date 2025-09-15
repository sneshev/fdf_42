#include "../../fdf.h"
#include "../../colors/colors.h"
#include "../drawing.h"

#define MIN_Z 2
#define MAX_Z 3

t_point	**alloc_newmap(t_map *map);
void	replace_points(t_map map, t_map *newmap, t_side side);

// make data and map pointers bro..
static void	draw_vertical_lines(t_data data, t_map map, unsigned int color[2], int grid_data[4])
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
			color[0] = map.points[j][col].color;
			j++;
			ncd[X] = map.x[MIN] + col * step_x;
			ncd[Y] = map.y[MAX] - (map.points[j][col].value - grid_data[MIN_Z]) * step_y;
			color[1] = map.points[j][col].color;
			draw_coordinate_line(data, cd, ncd, color);
		}
		col++;
	}
}

// make data and map pointers bro..
static void	draw_horizontal_lines(t_data data, t_map map, unsigned int color[2], int grid_data[4])
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
			color[0] = map.points[row][i].color;
			i++;
			ncd[X] = map.x[MIN] + i * step_x;
			ncd[Y] = map.y[MAX] - (map.points[row][i].value - grid_data[MIN_Z]) * step_y;
			color[1] = map.points[row][i].color;
			draw_coordinate_line(data, cd, ncd, color);
		}
		row++;
	}
}

// make data and map pointers bro..
void	draw_front_view(t_data data, t_map map)
{
	int	grid_data[4];
	unsigned int color[2];
	
	get_grid_data(map, grid_data);
	draw_horizontal_lines(data, map, color, grid_data);
	draw_vertical_lines(data, map, color, grid_data);
	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
}

void	draw_side_view(t_data data, t_side side)
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
