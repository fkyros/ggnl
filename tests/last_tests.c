#include <stdio.h>
#include "../get_next_line.h"

int main()
{
	char *res;

	res = get_next_line(-1);
	printf("\"%s\"\n", res);

	res = get_next_line(100);
	printf("\"%s\"\n", res);

	res = get_next_line(100);
	printf("\"%s\"\n", res);
	return 0;
}
