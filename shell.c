#include "shell.h"

/**
 * main - shell for taking user commands
 *
 * Return: int 0, upon exit.
 */

int main(int argc, char **argv, char **envp)
{
	char *line;
	char **args;
	int status;
	(void) argc, (void) argv;

	printf("Welcome to our attempt at a simple shell.\n\n");
	do {
		printf(">$ ");
		line = read_line();
		args = split_line(line);
		status = _execute(args, envp);

		free(line);
		free(args);

	} while (status);
	return (0);
}
