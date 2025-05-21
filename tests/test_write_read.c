#include "tests.h"

void	test_write_line(char *value, size_t write_len, int ft_write_fd, int write_fd, bool is_set)
{
	printf("| val = %-23s|%*s|%*s|%*s|%*s|%*s|\n", value, 30, "", 30, "", 30, "", 30, "", 30, "");
	printf("| wrt_len = %-19ld|", write_len);
	if (is_set)
		printf(" wrt_fd = %-20d|", write_fd);
	else
		printf(" wrt_fd = %-20s|", "pipe");

	printf("%*s|", 30, "");

	write(write_fd, value, write_len);
	printf(" wrt_err = %-19d|%*s|", errno, 30, "");
	errno = 0;

	ft_write(ft_write_fd, value, write_len);
	printf(" ft_wrt_err = %-16d|", errno);
	errno = 0;

	printf("\n");
}

void	test_read_line(size_t read_len, int ft_read_fd, int read_fd, bool is_set)
{
	char buffer[50];

	printf("| rd_len = %-20ld|", read_len);
	if (is_set)
		printf(" rd_fd = %-21d|", read_fd);
	else
		printf(" rd_fd = %-21s|", "pipe");

	bzero(buffer, 49);

	if (!read(read_fd, buffer, read_len))
		printf(" rd = %-24s| rd_err = %-20d|", "EOF", errno);
	else
		printf(" rd = %-24s| rd_err = %-20d|", buffer, errno);
	errno = 0;

	bzero(buffer, 49);

	if (!ft_read(ft_read_fd, buffer, read_len))
		printf(" ft_rd = %-21s| ft_rd_err = %-17d|", "EOF", errno);
	else
		printf(" ft_rd = %-21s| ft_rd_err = %-17d|", buffer, errno);
	errno = 0;

	printf("\n");
}

int	*test_write_read_line(char *value, int write_len, int read_len, int write_fd, int read_fd, char *spacing, bool close_read_fd)
{
	int	fd[2];
	int	ft_fd[2];
	int *fd_ret;
	bool is_set = true;
	if (!read_fd && !write_fd)
	{
		if (pipe(fd) < 0)
		{
			perror("pipe: ");
			return NULL;
		}
		if (pipe(ft_fd) < 0)
		{
			perror("pipe: ");
			return NULL;
		}
		is_set = false;
	}

	if (spacing)
		printf("%s\n", spacing);

	if (is_set)
		test_write_line(value, write_len, write_fd, write_fd, is_set);
	else
	{
		test_write_line(value, write_len, ft_fd[1], fd[1], is_set);
		close(ft_fd[1]);
		close(fd[1]);
	}
		
	if (is_set)
		test_read_line(read_len, read_fd, read_fd, is_set);
	else
	{
		test_read_line(read_len, ft_fd[0], fd[0], is_set);
		if (close_read_fd)
		{
			close(ft_fd[0]);
			close(fd[0]);
		}
		else{
			fd_ret = malloc(sizeof(int)*2);
			fd_ret[0] = ft_fd[0];
			fd_ret[1] = fd[0];
			return fd_ret;
		}
	}
	return NULL;
}

void	test_write_read()
{
	seperate_start(187, "write && read");

	char middle_spacing[188];
	memset(middle_spacing, '-', 187);
	middle_spacing[0] = '|';
	middle_spacing[186] = '|';
	middle_spacing[187] = '\0';


	test_write_read_line("", 1, 1, 0, 0, NULL, true);
	test_write_read_line(NULL, 1, 1, 0, 0, middle_spacing, true);
	test_write_read_line("Hi", 1, 20, -1, -1, middle_spacing, true);
	test_write_read_line("Hi", 1, 20, 76, 76, middle_spacing, true);
	test_write_read_line("Hi", 1, 20, 0, 0, middle_spacing, true);
	test_write_read_line("Hi", 20, 5, 0, 0, middle_spacing, true);

	int *read_fd = test_write_read_line("Hi", 2, 1, 0, 0, middle_spacing, false);
	test_read_line(1, read_fd[0], read_fd[1], false);
	test_read_line(1, read_fd[0], read_fd[1], false);
	free(read_fd);

	test_write_read_line("Hi", 2, 2, 0, 0, middle_spacing, true);
	
	read_fd = test_write_read_line("Hello", 5, 2, 0, 0, middle_spacing, false);
	test_read_line(2, read_fd[0], read_fd[1], false);
	test_read_line(1, read_fd[0], read_fd[1], false);
	test_read_line(1, read_fd[0], read_fd[1], false);
	free(read_fd);
	
	seperate_end(187);
}