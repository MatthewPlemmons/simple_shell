#include "shell.h"

/**
 * append_to_file - writes text to end of file..
 *
 * @filename: file to be written to.
 * @text_content: text to be written to file.
 * Return: 1 on success, -1 on failure.
 */
int append_to_file(const char *filename, char *text_content)
{
	int fd, temp, count;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	fd = open(filename, O_RDWR | O_APPEND);
	if (fd == -1)
		return (-1);

	count = 0;
	while (text_content[count] != '\0')
	{
		count++;
	}

	temp = write(fd, text_content, count);
	close(fd);
	if (temp == -1)
		return (-1);

	return (1);
}
