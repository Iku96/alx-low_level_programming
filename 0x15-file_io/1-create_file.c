#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


/**
 * create_file - the function
 * @filename: the nnem o fthe file to be created
 * @text_content: The text
 * Description: THis createas another file
 * Return: int
 */
int create_file(const char *filename, char *text_content)
{
	int fd;

	if (!filename)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		int len = strlen(text_content);
		int written = write(fd, text_content, len);
		if (written != len)
			return (-1);
	}

	close(fd);
	return (1);
}
