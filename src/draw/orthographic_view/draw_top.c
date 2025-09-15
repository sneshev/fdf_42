#include "../../fdf.h"

static void	draw_horizontal_lines(t_data data, t_map map, unsigned int color[2])
{
	float	step_x;
	float	step_y;
	int		i;
	int		row;
	int		cd[2];
	int		ncd[2];

	step_x = (float)map.width[PADDED] / (float)(map.width[REAL] - 1);
	step_y = (float)map.height[PADDED] / (float)(map.height[REAL] - 1);
	row = 0;
	while (row < map.height[REAL])
	{
		i = 0;
		while (i < map.width[REAL] - 1)
		{
			cd[X] = map.x[MIN] + i * step_x;
			cd[Y] = map.y[MIN] + row * step_y;
			color[0] = map.points[row][i].color;
			i++;
			ncd[X] = map.x[MIN] + i * step_x;
			ncd[Y] = map.y[MIN] + row * step_y;
			color[1] = map.points[row][i].color;
			draw_coordinate_line(data, cd, ncd, color);
		}
		row++;
	}
}

static void	draw_vertical_lines(t_data data, t_map map, unsigned int color[2])
{
	(void)data;
	(void)map;
	(void)color;
}

void	draw_top_view(t_data data)
{
	(void)data;
	unsigned int color[2];

	draw_horizontal_lines(data, *data.map, color);
	draw_vertical_lines(data, *data.map, color);
	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
}