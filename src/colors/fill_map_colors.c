#include "../fdf.h"

#define MIN_Z 2
#define MAX_Z 3

static unsigned int	get_point_color(t_point *point, int min, int max)
{
	double	t;

	if (point->value < 0)
	{
		t = find_t(point->value, min, 0);
		return (find_exact_color(t, COLOR_LOW, COLOR_GROUND)); //for now no gradient

	}
	else if (point->value == 0)
		return (COLOR_GROUND);
	else
	{
		t = find_t(point->value, 0, max);
		return (find_exact_color(t, COLOR_GROUND, COLOR_HIGH));	
	}
}


void	fill_colors(t_map *map)
{
	int	grid_data[4];
	int	i;
	int	j;

	get_grid_data(*map, grid_data);
	map->color[HIGH] = COLOR_HIGH;
	map->color[GROUND] = COLOR_GROUND;
	map->color[LOW] = COLOR_LOW;
	i = 0;
	while (i < map->height[REAL])
	{
		j = 0;
		while (j < map->width[REAL])
		{
			map->points[i][j].color = get_point_color(&map->points[i][j], grid_data[MIN_Z], grid_data[MAX_Z]);
			j++;
		}
		i++;
	}
}