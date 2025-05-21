#ifndef TESTS_H
# define TESTS_H
# include "../libasm.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

char*	concat(const char *s1, const char *s2);
void	test_strlen();
void	test_strcpy();
void	test_strcmp();
void	test_write_read();
void	test_strdup();

#endif