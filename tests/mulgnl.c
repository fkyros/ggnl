#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd1 = open("41_with_nl", O_RDONLY);
	printf("\"%s\"\n", get_next_line(1000));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd1));
	printf("0-9 cuatro veces\n\n");

	int fd2 = open("42_with_nl", O_RDONLY);
	printf("\"%s\"\n", get_next_line(1001));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd2));
	printf("0-9 cuatro veces y un 0\n\n");

	int fd3 = open("43_with_nl", O_RDONLY);
	printf("\"%s\"\n", get_next_line(1002));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd3));
	printf("0-9 cuatro veces y un 01\n\n");

	printf("\"%s\"\n", get_next_line(1003));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd1));
	printf("un 0\n\n");

	printf("\"%s\"\n", get_next_line(1003));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd2));
	printf("un 1\n\n");

	printf("\"%s\"\n", get_next_line(1003));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd3));
	printf("un 2\n\n");

	printf("\"%s\"\n", get_next_line(fd1));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd2));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd3));
	printf("null\n\n");

	int fd4 = open("nl", O_RDONLY);
	printf("\"%s\"\n", get_next_line(1006));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd4));
	printf("salto de linea\n\n");

	printf("\"%s\"\n", get_next_line(1007));
	printf("null\n\n");

	printf("\"%s\"\n", get_next_line(fd4));
	printf("null\n\n");

	return 0;
}
