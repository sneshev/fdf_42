#include "fdf.h"

int	ft_nbrlen(int n)
{
	int len;

	if (n < 0)
	{
		if (n == INT_MIN)
			return (11);
		return (ft_nbrlen(-n) + 1);
	}
	len = 0;
	while (n > 0)
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
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_nbrlen(map->map[i][j]) > max_digits)
				max_digits = ft_nbrlen(map->map[i][j]);
			j++;
		}
		i++;
	}
	return (max_digits);
}

void	print_map(t_map *map)
{
	int i;
	int j;
	int max_digits;

	if (!map)
		return ;
	i = 0;
	ft_printf("width: %d, height: %d\n", map->width, map->height);
	max_digits = find_max_digits(map);
	ft_printf("max_digits: %d\n", max_digits);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("%d ", map->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
