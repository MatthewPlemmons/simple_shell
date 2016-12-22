#include "shell.h"

/**
 * _launch - launch a program and wait for it.
 *
 * @args: list of arguments
 * Return: returns 1 to continue running.
 */
int _launch(char **args, char **envp)
{

	char **path, *file;
	pid_t pid;
	int status;

	if (_strchr(*args, '/') == NULL)
	{
		path = getpath();
		file = findfile(path, args[0]);
	}
	else
		file = *args;

	pid = fork();
	if (pid == 0)
	{
		if (execve(file, args, envp) == -1)
			perror("exevce failed");

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
