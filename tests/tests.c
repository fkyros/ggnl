#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *line;
	//int fd = open("tests/1char.txt", O_RDONLY);
	int fd = 0;
	int i = 0;

	while (i < 3)
	{
		line = get_next_line(fd);
		printf("\"%s\"\n", line);
		i++;
	}
	close(fd);
	return 0;
}
