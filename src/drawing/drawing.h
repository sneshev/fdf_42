#ifndef DRAWING_H
# define DRAWING_H

# include "../fdf.h"

// map rotation utils 
t_point	**alloc_newmap(t_map *map);
void	replace_points(t_map map, t_map *newmap, t_side side);

//rotation
void rotate_points_x(t_map *map, float t);
void rotate_points_y(t_map *map, float t);
void rotate_points_z(t_map *map, float t);
void rotate_points_xyz(t_map *map, t_rotation rot);


#endif