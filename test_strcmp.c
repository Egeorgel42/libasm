#include "tests.h"

void	test_strcmp_line(char *str1, char *str2)
{
	printf("| value_1 = %-29s| value_2 = %-29s| strcmp = %-30d| ft_strcmp = %-27d|\n", str1, str2 , strcmp(str1, str2), ft_strcmp(str1, str2));
}

void	test_strcmp()
{
	char spacing[166];
	memset(spacing, '=', 165);
	spacing[165] = '\0';

	printf("|  strcmp  |\n");
	printf("%s\n", spacing);

	test_strcmp_line("", "");
	test_strcmp_line("", "1");
	test_strcmp_line("1", "");
	test_strcmp_line("1", "2");
	test_strcmp_line("test", "test\0");
	test_strcmp_line("test", "tests");
	test_strcmp_line("test", "testssssssss");
	test_strcmp_line("testss", "test");

	printf("%s\n", spacing);

	return;
}
