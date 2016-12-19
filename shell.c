#include "shell.h"

/**
 * main - shell for taking user commands
 *
 * Return: int 0, upon exit.
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = read_line();
		args = split_line(line);
		status = _execute(args);

		free(line);
		free(args);

	} while (status);
	return (0);
}
