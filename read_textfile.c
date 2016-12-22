#include "shell.h"

/**
 * read_textfile - reads a text file and prints to POSIX stdout.
 *
 * @filename: file to be opened and read.
 * @letters: number of letters it should read and print.
 * Return: returns the actual number of letters it could read.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, temp, count, writeval;
	char *buf;

	buf = malloc(sizeof(*buf) * letters);
	if (buf == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	count = read(fd, buf, letters);
	if (count == -1)
		return (0);

	if (count > 0)
		writeval = write(STDOUT_FILENO, buf, count);

	if (writeval == -1 || writeval != count)
		return (0);

	temp = close(fd);
	if (temp == -1)
		return (0);

	free(buf);
	return (writeval);
}
