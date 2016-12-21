#include "shell.h"

/**
 * findfile - look through the directories taken from PATH to find file.
 * @dirs: pointer array for path directories.
 * @args: contains file/command to find.
 * Returns: 
 */
int findfile(char **dirs, char **args)
{
	opendir();
	readdir();
	closedir();
}
