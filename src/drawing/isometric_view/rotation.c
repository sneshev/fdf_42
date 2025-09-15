#include "../../fdf.h"
#include "../drawing.h"

void rotate_points_x(t_map *map, float th)
{
	(void)map;
	(void)th;
	// map->points[0][0].value = 4;
	// map->points[0][0].color = GREEN;
}

void rotate_points_y(t_map *map, float th)
{
	(void)map;
	(void)th;
}

void rotate_points_z(t_map *map, float th)
{
	(void)map;
	(void)th;
}


void rotate_points_xyz(t_map *map, t_rotation rot)
{
	rotate_points_x(map, rot.xt);
	rotate_points_y(map, rot.yt);
	rotate_points_z(map, rot.zt);
}