#include "shell.h"


int parsepath(char *p)
{
	int i, n_dirs;
	char *dirs, *cur, *tmp;

	/* Get number of directories in PATH based on how many
	   ':' seperators are present */
	n_dirs = 0;
	for (i = 0; p[i]; i++)
		if (p[i] == ':')
			n_dirs++;
	n_dirs++;

	dirs = malloc(sizeof(char *) * n_dirs);
	if (!dirs)
	{
		perror("Memory allocation failed");
		return (0);
	}

	/* This ain't workin. Rewrite to run for n_dirs,
	   then iterate over p until ':', then use iterator
	   j of that loop to allocate mem for dir[i], THEN
	   strncpy() j bytes into the new space. */
	cur = dirs;
	for (i = 0; *p; i++)
	{
		tmp = cur;
		while ((*cur++ = *p++))
		{
			if (*p == ':')
			{
				*cur = '\0';
				dirs[i] = *tmp;
				break;
			}
		}
	}
	dirs[i] = *tmp;

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
