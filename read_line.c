#include "shell.h"

/*
 * read_line - gets input from stdin.
 * Description: temp replacment for getline(). if buffer is filled, reallocate
 * more memory to buffer.
 *
 * @return: returns the line it read from stdin.
 */
char *read_line(void)
{
	int bufsize, position, c;
	char *buffer, *temp;

	position = 0;
	bufsize = 1024;
	buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		fprintf(stderr, "$: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
			buffer[position] = c;
		position++;

		if (position >= bufsize)
		{
			temp = malloc(sizeof(char) * bufsize);
			temp = buffer;
			bufsize = bufsize + 1024;
			free(buffer);
			buffer = malloc(sizeof(char) * bufsize);
			buffer = temp;
			free(temp);
			if (!buffer)
			{
				fprintf(stderr, "$: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
