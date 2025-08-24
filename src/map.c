#include "fdf.h"

static char	*fetch_rawmap(char *file_name)
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
	map = NULL;
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

static bool	is_valid_map(char **map)
{
	(void)map;
	return (true);
}

char **get_map(char *file_name)
{
	char *rawmap;
	char **map;

	rawmap = fetch_rawmap(file_name);
	if (!rawmap)
		return (NULL);
	map = ft_split(rawmap, '\n');
	free(rawmap);
	if (!map)
		return (ft_printf("malloc err"), NULL);
	if (!is_valid_map(map))
		return (ft_printf("Error: invalid map\n"), free_arr(map), NULL);
	return (map);
}
