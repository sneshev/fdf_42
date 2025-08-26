#include "../fdf.h"

#define WHITE 0xFFFFFF
#define GREEN 0x00FF00
#define RED 0xFF0000

void	draw_bulgaria(t_data data)
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
	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
}