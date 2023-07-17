#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>

void extractLineTest()
{
	char *line;
	char *res;
	char *expectedRes;
	char *prueba;

	//-----------------------------------------
	prueba = "sencilla";
	line = "hola que tal\n que tal";
	expectedRes = "hola que tal\n";
	res = extractLineFromStash(line);
	if (!strcmp(res, expectedRes))
		printf("\t%s: ✅\n", prueba);
	else
	{
		printf("\t%s: ❌\n", prueba);
		printf("\tlinea esperada: \"%s\"\n", expectedRes);
		printf("\tlinea resultante: \"%s\"\n", res);
	}
	free(res);

	//-----------------------------------------
	prueba = "vacio";
	line = "\n que tal";
	expectedRes = "\n";
	res = extractLineFromStash(line);
	if (!strcmp(res, expectedRes))
		printf("\t%s: ✅\n", prueba);
	else
	{
		printf("\t%s: ❌\n", prueba);
		printf("\tlinea esperada: \"%s\"\n", expectedRes);
		printf("\tlinea resultante: \"%s\"\n", res);
	}
	free(res);

	//-----------------------------------------
	prueba = "doble";
	line = "hola\n que tal\n que tal";
	expectedRes = "hola\n";
	res = extractLineFromStash(line);
	if (!strcmp(res, expectedRes))
		printf("\t%s: ✅\n", prueba);
	else
	{
		printf("\t%s: ❌\n", prueba);
		printf("\tlinea esperada: \"%s\"\n", expectedRes);
		printf("\tlinea resultante: \"%s\"\n", res);
	}
	free(res);
}

void joinStashWithBufferTest()
{
	char *prueba;
	char *firstLine;
	char *mallocFirstLine;
	char *secondLine;
	char *expectedRes;
	char *res;

	//-----------------------------------------
	prueba = "sencilla";
	firstLine = "hola que tal";
	secondLine = "soi bobo";
	expectedRes = "hola que talsoi bobo";
	mallocFirstLine = malloc(strlen(firstLine) + 1);
	mallocFirstLine = strcpy(mallocFirstLine, firstLine);

	res = joinStashWithBuffer(mallocFirstLine, secondLine);
	if (!strcmp(res, expectedRes))
		printf("\t%s: ✅\n", prueba);
	else
	{
		printf("\t%s: ❌\n", prueba);
		printf("\tlinea esperada: \"%s\"\n", expectedRes);
		printf("\tlinea resultante: \"%s\"\n", res);
	}
	free(res);

	//-----------------------------------------
	prueba = "union con NULL";
	firstLine = "hola que tal";
	secondLine = NULL;
	expectedRes = "hola que tal";
	mallocFirstLine = malloc(strlen(firstLine) + 1);
	mallocFirstLine = strcpy(mallocFirstLine, firstLine);


	res = joinStashWithBuffer(mallocFirstLine, secondLine);
	if (!strcmp(res, expectedRes))
		printf("\t%s: ✅\n", prueba);
	else
	{
		printf("\t%s: ❌\n", prueba);
		printf("\tlinea esperada: \"%s\"\n", expectedRes);
		printf("\tlinea resultante: \"%s\"\n", res);
	}
	free(res);

	//-----------------------------------------
	prueba = "union con salto de linea y tabs";
	firstLine = "hola que tal";
	secondLine = "                  .\n\t";
	expectedRes = "hola que tal                  .\n\t";
	mallocFirstLine = malloc(strlen(firstLine) + 1);
	mallocFirstLine = strcpy(mallocFirstLine, firstLine);

	res = joinStashWithBuffer(mallocFirstLine, secondLine);
	if (!strcmp(res, expectedRes))
		printf("\t%s: ✅\n", prueba);
	else
	{
		printf("\t%s: ❌\n", prueba);
		printf("\tlinea esperada: \"%s\"\n", expectedRes);
		printf("\tlinea resultante: \"%s\"\n", res);
	}
	free(res);
}

void deleteLineFromStashTest()
{
	char *prueba;
	char *stash;
	char *mallocStash;
	char *expectedRes;
	char *res;

	//-----------------------------------------
	prueba = "sencilla";
	stash = "hola que tal\nsoi bobo";
	expectedRes = "soi bobo";
	mallocStash = malloc(strlen(stash) + 1);
	mallocStash = strcpy(mallocStash, stash);


	res = deleteLineFromStash(mallocStash);
	if (!strcmp(res, expectedRes))
		printf("\t%s: ✅\n", prueba);
	else
	{
		printf("\t%s: ❌\n", prueba);
		printf("\tlinea esperada: \"%s\"\n", expectedRes);
		printf("\tlinea resultante: \"%s\"\n", res);
	}
	free(res);
}

int main()
{
	printf("pruebas de extractLineFromStash:\n");
	extractLineTest();
	printf("pruebas de joinStashWithBuffer:\n");
	joinStashWithBufferTest();
	printf("pruebas de deleteLineFromStash:\n");
	deleteLineFromStashTest();
	return (0);
}
