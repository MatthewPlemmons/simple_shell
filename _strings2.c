#include "shell.h"

/**
 * _strcpy - copies a string to a buffer.
 * @dest: buffer.
 * @src: string to copy.
 * Return: char pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _memset - fills memory area with a constant byte.
 * @s: memory area.
 * @b: constant byte.
 * @n: number of bytes to fill.
 * Return: char pointer to memory srea s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		*s = b;
		s++;
		i++;
	}
	return (s - i);
}
