#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

void print_error(const char *filename, int fd, const char *error)
{
	dprintf(STDERR_FILENO, "Error: %s %s\n", error, filename);
	if (fd != -1)
		close(fd);
	exit(98);
}

int main(int argc, char **argv)
{
	int fd_from, fd_to;
	char buf[BUF_SIZE];
	ssize_t n_read, n_written;

	if (argc != 3)
	{
		exit(97);
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error(argv[1], fd_from, "Can't read from file");

	fd_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
		print_error(argv[2], fd_to, "Can't write to");

	while ((n_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		n_written = write(fd_to, buf, n_read);
		if (n_written != n_read)
			print_error(argv[2], fd_to, "Can't write to");
	}
	if (n_read == -1)
		print_error(argv[1], fd_from, "Can't read from file");
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}


