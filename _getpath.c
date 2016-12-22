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

char **arr_alloc(int n_ptrs)
{
	char **arr_ptrs;

	arr_ptrs = malloc(sizeof(char *) * n_ptrs + 1);
	if (!arr_ptrs)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	arr_ptrs[n_ptrs + 1] = NULL;
	return (arr_ptrs);

}


char **parsepath(char *p)
{
	int i, j, n_ptrs;
	char **dirs;
	char *curr, *tmp;

	n_ptrs = 0;
	for (i = 0; p[i]; i++)
		if (p[i] == ':')
			n_ptrs++;
	n_ptrs++;

	dirs = arr_alloc(n_ptrs);
	curr = p;
	for (i = 0; i < n_ptrs; i++)
	{
		tmp = curr;
		for (j = 1; *curr++; j++)
		{
			if (*curr == ':' || *curr == '\0')
			{
				dirs[i] = _strndup(tmp, j);
				curr++;
				break;
			}
		}
	}
	return (dirs);
}

char **getpath(void)
{
	unsigned int i, size;
	char *path;

	size = _strlen("PATH=");
	for (i = 0; environ[i]; i++)
	{
		if (_strstr(environ[i], "PATH"))
		{
			path = environ[i];
			return(parsepath(path += size));
		}
	}
	perror("PATH not found");
	return (NULL);
}
