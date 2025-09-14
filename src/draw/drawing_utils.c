#include "../fdf.h"
#include "../colors/colors.h"

//from fractol
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

// draw the contour of the canvas
void	draw_contour(t_data data)
{
	int		x;
	int		y;

	y = data.map->y[MIN];
	while (y < data.map->y[MAX])
	{
		x = data.map->x[MIN];
		while (x < data.map->x[MAX])
		{
			if (x == data.map->x[MIN] || x == data.map->x[MAX] - 1 ||
					y == data.map->y[MIN] || y == data.map->y[MAX] - 1)
				put_image_pixel(data, x, y, DIM_WHITE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
}
