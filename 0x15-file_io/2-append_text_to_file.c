#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/**
 * append_text_to_file - the function
 * @filename: the name of file
 * @text_content: text to be appended
 * Description: text appending to a file
 * Return: int
 */
int append_text_to_file(const char *filename, char *text_content)
{

	int len;
	int written;
	int fd;

	if (!filename)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);

	if (fd == -1)
		return (-1);
	if (text_content)
	{
		len = strlen(text_content);
		written = write(fd, text_content, len);
		if (written != len)
			return (-1);
	}
	close(fd);
	return (1);
}

