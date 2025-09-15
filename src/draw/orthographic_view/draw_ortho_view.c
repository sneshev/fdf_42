#include "../../fdf.h"

void	draw_side_view(t_data data, t_side side);
void	draw_top_view(t_data data);


void	draw_ortho_view(t_data data, t_side side)
{
	if (side == TOP)
		draw_top_view(data);
	else
		draw_side_view(data, side);
}