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
