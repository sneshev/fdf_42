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

static int	**ctoi_map_ret(char **map, int **int_map)
{
	free_arr(map);
	return (int_map);
}

static int	**ctoi_map(char **map, int width, int height)
{
	int **int_map;
	char *line;
	int i;
	int j;

	i = 0;
	int_map = malloc(sizeof(int *) * height);
	if (!int_map)
		return (ctoi_map_ret(map, NULL));
	while (map[i])
	{
		j = 0;
		int_map[i] = malloc(sizeof(int) * width);
		if (!int_map[i])
			return (free_irr(int_map, i), ctoi_map_ret(map, int_map));			
		line = map[i];
		while (j < width)
		{
			while (is_space(*line))
				line++;
			int_map[i][j] = ft_atoi(line);
			while (ft_isdigit(*line) || *line == '-')
				line++;
			j++;
		}
		i++;
	}
	return (ctoi_map_ret(map, int_map));
}

static int	count_numbers(char *line)
{
	int count;

	count = 0;
	while (*line)
	{
		while (is_space(*line))
			line++;
		if (*line == '\0')
			break ;
		if (ft_isdigit(*line))
			count++;
		while (ft_isdigit(*line))
			line++;
	}
	return (count);
}

// assume valid map
t_map *create_map_struct(char **map_arr)
{
	t_map *map;
	int width;
	int height;

	map = malloc(sizeof(t_map));
	if (!map)
		return (free_arr(map_arr), NULL);
	width = count_numbers(map_arr[0]);
	height = 0;
	while (map_arr[height])
		height++;
	map->map = ctoi_map(map_arr, width, height);
	if (!map->map)
		return (free(map), NULL);
	map->width = width;
	map->height = height;
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
		return (ft_printf("malloc err"), NULL);
	if (!is_valid_map(map))
		return (ft_printf("Error: invalid map\n"), free_arr(map), NULL);
	return (create_map_struct(map));
}
