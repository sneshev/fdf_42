#include "../fdf.h"

void	draw_front_view(t_map *map, t_mlxt mlxt)
{
	int	grid_data[3];
	(void)mlxt;

	get_grid_data(map, grid_data);
	ft_printf("max_x: %d, max_y: %d, max_z: %d\n", grid_data[0], grid_data[1], grid_data[2]);
}

void	draw_side_view(t_map *map, t_mlxt mlxt)
{
	(void)map;
	(void)mlxt;
}

void	draw_top_view(t_map *map, t_mlxt mlxt)
{
	(void)map;
	(void)mlxt;
}