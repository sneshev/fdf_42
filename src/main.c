#include "fdf.h"

void	read_map(char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s\n", line);
		line = get_next_line(fd);
	}
	close(fd);
}


int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	read_map("maps/valid0.fdf");
	return (0);
}

	