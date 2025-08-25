#include "fdf.h"

int	ft_error(char *str)
{
	ft_printf("Error: %s\n", str);
	return (1);
}

// int	main(int argc, char **argv)
int	main()
{
	int	argc = 2;
	char *argv[] = {"./fdf", "valid0.fdf"};
	t_map *map;
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	if (argc != 2)
		return (ft_error("invalid number of arguments"));

	map = get_map(argv[1]);
	if (!map)
		return (ft_error("failed to get map"));
	print_map(map);
	
	if (init_data(&data, &map) == -1)
		return (free_map(&map), ft_error("failed to init data"), 1);

	draw_fdf(data);
	mlx_event_handle(&data);
	mlx_loop(data.mlx);
}

	