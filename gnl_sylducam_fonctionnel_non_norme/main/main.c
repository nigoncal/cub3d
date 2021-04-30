#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line.h"

int main()
{
	int	ret = 1;
	char *line;
	int	fd = open("file", O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		dprintf(1, "%s\n", line);
		dprintf(1, "ret = %d\n" , ret);
	}
}

