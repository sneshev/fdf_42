#include "../fdf.h"

#define MIN_Z 2
#define MAX_Z 3

void	draw_front_view(t_map *map, t_mlxt mlxt)
{
	int	grid_data[4];
	(void)mlxt;

	get_grid_data(map, grid_data);
	ft_printf("x: %d, y: %d, min_z: %d, max_z: %d\n", grid_data[X], grid_data[Y], grid_data[MIN_Z], grid_data[MAX_Z]);
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