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
