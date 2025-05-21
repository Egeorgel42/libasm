#include "tests.h"

void	test_strdup_line(char *str)
{
	char *ftval;
	char *val;

	val = strdup(str);
	ftval = ft_strdup(str);
	printf("| value = %-31s| strdup = %-30s| ft_strdup = %-27s|", str, val, ftval);
	confirm_equality(!strcmp(val, ftval) && str != val && str != ftval && errno == 0);
	free(val);
	free(ftval);
}

void	test_strdup()
{
	seperate_start(124, "strdup");

	test_strdup_line("");
	test_strdup_line("hi");
	test_strdup_line("test");
	test_strdup_line("blabla etc...");
	
	seperate_end(124);
}