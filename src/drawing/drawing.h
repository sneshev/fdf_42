#ifndef DRAWING_H
# define DRAWING_H

# include "../fdf.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif


// map rotation utils 
t_point	**alloc_newmap(t_map *map);
void	replace_points(t_map map, t_map *newmap, t_side side);
void	copy_map_values(t_map map, t_map *new_map, t_side side);

//rotation
void rotate_points_x(t_map *map, float t);
void rotate_points_y(t_map *map, float t);
void rotate_points_z(t_map *map, float t);
void rotate_points_xyz(t_map *map, t_rotation rot);


#endif