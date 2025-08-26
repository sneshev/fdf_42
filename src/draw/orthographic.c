#include "../fdf.h"
#include "colors.h"

#define MIN_Z 2
#define MAX_Z 3

// void	draw_vertical_lines(t_data data, int grid_data[4])
// {
// 	int	x;
// 	int hpp = data.map->height[PIXEL] / data.map->height[REAL];
// 	int	wpp = data.map->width[PIXEL] / data.map->width[REAL];

// }

// void	draw_horizontal_lines(t_data data, int grid_data[4])
// {
// 	(void)data;
// }

void	draw_front_view(t_data data)
{
	int	grid_data[4];
	int	start[2];
	int	end[2];
	
	get_grid_data(data, grid_data);
	ft_printf("x: %d, y: %d, min_z: %d, max_z: %d\n", 
		grid_data[X], grid_data[Y], grid_data[MIN_Z], grid_data[MAX_Z]);
	
	// draw_vertical_lines(data, grid_data);
	// draw_horizontal_lines(data, grid_data);
	start[X] = 10;
	start[Y] = 15;
	end[X] = 350;
	end[Y] = 350;
	int color[2] = {WHITE, WHITE};
	draw_coordinate_line(data, start, end, color);
	
}

void	draw_side_view(t_data data)
{
	(void)data;
}

void	draw_top_view(t_data data)
{
	(void)data;
}