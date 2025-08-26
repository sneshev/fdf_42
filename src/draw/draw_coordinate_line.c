#include "../fdf.h"
#include "colors.h"

// static void	swap_coords(int coord1[2], int coord2[2])
// {
	// int temp[2];
	// temp[0] = coord1[0];
	// temp[1] = coord1[1];
	// coord1[0] = coord2[0];
	// coord1[1] = coord2[1];
	// coord2[0] = temp[0];
	// coord2[1] = temp[1];
// }

bool	is_valid_coord(t_data data, int coord[2])
{
	(void)data;
	if (coord[X] < 0)
		return (false);
	if (coord[Y] < 0)
		return (false);
	// if (coord[X] > data.mlxt.width[PIXEL])
	// 	return (false);
	// if (coord[Y] > data.mlxt.height[PIXEL])
	// 	return (false);
	return (true);
}

// start[X] == end[X]
static void	draw_vertical_line(t_data data, int start[2], int end[2], int color[2])
{
	if (!is_valid_coord(data, start) || !is_valid_coord(data, end))
		return ;
	while(start[Y] != end[Y])
	{
		put_image_pixel(data, start[X], start[Y], color[0]);
		if (start[Y] < end[Y])
			start[Y]++;
		else
			start[Y]--;
	}
	put_image_pixel(data, end[X], end[Y], color[0]);
}

// start[Y] == end[Y]
static void	draw_horizontal_line(t_data data, int start[2], int end[2], int color[2])
{
	if (!is_valid_coord(data, start) || !is_valid_coord(data, end))
		return ;
	while(start[X] != end[X])
	{
		put_image_pixel(data, start[X], start[Y], color[0]);
		if (start[X] < end[X])
			start[X]++;
		else
			start[X]--;
	}
	put_image_pixel(data, end[X], end[Y], color[0]);
}

// start[Y] < end[Y]
static void	draw_diagonal_line(t_data data, int start[2], int end[2], int color[2])
{
	int	step;
	int	i;

	if (!is_valid_coord(data, start) || !is_valid_coord(data, end))
		return ;
	step = abs(start[X] - end[X]) / abs(start[Y] - end[Y]);
	while(start[Y] <= end[Y])
	{
		i = 0;
		put_image_pixel(data, start[X], start[Y], color[X]);
		mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
		ft_printf("start[X]: %d, start[Y]: %d\n", start[X], start[Y]);
		if (step < 0)
		{
			while(i-- > step)
			{
				start[Y]++;
				put_image_pixel(data, start[X], start[Y], color[0]);
				mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
				ft_printf("start[X]: %d, start[Y]: %d\n", start[X], start[Y]);
			}
			start[X]++;
		}
		else
		{
			while(i++ < step)
			{
				start[X]++;
				put_image_pixel(data, start[X], start[Y], color[0]);
				mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
				ft_printf("start[X]: %d, start[Y]: %d\n", start[X], start[Y]);
			}
			start[Y]++;
		}
		if (step == 0)
		{
			start[Y]++;
			start[X]++;
		}
		put_image_pixel(data, start[X], start[Y], color[0]);
		mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
	}
}

void	draw_coordinate_line(t_data data, int coord1[2], int coord2[2], int color[2])
{
	if (coord1[X] == coord2[X] && coord1[Y] == coord2[Y])
		return ;
	else if (coord1[X] == coord2[X])
		draw_vertical_line(data, coord1, coord2, color);
	else if (coord1[Y] == coord2[Y])
		draw_horizontal_line(data, coord1, coord2, color);
	else
	{
		if (coord1[Y] > coord2[Y])
			draw_diagonal_line(data, coord2, coord1, color);
		else
			draw_diagonal_line(data, coord1, coord2, color);
	}
	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
}
