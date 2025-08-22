#include "fdf.h"

char	*fetch_map(char *file_name)
{
	int		fd;
	char	*map;
	char	*tmp;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), NULL);
	while (line)
	{
		tmp = ft_strjoin(map, line);
		free(map);
		free(line);
		if (!tmp)
			return (NULL);
		map = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}


int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *map = fetch_map("maps/valid0.fdf");
	if (!map)
	{
		ft_printf("Error: failed to fetch map\n");
		return (1);
	}
	ft_printf("%s\n", map);
	free(map);
	return (0);
}

	