#include "tests.h"

int*	make_pipe()
{
	int *pipes = malloc(sizeof(int) * 4);
	if (pipe(pipes) || pipe(pipes + 2))
	{
		printf("pipe err during test, exiting");
		exit(1);
	}
	return pipes;
}

void test_write_line(char *value, size_t len, int fd, int ft_fd, bool close_fd)
{
	int wr_ret = write(fd, value, len);
	int wr_errno = errno;
	errno = 0;
	int ft_wr_ret = ft_write(ft_fd, value, len);

	printf("| write | val = %-23s| len = %-23ld| err = %-23d| ft_err = %-20d| %*s|", value, len, wr_errno, errno, 28, "");
	confirm_equality(wr_ret == ft_wr_ret && wr_errno == errno);
	if (close_fd)
	{
		close(fd);
		close(ft_fd);
	}
	errno = 0;
}

void test_read_line(size_t len, int fd, int ft_fd, bool close_fd)
{
	char buffer1[50] = "not set";
	char buffer2[50] = "not set";

	int rd_ret = read(fd, buffer1, len);
	int wr_errno = errno;
	errno = 0;
	if (!rd_ret)
		strcpy(buffer1, "EOF");
	else if (!wr_errno)
		buffer1[rd_ret] = '\0';
	printf("| read  | len = %-23ld| err = %-23d| read = %-22s|", len, wr_errno, buffer1);

	int ft_rd_ret = ft_read(ft_fd, buffer2, len);
	if (!ft_rd_ret)
		strcpy(buffer2, "EOF");
	else if (!errno)
		buffer2[ft_rd_ret] = '\0';
	printf(" ft_err = %-20d| ft_read = %-18s|", errno, buffer2);
	confirm_equality(!strcmp(buffer1, buffer2) && rd_ret == ft_rd_ret && wr_errno == errno);

	if (close_fd)
	{
		close(fd);
		close(ft_fd);
	}
	errno = 0;
}

void	test_write_read()
{
	seperate_start(163, "write");

	test_write_line("", 1, -1, -1, false);
	test_read_line(1, -1, -1, false);
	test_write_line("", 1, 79, 79, false); 
	test_read_line(1, 79, 79, false); //invalid fd

	seperate_test(163);

	int *pipes = make_pipe();
	test_write_line("", 1, pipes[1], pipes[3], true); //write "" and close
	test_read_line(1, pipes[0], pipes[2], false); // read ""
	test_read_line(1, pipes[0], pipes[2], true); //accessed end of file and close
	test_read_line(1, pipes[0], pipes[2], false); //accessed invalid fd => errno 9
	free(pipes);

	seperate_test(163);

	pipes = make_pipe();
	test_write_line(NULL, 1, pipes[1], pipes[3], false); //write NULL => errno 14
	test_write_line("", 0, pipes[1], pipes[3], true); //write len 0
	test_read_line(2, pipes[0], pipes[2], true); //read empty file
	free(pipes);

	seperate_test(163);

	pipes = make_pipe();
	test_write_line("Hello There !", 6, pipes[1], pipes[3], false); //write "Hello "
	test_write_line("There ! jlabwdahbkw", 7, pipes[1], pipes[3], false); //write "There !"
	test_write_line("General Kenobi", 14, pipes[1], pipes[3], true); //write "General Kenobi"
	test_read_line(13, pipes[0], pipes[2], false); //read "hello there !"
	test_read_line(1000, pipes[0], pipes[2], true); //read "General Kenobi"
	free(pipes);

	seperate_test(163);

	pipes = make_pipe();
	test_write_line("Hello", 5, pipes[1], pipes[3], true); //write "Hello "
	test_read_line(2, pipes[0], pipes[2], false); //read "he"
	test_read_line(4, pipes[0], pipes[2], false); //read "llo"
	test_read_line(3, pipes[0], pipes[2], true); //read EOF
	free(pipes);

	seperate_end(163);
}