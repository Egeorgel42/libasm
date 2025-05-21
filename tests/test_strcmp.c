#include "tests.h"

void	test_strcmp_line(char *str1, char *str2)
{
	char *value_1 = concat(" value_1 = ", str1);
	char *value_2 = concat(" value_2 = ", str2);
	char *strcmp_val = concat_int(" strcmp = ", strcmp(str1, str2));
	char *ft_strcmp_val = concat_int(" ft_strcmp = ", strcmp(str1, str2));

	printf("|%-40s|%-40s|%-40s|%-40s|", value_1, value_2 , strcmp_val, ft_strcmp_val);
	confirm_equality(strcmp(str1, str2) == strcmp(str1, str2) && errno == 0);

	free(value_1);
	free(value_2);
	free(strcmp_val);
	free(ft_strcmp_val);
}

void	test_strcmp()
{
	seperate_start(165, "strcmp");

	test_strcmp_line("", "");
	test_strcmp_line("", "1");
	test_strcmp_line("1", "");
	test_strcmp_line("1", "2");
	test_strcmp_line("test", "test\0");
	test_strcmp_line("test", "tests");
	test_strcmp_line("test", "testssssssss");
	test_strcmp_line("testss", "test");

	seperate_end(165);

	return;
}
