#include "tests.h"

char*	concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
	if (!result)
	{
		printf("malloc err, program exited");
		exit(1);
	}
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char*	concat_int(const char *s1, const int nbr)
{
	char s2[1000];
	sprintf(s2,"%d",nbr);
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
	if (!result)
	{
		printf("malloc err, program exited");
		exit(1);
	}
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void	seperate_start(int width, char *title)
{
	printf("|    %s    |\n", title);
	for (int i = 0; i < width; i++)
		printf("=");
	printf("\n");
}

void	seperate_end(int width)
{
	for (int i = 0; i < width; i++)
		printf("=");
	printf("\n");
}

void	confirm_equality(bool value)
{
	if (value)
		printf(" OK\n");
	else
		printf(" KO\n");
}