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
		return (write(1, "Error: drawing invalid line\n", 28), false);
	if (coord[Y] < 0)
		return (write(1, "Error: drawing invalid line\n", 28), false);
	if (coord[X] >= data.map->width[PIXEL])
		return (write(1, "Error: drawing invalid line\n", 28), false);
	if (coord[Y] >= data.map->height[PIXEL])
		return (write(1, "Error: drawing invalid line\n", 28), false);
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
	put_image_pixel(data, start[X], start[Y], color[0]);
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
	put_image_pixel(data, start[X], start[Y], color[0]);
}

// start[Y] < end[Y]
static void	draw_diagonal_line(t_data data, int start[2], int end[2], int color[2])
{
	float	step;
	float	curr_step;
	float	i;

	if (!is_valid_coord(data, start) || !is_valid_coord(data, end))
		return ;
	step = (float)abs(start[X] - end[X]) / (float)abs(start[Y] - end[Y]);
	i = 0;
	curr_step = step;
	while(start[Y] <= end[Y])
	{
		put_image_pixel(data, start[X], start[Y], color[X]);
		if (step < 0)
		{
			while(i > curr_step)
			{
				if (start[Y] < end[Y])
					start[Y]++;
				else
					start[Y]--;
				put_image_pixel(data, start[X], start[Y], color[0]);
				i--;
			}
			curr_step -= curr_step;
			start[X]++;
		}
		else if (step > 0)
		{
			while(i < curr_step)
			{
				if (start[X] < end[X])
					start[X]++;
				else
					start[X]--;
				put_image_pixel(data, start[X], start[Y], color[0]);
				i++;
			}
			curr_step += step;
			start[Y]++;
		}
		if (step == 0)
		{
			start[Y]++;
			start[X]++;
		}
		put_image_pixel(data, start[X], start[Y], color[0]);
	}
}

/*
	.put the color inside the coord[] array
	.add a argument for width of line (narrow, thick, ..)
*/
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


/* 
	.Bresenham’s Line Algorithm produces a line that looks as straight as possible on a pixel grid

	.Xiaolin Wu’s algorithm draws blended pixels for fractional coverage.
	Makes lines look visually straight but is more complicated.
	the algorithm draws partial brightness on neighboring pixels to smooth the staircase.
	Anti-aliasing (optional, advanced)

*/


// // Bresenham’s
// void	draw_coordinate_line(t_data data, int coord1[2], int coord2[2], int color[2])
// {
//     int dx = abs(coord2[X] - coord1[X]);
//     int sx = coord1[X] < coord2[X] ? 1 : -1;
//     int dy = -abs(coord2[Y] - coord1[Y]);
//     int sy = coord1[Y] < coord2[Y] ? 1 : -1;
//     int err = dx + dy; // error value

//     while (1)
//     {
//         put_image_pixel(data, coord1[X], coord1[Y], color[X]);
//         if (coord1[X] == coord2[X] && coord1[Y] == coord2[Y])
//             break;
//         int e2 = 2 * err;
//         if (e2 >= dy)
//         {
//             err += dy;
//             coord1[X] += sx;
//         }
//         if (e2 <= dx)
//         {
//             err += dx;
//             coord1[Y] += sy;
//         }
//     }
//  	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
// }