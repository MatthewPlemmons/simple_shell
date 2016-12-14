#include "simshell.h"

/*
 * split_line - splits the line in segments.
 * Description: 
 *
 * @line: sentence to be split.
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

	token = strtok(line, 64);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize = bufsize + 64;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "$: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, 64);
	}
	tokens[position] = NULL;
	return (tokens);
}
