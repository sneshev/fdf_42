#include "../fdf.h"

//from fractol
void	put_image_pixel(t_data data, int x, int y, int color)
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

void	draw_coordinate_line(t_data data, t_point p1, t_point p2)
{
	(void)data;
	(void)p1;
	(void)p2;
}
