#include "../fdf.h"

// find graded color and place pixel on the image buffer
void	img_colrpix(t_data data, int cd[2], double t, unsigned int color_range[2])
{
	unsigned int	color;

	color = find_exact_color(t, color_range[0], color_range[1]);
	put_image_pixel(data, cd[X], cd[Y], color);
	// printf("put pixel at {%d, %d} (%d)\n", cd[X], cd[Y], color);
}