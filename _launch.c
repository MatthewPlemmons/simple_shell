#include "shell.h"

/**
 * _launch - launch a program and wait for it.
 *
 * @args: list of arguments
 * Return: returns 1 to continue running.
 */
int _launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execv(args[0], args) == -1)
			perror("$ ");

		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("$ ");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
