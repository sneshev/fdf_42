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

	if (argc != 2)
		return (ft_error("invalid number of arguments"));

	map = get_map(argv[1]);
	if (!map)
		return (ft_error("failed to get map"));
	print_map(map);
	
	if (init_data(&data, &map) == -1)
		return (free_map(&map), ft_error("failed to init data"), 1);


	// mlx_loop(data.mlx);

	free_data(&data);
	return (0);
}

	