#include "simshell.h"

/*
 * main_loop - main loop to continue untill user enters "exit"
 *
 * @return: returns status to tell main func to exit or not.
 */
void main_loop(void)
{
	char *line
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
}
