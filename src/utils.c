#include "fdf.h"

bool	is_space(char c)
{
	if (c == ' ')
		return (true);
	return (false);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_irr(int **arr, int height)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

bool	is_number(char *str)
{
	while (*str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	is_positive_int(char *str)
{
	const char  *int_max = "2147483647";
	int		 i;

	if (!is_number(str))
		return (false);
	while (*str == '+')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) < 10)
		return (true);
	else if (ft_strlen(str) > 10)
		return (false);
	i = 0;
	if (*str > '2')
		return (false);
	while(str[i] == int_max[i])
	{
		i++;
		if (str[i] > int_max[i])
			return (false);
	}
	return (true);
}

void	free_map(t_map **map)
{
	free_irr((*map)->map, (*map)->height);
	free(*map);
	*map = NULL;
}