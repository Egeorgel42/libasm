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
	test_strlen_line("tests\0");
	test_strlen_line("AWDSAs_awd");

	/*char str[2];
	str[0] = 'a';
	str[1] = 'b';
	printf("%ld\n", strlen(str));
	printf("| value = %-41s| strlen = %-40ld| ft_strlen = %-37ld|\n", "ab", strlen(str), ft_strlen(str));*/		//both of them segfault

	/*
	printf("%ld\n", strlen(NULL));
	printf("%ld\n", ft_strlen(NULL));*/		//both of them segfault

	seperate_end(124);
}
