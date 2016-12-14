#include "simshell.h"

/*
 * _launch - launch a program and wait for it.
 *
 * @args: list of arguments
 * @return: returns 1 to continue running.
 */
int _launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("$ ");

		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("$ ");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFESIGNALED(status));
	}
	return (1);
}
