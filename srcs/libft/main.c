#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *line = NULL;
	int	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		dprintf(1, "%s\n", line);
	}
}

