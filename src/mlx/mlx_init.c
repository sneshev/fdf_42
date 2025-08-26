#include "../fdf.h"

int	init_mlx_data(t_data *data)
{
	t_img_info	*img_info;
	t_mlxt		*mlxt;

	mlxt = &data->mlxt;
	mlxt->mlx = (void *)mlx_init();
	if (!mlxt->mlx)
		return (-1);
	mlxt->win = mlx_new_window(mlxt->mlx, WIDTH, HEIGHT, "fdf");
	if (!mlxt->win)
		return (-1);
	mlxt->img = mlx_new_image(mlxt->mlx, WIDTH, HEIGHT);
	if (!mlxt->img)
		return (-1);
	mlxt->img_info = (t_img_info *)malloc(sizeof (t_img_info));
	if (!mlxt->img_info)
		return (-1);
	img_info = mlxt->img_info;
	img_info->addr = mlx_get_data_addr(mlxt->img,
			&img_info->bpp, &img_info->line_length, &img_info->endian);
	if (!img_info->addr || !img_info->bpp || !img_info->line_length)
		return (-1);
	return (1);
}