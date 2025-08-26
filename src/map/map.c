#include "../fdf.h"

bool	is_valid_map(char **map);

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

static t_point	**ctot_map(char **map, int *width, int height)
{
	t_point **points;
	char *line;
	int i;
	int j;

	i = 0;
	points = malloc(sizeof(t_point *) * height);
	if (!points)
		return (free_arr(map), NULL);
	while (map[i])
	{
		j = 0;
		points[i] = malloc(sizeof(t_point) * width[i]);
		if (!points[i])
			return (free_points(points, i), free_arr(map), NULL);			
		line = map[i];
		while (j < width[i])
		{
			while (is_space(*line))
				line++;
			points[i][j].coordinate[X] = j;
			points[i][j].coordinate[Y] = i;
			points[i][j].value = ft_atoi(line);
			while (ft_isdigit(*line) || *line == '-')
				line++;
			j++;
		}
		i++;
	}
	return (free_arr(map), points);
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
		if (ft_isdigit(*line) || (*line == '-' && ft_isdigit(*(line + 1))))
			count++;
		if (*line == '-')
			line++;
		while (ft_isdigit(*line))
			line++;
	}
	return (count);
}

// assume valid map
t_map *create_map_struct(char **map_arr)
{
	t_map *map;
	int i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (free_arr(map_arr), NULL);
		
	map->height = 0;
	while (map_arr[map->height])
		map->height++;
	map->width = malloc(sizeof(int) * map->height);
	if (!map->width)
		return (free_map(&map), free_arr(map_arr), NULL);
	i = 0;
	while (i < map->height)
	{
		map->width[i] = count_numbers(map_arr[i]);
		i++;
	}
	map->points = ctot_map(map_arr, map->width, map->height);
	if (!map->points)
		return (free_map(&map), free_arr(map_arr), NULL);
	map->width_px = WIDTH;
	map->height_px = HEIGHT;
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
