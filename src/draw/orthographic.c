#include "../fdf.h"
#include "colors.h"

#define MIN_Z 2
#define MAX_Z 3

void	draw_vertical_lines(t_data data, t_map map, int grid_data[4])
{
	float	step_x;
	float	step_y;
	int		col;
	int		j;
	int		cd[2];
	int		ncd[2];
	int		color[2] = {GREEN, GREEN};

	step_x = (float)map.width[PADDED] / (float)(map.width[REAL] - 1);
	step_y = (float)map.height[PADDED] / (float)(grid_data[MAX_Z] - grid_data[MIN_Z]);
	col = 0;
	while (col < map.width[REAL])
	{
		j = 0;
		while (j < map.height[REAL] - 1)
		{
			cd[X] = map.x[MIN] + col * step_x;
			cd[Y] = map.y[MAX] - map.points[j][col].value * step_y;
			j++;
			ncd[X] = map.x[MIN] + col * step_x;
			ncd[Y] = map.y[MAX] - map.points[j][col].value * step_y;
			draw_coordinate_line(data, cd, ncd, color);
		}
		col++;
	}
	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
}

void	draw_horizontal_lines(t_data data, t_map map, int grid_data[4])
{
	float	step_x;
	float	step_y;
	int		i;
	int		row;
	int		cd[2];
	int		ncd[2];
	int		color[2] = {GREEN, GREEN};

	step_x = (float)map.width[PADDED] / (float)(map.width[REAL] - 1);
	step_y = (float)map.height[PADDED] / (float)(grid_data[MAX_Z] - grid_data[MIN_Z]);
	row = 0;
	while(row < map.height[REAL])
	{
		i = 0;
		while (i < map.width[REAL] - 1)
		{
			cd[X] = map.x[MIN] + i * step_x;
			cd[Y] = map.y[MAX] - map.points[row][i].value * step_y;
			i++;
			ncd[X] = map.x[MIN] + i * step_x;
			ncd[Y] = map.y[MAX] - map.points[row][i].value * step_y;
			draw_coordinate_line(data, cd, ncd, color);
		}
		row++;
	}
	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
}

void	draw_front_view(t_data data)
{
	int	grid_data[4];
	// int color[2] = {WHITE, WHITE};
	
	get_grid_data(data, grid_data);
	// ft_printf("x: %d, y: %d, min_z: %d, max_z: %d\n", 
		// grid_data[X], grid_data[Y], grid_data[MIN_Z], grid_data[MAX_Z]);
	
	draw_horizontal_lines(data, *data.map, grid_data);
	draw_vertical_lines(data, *data.map, grid_data);
}

// void	draw_side_view(t_data data)
// {
// 	(void)data;
// }

// void	draw_top_view(t_data data)
// {
// 	(void)data;
// }