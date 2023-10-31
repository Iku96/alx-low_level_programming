#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * read_textfile - the function
 * @filename: the name of the file to be read
 * @letters: the size interms of bytes
 * Description: Read a file and output iin posix
 * Return: integer
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	char *buffer;
	int read_text, write_text;


	buffer = malloc(letters);

	file = open(filename, O_RDONLY);

	if (file == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}

	read_text = read(file, buffer, letters);

	if (filename == NULL)
	{
		free(buffer);
		close(file);
		return (0);
	}


	write_text = write(STDOUT_FILENO, buffer, read_text);

	if (write_text == -1 || write_text != read_text)
	{
		free(buffer);
		close(file);
		return (0);
	}
	free(buffer);
	close(file);
	return (read_text);
}
