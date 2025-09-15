#include "../../fdf.h"
#include "../../colors/colors.h"

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
	if (coord[X] < 0 || coord[Y] < 0 || coord[X] >= data.map->width[PIXEL] || coord[Y] >= data.map->height[PIXEL])
		printf("x = %d, y = %d\n", coord[X], coord[Y]);
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
static void	draw_vertical_line(t_data data, int cd[2], int end[2], unsigned int color[2])
{
	int start_y;

	if (!is_valid_coord(data, cd) || !is_valid_coord(data, end))
		return ;

	start_y = cd[Y];
	while(cd[Y] != end[Y])
	{
		img_colrpix(data, cd, find_t(cd[Y], start_y, end[Y]), color);
		if (cd[Y] < end[Y])
			cd[Y]++;
		else
			cd[Y]--;
	}
	img_colrpix(data, cd, find_t(cd[Y], start_y, end[Y]), color);
}

// start[Y] == end[Y]
static void	draw_horizontal_line(t_data data, int cd[2], int end[2], unsigned int color[2])
{
	int start_x;

	if (!is_valid_coord(data, cd) || !is_valid_coord(data, end))
		return ;

	start_x = cd[X];
	while(cd[X] != end[X])
	{
		img_colrpix(data, cd, find_t(cd[X], start_x, end[X]), color);
		if (cd[X] < end[X])
			cd[X]++;
		else
			cd[X]--;
	}
	img_colrpix(data, cd, find_t(cd[X], start_x, end[X]), color);
}

// start[Y] < end[Y]
static void	draw_diagonal_line(t_data data, int cd[2], int end[2], unsigned int color[2])
{
	float	step;
	float	curr_step;
	float	i;
	int		start_y;

	if (!is_valid_coord(data, cd) || !is_valid_coord(data, end))
		return ;
	step = (float)abs(cd[X] - end[X]) / (float)abs(cd[Y] - end[Y]);
	i = 0;
	curr_step = step;
	start_y = cd[Y];
	while(cd[Y] <= end[Y])
	{
		img_colrpix(data, cd, find_t(cd[Y], start_y, end[Y]), color);
		if (step < 0)
		{
			while(i > curr_step)
			{
				if (cd[Y] < end[Y])
					cd[Y]++;
				else
					cd[Y]--;
				img_colrpix(data, cd, find_t(cd[Y], start_y, end[Y]), color);
				i--;
			}
			curr_step -= curr_step;
			cd[X]++;
		}
		else if (step > 0)
		{
			while(i < curr_step)
			{
				if (cd[X] < end[X])
					cd[X]++;
				else
					cd[X]--;
				img_colrpix(data, cd, find_t(cd[Y], start_y, end[Y]), color);
				i++;
			}
			curr_step += step;
			cd[Y]++;
		}
		if (step == 0)
		{
			cd[Y]++;
			cd[X]++;
		}
		img_colrpix(data, cd, find_t(cd[Y], start_y, end[Y]), color);
	}
}

/*
	DOES NOT IMAGE_TO_WIDNOW()
	.put the color inside the coord[] array
	.add a argument for width of line (narrow, thick, ..)

	.color can be part of the coord1[] and coord2[] arrays. They will then be unsigned int arrays, thats okay
*/
void	draw_coordinate_line(t_data data, int coord1[2], int coord2[2], unsigned int color[2])
{
	unsigned int	tmp_color;

	if (coord1[X] == coord2[X] && coord1[Y] == coord2[Y])
		return ;
	else if (coord1[X] == coord2[X])
		draw_vertical_line(data, coord1, coord2, color);
	else if (coord1[Y] == coord2[Y])
		draw_horizontal_line(data, coord1, coord2, color);
	else
	{
		if (coord1[Y] > coord2[Y])
			{
				tmp_color = color[0];
				color[0] = color[1];
				color[1] = tmp_color;
				draw_diagonal_line(data, coord2, coord1, color);
			}
		else
			draw_diagonal_line(data, coord1, coord2, color);
	}
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