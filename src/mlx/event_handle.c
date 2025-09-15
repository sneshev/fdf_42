#include "../fdf.h"

#define ESC 65307 
# define L 108
# define R 114
# define F 102
# define B 98
# define T 116

int	close_window(t_data *data)
{
	free_data_exit(data);
	return (1);
}

int	set_keyhooks(int key, t_data *data)
{
	if (key == ESC)
		free_data_exit(data);
	if (key == L)
		draw_ortho_view(*data, LEFT);
	if (key == R)
		draw_ortho_view(*data, RIGHT);
	if (key == F)
		draw_ortho_view(*data, FRONT);
	if (key == B)
		draw_ortho_view(*data, BACK);
	if (key == T)
		draw_ortho_view(*data, TOP);
	return (1);
}

void	mlx_event_handle(t_data *data)
{
	// mlx_hook(data->win, 4, 4, set_mouse_events, data);
	mlx_hook(data->mlxt.win, 17, 0, close_window, data);
	mlx_key_hook(data->mlxt.win, set_keyhooks, data);
}