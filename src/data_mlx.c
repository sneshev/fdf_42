#include "fdf.h"

#define ESC 65307 

int	close_window(t_data *data)
{
	free_data_exit(data);
	return (1);
}

int	set_keyhooks(int key, t_data *data)
{
	(void)data;
	if (key == ESC)
		free_data_exit(data);
	return (1);
}

void	mlx_event_handle(t_data *data)
{
	// mlx_hook(data->win, 4, 4, set_mouse_events, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_key_hook(data->win, set_keyhooks, data);
}

int	init_data(t_data *data, t_map **map)
{
	t_img_info	*img_info;

	data->map = *map;
	data->mlx = (void *)mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (0);
	data->img_info = (t_img_info *)malloc(sizeof (t_img_info));
	if (!data->img_info)
		return (0);
	img_info = data->img_info;
	img_info->addr = mlx_get_data_addr(data->img,
			&img_info->bpp, &img_info->line_length, &img_info->endian);
	if (!img_info->addr || !img_info->bpp || !img_info->line_length)
		return (0);
	return (1);
}
