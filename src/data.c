#include "fdf.h"

int	init_data(t_data *data, t_map **map)
{
	t_img_info	*img_info;

	data->map = *map;
	data->mlx = (void *)mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (0);
	data->img_info = (t_img_info *)malloc(sizeof (t_img_info));
	if (!data->img_info)
		return (0);
	img_info = data->img_info;
	img_info->addr = mlx_get_data_addr(data->img,
			&img_info->bpp, &img_info->line_length, &img_info->endian);
	if (!img_info->addr || !img_info->bpp || !img_info->line_length)
		return (0);
	return (1);
}
