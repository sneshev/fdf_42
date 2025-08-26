#include "../fdf.h"

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
	free_points((*map)->points, (*map)->height[REAL]);
	free(*map);
	*map = NULL;
}

void	free_data_exit(t_data *data)
{
	if (data->mlxt.img_info)
		free(data->mlxt.img_info);
	if (data->mlxt.img && data->mlxt.mlx)
		mlx_destroy_image(data->mlxt.mlx, data->mlxt.img);
	if (data->mlxt.win && data->mlxt.mlx)
		mlx_destroy_window(data->mlxt.mlx, data->mlxt.win);
	if (data->mlxt.mlx)
	{
		mlx_destroy_display(data->mlxt.mlx);
		free(data->mlxt.mlx);
	}
	if (data->map)
		free_map(&(data->map));
	exit(0);
}
