#include "tests.h"

void	test_strcmp_line(char *str1, char *str2)
{
	char *value_1 = strjoin(" value_1 = ", str1);
	char *value_2 = strjoin(" value_2 = ", str2);
	char *strcmp_val = strjoin(" strcmp = ", strcmp(str1, str2));
	char *ft_strcmp_val = strjoin(" ft_strcmp = ", strcmp(str1, str2));
	char is_ko[3] = " OK";

	if (strcmp(str1, str2) != ft_strcmp(str1, str2))
		strcpy(is_ko, " KO");

	printf("|%-40s|%-40s|%-40s|%-40s|%s\n", value_1, value_2 , strcmp_val, ft_strcmp_val, is_ko);

	free(value_1);
	free(value_2);
	free(strcmp_val);
	free(ft_strcmp_val);
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
