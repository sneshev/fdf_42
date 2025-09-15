#include "../../fdf.h"
#include "../drawing.h"

void	draw_top_view(t_data data, t_map *map);


void	draw_isometric_projection(t_data data, t_map map, t_rotation rot)
{
	map.points = alloc_newmap(&map);
	if (!map.points)
	{
		printf("failed to allocate newmap\n");
		return ;
	}
	rotate_points_xyz(&map, rot);
	draw_top_view(data, data.map);
	// mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	free_points(map.points, map.height[REAL]);
}
