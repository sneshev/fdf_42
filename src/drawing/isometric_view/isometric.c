#include "../../fdf.h"
#include "../drawing.h"

void	draw_top_view(t_data data, t_map *map);


void	draw_isometric_projection(t_data data, t_map map, t_rotation rot)
{
	t_map	new_map;

	copy_map_values(map, &new_map, FRONT);
	new_map.points = alloc_newmap(&map);
	if (!new_map.points)
	{
		printf("failed to allocate newmap\n");
		return ;
	}
	replace_points(map, &new_map, FRONT);
	rotate_points_xyz(&map, rot);
	draw_top_view(data, &map);
	free_points(new_map.points, new_map.height[REAL]);
}
