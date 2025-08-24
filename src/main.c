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

	if (argc != 2)
		return (ft_error("invalid number of arguments"));
	t_map *map;
	map = get_map(argv[1]);
	if (!map)
		return (ft_error("failed to fetch map"));
	print_map(map);
	free_map(&map);
	return (0);
}

	