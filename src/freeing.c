#include "fdf.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_points(t_point **points, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(points[i++]);
	free(points);
}

void	free_map(t_map **map)
{
	free_points((*map)->points, (*map)->height);
	free((*map)->width);
	free(*map);
	*map = NULL;
}
