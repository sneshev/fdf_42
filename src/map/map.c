#include "../fdf.h"

bool	is_valid_map(char **map);
t_map *create_map_struct(char **map_arr);

static char	*get_filename(char *file_name)
{
	if (ft_strncmp(file_name, "maps/", 5) == 0)
		return (ft_strdup(file_name));
	return (ft_strjoin("maps/", file_name));
}

static char	*fetch_rawmap(char *filename)
{
	int		fd;
	char	*map;
	char	*tmp;
	char	*line;

	filename = get_filename(filename);
	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (ft_error("failed to open file"), NULL);
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
			return (close(fd), NULL);
		map = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

t_map *get_map(char *file_name)
{
	char *rawmap;
	char **map;

	rawmap = fetch_rawmap(file_name);
	if (!rawmap)
		return (NULL);
	map = ft_split(rawmap, '\n');
	free(rawmap);
	if (!map)
		return (ft_error("malloc error"), NULL);
	if (!is_valid_map(map))
		return (ft_error("invalid map"), free_arr(map), NULL);
	return (create_map_struct(map));
}
