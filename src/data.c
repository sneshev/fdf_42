#include "fdf.h"

int	init_data(t_data *data, t_map **map)
{
	data->map = *map;
	// data->mlx = (void *)mlx_init();
	// if (!data->mlx)
	// 	return (ft_error("failed to init mlx"), -1);
	// data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	// if (!data->win)
	// 	return (ft_error("failed to init window"), -1);
	// data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// if (!data->img)
	// 	return (ft_error("failed to init image"), -1);
	// data->img_info = (t_img_info *)malloc(sizeof(t_img_info));
	// if (!data->img_info)
	// 	return (ft_error("failed to init image info"), -1);
	// data->img_info->addr = mlx_get_data_addr(data->img, &data->img_info->bpp, &data->img_info->line_length, &data->img_info->endian);
	// if (!data->img_info->addr)
	// 	return (ft_error("failed to get image data addr"), -1);
	return (0);
}
