#include "../fdf.h"

int	ft_nbrlen(int n)
{
	int len;

	if (n < 0)
	{
		if (n == INT_MIN)
			return (11);
		return (ft_nbrlen(-n) + 1);
	}
	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	find_max_digits(t_map *map)
{
	int max_digits;
	int i;
	int j;

	max_digits = 0;
	i = 0;
	while (i < map->height[REAL])
	{
		j = 0;
		while (j < map->width[REAL])
		{
			if (ft_nbrlen(map->points[i][j].value) > max_digits)
				max_digits = ft_nbrlen(map->points[i][j].value);
			j++;
		}
		i++;
	}
	return (max_digits);
}

void	print_colored_num(t_map *map, int num)
{
	int min;
	int max;
	int i;
	int j;

	min = INT_MAX;
	max = INT_MIN;
	i = 0;
	while (i < map->height[REAL])
	{
		j = 0;
		while (j < map->width[REAL])
		{
			if (map->points[i][j].value < min)
				min = map->points[i][j].value;
			if (map->points[i][j].value > max)
				max = map->points[i][j].value;
			j++;
		}
		i++;
	}
	ft_printf("\033[%dm%d \033[0m", 31 + (int)((num - min) * 5.0 / (max - min)), num);
}

void	print_map(t_map *map)
{
	int i;
	int j;
	int max_digits;
	int	digits;

	if (!map)
		return ;
	i = 0;
	ft_printf("width: %d, height: %d\n", map->width[REAL], map->height[REAL]);
	max_digits = find_max_digits(map);
	ft_printf("max_digits: %d\n", max_digits);
	while (i < map->height[REAL])
	{
		j = 0;
		while (j < map->width[REAL])
		{
			digits = ft_nbrlen(map->points[i][j].value);
			while (digits++ < max_digits)
				ft_printf(" ");
			print_colored_num(map, map->points[i][j].value);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
