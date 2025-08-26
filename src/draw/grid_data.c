#include "../fdf.h"

static int	get_max_z(t_map *map)
{
	int	max_z;
	int	i;
	int	j;

	max_z = map->points[0][0].value;
	i = 0;
	while (i < map->height[REAL])
	{
		j = 0;
		while (j < map->width[REAL])
		{
			if (map->points[i][j].value > max_z)
				max_z = map->points[i][j].value;
			j++;
		}
		i++;
	}
	return (max_z);
}

static int	get_min_z(t_map *map)
{
	int	min_z;
	int	i;
	int	j;

	min_z = map->points[0][0].value;
	i = 0;
	while (i < map->height[REAL])
	{
		j = 0;
		while (j < map->width[REAL])
		{
			if (map->points[i][j].value < min_z)
				min_z = map->points[i][j].value;
			j++;
		}
		i++;
	}
		return (min_z);
}

void	get_grid_data(t_map *map, int *grid_data)
{
	grid_data[0] = map->width[REAL];
	grid_data[1] = map->height[REAL];
	grid_data[2] = get_min_z(map);
	grid_data[3] = get_max_z(map);
}