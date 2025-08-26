#include "../fdf.h"

static int	get_max_x(t_map *map)
{
	int	max_x;
	int	i;

	max_x = map->width[0];
	i = 0;
	while (i < map->height)
	{
		if (map->width[i] > max_x)
			max_x = map->width[i];
		i++;
	}
	return (max_x);
}

static int	get_max_z(t_map *map)
{
	int	max_z;
	int	i;
	int	j;

	max_z = map->points[0][0].value;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width[i])
		{
			if (map->points[i][j].value > max_z)
				max_z = map->points[i][j].value;
			j++;
		}
		i++;
	}
	return (max_z);
}

void	get_grid_data(t_map *map, int *grid_data)
{
	grid_data[0] = get_max_x(map);
	grid_data[1] = map->height;
	grid_data[2] = get_max_z(map);
}