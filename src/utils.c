#include "fdf.h"

bool	is_space(char c)
{
	if (c == ' ')
		return (true);
	return (false);
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
	free_points((*map)->points, (*map)->height);
	free((*map)->width);
	free(*map);
	*map = NULL;
}