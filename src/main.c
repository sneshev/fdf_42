#include "fdf.h"

void	draw_bulgaria(t_data data);
void	draw_contour(t_data data);

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
	print_map(map);
	data.map = map;
	if (init_mlx_data(&data) == -1)
		return (free_map(&map), ft_error("failed to init data"), 1);

	draw_contour(data);
	// draw_ortho_view(data, FRONT);
	draw_ortho_view(data, RIGHT);
	// draw_bulgaria(data);

	mlx_event_handle(&data);
	mlx_loop(data.mlxt.mlx);
}

/*
	i can also do the orthographic projections ez:
	
	
*/