#include <stdio.h>
#include "shell.h"

int _env(void)
{
	int i;

	for(i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}
