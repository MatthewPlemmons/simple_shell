#include "shell.h"

/**
 * _history - prints out command history.
 * Description: prints history from file .simple_shell_history file.
 *
 * Return: always returns 1, for shell to continue to function.
 */
int _history(void)
{
	char *filename;

	filename = ".simple_shell_history";

	if (read_textfile(filename, 99999999) <= 0)
		printf("Error reading %s file. \n", filename);

	return(1);
}
