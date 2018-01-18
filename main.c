#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main()
{
	int	fd;
	char *line;
	int	is_error;
	fd = open("text", O_RDONLY);
	while ((is_error = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	system("leaks test");
	return 0;
}