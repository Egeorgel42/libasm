#include "tests.h"

void	replace_null(char *dest, char *src, int len)
{
	int i = 0;
	bzero(dest, 50);
	while (i < len)
	{
		if (!src[i])
		{
			strncpy(dest, src, i);
			strcat(dest, "\\0");
			strncat(dest, src+i+1, len - (i + 1));
			return;
		}
		i++;
	}
	ft_strcpy(dest, src);
	return;
}

void	strcpy_test_line(char *s1, char *s2)
{
	char printf_buff1[50];
	char printf_buff2[50];
	char* dest = strdup(s1);
	char* src = strdup(s2);
	char* reset = strdup(dest);
	int i = ft_strlen(dest);

	printf("| value_src = %-27s| value_dest = %-26s|", src, dest);

	strcpy(dest, src);
	replace_null(printf_buff1, dest, i);
	printf(" strcpy = %-30s|", printf_buff1);

	ft_strcpy(dest, reset);
	ft_strcpy(dest, src);
	replace_null(printf_buff2, dest, i);
	printf(" ft_strcpy = %-27s|", printf_buff2);

	confirm_equality(!strcmp(printf_buff1, printf_buff2) && errno == 0);

	free(reset);
}

void	test_strcpy()
{
	seperate_start(165, "strcpy");

	strcpy_test_line("oooooooooooooooooooooooooo", "");
	strcpy_test_line("oooooooooooooooooooooooooo", "bruh");
	strcpy_test_line("bruh", "Hi");
	strcpy_test_line("Hi", "");
	strcpy_test_line("", "1");
	strcpy_test_line("1", "2");

	seperate_end(165);
}