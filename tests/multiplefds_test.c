#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../get_next_line_bonus.h"

int main()
{
	int fd1 = open("read_error.txt", O_RDONLY);
	int fd2 = open("lines_around_10.txt", O_RDONLY);

	printf("fd1: \"%s\"\n", get_next_line(fd1));
	printf("fd1: todos a\n\n");
	
	printf("fd2: \"%s\"\n", get_next_line(fd2));
	printf("fd2: 0-9\n\n");
	
	printf("fd1: \"%s\"\n", get_next_line(fd1));
	printf("fd1: todos b\n\n");
	
	printf("fd2: \"%s\"\n", get_next_line(fd2));
	printf("fd2: 0-8\n\n");
	
	get_next_line(fd1);
	get_next_line(fd1);
	get_next_line(fd1);
	get_next_line(fd1);
	get_next_line(fd1);
	printf("fd1: \"%s\"\n", get_next_line(fd1));
	printf("fd1: NULL\n\n");

	close(fd1);
	fd1 = open("read_error.txt", O_RDONLY);

	printf("fd2: \"%s\"\n", get_next_line(fd2));
	printf("fd2: 9-9\n\n");

	printf("fd1: \"%s\"\n", get_next_line(fd1));
	printf("fd1: todos a\n\n");

	printf("fd2: \"%s\"\n", get_next_line(fd2));
	printf("fd2: 0-9\n\n");

	printf("fd1: \"%s\"\n", get_next_line(fd1));
	printf("fd1: todos b\n\n");

	printf("fd1: \"%s\"\n", get_next_line(fd1));
	printf("fd1: todos c\n\n");

	printf("fd1: \"%s\"\n", get_next_line(fd1));
	printf("fd1: todos d\n\n");

	printf("fd2: \"%s\"\n", get_next_line(fd2));
	printf("fd2: todo x\n\n");

	printf("fd2: \"%s\"\n", get_next_line(fd2));
	printf("fd2: NULL\n\n");

	printf("fd1: \"%s\"\n", get_next_line(fd1));
	printf("fd1: NULL\n\n");

	close(fd1);
	close(fd2);
	return 0;
}
