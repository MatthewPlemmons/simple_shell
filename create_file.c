#include "shell.h"

/**
 * create_file - creates a text file.
 *
 * @filename: file to be written to.
 * @text_content: text to be written to file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t temp, count;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	count = 0;
	while (text_content[count] != '\0')
	{
		count++;
	}
	if (count > 0)
		temp = write(fd, text_content, count);

	if (temp == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
