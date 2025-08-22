#include "fdf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char **map;
	map = get_map("maps/valid0.fdf");
	if (!map)
	{
		ft_printf("Error: failed to fetch map\n");
		return (1);
	}
	print_map(map);
	free(map);
	return (0);
}

	