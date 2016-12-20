#include "shell.h"


int parsepath(char *p)
{
	int i, n_dirs;
	char *dirs, *cur, *tmp;

	n_dirs = 0;
	for (i = 0; p[i]; i++)
		if (p[i] == ':')
			n_dirs++;
	n_dirs++;

	dirs = malloc(sizeof(char *) * n_dirs);
	if (!dirs)
	{
		perror("Memory allocation failed");
		return (1);
	}


	for (i = 0; i < n_dirs; i++)
	{
		for (j = 0; p[j]; j++)
		{
			if (p[j] == ':')
			{
				dir[i] = malloc(sizeof(j));
				if (!dir[i])
				{
					perror("Memory allocation failed");
					return (1);
				}
				strncpy(dir[i], p, j);
				break;
			}
		}
	}

	for (i = 0; dirs[i]; i++)
		printf("parsepath: %i\n", dirs[i]);
	free(dirs);
	return (1);
}

int getpath(void)
{
	unsigned int i, j, size;
	char ispath[4];
	char *path;

	size = sizeof(ispath);
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < size; j++)
			ispath[j] = environ[i][j];

		if (strcmp(ispath, "PATH") == 0)
		{
			path = environ[i];
			return(parsepath(path));
		}
		if (!environ[i + 1])
		{
			perror("PATH not found");
			return (1);
		}
	}
	return (0);
}
