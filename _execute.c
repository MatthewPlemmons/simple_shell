#include "simshell.h"

/*
 * _execute - looks for built ins or launches program.
 * Description: 
 *
 * @args: list of arguments
 * @return: returns 1 to continue running, 0 if exit.
 */
int _execute(char **args)
{
	int i;
	
	if (args[0] == NULL)
		return (1);

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], bui;tin_str[i]) == 0)
			return(*nuiltin_func[i])(args);
	}
	return _launch(args);
}
