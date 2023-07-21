#include <stdio.h>
#include "../get_next_line.h"
#include <fcntl.h>


int main()
{
	int fd = open("read_error.txt", O_RDONLY);

	printf("\"%s\"\n", get_next_line(fd));
	printf("todo a\n\n");
	printf("\"%s\"\n", get_next_line(fd));
	printf("todo b\n\n");
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	printf("\"%s\"\n", get_next_line(fd));
	printf("null\n\n");
	close(fd);
	fd = open("read_error.txt", O_RDONLY);
	printf("\"%s\"\n", get_next_line(fd));
	printf("todo a\n\n");
	printf("\"%s\"\n", get_next_line(fd));
	printf("todo b\n\n");
	printf("\"%s\"\n", get_next_line(fd));
	printf("todo c\n\n");
	printf("\"%s\"\n", get_next_line(fd));
	printf("todo d\n\n");
	printf("\"%s\"\n", get_next_line(fd));
	printf("null\n\n");
	close(fd);
	return 0;
}
