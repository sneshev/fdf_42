#include "../../fdf.h"

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
