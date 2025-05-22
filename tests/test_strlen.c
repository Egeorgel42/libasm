#include "tests.h"

void	test_strlen_line(char* str)
{
	printf("| value = %-31s| strlen = %-30ld| ft_strlen = %-27ld|", str, strlen(str), ft_strlen(str));
	confirm_equality(strlen(str) == ft_strlen(str) && errno == 0);
}

void	test_strlen()
{
	seperate_end(16);
	seperate_start(124, "strlen");

	test_strlen_line("");
	test_strlen_line("test");
	test_strlen_line("tests\0aaa");
	test_strlen_line("AWDSAs_awd");

	seperate_end(124);
}
