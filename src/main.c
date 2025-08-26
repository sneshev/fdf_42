#include "fdf.h"

// int	main(int argc, char **argv)
int	main()
{
	int	argc = 2;
	char *argv[] = {"./fdf", "valid1.fdf"};
	t_map *map;
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	if (argc != 2)
		return (ft_error("invalid number of arguments"));

	map = get_map(argv[1]);
	if (!map)
		return (ft_error("failed to get map"));
	printf("yay!\n");
	print_map(map);
	data.map = map;
	if (init_mlx_data(&data) == -1)
		return (free_map(&map), ft_error("failed to init data"), 1);

	draw_front_view(data);

	mlx_event_handle(&data);
	mlx_loop(data.mlxt.mlx);
}

/*
	i can also do the orthographic projections ez:
	
	
*/