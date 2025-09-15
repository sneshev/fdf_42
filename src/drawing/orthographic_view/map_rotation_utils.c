#include "../../fdf.h"

// needs to have .width and .height already
t_point	**alloc_newmap(t_map *map)
{
	t_point	**points;
	int		width;
	int		height;
	int		i;

	height = map->height[REAL];
	width = map->width[REAL];
	points = (t_point **)malloc(height * sizeof(t_point *));
	if (!points)
		return (NULL);
	i = 0;
	while (i < height)
	{
		points[i] = (t_point *)malloc(width * sizeof(t_point));
		if (!points[i])
			return (free_points(points, i), NULL);
		i++;
	}
	return (points);
}

void	copy_map_values(t_map map, t_map *new_map, t_side side)
{
	if (side == LEFT || side == RIGHT)
	{
		new_map->height[REAL] = map.width[REAL];
		new_map->width[REAL] = map.height[REAL];
	}
	else if (side == FRONT || side == BACK)
	{
		new_map->height[REAL] = map.height[REAL];
		new_map->width[REAL] = map.width[REAL];
	}
	new_map->height[1] = map.height[1];
	new_map->height[2] = map.height[2];
	new_map->width[1] = map.width[1];
	new_map->width[2] = map.width[2];
	new_map->x[0] = map.x[0];
	new_map->x[1] = map.x[1];
	new_map->y[0] = map.y[0];
	new_map->y[1] = map.y[1];
}

// rotates the map
void	replace_points(t_map map, t_map *newmap, t_side side)
{
	int	i;
	int	j;
	int	height = map.height[REAL];
	int	width = map.width[REAL];
	
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (side == FRONT)
				newmap->points[i][j] = map.points[i][j];
			if (side == BACK)
				newmap->points[height - i - 1][width - j - 1] = map.points[i][j];
			if (side == LEFT)
				newmap->points[width - j - 1][i] = map.points[i][j];
			if (side == RIGHT)
				newmap->points[j][height - i - 1] = map.points[i][j];
			j++;	
		}
		i++;
	}
}
