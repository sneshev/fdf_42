#include "fdf.h"

#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF

//from fractol
void	put_image_pixel(t_data data, int x, int y, int color)
{
	char	*pixel;
	void	*addr;
	int		bpp;
	int		line_length;

	addr = data.img_info->addr;
	bpp = data.img_info->bpp;
	line_length = data.img_info->line_length;
	pixel = (char *)addr + (y * line_length + x * (bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_line(t_data data, t_point p1, t_point p2)
{
	(void)data;
	(void)p1;
	(void)p2;
}

void	draw_fdf(t_data data)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT / 3)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_image_pixel(data, x, y, WHITE);
			x++;
		}
		y++;
	}
	while (y < HEIGHT * 2 / 3)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_image_pixel(data, x, y, GREEN);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_image_pixel(data, x, y, RED);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
}
