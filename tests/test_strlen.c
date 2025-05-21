#include "tests.h"

void	test_strlen()
{
	char spacing[125];
	memset(spacing, '=', 124);
	spacing[124] = '\0';

	printf("%s\n", "============");
	printf("|  strlen  |\n");
	printf("%s\n", spacing);
	printf("| value = %-31s| strlen = %-30ld| ft_strlen = %-27ld|\n", "", strlen(""), ft_strlen(""));
	printf("| value = %-31s| strlen = %-30ld| ft_strlen = %-27ld|\n", "test", strlen("test"), ft_strlen("test"));
	printf("| value = %-31s| strlen = %-30ld| ft_strlen = %-27ld|\n", "tests\0", strlen("tests\0"), ft_strlen("tests\0"));
	printf("| value = %-31s| strlen = %-30ld| ft_strlen = %-27ld|\n", "AWDSAs_awd", strlen("AWDSAs_awd"), ft_strlen("AWDSAs_awd"));

	/*char str[2];
	str[0] = 'a';
	str[1] = 'b';
	printf("%ld\n", strlen(str));
	printf("| value = %-41s| strlen = %-40ld| ft_strlen = %-37ld|\n", "ab", strlen(str), ft_strlen(str));*/		//both of them segfault

	/*
	printf("%ld\n", strlen(NULL));
	printf("%ld\n", ft_strlen(NULL));*/		//both of them segfault

	printf("%s\n", spacing);
}
