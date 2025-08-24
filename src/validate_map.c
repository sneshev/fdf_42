#include "fdf.h"

bool	is_valid_number(char *str)
{
	int		i;
	int		negative;

	negative = 0;
	i = 0;
	if (str[i] == '-')
	{
		negative = 1;
		str++;
	}
	while (ft_isdigit(str[i]))
		i++;
	if (i > 10 || i == 0)
		return (false);
	if (i < 10 || *str < '2')
		return (true);
	if (*str > '2')
		return (false);
	str++;
	if (negative && ft_strncmp(str, "147483648", 9) <= 0)
		return (true);
	else if (!negative && (ft_strncmp(str, "147483647", 9) <= 0))
		return (1);
	return (false);
}

bool	is_valid_line(char *line)
{
	int j;

	j = 0;
	while (line[j])
	{
		while (is_space(line[j]))
			j++;
		if (line[j] == '\0')
			return (true);
		if (!is_valid_number(line + j))
			return (false);
		if (line[j] == '-')
			j++;
		while (ft_isdigit(line[j]))
			j++;
	}
	return (true);
}

bool	is_valid_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (!is_valid_line(map[i]))
			return (false);
		i++;
	}
	return (true);
}