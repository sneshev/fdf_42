#include "../fdf.h"

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