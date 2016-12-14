#include "simshell.h"

/*
 * split_line - splits the line in segments.
 * Description: temp replacment for getline(). if buffer is filled, reallocate
 * more memory to buffer.
 *
 * @return: returns an array of segments.
 */
char **split_line(char *line)
{
	int bufsize, position;
	char **tokens, **tokens_backup, *token;
	
	bufsize = 64;
	position = 0;
	tokens = malloc(bufsize * sizeof(char*));

	if (!tokens)
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
			bufsize = bufsize + 1024;
			buffer = realloc(buffer, buffsize);
			if (!buffer)
			{
				fprintf(stderr, "$: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
