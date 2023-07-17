#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int fd;

	fd = open("41_no_nl", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("\"%s\" ", line);
		free(line);
	}
	return (0);
}
