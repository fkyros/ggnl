#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int fd;

	fd = open("nl", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)))
	{
		if (line == NULL)
			printf("la siguiente es nula!\n");
		printf("\"%s\" ", line);
		free(line);
	}
	return (0);
}
