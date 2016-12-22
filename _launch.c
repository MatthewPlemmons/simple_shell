#include "shell.h"

/**
 * _launch - launch a program and wait for it.
 *
 * @args: list of arguments
 * Return: returns 1 to continue running.
 */
int _launch(char **args, char **envp)
{

	/* char **path; */
	pid_t pid;
	int status;


	/* in order for execve to run external functions it must
	   be given full path of the file */
	/*
	path = getpath();
	file = findfile(args[0], path);
	*/
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
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
