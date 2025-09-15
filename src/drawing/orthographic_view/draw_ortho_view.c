#include "../../fdf.h"

void	draw_side_view(t_data data, t_side side);
void	draw_top_view(t_data data, t_map *map);


void	draw_ortho_view(t_data data, t_side side)
{
	// mlx_clear_window(data.mlxt.mlx, data.mlxt.win);
	if (side == TOP)
		draw_top_view(data, data.map);
	else
		draw_side_view(data, side);
}