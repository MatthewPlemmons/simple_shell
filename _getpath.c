#include "shell.h"

/*
void _freearr(char **dirs)
{
	while (*dirs++)
	{
		free(*dirs);
	}
	free(dirs);
}
*/


char **parsepath(char *p)
{
	int i, j, n_dirs;
	char **dirs;
	char *curr, *tmp;

	n_dirs = 0;
	for (i = 0; p[i]; i++)
		if (p[i] == ':')
			n_dirs++;
	n_dirs++;

	dirs = malloc(sizeof(char *) * n_dirs + 1);
	if (!dirs)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}


	curr = p;
	while (*curr++ != '=')
		;

	for (i = 0; i < n_dirs; i++)
	{
		tmp = curr;
		for (j = 1; *curr++; j++)
		{
			if (*curr == ':' || *curr == '\0')
			{
				dirs[i] = malloc(sizeof(char) * j + 1);
				if (!dirs[i])
				{
					perror("Memory allocation failed");
					exit(EXIT_FAILURE);
				}
				curr++;
				strncpy(dirs[i], tmp, j);
				dirs[i][j] = '\0';
				break;
			}
		}
	}
	dirs[i] = NULL;

	return (dirs);
}

char **getpath(void)
{
	unsigned int i, j, size;
	char ispath[4];
	char *path;

	size = sizeof(ispath);
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < size; j++)
			ispath[j] = environ[i][j];

		/* replace with custom implementaion of strcmp */
		if (strcmp(ispath, "PATH") == 0)
		{
			path = environ[i];
			return(parsepath(path));
		}
	}
	perror("PATH not found");
	return (NULL);
}
