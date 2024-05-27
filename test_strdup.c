#include "tests.h"

void	test_strdup_line(char *str)
{
	char *ftval;
	char *val;

	val = strdup(str);
	ftval = ft_strdup(str);
	printf("| value = %-31s| strdup = %-30s| ft_strdup = %-27s|\n", str, val, ftval);
	free(val);
	free(ftval);
}

void	test_strdup()
{
	char spacing[125];
	memset(spacing, '=', 124);
	spacing[124] = '\0';
	
	printf("|  strdup  |\n");
	printf("%s\n", spacing);

	test_strdup_line("");
	test_strdup_line("hi");
	test_strdup_line("test");
	test_strdup_line("blabla etc...");
	
	printf("%s\n", spacing);
}