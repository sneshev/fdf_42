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

void	draw_horizontal_lines(t_data data, int grid_data[4])
{
	(void)grid_data;
	t_map	*map;
	float	step_x;
	float	step_y;
	int		i;
	int		row;
	int		cd[2];
	int		ncd[2];
	int		color[2] = {GREEN, GREEN};

	map = data.map;
	step_x = (float)map->width[PADDED] / (float)map->width[REAL];
	step_y = (float)map->height[PADDED] / (float)map->height[REAL];
	row = 0;
	while(row < map->height[REAL])
	{
		i = 0;
		printf("\nrow %d\n", row);
		while (i < map->width[REAL])
		{
			cd[X] = map->x[MIN] + i * step_x;
			cd[Y] = map->y[MAX] - map->points[row][i].value * step_y;
			i++;
			ncd[X] = map->x[MIN] + i * step_x;
			ncd[Y] = map->y[MAX] - map->points[row][i].value * step_y;
			if (i < map->width[REAL])
			{
				printf("drawing(%d): x {%d->%d}, y {%d->%d}\n", i, cd[X], ncd[X], cd[Y], ncd[Y]);
				draw_coordinate_line(data, cd, ncd, color);
			}
		}
		row++;
		// sleep(1);
		mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
	}
}

void	draw_front_view(t_data data)
{
	int	grid_data[4];
	// int color[2] = {WHITE, WHITE};
	
	get_grid_data(data, grid_data);
	// ft_printf("x: %d, y: %d, min_z: %d, max_z: %d\n", 
		// grid_data[X], grid_data[Y], grid_data[MIN_Z], grid_data[MAX_Z]);
	
	// draw_vertical_lines(data, grid_data);
	draw_horizontal_lines(data, grid_data);
}

// void	draw_side_view(t_data data)
// {
// 	(void)data;
// }

// void	draw_top_view(t_data data)
// {
// 	(void)data;
// }