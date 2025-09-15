#include "../fdf.h"

void	put_image_pixel(t_data data, int x, int y, unsigned int color)
{
	char	*pixel;
	void	*addr;
	int		bpp;
	int		line_length;

	addr = data.mlxt.img_info->addr;
	bpp = data.mlxt.img_info->bpp;
	line_length = data.mlxt.img_info->line_length;
	pixel = (char *)addr + (y * line_length + x * (bpp / 8));
	*(unsigned int *)pixel = color;
}

// find graded color and place pixel on the image buffer
void	img_colrpix(t_data data, int cd[2], double t, unsigned int color_range[2])
{
	unsigned int	color;

	color = find_exact_color(t, color_range[0], color_range[1]);
	put_image_pixel(data, cd[X], cd[Y], color);
	// printf("put pixel at {%d, %d} (%d)\n", cd[X], cd[Y], color);
}