#include <stdio.h>
#include "shell.h"

/**
 * _env - prints out current enviroment variables.
 *
 * Return: always returns 1
 */
int _env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}
