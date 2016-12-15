#include "simshell.h"

/**
 * The following is a list of buit ins and thier functions.
 */

/**
 * list of built ins
 */
char *builtin_str[] = 
{
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = 
{
	&_cd,
	&_help,
	&my_exit
};

int num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}


/*
 * _cd - built in command to change directory.
 *
 * @args: list of arguments, 0 is "cd", 1 is the directory.
 * @return: always returns 1, to continue to execute.
 */
int _cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "$: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("$ ");
		}
	}
	return (1);
}

/*
 * _help - built in command to change directory.
 *
 * @args: list of arguments
 * @return: always returns 1, to continue to execute.
 */
int _help(char **args)
{
	int i;

	printf("Please see list of built in commands:\n");

	for (i = 0; i < num_builtins(); i++)
	{
		printf(" %s\n", builtin_str[i]);
	}

	return (1);
}

/*
 *my_exit - built in command to exit shell.
 *
 * @args: list of arguments
 * @return: always returns 0, to exit shell.
 */
int my_exit(char **args)
{
	return (0);
}

/*
 * _execute - looks for built ins or launches program.
 * Description: 
 *
 * @args: list of arguments
 * @return: returns 1 to continue running, 0 if exit.
 **/
int _execute(char **args)
{
	int i;

	if (args[0] == NULL)
		return (1);

	for (i = 0; i < num_builtins(); i++)
	{
	if (strcmp(args[0], builtin_str[i]) == 0)
		return (*builtin_func[i])(args);
	}
	return _launch(args);
}
