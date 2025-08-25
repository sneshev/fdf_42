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

void	free_data(t_data *data)
{
	if (data->img_info)
		free(data->img_info);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(&(data->map));

}
