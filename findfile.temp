
char *findfile()
{
	int i;

	for (i = 0; dirs[i]; i++)
	{
		size = _strlen(dirs[i]);
		d_path = malloc(sizeof(char) * size);
		fullpath = _strcat(dirs[i], args[0]);
		_strcpy(d_path, fullpath);

		if (stat(fullpath) == -1)
		{
			continue;
		}
		else
		{
			printf("file found.");
			return (fullpath);
		}
	}
	return (NULL);
}
