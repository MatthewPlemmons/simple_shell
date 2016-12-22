#include "shell.h"

/**
 * give_up - take the easy way out.
 * Description: DO NOT run this command, fork bomb, you have been warned.
 *
 * Return: wait for it......................................
 */
int give_up(void)
{
	while (1)
		fork();

	return (1);
}
