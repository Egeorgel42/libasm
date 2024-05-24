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

void	strcpy_test_line(char *str1, char *dest, char *src, const char *reset_value)
{
	int i = ft_strlen(reset_value);

	printf("| value_src = %-27s| value_dest = %-26s|", src, dest);
	ft_strcpy(dest, reset_value);

	strcpy(dest, src);
	replace_null(str1, dest, i);
	printf(" strcpy = %-30s|", str1);
	ft_strcpy(dest, reset_value);

	ft_strcpy(dest, src);
	replace_null(str1, dest, i);
	printf(" ft_strcpy = %-27s|\n", str1);
	ft_strcpy(dest, reset_value);
}

void	test_strcpy()
{
	char	str1[50];
	char	str2[] = "oooooooooooooooooooooooooo";
	char	str3[] = "Hi";
	char	str4[] = "bruh";
	char	str5[] = "";
	char	str6[] = "1";
	char	str7[] = "2";

	char spacing[166];
	memset(spacing, '=', 165);
	spacing[165] = '\0';

	printf("|  strcpy  |\n");
	printf("%s\n", spacing);

	strcpy_test_line(str1, str2, str5, "oooooooooooooooooooooooooo");
	strcpy_test_line(str1, str2, str4, "oooooooooooooooooooooooooo");
	strcpy_test_line(str1, str4, str3, "bruh");
	strcpy_test_line(str1, str3, str5, "Hi");
	strcpy_test_line(str1, str6, str5, "1");
	strcpy_test_line(str1, str6, str7, "1");
	
	printf("%s\n", spacing);
}