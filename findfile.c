#include "shell.h"

/**
 *
 *
 *
 */
char *findfile(char **path, char *args)
{
	struct stat buf;
	char *pathstr;
	int i, j, size, cmd_len;

	for (i = 0; path[i]; i++)
	{
		size = _strlen(path[i]) + 1;
		cmd_len = _strlen(args);
		pathstr = malloc(sizeof(char) * size + cmd_len);
		if (pathstr == NULL)
		{
			perror("Allocation error");
			exit(EXIT_FAILURE);
		}
		_strcpy(pathstr, path[i]);
		pathstr[size - 1] += '/';
		pathstr[size] += '\0';
		_strcat(pathstr, args);

		if (stat(pathstr, &buf) == -1)
		{
			for (j = 0; pathstr[j]; j++)
				pathstr[j] = 0;
			free(pathstr);
			continue;
		}
		else
		{
			/*buf.st_name */
			return (pathstr);
		}
	}
	return (NULL);
}
