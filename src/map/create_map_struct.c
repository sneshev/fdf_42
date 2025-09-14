#include "../fdf.h"

int	count_numbers(char *line)
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

void	fill_point(t_point *point, int val, int i, int j)
{
	point->coordinate[Y] = i;
	point->coordinate[X] = j;
	point->value = val;
	point->color = WHITE;
}

static t_point	**ctot_map(char **map, int width, int height)
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
		points[i] = malloc(sizeof(t_point) * width);
		if (!points[i])
			return (free_points(points, i), free_arr(map), NULL);			
		line = map[i];
		while (j < width)
		{
			while (is_space(*line))
				line++;
			fill_point(&points[i][j], ft_atoi(line), i, j);
			while (ft_isdigit(*line) || *line == '-')
				line++;
			j++;
		}
		i++;
	}
	return (free_arr(map), points);
}

// assume valid map
t_map *create_map_struct(char **map_arr)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (free_arr(map_arr), NULL);
	map->width[REAL] = count_numbers(map_arr[0]);
	map->height[REAL] = 0;
	while (map_arr[map->height[REAL]])
	{
		if (count_numbers(map_arr[map->height[REAL]]) != map->width[REAL])
			return (ft_error("invalid map"), free_map(&map), free_arr(map_arr), NULL);
		map->height[REAL]++;

	}
	map->points = ctot_map(map_arr, map->width[REAL], map->height[REAL]);
	if (!map->points)
		return (free_map(&map), free_arr(map_arr), NULL);
	map->width[PIXEL] = WIDTH;
	map->height[PIXEL] = HEIGHT;
	map->width[PADDED] = WIDTH - (WIDTH * PADDING_PERC / 50);
	map->height[PADDED] = HEIGHT - (HEIGHT * PADDING_PERC / 50);
	map->x[MIN] = (WIDTH * PADDING_PERC / 100);
	map->x[MAX] = WIDTH - (WIDTH * PADDING_PERC / 100);
	map->y[MIN] = (HEIGHT * PADDING_PERC / 100);
	map->y[MAX] = HEIGHT - (HEIGHT * PADDING_PERC / 100);
	return (map);
}
